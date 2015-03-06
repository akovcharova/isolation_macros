#include "plot_piechart.hpp"

#include <vector>
#include <iostream>
#include <iomanip>

#include "TColor.h"
#include "TPie.h"
#include "TCanvas.h"

#include "small_tree_quick.hpp"
#include "timer.hpp"
#include "utilities.hpp"

using namespace std;

int main(){
  small_tree_quick ttbar("archive/current/skim/*TTJets*");
  small_tree_quick wjets("archive/current/skim/*WJetsToLNu_HT*");
  small_tree_quick single_t("archive/current/skim/*_T*-channel*");
  small_tree_quick ttv("archive/current/skim/*TTWJets*");
  ttv.Add("archive/current/skim/*TTZJets*");

  small_tree_quick other("archive/current/skim/*QCD_HT*");
  other.Add("archive/current/skim/*ZJetsToNuNu_HT*");
  other.Add("archive/current/skim/*WH_HToBB*");
  other.Add("archive/current/skim/*DYJetsToLL*");

  vector<string> cuts;
  cuts.push_back("reliso_lowmt_lowmj");
  cuts.push_back("reliso_lowmt_lowmj_tkveto");
  cuts.push_back("reliso_lowmt_highmj");
  cuts.push_back("reliso_lowmt_highmj_tkveto");
  cuts.push_back("reliso_highmt_lowmj");
  cuts.push_back("reliso_highmt_lowmj_tkveto");
  cuts.push_back("reliso_highmt_highmj");
  cuts.push_back("reliso_highmt_highmj_tkveto");
  cuts.push_back("reliso_dy");
  cuts.push_back("reliso_dy_tkveto");
  cuts.push_back("reliso_dphi");
  cuts.push_back("reliso_dphi_tkveto");
  cuts.push_back("miniso_lowmt_lowmj");
  cuts.push_back("miniso_lowmt_lowmj_tkveto");
  cuts.push_back("miniso_lowmt_highmj");
  cuts.push_back("miniso_lowmt_highmj_tkveto");
  cuts.push_back("miniso_highmt_lowmj");
  cuts.push_back("miniso_highmt_lowmj_tkveto");
  cuts.push_back("miniso_highmt_highmj");
  cuts.push_back("miniso_highmt_highmj_tkveto");
  cuts.push_back("miniso_dy");
  cuts.push_back("miniso_dy_tkveto");
  cuts.push_back("miniso_dphi");
  cuts.push_back("miniso_dphi_tkveto");

  TColor ucsb_blue(1000, 1/255.,57/255.,166/255.);
  TColor ucsb_gold(1001, 255/255.,200/255.,47/255);
  TColor penn_red(1002, 149/255.,0/255.,26/255.);
  TColor uf_orange(1003, 255/255.,74/255.,0/255.);
  TColor uo_green(1004, 0/255.,79/255.,39/255.);
  TColor tcu_purple(1005, 52/255.,42/255.,123/255.);
  TColor tar_heel_blue(1006, 86/255.,160/255.,211/255.);
  TColor sig_teal(1007, 96/255.,159/255.,128/255.);
  TColor sig_gold(1008, 215/255.,162/255.,50/255.);
  TColor seal_brown(1010, 89/255.,38/255.,11/255.);

  vector<string> snames;
  vector<int> colors;
  vector<vector<float> > counts(cuts.size());
  ProcessTree(ttbar, counts, 1); snames.push_back("tt (1l)"); colors.push_back(1000);
  ProcessTree(ttbar, counts, 2); snames.push_back("tt (2l)"); colors.push_back(1006);
  ProcessTree(wjets, counts, 0); snames.push_back("WJets"); colors.push_back(1004);
  ProcessTree(single_t, counts, 0); snames.push_back("Single t"); colors.push_back(1005);
  ProcessTree(ttv, counts, 0); snames.push_back("ttV"); colors.push_back(1002);
  ProcessTree(other, counts, 0); snames.push_back("other"); colors.push_back(1001);

  MakeTable(counts, cuts, snames);

  for(size_t icut = 0; icut < counts.size(); ++icut){
    for(size_t icount(0); icount < counts[icut].size(); icount++){
      if(snames[icount] == "ttV") counts.at(icut).at(icount) /= 2.75;
      if(cuts.at(icut)=="miniso_highmt_lowmj") cout<<counts.at(icut).at(icount)<<", ";
    }
    cout<<endl;
    MakePie(counts.at(icut), cuts.at(icut), snames, colors);
  }
}

