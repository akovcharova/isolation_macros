// plot_distribution: Macro that plots variables both lumi weighted and normalized to the same area.

#include <iostream>
#include "TChain.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLine.h"
#include "TStyle.h"
#include "TString.h"

#include "styles.hpp"
#include "utilities.hpp"

using namespace std;
using std::cout;
using std::endl;

class hfeats {
public:
  hfeats(TString ivarname, int inbins, float iminx, float imaxx, vector<int> isamples,
	 TString ititle="", TString icuts="1", float icut=-1){
    varname = ivarname; nbins = inbins; minx = iminx; maxx = imaxx; title = ititle;
    cuts = icuts; cut = icut; samples = isamples;
    tag = ivarname+"_"+cuts; tag.ReplaceAll("_1",""); tag.ReplaceAll(".",""); 
    tag.ReplaceAll("(",""); tag.ReplaceAll("$","");  tag.ReplaceAll(")",""); 
    tag.ReplaceAll("[",""); tag.ReplaceAll("]",""); 
    tag.ReplaceAll("/","_"); tag.ReplaceAll("*",""); tag.ReplaceAll("&&","_");
    tag.ReplaceAll(">",""); tag.ReplaceAll("<",""); tag.ReplaceAll("=","");
    tag.ReplaceAll("+",""); 
    unit = "";
    if(title.Contains("GeV)")) unit = "GeV";
    if(title.Contains("phi")) unit = "rad";
  }
  TString title, varname, tag, cuts, unit;
  int nbins;
  float minx, maxx, cut;
  vector<int> samples;
};

class sfeats {
public:
  sfeats(TString ifile, TString ilabel, int icolor, int istyle=1, TString icut="1"){
    file = ifile; label = ilabel; cut = icut;
    color = icolor; style = istyle;
  }
  TString file, label, cut;
  int color, style;
};

