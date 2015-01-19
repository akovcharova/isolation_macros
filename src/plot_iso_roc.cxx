// plot_roc: Macro that plots ROC curves

#include <stdexcept>
#include <iostream>

#include "TChain.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLine.h"
#include "TDirectory.h"
#include "TMarker.h"

#include "styles.hpp"
#include "utilities.hpp"
#include "plot_iso_roc.hpp"

using namespace std;

int main(){
  styles style("1Dtitle"); style.setDefaultStyle();

  TString folder="/cms2r0/manuelf/root/small/archive/15-01-08/";
  TString folder_tt="/cms2r0/manuelf/root/small/archive/15-01-14/";
  TString folder_pu="/cms2r0/manuelf/root/small/archive/14-12-21/";
  // NTUPLES
  vector<TString> v_t1;
  v_t1.push_back(folder+"*T1tttt*1500_*PU20*");
  vector<TString> v_t1c;
  v_t1c.push_back(folder+"*T1tttt*1200_*PU20*");
  vector<TString> v_t2;
  v_t2.push_back(folder+"*T2tt*850_*PU20*");
  vector<TString> v_t1pu40;
  v_t1pu40.push_back(folder_pu+"*T1tttt*1500_*PU40*");
  vector<TString> v_tt;
  v_tt.push_back(folder_tt+"*TTJet*");
  vector<TString> v_tts;
  v_tts.push_back(folder+"*TTJet*batch55*");

  ////////////////////////// MUONS /////////////////////////
  vector<sample_class> mus_tt; 
  mus_tt.push_back(sample_class("tt truth-matched prompt #mu", v_tt, "mus_tru_tm&&mus_sigid"));
  mus_tt.push_back(sample_class("tt non-truth-matched #mu", v_tt, "!mus_tru_tm&&mus_sigid"));

  vector<sample_class> mus_tts; 
  mus_tts.push_back(sample_class("tt truth-matched prompt #mu", v_tts, "mus_tru_tm&&mus_sigid"));
  mus_tts.push_back(sample_class("tt non-truth-matched #mu", v_tts, "!mus_tru_tm&&mus_sigid"));

  vector<sample_class> mus_tt_t1; 
  mus_tt_t1.push_back(sample_class("T1tttt(1500,100) truth-matched prompt #mu", v_t1, "mus_tru_tm&&mus_sigid"));
  mus_tt_t1.push_back(sample_class("tt non-truth-matched #mu", v_tt, "!mus_tru_tm&&mus_sigid"));

  vector<sample_class> mus_t1; 
  mus_t1.push_back(sample_class("T1tttt(1500,100) truth-matched prompt #mu", v_t1, "mus_tru_tm&&mus_sigid"));
  mus_t1.push_back(sample_class("T1tttt(1500,100) non-TM #mu", v_t1, "!mus_tru_tm&&mus_sigid"));

  vector<sample_class> mus_t1cpu20; 
  mus_t1cpu20.push_back(sample_class("T1tttt(1200,800) truth-matched prompt #mu", v_t1c, "mus_tru_tm&&mus_sigid"));
  mus_t1cpu20.push_back(sample_class("T1tttt(1200,800) non-TM #mu", v_t1c, "!mus_tru_tm&&mus_sigid"));

  vector<sample_class> mus_t2pu20; 
  mus_t2pu20.push_back(sample_class("T2tt(850,100) truth-matched prompt #mu", v_t2, "mus_tru_tm&&mus_sigid"));
  mus_t2pu20.push_back(sample_class("T2tt(850,100) non-TM #mu", v_t2, "!mus_tru_tm&&mus_sigid"));

  vector<sample_class> mus_t1pu40; 
  mus_t1pu40.push_back(sample_class("T1tttt(1500,100) PU40 truth-matched prompt #mu", v_t1pu40, "mus_tru_tm&&mus_sigid"));
  mus_t1pu40.push_back(sample_class("T1tttt(1500,100) PU40 non-TM #mu", v_t1pu40, "!mus_tru_tm&&mus_sigid"));

  ////////////////////////// ELECTRONS /////////////////////////

  vector<sample_class> els_tt; 
  els_tt.push_back(sample_class("tt truth-matched prompt e", v_tt, "els_tru_tm&&els_sigid&&els_ispf"));
  els_tt.push_back(sample_class("tt non-truth-matched e", v_tt, "!els_tru_tm&&els_sigid&&els_ispf"));

  vector<sample_class> els_tts; 
  els_tts.push_back(sample_class("tt truth-matched prompt e", v_tts, "els_tru_tm&&els_sigid&&els_ispf"));
  els_tts.push_back(sample_class("tt non-truth-matched e", v_tts, "!els_tru_tm&&els_sigid&&els_ispf"));

  vector<sample_class> els_tt_t1; 
  els_tt_t1.push_back(sample_class("T1tttt(1500,100) truth-matched prompt e", v_t1, "els_tru_tm&&els_sigid&&els_ispf"));
  els_tt_t1.push_back(sample_class("tt non-truth-matched e", v_tt, "!els_tru_tm&&els_sigid&&els_ispf"));

  vector<sample_class> els_t1cpu20; 
  els_t1cpu20.push_back(sample_class("T1tttt(1200,800) truth-matched prompt e", v_t1c, "els_tru_tm&&els_sigid&&els_ispf"));
  els_t1cpu20.push_back(sample_class("T1tttt(1200,800) non-TM e", v_t1c, "!els_tru_tm&&els_sigid&&els_ispf"));

  vector<sample_class> els_t1; 
  els_t1.push_back(sample_class("T1tttt(1500,100) truth-matched prompt e", v_t1, "els_tru_tm&&els_sigid&&els_ispf"));
  els_t1.push_back(sample_class("T1tttt(1500,100) non-TM e", v_t1, "!els_tru_tm&&els_sigid&&els_ispf"));

  vector<sample_class> els_t2pu20; 
  els_t2pu20.push_back(sample_class("T2tt(850,100) truth-matched prompt e", v_t2, "els_tru_tm&&els_sigid&&els_ispf"));
  els_t2pu20.push_back(sample_class("T2tt(850,100) non-TM e", v_t2, "!els_tru_tm&&els_sigid&&els_ispf"));

  vector<sample_class> els_t1pu40; 
  els_t1pu40.push_back(sample_class("T1tttt(1500,100) PU40 truth-matched prompt e", v_t1pu40, "els_tru_tm&&els_sigid&&els_ispf"));
  els_t1pu40.push_back(sample_class("T1tttt(1500,100) PU40 non-TM e", v_t1pu40, "!els_tru_tm&&els_sigid&&els_ispf"));

  // Markers to be plot on curves: 29 is a star, 8 a circle
  int mini_style(8); float mini_size(2);
  vector<marker_class> mus_std, mus_new, els_std, mus_cuts_miniso, els_cuts_miniso;
  els_std.push_back(marker_class(0.22, 4, 28, 29));
  mus_std.push_back(marker_class(0.2, 4, 1, 29));
  mus_new.push_back(marker_class(0.2, 4, 28, 29));
  els_cuts_miniso.push_back(marker_class(0.4,  mini_size, 4, mini_style));
  els_cuts_miniso.push_back(marker_class(0.2,  mini_size, 4, mini_style));
  els_cuts_miniso.push_back(marker_class(0.1,  5, 4, 29));
  //els_cuts_miniso.push_back(marker_class(0.1, mini_size, 4, mini_style));
  els_cuts_miniso.push_back(marker_class(0.05, mini_size, 4, mini_style));

  mus_cuts_miniso.push_back(marker_class(0.4,  mini_size, 4, mini_style));
  mus_cuts_miniso.push_back(marker_class(0.2,  mini_size, 4, mini_style));
  mus_cuts_miniso.push_back(marker_class(0.1,  mini_size, 4, mini_style));
  //mus_cuts_miniso.push_back(marker_class(0.05,  mini_size, 4, mini_style));
  mus_cuts_miniso.push_back(marker_class(0.05, 5, 4, 29));

  ///////////////////// Isolation variables /////////////////////
  vector<var_class> mus_vars;
  mus_vars.push_back(var_class("mus_reliso_r04",0,10,"Rel. Iso. (R=0.4)",1,1,mus_std));
  mus_vars.push_back(var_class("mus_reliso_r03",0,10,"Rel. Iso. (R=0.3)",28,1));
  mus_vars.push_back(var_class("mus_reliso_r02",0,10,"Rel. Iso. (R=0.2)",kMagenta+2));
  mus_vars.push_back(var_class("mus_reliso_r015",0,10,"Rel. Iso. (R=0.15)",3));
  mus_vars.push_back(var_class("mus_reliso_r01",0,10,"Rel. Iso. (R=0.1)",2));
  mus_vars.push_back(var_class("min(mus_reliso_r02,mus_miniso_tr10)",0,10,"Mini Iso. (0.05<R<0.2)",4,1,mus_cuts_miniso));

  vector<var_class> els_vars;
  els_vars.push_back(var_class("els_reliso_r04",0,10,"Rel. Iso. (R=0.4)",1));
  els_vars.push_back(var_class("els_reliso_r03",0,10,"Rel. Iso. (R=0.3)",28,1,els_std));
  els_vars.push_back(var_class("els_reliso_r02",0,10,"Rel. Iso. (R=0.2)",kMagenta+2));
  els_vars.push_back(var_class("els_reliso_r015",0,10,"Rel. Iso. (R=0.15)",3));
  els_vars.push_back(var_class("els_reliso_r01",0,10,"Rel. Iso. (R=0.1)",2));
  els_vars.push_back(var_class("min(els_reliso_r02,els_miniso_tr10)",0,10,"Mini Iso. (0.05<R<0.2)",4,1,els_cuts_miniso));

  vector<var_class> mus_vars_ptrel;
  mus_vars_ptrel.push_back(var_class("mus_reliso_r04",0,10,"Rel. Iso. (R=0.4)",1,1,mus_std));
  mus_vars_ptrel.push_back(var_class("min(mus_reliso_r02,mus_miniso_tr10)",0,10,"Mini Iso. (0.05<R<0.2)",4,1,mus_cuts_miniso));
  mus_vars_ptrel.push_back(var_class("mus_ptrel_0+(mus_reliso_r04<0.3)*9999.",500,0,
   			   "p_{T}^{rel} || Rel. Iso. (R=0.4) < 0.3",1,2));
  mus_vars_ptrel.push_back(var_class("mus_ptrel_0+(min(mus_reliso_r02,mus_miniso_tr10)<0.3)*9999.",500,0,
			   "p_{T}^{rel} || Mini Iso. < 0.3",4,2));

  vector<var_class> els_vars_ptrel;
  els_vars_ptrel.push_back(var_class("els_reliso_r03",0,10,"Rel. Iso. (R=0.3)",28,1,els_std));
  els_vars_ptrel.push_back(var_class("min(els_reliso_r02,els_miniso_tr10)",0,10,"Mini Iso. (0.05<R<0.2)",4,1,els_cuts_miniso));
  els_vars_ptrel.push_back(var_class("els_ptrel_0+(els_reliso_r03<0.1)*9999.",500,0,
   			   "p_{T}^{rel} || Rel. Iso. (R=0.3) < 0.1",28,2));
  els_vars_ptrel.push_back(var_class("els_ptrel_0+(min(els_reliso_r02,els_miniso_tr10)<0.1)*9999.",500,0,
			   "p_{T}^{rel} || Mini Iso. < 0.1",4,2));

  ///////////////////// ROCs to be plotted /////////////////////

  TString mus_ptcuts[] = {"mus_pt>=20","mus_pt>=20&&mus_pt<50","mus_pt>=50&&mus_pt<100",
  			  "mus_pt>=100&&mus_pt<200","mus_pt>=200"};
  TString els_ptcuts[] = {"els_pt>=20","els_pt>=20&&els_pt<50","els_pt>=50&&els_pt<100",
  			  "els_pt>=100&&els_pt<200","els_pt>=200"};
  TString htcuts[] = {"ht>=750","ht>=750&&ht<1000"};
  TString metcuts[] = {"1","met>=200&&met<600"};
  TString cuts;
  for(int iht(0); iht<2; iht++){
    for(int imet(0); imet<1; imet++){
      for(int ipt(0); ipt<5; ipt++){ 
  	cuts = mus_ptcuts[ipt]+"&&"+htcuts[iht]+"&&"+metcuts[imet];
  	DrawROC(mus_tt_t1, mus_vars, cuts, "mus_t1");
  	DrawROC(mus_tt_t1, mus_vars_ptrel, cuts, "mus_t1_ptrel");
  	cuts = els_ptcuts[ipt]+"&&"+htcuts[iht]+"&&"+metcuts[imet];
  	DrawROC(els_tt_t1, els_vars, cuts, "els_t1");
  	DrawROC(els_tt_t1, els_vars_ptrel, cuts, "els_t1_ptrel");

      }
    }
  }


  ///////////////////// Isolation variables for PU/////////////////////
  vector<var_class> mus_vars_pu;
  mus_vars_pu.push_back(var_class("mus_reliso_r04",0,10,"Rel. Iso. (R=0.4)",1,1,mus_std));
  mus_vars_pu.push_back(var_class("mus_reliso_r03",0,10,"Rel. Iso. (R=0.3)",28,1));
  mus_vars_pu.push_back(var_class("mus_reliso_r02",0,10,"Rel. Iso. (R=0.2)",kMagenta+2));
  mus_vars_pu.push_back(var_class("min(mus_reliso_r02,mus_miniso_tr10)",0,10,"Mini Iso. (0.05<R<0.2)",4,1,mus_cuts_miniso));

  vector<var_class> els_vars_pu;
  els_vars_pu.push_back(var_class("els_reliso_r03",0,10,"Rel. Iso. (R=0.3)",28,1,els_std));
  els_vars_pu.push_back(var_class("els_reliso_r02",0,10,"Rel. Iso. (R=0.2)",kMagenta+2));
  els_vars_pu.push_back(var_class("min(els_reliso_r02,els_miniso_tr10)",0,10,"Mini Iso. (0.05<R<0.2)",4,1,els_cuts_miniso));
  // PU comparison
  DrawROC(mus_t1, mus_vars_pu, "mus_pt>20&&ht>750&&met>250&&ntrupv<20", "mus_isopu20");
  DrawROC(mus_t1pu40, mus_vars_pu, "mus_pt>20&&ht>750&&met>250&&ntrupv>30", "mus_isopu40");
  DrawROC(els_t1, els_vars_pu, "els_pt>20&&ht>750&&met>250&&ntrupv<20", "els_isopu20");
  DrawROC(els_t1pu40, els_vars_pu, "els_pt>20&&ht>750&&met>250&&ntrupv>30", "els_isopu40");

  // // ttbar
  DrawROC(els_tts, els_vars, "els_pt>=20", "els_tt");
  DrawROC(mus_tts, mus_vars, "mus_pt>=20", "mus_tt");
  DrawROC(els_tt, els_vars, "els_pt>=20&&els_pt<50&&ht>=750&&ht<1000", "els_tt");
  DrawROC(mus_tt, mus_vars, "mus_pt>=20&&mus_pt<50&&ht>=750&&ht<1000", "mus_tt");

  // TString musCuts("mus_pt>=100&&mus_pt<200");
  // TString elsCuts("els_pt>=100&&els_pt<200");
  // TString musCuts("mus_pt>=200");
  // TString elsCuts("els_pt>=200");
  // TString Cuts("&&ht>=1000&&ht<1500");
  // DrawROC(els_t1, els_vars, elsCuts+Cuts, "els_t1");
  // DrawROC(mus_t1, mus_vars, musCuts+Cuts, "mus_t1");
  // DrawROC(els_tt, els_vars, elsCuts+Cuts, "els_tt");
  // DrawROC(mus_tt, mus_vars, musCuts+Cuts, "mus_tt");

  
  // // Signal points, full pT range
  // DrawROC(els_tt_t1, els_vars, "els_pt>20&&ht>750&&met>250", "els_isott_t1");
  // DrawROC(els_t2pu20, els_vars, "els_pt>20&&ht>750&&met>250", "els_isot2");
  // DrawROC(els_t1cpu20, els_vars, "els_pt>20&&ht>750&&met>250", "els_isott_t1c");
  // DrawROC(els_tt_t1, els_vars, "els_pt>20&&ht>750&&met>250", "els_isott");
  // // Signal points, full pT range
  // DrawROC(mus_t1, mus_vars, "mus_pt>20&&ht>750&&met>250", "mus_isot1");
  // DrawROC(mus_t2pu20, mus_vars, "mus_pt>20&&ht>750&&met>250", "mus_isot2");
  // DrawROC(mus_t1cpu20, mus_vars, "mus_pt>20&&ht>750&&met>250", "mus_isot1c");
  // DrawROC(mus_tt_t1, mus_vars, "mus_pt>20&&ht>750&&met>250", "mus_isott");


}

