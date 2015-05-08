// eff_dependence: calculates the dependence of the isolation efficiency in terms of
//                 lepton pT, HT, njets, MJ, MET, ntrupv

#include "eff_dependence.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>

#include "TH1D.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TLorentzVector.h"

#include "RooStats/NumberCountingUtils.h"

using namespace std;

namespace channel { enum { el=0, mu=1, last=2}; }
namespace mode { enum { eff=0, fake=1, last=2}; }

bool msgdbg = true;

int main(){

  // string isostr = "miniso"; 
  // const double iso_cut[2] = {0.05, 0.3}; //el, mu

  TString basedir = "/cms5r0/manuelf/root/archive/15-01-30/";

  vector<TString> samples;
  vector<TString> fnames;
  samples.push_back("*-T1tttt_2J_mGl-1500_mLSP-100_*"); fnames.push_back("T1tttt1500");
  //samples.push_back("*_TTJets*"); fnames.push_back("ttbar");
  // samples.push_back("*_QCD_*"); fnames.push_back("qcd");
  // samples.push_back("*-T1tttt_2J_mGl-1200_mLSP-800_*PU20*"); fnames.push_back("T1tttt1200");
  // samples.push_back("*_WJetsToLNu*"); fnames.push_back("wjets");
  // samples.push_back("*-T2tt_2J_mStop-650_mLSP-325_*"); fnames.push_back("T2tt650");
  // samples.push_back("*-T2tt_2J_mStop-850_mLSP-100_*"); fnames.push_back("T2tt850");

  vector<TString> isotypes;               vector<double> el_isocut;      vector<double> mu_isocut;
  isotypes.push_back("none");             el_isocut.push_back(0.);       mu_isocut.push_back(0.); //cut value will *not* be used
  isotypes.push_back("reliso");           el_isocut.push_back(0.);       mu_isocut.push_back(0.); //cut value will *not* be used
  isotypes.push_back("miniso_tr10");      el_isocut.push_back(0.1);      mu_isocut.push_back(0.2);
  isotypes.push_back("miniso_tr10_r03_vvl");      el_isocut.push_back(0.1);      mu_isocut.push_back(0.2);
  isotypes.push_back("miniso_tr10_r03_04");      el_isocut.push_back(0.1);      mu_isocut.push_back(0.2);
  //isotypes.push_back("reliso_trig");           el_isocut.push_back(0.);       mu_isocut.push_back(0.); //cut value will *not* be used

  for (unsigned sample=0; sample<samples.size(); sample++) {

    TFile fout("isolation_"+fnames[sample]+".root","RECREATE");

    TH1D h_pt[5][channel::last][mode::last];
    TH1D h_ht[5][channel::last][mode::last];
    TH1D h_njets[5][channel::last][mode::last];
    TH1D h_mj[5][channel::last][mode::last];
    TH1D h_met[5][channel::last][mode::last];
    TH1D h_pv[5][channel::last][mode::last];
    for (unsigned i=0; i<5; i++){
      for (unsigned j=0; j<channel::last; j++){ 
        for (unsigned k=0; k<mode::last; k++){ 
          TString nm;
          nm = isotypes[i];
          if (k==mode::fake) nm +="_fake";  
          if (j==channel::el) nm +="_el";
          else nm += "_mu";
          h_pt[i][j][k] = TH1D("h_pt_"+nm,"h_pt_"+nm+"; lepton p_{T} [GeV];", 40, 0.,400.); h_pt[i][j][k].Sumw2();
          h_ht[i][j][k] = TH1D("h_ht_"+nm,"h_ht_"+nm+"; H_{T} [GeV];", 50, 0.,2500.); h_ht[i][j][k].Sumw2();
          h_njets[i][j][k] = TH1D("h_njets_"+nm,"h_njets_"+nm+"; jet multiplicity;", 20, -0.5,19.5); h_njets[i][j][k].Sumw2();
          h_mj[i][j][k] = TH1D("h_mj_"+nm,"h_mj_"+nm+"; sumJetMass [GeV];", 50, 0.,1400.); h_mj[i][j][k].Sumw2();
          h_met[i][j][k] = TH1D("h_met_"+nm,"h_met_"+nm+"; MET [GeV];", 50, 0.,1600.); h_met[i][j][k].Sumw2();
          h_pv[i][j][k] = TH1D("h_pv_"+nm,"h_pv_"+nm+"; n_{PV}^{true};", 50, 10.,60.); h_pv[i][j][k].Sumw2();
        }
      }
    }


    small_tree_quick tree((basedir+samples[sample]).Data());

    const long nent = tree.GetEntries();
    cout<<"Number of events to run over: "<<nent<<endl;
    for (long ientry=0; ientry<nent; ientry++){
      if (ientry%100000==0) cout<<"Processed events: "<<ientry<<endl;
      tree.GetEntry(ientry);

      double weight = 1;
      if (fnames[sample]=="wjets" || fnames[sample]=="qcd") weight = tree.weight()*5;

      //---------- ELECTRONS ----------------      
      for (unsigned iel=0; iel<tree.els_pt().size(); iel++){
        if (!(tree.els_ispf()[iel]) || 
            !(tree.els_sigid()[iel]) ||
            tree.els_pt()[iel]<10.) continue;

        for (unsigned iiso(0); iiso<isotypes.size(); iiso++){
          if (passIsolation(tree, iel, /*isElectron*/ true, /*isveto*/ false, isotypes[iiso], el_isocut[iiso])) {
            unsigned this_mode = mode::fake;
            if (tree.els_tru_tm()[iel]) this_mode = mode::eff;
            h_pt[iiso][channel::el][this_mode].Fill(tree.els_pt()[iel], weight);
	    if(tree.els_pt()[iel]<20) continue;
	    if(iiso==3 && tree.els_reliso_r03()[iel] > 1.5) continue;
	    //if(iiso==3 && tree.els_reliso_r02()[iel] > 0.8) continue;
	    if(iiso==4 && tree.els_reliso_r03()[iel] > 0.4) continue;

            h_ht[iiso][channel::el][this_mode].Fill(tree.ht(), weight);
            h_njets[iiso][channel::el][this_mode].Fill(tree.njets(), weight);
            h_mj[iiso][channel::el][this_mode].Fill(tree.mj_30(), weight);
            h_met[iiso][channel::el][this_mode].Fill(tree.met(), weight);
            h_pv[iiso][channel::el][this_mode].Fill(tree.ntrupv(), weight);
          }
        }
      }
      
      //---------- MUONS ----------------
      for (unsigned imu=0; imu<tree.mus_pt().size(); imu++){
        if (!(tree.mus_sigid()[imu]) ||
          tree.mus_pt()[imu]<10.) continue;

        for (unsigned iiso(0); iiso<isotypes.size(); iiso++){      
          if (passIsolation(tree, imu, /*isElectron*/ false, /*isveto*/ false, isotypes[iiso], mu_isocut[iiso])) {
            unsigned this_mode = mode::fake;
            if (tree.mus_tru_tm()[imu]) this_mode = mode::eff;
            h_pt[iiso][channel::mu][this_mode].Fill(tree.mus_pt()[imu], weight);
	    if(tree.mus_pt()[imu]<20) continue;
	    if(iiso==3 && tree.mus_reliso_r03()[imu] > 1) continue;
	    //if(iiso==3 && tree.mus_reliso_r02()[imu] > 1.2) continue;
	    if(iiso==4 && tree.mus_reliso_r03()[imu] > 0.4) continue;

            h_ht[iiso][channel::mu][this_mode].Fill(tree.ht(), weight);
            h_njets[iiso][channel::mu][this_mode].Fill(tree.njets(), weight);
            h_mj[iiso][channel::mu][this_mode].Fill(tree.mj_30(), weight);
            h_met[iiso][channel::mu][this_mode].Fill(tree.met(), weight);
            h_pv[iiso][channel::mu][this_mode].Fill(tree.ntrupv(), weight);
          }
        }
      }

      
    }

    fout.Write();
    fout.Close();
  }
  return 0;
}