void ProcessTree(small_tree_quick &tree, vector<vector<float> > &counts, short cut_type){
  for(size_t icut = 0; icut < counts.size(); ++icut){
    counts.at(icut).push_back(0.);
  }
  long num_entries = tree.GetEntries();
  Timer timer(num_entries, 1.);
  timer.Start();
  for(long entry = 0; entry < num_entries; ++entry){
    timer.Iterate();
    tree.GetEntry(entry);

    int nl = ((tree.mc_type() & 0xF00) >> 8);
    int ntl = ((tree.mc_type() & 0xF0) >> 4);
    int nt = (tree.mc_type() & 0xF);
    int nth = nt - ntl;
    short this_type = 1;
    if(nl+nth>=2){
      this_type = 2;
    }else{
      this_type = 1;
    }
    if(cut_type != 0 && cut_type != this_type) continue;
    
    if(tree.nbm()<1 || tree.njets()<6 || tree.ht()<500.) continue;

    float weight = 4.*tree.weight();
    float mt, st;
    int nleps;
    CountRelIso(tree, nleps, mt, st);
    if(tree.ht()>500. && tree.nbm()>=2 && tree.met()>250.){
      if(nleps==1){
	if(mt<150.){
	  if(tree.mj()<600.){
	    counts.at(0).back() += weight;
	    if(tree.nisotks()<2) counts.at(1).back() += weight;
	  }else{
	    counts.at(2).back() += weight;
	    if(tree.nisotks()<2) counts.at(3).back() += weight;
	  }
	}else{
	  if(tree.mj()<600.){
	    counts.at(4).back() += weight;
	    if(tree.nisotks()<2) counts.at(5).back() += weight;
	  }else{
	    counts.at(6).back() += weight;
	    if(tree.nisotks()<2) counts.at(7).back() += weight;
	  }
	}
      }else if(nleps==2){
	counts.at(8).back() += weight;
	if(tree.nisotks()<3) counts.at(9).back() += weight;
      }
    }
    if(st>200. && nleps==1){
      counts.at(10).back() += weight;
      if(tree.nisotks()<2) counts.at(11).back() += weight;
    }

    CountMiniIso(tree, nleps, mt, st);
    if(tree.ht()>500. && tree.nbm()>=2 && tree.met()>250.){
      if(nleps==1){
	if(mt<150.){
	  if(tree.mj()<600.){
	    counts.at(12).back() += weight;
	    if(tree.nisotks()<2) counts.at(13).back() += weight;
	  }else{
	    counts.at(14).back() += weight;
	    if(tree.nisotks()<2) counts.at(15).back() += weight;
	  }
	}else{
	  if(tree.mj()<600.){
	    counts.at(16).back() += weight;
	    if(tree.nisotks()<2) counts.at(17).back() += weight;
	  }else{
	    counts.at(18).back() += weight;
	    if(tree.nisotks()<2) counts.at(19).back() += weight;
	  }
	}
      }else if(nleps==2){
	counts.at(20).back() += weight;
	if(tree.nisotks()<3) counts.at(21).back() += weight;
      }
    }
    if(st>200. && nleps==1){
      counts.at(22).back() += weight;
      if(tree.nisotks()<2) counts.at(23).back() += weight;
    }
  }
}

void CountRelIso(small_tree_quick &tree, int &nleps, float &mt, float &st){
  nleps = 0;
  mt = 0.;
  st = 0.;
  float high_pt = -1., phi = -1.;
  for(size_t i = 0; i < tree.mus_pt().size(); ++i){
    if(tree.mus_pt().at(i)>20.
       && tree.mus_sigid().at(i)
       && tree.mus_reliso_r04().at(i)<0.12){
      ++nleps;
      if(tree.mus_pt().at(i)>high_pt){
	high_pt = tree.mus_pt().at(i);
	phi = tree.mus_phi().at(i);
      }
    }
  }
  for(size_t i = 0; i < tree.els_pt().size(); ++i){
    if(tree.els_pt().at(i)>20.
       && tree.els_sigid().at(i)
       && ((tree.els_eta().at(i)<=1.479 && tree.els_reliso().at(i)<0.097213)
	   || (tree.els_eta().at(i)>1.479 && tree.els_reliso().at(i)<0.116708))){
      ++nleps;
      if(tree.els_pt().at(i)>high_pt){
	high_pt = tree.els_pt().at(i);
	phi = tree.els_phi().at(i);
      }
    }
  }

  if(nleps>0){
    mt = GetMT(high_pt, phi, tree.met(), tree.met_phi());
    st = high_pt + tree.met();
  }
}

void CountMiniIso(small_tree_quick &tree, int &nleps, float &mt, float &st){
  nleps = 0;
  mt = 0.;
  st = 0.;
  float high_pt = -1., phi = -1.;
  for(size_t i = 0; i < tree.mus_pt().size(); ++i){
    if(tree.mus_pt().at(i)>20.
       && tree.mus_sigid().at(i)
       && tree.mus_miniso_tr10().at(i)<0.4){
      ++nleps;
      if(tree.mus_pt().at(i)>high_pt){
	high_pt = tree.mus_pt().at(i);
	phi = tree.mus_phi().at(i);
      }
    }
  }
  for(size_t i = 0; i < tree.els_pt().size(); ++i){
    if(tree.els_pt().at(i)>20.
       && tree.els_sigid().at(i)
       && tree.els_miniso_tr10().at(i)<0.1){
      ++nleps;
      if(tree.els_pt().at(i)>high_pt){
	high_pt = tree.els_pt().at(i);
	phi = tree.els_phi().at(i);
      }
    }
  }

  if(nleps>0){
    mt = GetMT(high_pt, phi, tree.met(), tree.met_phi());
    st = high_pt + tree.met();
  }
}

void MakeTable(const vector<vector<float> > &counts,
	       const vector<string> &cuts,
	       const vector<string> &snames){
  cout << setw(32) << ' ' << ' ';
  for(size_t isample = 0; isample<snames.size(); ++isample){
    cout << setw(16) << snames.at(isample) << ' ';
  }
  cout << endl;
  for(size_t icut = 0; icut < counts.size(); ++icut){
    cout << setw(32) << cuts.at(icut) << ' ';
    for(size_t isample = 0; isample<counts.at(icut).size(); ++isample){
      cout << setw(16) << counts.at(icut).at(isample) << ' ';
    }
    cout << endl;
  }
}

void MakePie(vector<float> counts,
	     const string &cut,
	     const vector<string> &snames,
	     vector<int> colors){

  TPie pie("", "", colors.size(), &counts.at(0), &colors.at(0), NULL);
  for(size_t i = 0; i < snames.size(); ++i){
    //pie.SetEntryLabel(i, snames.at(i).c_str());
    pie.SetEntryLabel(i, "");
  }
  TCanvas c("","",600,600);
  pie.Draw();
  c.Print(("eps/pie_"+cut+".eps").c_str());
}