void DrawROC(vector<sample_class> samples, vector<var_class> vars, TString cuts, TString tag){
  TCanvas can;
  const int nbins(1000);
  vector<vector<TH1D> > histos;
  TString hname, totcut;
  TChain *chain[2];

  for(unsigned sam(0); sam < samples.size(); sam++){
    // Loading chains
    for(unsigned isam(0); isam < samples[sam].files.size(); isam++){
      chain[sam] = new TChain("tree");
      int nfiles = chain[sam]->Add(samples[sam].files[isam]);
      if(nfiles==0) cout<<samples[sam].files[isam]<<" not found"<<endl;
    }
    histos.push_back(vector<TH1D>());

    // Projecting variables
    for(unsigned var(0); var<vars.size(); var++){
      float minh(vars[var].minx), maxh(vars[var].maxx);
      if(minh > maxh){
	minh = maxh;
	maxh = vars[var].minx;
      }
      hname = "histo"; hname += sam; hname += var;
      totcut = "weight*("+cuts+"&&"+samples[sam].cut+")";
      histos[sam].push_back(TH1D(hname,"",nbins,minh,maxh));
      chain[sam]->Project(hname, vars[var].varname, totcut);
    } // Loop over variables
  } // Loop over samples

  TString title(cuts);
  if(title=="1") title = "";
  title.ReplaceAll("&&1",""); title.ReplaceAll("nvmus10==0&&nvels10==0", "0 leptons");  
  title.ReplaceAll("els_pt","p^{e}_{T}");title.ReplaceAll("mus_pt","p^{#mu}_{T}");
  title.ReplaceAll("mj_30", "M_{J}");
  title.ReplaceAll(">=", " #geq "); 
  title.ReplaceAll(">", " > "); title.ReplaceAll("<", " < "); title.ReplaceAll("&&", ", "); 
  title.ReplaceAll("met", "MET"); title.ReplaceAll("ht", "H_{T}");  title.ReplaceAll("mt", "m_{T}"); 
  title.ReplaceAll("nleps==1", "1 lepton");  title.ReplaceAll("ntrupv","n^{true}_{PV}");
  title.ReplaceAll("njets30","n_{jets}^{30}"); title.ReplaceAll("nbm30","n_{b}^{30}");
  title.ReplaceAll("njets","n_{jets}"); title.ReplaceAll("nbm","n_{b}");
  title.ReplaceAll("mindphin_metje","min#Delta#phi_{N}");
  title.ReplaceAll("nbl","n_{b,l}");
  TH1D base_histo("base",title,1,0.5,1.0);
  base_histo.SetXTitle(samples[0].label+" efficiency");
  base_histo.SetYTitle(samples[1].label+" rejection rate");
  base_histo.SetMinimum(0.0);
  base_histo.SetMaximum(1.0);
  base_histo.SetDirectory(0);
  base_histo.Draw();

  // Legend
  double legX = 0.13, legY = 0.15, legSingle = 0.064;
  double legW = 0.12, legH = legSingle*vars.size();
  TLegend leg(legX, legY, legX+legW, legY+legH);
  leg.SetTextSize(0.055); leg.SetFillColor(0); leg.SetFillStyle(0); leg.SetBorderSize(0);
  leg.SetTextFont(132);

  // Making individual graphs
  TGraph graphs[100]; // Had to make it an array because a vector<TGraph> kept crashing
  for(unsigned var(0); var<vars.size(); var++){
    graphs[var] = MakeROC(histos[0][var], histos[1][var], vars[var].minx < vars[var].maxx, vars[var].cuts);
    graphs[var].SetLineColor(vars[var].color);
    graphs[var].SetLineStyle(vars[var].style);
    graphs[var].SetLineWidth(3);
    leg.AddEntry(&(graphs[var]), vars[var].title, "l");
    graphs[var].Draw("lsame");
  } // Loop over variables
  leg.Draw();

  cuts.ReplaceAll(".",""); 
  cuts.ReplaceAll("(",""); cuts.ReplaceAll("$","");  cuts.ReplaceAll(")",""); 
  cuts.ReplaceAll("[",""); cuts.ReplaceAll("]",""); 
  cuts.ReplaceAll("/","_"); cuts.ReplaceAll("*",""); cuts.ReplaceAll("&&","_");
  cuts.ReplaceAll(">",""); cuts.ReplaceAll("<",""); cuts.ReplaceAll("=","");
  cuts.ReplaceAll("+",""); 
  TString pname("eps/roc_"+tag+"_"+cuts+".eps");  
  can.Print(pname);

  for(unsigned sam(0); sam < samples.size(); sam++)
    chain[sam]->Delete();
}

