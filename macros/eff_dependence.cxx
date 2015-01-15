#include "iso_eff_param.hpp"

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

bool msgdbg = true;

int main(){

  // string isostr = "miniso"; 
  // const double iso_cut[2] = {0.05, 0.3}; //el, mu

  string fname = "";
  string basedir = "/cms2r0/manuelf/root/small/archive/15-01-08/";
  // string sample = "*_QCD_*"; fname = "qcd";
  string sample = "*_TTJets*"; fname = "ttbar_fake";
  // string sample = "*-T1tttt_2J_mGl-1200_mLSP-800_*PU20*";
  // string sample = "*-T1tttt_2J_mGl-1500_mLSP-100_*PU20*"; fname = "T1tttt1500_fake";
  // string sample = "*_WJetsToLNu*"; fname = "wjets";
  // string sample = "*-T2tt_2J_mStop-650_mLSP-325_*";
  // string sample = "*-T2tt_2J_mStop-850_mLSP-100_*";

  TFile fout(("isolation_"+fname+".root").c_str(),"RECREATE");

  vector<TString> isotypes;       vector<double> el_isocut;      vector<double> mu_isocut;
  isotypes.push_back("none");     el_isocut.push_back(0.);       mu_isocut.push_back(0.);
  isotypes.push_back("reliso");   el_isocut.push_back(0.);       mu_isocut.push_back(0.);
  isotypes.push_back("miniso");   el_isocut.push_back(0.1);      mu_isocut.push_back(0.4);

  TH1D h_pt[3][2];
  TH1D h_ht[3][2];
  TH1D h_njets[3][2];
  TH1D h_mj[3][2];
  for (unsigned i=0; i<3; i++){
    for (unsigned j=0; j<2; j++){
      TString nm; 
      if (j==0) nm = "h_pt_"+isotypes[i]+"_el";
      else nm = "h_pt_"+isotypes[i]+"_mu";
      h_pt[i][j] = TH1D(nm,nm+"; lepton p_{T} [GeV];", 40, 0.,400.);
      h_pt[i][j].Sumw2();
      if (j==0) nm = "h_ht_"+isotypes[i]+"_el";
      else nm = "h_ht_"+isotypes[i]+"_mu";
      h_ht[i][j] = TH1D(nm,nm+"; H_{T} [GeV];", 50, 0.,2500.);
      h_ht[i][j].Sumw2();
      if (j==0) nm = "h_njets_"+isotypes[i]+"_el";
      else nm = "h_njets_"+isotypes[i]+"_mu";
      h_njets[i][j] = TH1D(nm,nm+"; jet multiplicity;", 20, -0.5,19.5);
      h_njets[i][j].Sumw2();
      if (j==0) nm = "h_mj_"+isotypes[i]+"_el";
      else nm = "h_mj_"+isotypes[i]+"_mu";
      h_mj[i][j] = TH1D(nm,nm+"; sumJetMass [GeV];", 50, 0.,2500.);
      h_mj[i][j].Sumw2();
    }
  }


  small_tree tree(basedir+sample);

  const long nent = tree.GetEntries();
  cout<<"Number of events to run over: "<<nent<<endl;
  for (long ientry=0; ientry<nent; ientry++){
    if (ientry%100000==0) cout<<"Processed events: "<<ientry<<endl;
    tree.GetEntry(ientry);

    // if (fname!="qcd" && (tree.mc_type()&0x0F00)!=0x100) continue;
    // if (tree.ht()<=500.) continue;

    double weight = 1;//tree.weight()*5;

    //---------- ELECTRONS ----------------      
    for (unsigned iel=0; iel<tree.els_pt().size(); iel++){
      if (!(tree.els_ispf()[iel]) || 
          !(tree.els_sigid()[iel]) ||
          tree.els_pt()[iel]<10.) continue;

      if (tree.els_tru_tm()[iel]) continue;
      // if (abs(tree.els_tru_id()[iel])!=11) continue;


      for (unsigned iiso(0); iiso<isotypes.size(); iiso++){
        if (passIsolation(tree, iel, /*isElectron*/ true, /*isveto*/ false, isotypes[iiso], el_isocut[iiso])) {
          h_pt[iiso][0].Fill(tree.els_pt()[iel], weight);
          h_ht[iiso][0].Fill(tree.ht(), weight);
          h_njets[iiso][0].Fill(tree.njets(), weight);
          h_mj[iiso][0].Fill(tree.mj_30(), weight);
        }
      }
    }
    
    //---------- MUONS ----------------
    for (unsigned imu=0; imu<tree.mus_pt().size(); imu++){
      if (!(tree.mus_sigid()[imu]) ||
        tree.mus_pt()[imu]<10.) continue;
        
      if (tree.mus_tru_tm()[imu]) continue;
      // if (abs(tree.mus_tru_id()[imu])!=13) continue;

      for (unsigned iiso(0); iiso<isotypes.size(); iiso++){      
        if (passIsolation(tree, imu, /*isElectron*/ false, /*isveto*/ false, isotypes[iiso], mu_isocut[iiso])) {
          h_pt[iiso][1].Fill(tree.mus_pt()[imu], weight);
          h_ht[iiso][1].Fill(tree.ht(), weight);
          h_njets[iiso][1].Fill(tree.njets(), weight);
          h_mj[iiso][1].Fill(tree.mj_30(), weight);
        }
      }
    }

    
  }

  fout.Write();
  fout.Close();
  return 0;
}


bool passIsolation(const small_tree &tree, int ilep, bool isElectron, bool isveto, TString isotype, const double iso_cut){

  if (isotype=="reliso"){ 
    if (isElectron){
      if (fabs(tree.els_eta()[ilep]) <= 1.479) 
        return (tree.els_reliso_r03()[ilep] < (isveto ? 0.3313 : 0.2179));
      else 
        return (tree.els_reliso_r03()[ilep] < (isveto ? 0.3816 : 0.254));
    } else {
      return tree.mus_reliso_r04()[ilep] < 0.2;//(isveto ? 0.2 : 0.12));
    }
  } else if (isotype=="reliso_r02") {
    if (isElectron) 
      return tree.els_reliso_r02()[ilep] < iso_cut;
    else 
      return tree.mus_reliso_r02()[ilep] < iso_cut;
  } else if (isotype=="miniso") {
    if (isElectron) 
      return ((tree.els_miniso_tr10()[ilep] < iso_cut) 
             || (tree.els_reliso_r02()[ilep] < iso_cut));
    else 
      return ((tree.mus_miniso_tr10()[ilep] < iso_cut) 
             || (tree.mus_reliso_r02()[ilep] < iso_cut));
  } else if (isotype=="none") {
    return true;
  } 
  return false;
}