bool passIsolation(const small_tree_quick &tree, int ilep, bool isElectron, bool isveto, TString isotype, const double iso_cut){

  if (isotype.Contains("reliso")){ 
    if (isElectron){
      if (fabs(tree.els_eta()[ilep]) <= 1.479) 
        return (tree.els_reliso_r03()[ilep] < (isveto ? 0.3313 : 0.164369));
      else 
        return (tree.els_reliso_r03()[ilep] < (isveto ? 0.3816 : 0.212604));
    } else {
      return tree.mus_reliso_r04()[ilep] < 0.2;//(isveto ? 0.2 : 0.12));
    }
  } else if (isotype=="reliso_r02") {
    if (isElectron) 
      return tree.els_reliso_r02()[ilep] < iso_cut;
    else 
      return tree.mus_reliso_r02()[ilep] < iso_cut;
  } else if (isotype.Contains("miniso_tr10")) {
    if (isElectron) 
      return ((tree.els_miniso_tr10()[ilep] < iso_cut) 
             || (tree.els_reliso_r02()[ilep] < iso_cut));
    else 
      return ((tree.mus_miniso_tr10()[ilep] < iso_cut) 
             || (tree.mus_reliso_r02()[ilep] < iso_cut));
  } else if (isotype=="miniso_tr10_pfpu") {
    if (isElectron) 
      return ((tree.els_miniso_tr10_pfpu()[ilep] < iso_cut) 
             || (tree.els_reliso_r02()[ilep] < iso_cut));
    else 
      return ((tree.mus_miniso_tr10_pfpu()[ilep] < iso_cut) 
             || (tree.mus_reliso_r02()[ilep] < iso_cut));
  } else if (isotype=="miniso_tr07") {
    if (isElectron) 
      return ((tree.els_miniso_tr07()[ilep] < iso_cut) 
             || (tree.els_reliso_r02()[ilep] < iso_cut));
    else 
      return ((tree.mus_miniso_tr07()[ilep] < iso_cut) 
             || (tree.mus_reliso_r02()[ilep] < iso_cut));
  } else if (isotype=="none") {
    return true;
  } 
  return false;
}