TGraph MakeROC(TH1D &good, TH1D &bad, const bool less_is_better, vector<marker_class> cuts){
  const int nbins = good.GetNbinsX();
  if(bad.GetNbinsX() != nbins) throw logic_error("Mismatched number of bins");

  TMarker marker;  

  TGraph graph(0);
  const double good_tot = good.Integral(0, nbins+1);
  const double bad_tot = bad.Integral(0, nbins+1);
  int inibin(0), endbin(nbins+1), dbin(1); unsigned icut(0);
  if(less_is_better){
    inibin = nbins+1;
    endbin = 0;
    dbin = -1;
  }
  for(int bin = inibin; bin*dbin<=endbin*dbin; bin+=dbin){
    const double good_pass = good.Integral(min(endbin,bin), max(endbin,bin));
    const double bad_pass = bad.Integral(min(endbin,bin), max(endbin,bin));
    const double x = good_pass/good_tot;
    const double y = 1.0-bad_pass/bad_tot;
    graph.SetPoint(graph.GetN(), x, y);
 
    // Plotting the stars
    if(icut<cuts.size()){
      float edge(good.GetXaxis()->GetBinUpEdge(bin));
      if((edge>=cuts[icut].cut&&!less_is_better) || (edge<=cuts[icut].cut&&less_is_better)){
	marker.SetMarkerStyle(cuts[icut].style);marker.SetMarkerColor(cuts[icut].color);
	marker.SetMarkerSize(cuts[icut].size); 
	marker.DrawMarker(x,y);
	icut++;
      }
    }
  }
  TString name(good.GetName());
  name += "graph";
  graph.SetName(name);
  graph.SetTitle(name);

  return graph;
}

var_class::var_class(TString ivarname, float iminx, float imaxx, TString ititle, int icolor, 
	    int istyle, vector<marker_class> icuts){
  varname = ivarname; minx = iminx; maxx = imaxx; title = ititle;
  cuts = icuts; 
  color = icolor; style = istyle;
}

sample_class::sample_class(TString ilabel, vector<TString> ifiles, TString icut){
  files = ifiles; label = ilabel; cut = icut;
}

marker_class::marker_class(float icut, float isize, int icolor, int istyle){
  cut=icut; size=isize; color=icolor; style=istyle;
}