int main(){
  styles style("1Dtitle"); style.setDefaultStyle();gStyle->SetPadTickY(1);
  vector<hfeats> vars;
  TCanvas can;
  TString luminosity="5", folder="/cms2r0/manuelf/root/small/archive/15-01-08/";
  // Reading ntuples
  vector<TChain *> chain;
  vector<sfeats> Samples; 
  // Base Iso samples
  Samples.push_back(sfeats(folder+"*T1tttt*1500_*PU20*", "T1tttt truth-matched", 4, 1, "mus_tru_tm&&mus_sigid"));
  Samples.push_back(sfeats("/cms2r0/manuelf/root/small/archive/15-01-14/*TTJet*", "tt truth-matched", kGreen+2, 1, "mus_tru_tm&&mus_sigid"));
  Samples.push_back(sfeats("/cms2r0/manuelf/root/small/archive/15-01-14/*TTJet*", "tt non-truth-matched", kRed, 1, "!mus_tru_tm&&mus_sigid"));
  Samples.push_back(sfeats(folder+"*T1tttt*1500_*PU20*", "T1tttt truth-matched", 4, 1, "els_tru_tm&&els_sigid&&els_ispf"));
  Samples.push_back(sfeats("/cms2r0/manuelf/root/small/archive/15-01-14/*TTJet*", "tt truth-matched", kGreen+2, 1, "els_tru_tm&&els_sigid&&els_ispf"));
  Samples.push_back(sfeats("/cms2r0/manuelf/root/small/archive/15-01-14/*TTJet*", "tt non-truth-matched", kRed, 1, "!els_tru_tm&&els_sigid&&els_ispf"));

  // Non-truth-matched electrons broken down
  Samples.push_back(sfeats("/cms2r0/manuelf/root/small/archive/15-01-14/*TTJet*", "tt non-prompt e", kRed, 1, "!els_tru_tm&&els_sigid&&els_ispf&&abs(els_tru_id)==11"));
  Samples.push_back(sfeats("/cms2r0/manuelf/root/small/archive/15-01-14/*TTJet*", "tt fake e with no #tau#rightarrowhad", 4, 1, "!els_tru_tm&&els_sigid&&els_ispf&&abs(els_tru_id)!=11&&((mc_type&0x000F)*0x10<=(mc_type&0x00F0))"));
  Samples.push_back(sfeats("/cms2r0/manuelf/root/small/archive/15-01-14/*TTJet*", "tt fake e with #tau#rightarrowhad", 28, 1, "!els_tru_tm&&els_sigid&&els_ispf&&abs(els_tru_id)!=11&&((mc_type&0x000F)*0x10>(mc_type&0x00F0))"));

  // Samples for truth-matching (DeltaR)
  Samples.push_back(sfeats("/cms2r0/manuelf/root/small/out/small_quick_SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2299_v77.root", "Reconstructed muons", 2, 1, "mus_sigid"));
  Samples.push_back(sfeats("/cms2r0/manuelf/root/small/out/small_quick_SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2299_v77.root", "Reconstructed electrons", 4, 1, "els_sigid&&els_ispf"));


 for(unsigned sam(0); sam < Samples.size(); sam++){
    chain.push_back(new TChain("tree"));
    chain[sam]->Add(Samples[sam].file);
  }

  vector<int> mus_tt_t1;
  mus_tt_t1.push_back(0);
  mus_tt_t1.push_back(1);
  mus_tt_t1.push_back(2);

  vector<int> els_tt_t1;
  els_tt_t1.push_back(3);
  els_tt_t1.push_back(4);
  els_tt_t1.push_back(5);

  vector<int> els_tt_ntm;
  els_tt_ntm.push_back(4);
  els_tt_ntm.push_back(6);
  els_tt_ntm.push_back(7);
  els_tt_ntm.push_back(8);

  vector<int> mus_t1_dr;
  mus_t1_dr.push_back(9);
  vector<int> els_t1_dr;
  els_t1_dr.push_back(10);

  vars.push_back(hfeats("mus_tru_dr",50,0,0.5, mus_t1_dr, "min#DeltaR(#mu_{reco}, #mu_{true})","mus_pt>20",0.1));
  vars.push_back(hfeats("els_tru_dr",50,0,0.5, els_t1_dr, "min#DeltaR(e_{reco}, e_{true})","els_pt>20",0.1));

  vars.push_back(hfeats("mus_ptrel_0",40,0,40, mus_tt_t1, "Muon p^{rel}_{T} (GeV)","ht>750&&met>200"));
  vars.push_back(hfeats("mus_ptrel_0",40,0,40, mus_tt_t1, "Muon p^{rel}_{T} (GeV)","ht>750&&met>200&&mus_reliso_r04>0.3"));
  vars.push_back(hfeats("mus_ptrel_0",40,0,40, mus_tt_t1, "Muon p^{rel}_{T} (GeV)","ht>750&&met>200&&mus_miniso_tr10>0.3"));
  vars.push_back(hfeats("mus_pt",50,0,400, mus_tt_t1, "Muon p_{T} (GeV)","ht>750&&met>200"));
  vars.push_back(hfeats("mus_reliso_r04",40,0,2, mus_tt_t1, "Muon relative isolation (R=0.4)","mus_pt>=20&&ht>750"));
  vars.push_back(hfeats("min(mus_reliso_r02,mus_miniso_tr10)",40,0,2, mus_tt_t1, "Muon mini isolation (0.05<R<0.2)","mus_pt>=20&&ht>750"));

  vars.push_back(hfeats("els_ptrel_0",40,0,40, els_tt_t1, "Electron p^{rel}_{T} (GeV)","ht>750&&met>200"));
  vars.push_back(hfeats("els_ptrel_0",40,0,40, els_tt_t1, "Electron p^{rel}_{T} (GeV)","ht>750&&met>200&&els_reliso_r03>0.1"));
  vars.push_back(hfeats("els_ptrel_0",40,0,40, els_tt_t1, "Electron p^{rel}_{T} (GeV)","ht>750&&met>200&&els_miniso_tr10>0.1"));
  vars.push_back(hfeats("els_pt",50,0,400, els_tt_t1, "Electron p_{T} (GeV)","ht>750&&met>200"));
  vars.push_back(hfeats("els_reliso_r03",40,0,2, els_tt_t1, "Electron relative isolation (R=0.3)","els_pt>=20&&ht>750"));
  vars.push_back(hfeats("min(els_reliso_r02,els_miniso_tr10)",40,0,2, els_tt_t1, "Electron mini isolation (0.05<R<0.2)","els_pt>=20&&ht>750"));

  // Non-truth-matched electrons broken down
  vars.push_back(hfeats("els_reliso_r03",40,0,2, els_tt_ntm, "Electron relative isolation (R=0.3)","ht>750&&els_pt>=20"));
  vars.push_back(hfeats("min(els_reliso_r02,els_miniso_tr10)",40,0,2, els_tt_ntm, "Electron mini isolation (0.05<R<0.2)","ht>750&&els_pt>=20"));


  float minLog = 0.04, maxLog = 10;
  double legX = 0.44, legY = 0.89, legSingle = 0.075;
  double legW = 0.12, legH = legSingle*vars[0].samples.size();
  TLegend leg(legX, legY-legH, legX+legW, legY);
  leg.SetTextSize(0.07); leg.SetFillColor(0); leg.SetFillStyle(0); leg.SetBorderSize(0);
  leg.SetTextFont(132);

  TLine line; line.SetLineColor(28); line.SetLineWidth(4); line.SetLineStyle(2);
  vector< vector<TH1D*> > histo[2];
  vector<TH1D*> varhisto;
  vector<float> nentries;
  float totentries;
  TString hname, pname, variable, leghisto, totCut, title, ytitle;
  for(unsigned var(0); var<vars.size(); var++){
    cout<<endl;
    // Generating vector of histograms
    title = vars[var].cuts; if(title=="1") title = "";
    title.ReplaceAll("nvmus==1&&nmus==1&&nvels==0","1 #mu");
    title.ReplaceAll("els_pt","p^{e}_{T}");title.ReplaceAll("mus_pt","p^{#mu}_{T}");
    title.ReplaceAll("mus_reliso_r04","RelIso"); title.ReplaceAll("els_reliso_r03","RelIso"); title.ReplaceAll("els_reliso","RelIso");
    title.ReplaceAll("mus_miniso_tr10","MiniIso"); title.ReplaceAll("els_miniso_tr10","MiniIso"); title.ReplaceAll("els_miniso_tr15","MiniIso");
    title.ReplaceAll("njets","n_{jets}");title.ReplaceAll("abs(lep_id)==13&&","");
    title.ReplaceAll(">=", " #geq "); title.ReplaceAll(">", " > "); title.ReplaceAll("&&", ", "); 
    title.ReplaceAll("met", "MET"); title.ReplaceAll("ht", "H_{T}");  title.ReplaceAll("mt", "m_{T}"); 
    title.ReplaceAll("nleps==1", "1 lepton");  title.ReplaceAll("nbm","n_{b}");
    title.ReplaceAll("nbl[1]","n_{b,l}");
    for(unsigned his(0); his < 2; his++){
      varhisto.resize(0);
      for(unsigned sam(0); sam < vars[var].samples.size(); sam++){
	hname = "histo"; hname += var; hname += his; hname += sam;
	varhisto.push_back(new TH1D(hname, title, vars[var].nbins, vars[var].minx, vars[var].maxx));
      }
      histo[his].push_back(varhisto);
    }

    //// Plotting lumi-weighted distributions in histo[0], and then area-normalized in histo[1] ///
    leg.Clear();
    nentries.resize(0);
    totentries = 0;
    variable = vars[var].varname;
    float maxhisto(-999);
    for(unsigned sam(0); sam < vars[var].samples.size(); sam++){
      int isam = vars[var].samples[sam];
      bool isSig = Samples[isam].file.Contains("T1tttt");
      isSig=(sam==1);
      totCut = luminosity+"*weight*("+vars[var].cuts+"&&"+Samples[isam].cut+")"; 
      chain[isam]->Project(histo[0][var][sam]->GetName(), variable, totCut);
      histo[0][var][sam]->SetBinContent(vars[var].nbins,
					  histo[0][var][sam]->GetBinContent(vars[var].nbins)+
					  histo[0][var][sam]->GetBinContent(vars[var].nbins+1));
      nentries.push_back(histo[0][var][sam]->Integral(1,vars[var].nbins));
      totentries += nentries[sam];
      histo[0][var][sam]->SetXTitle(vars[var].title);
      ytitle = "Entries for "+luminosity+" fb^{-1}";
      if(vars[var].unit!="") {
	int digits(0);
	float binwidth((vars[var].maxx-vars[var].minx)/static_cast<float>(vars[var].nbins));
	if(binwidth<1) digits = 1;
	ytitle += ("/("+RoundNumber(binwidth,digits) +" "+vars[var].unit+")");
      }
      histo[0][var][sam]->SetYTitle(ytitle);
      // Cloning histos for later
      for(int bin(0); bin<=histo[0][var][sam]->GetNbinsX()+1; bin++)
	histo[1][var][sam]->SetBinContent(bin, histo[0][var][sam]->GetBinContent(bin));

      if(!isSig){ // Adding previous bkg histos
	for(int bsam(sam-1); bsam >= 0; bsam--){
	  if(!Samples[vars[var].samples[bsam]].file.Contains("T1tttt")){
	    histo[0][var][sam]->Add(histo[0][var][bsam]);
	    break;
	  }
	}
	histo[0][var][sam]->SetFillColor(Samples[isam].color);
	histo[0][var][sam]->SetFillStyle(1001);
	histo[0][var][sam]->SetLineColor(1);
	histo[0][var][sam]->SetLineWidth(1);
      } else {
	histo[0][var][sam]->SetLineColor(Samples[isam].color);
	histo[0][var][sam]->SetLineStyle(Samples[isam].style);
	histo[0][var][sam]->SetLineWidth(3);
      }
      if(maxhisto < histo[0][var][sam]->GetMaximum()) maxhisto = histo[0][var][sam]->GetMaximum();
    } // First loop over samples
    int firstplotted(-1);
    for(int sam(vars[var].samples.size()-1); sam >= 0; sam--){
      int isam = vars[var].samples[sam];
      leghisto = Samples[isam].label+" [N = " + RoundNumber(nentries[sam],0) + "]";
      leg.AddEntry(histo[0][var][sam], leghisto);
      bool isSig = Samples[isam].file.Contains("T1tttt");
      isSig = (sam==1);
      if(!isSig){
	if(firstplotted < 0) {
	  histo[0][var][sam]->Draw();
	  firstplotted = sam;
	} else histo[0][var][sam]->Draw("same");
      }
    }
    for(int sam(vars[var].samples.size()-1); sam >= 0; sam--){
      int isam = vars[var].samples[sam];
      bool isSig = Samples[isam].file.Contains("T1tttt");
      isSig = (sam==1);
      if(isSig) histo[0][var][sam]->Draw("same");
    }
    legH = legSingle*vars[var].samples.size(); leg.SetY1NDC(legY-legH);
    leg.Draw(); 
    if(histo[0][var][firstplotted]->GetMinimum() > minLog) histo[0][var][firstplotted]->SetMinimum(minLog);
    histo[0][var][firstplotted]->SetMinimum(minLog);
    histo[0][var][firstplotted]->SetMaximum(maxhisto*maxLog);
    if(variable=="mt" && var==vars.size()-1) {
      histo[0][var][firstplotted]->SetMinimum(0.2);
      histo[0][var][firstplotted]->SetMaximum(maxhisto*2);
    }
    if(vars[var].cut>0) line.DrawLine(vars[var].cut, 0, vars[var].cut, maxhisto*maxLog);
    can.SetLogy(1);
    pname = "eps/log_lumi_"+vars[var].tag+".eps";
    can.SaveAs(pname);
    histo[0][var][firstplotted]->SetMinimum(0);
    histo[0][var][firstplotted]->SetMaximum(maxhisto*1.1);
    can.SetLogy(0);
    pname = "eps/lumi_"+vars[var].tag+".eps";
    can.SaveAs(pname);

    //////////// Plotting area-normalized distributions ////////////
    leg.Clear(); maxhisto = -999;
    for(unsigned sam(0); sam < vars[var].samples.size(); sam++){
      int isam = vars[var].samples[sam];
      histo[1][var][sam]->SetLineColor(Samples[isam].color);
      histo[1][var][sam]->SetLineStyle(Samples[isam].style);
      histo[1][var][sam]->SetLineWidth(3);
      if(nentries[sam]) histo[1][var][sam]->Scale(100./nentries[sam]);
      if(maxhisto < histo[1][var][sam]->GetMaximum()) maxhisto = histo[1][var][sam]->GetMaximum();
      if(sam==0){
	histo[1][var][sam]->SetXTitle(vars[var].title);
	histo[1][var][sam]->SetYTitle("Entries (%)");
	histo[1][var][sam]->Draw();
      } else histo[1][var][sam]->Draw("same");
      // leghisto = Samples[isam].label+" ["+RoundNumber(nentries[sam]*100,1,totentries)+"%]";//+"%, #mu = ";
      leghisto = Samples[isam].label+" [#mu = ";
      int digits(1);
      leghisto += RoundNumber(histo[1][var][sam]->GetMean(),digits) + "]";
      if(vars[var].varname.Contains("tru_dr")) leghisto = Samples[isam].label;
      leg.AddEntry(histo[1][var][sam], leghisto);
    } // Loop over samples
    leg.Draw(); 
    if(vars[var].cut>0) line.DrawLine(vars[var].cut, 0, vars[var].cut, maxhisto*1.1);
    histo[1][var][0]->SetMaximum(maxhisto*1.1);
    can.SetLogy(0);
    pname = "eps/shapes_"+vars[var].tag+".eps";
    can.SaveAs(pname);
    histo[1][var][0]->SetMaximum(maxhisto*maxLog);
    //histo[1][var][0]->SetMinimum(0.01);
    can.SetLogy(1);
    pname = "eps/log_shapes_"+vars[var].tag+".eps";
    can.SaveAs(pname);
  }// Loop over variables

  for(unsigned his(0); his < 2; his++){
    for(unsigned var(0); var<vars.size(); var++){
      for(unsigned sam(0); sam < vars[var].samples.size(); sam++)
	if(histo[his][var][sam]) histo[his][var][sam]->Delete();
    }
  }
}

