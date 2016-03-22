#include "table_ra4_mini.hpp"

#include <vector>
#include <iostream>
#include <iomanip>

#include "small_tree_basic.hpp"
#include "timer.hpp"
#include "utilities.hpp"

#include "TString.h"
#include "RooStats/NumberCountingUtils.h"

using namespace std;
vector<int> elcuts, mucuts;

int main(){
  string folder("archive/15-03-03/skim/");

  small_tree_basic ttbar(folder+"*TTJets*");
  small_tree_basic wjets(folder+"*_WJets*");
  small_tree_basic single(folder+"*-channel*");
  small_tree_basic ttw(folder+"*TTWJets*");
  small_tree_basic ttz(folder+"*TTZJets*");
  small_tree_basic ttv(folder+"*TTZJets*");
  ttv.Add(folder+"*TTWJets*");
  small_tree_basic other(folder+"*QCD_HT*");
  //other.Add(folder+"*_WJet*");
  other.Add(folder+"*_ZJet*");
  other.Add(folder+"*DY*");
  other.Add(folder+"*WH_HToBB*");
  small_tree_basic t1tttt_nc(folder+"*T1tttt*1500*100*");
  small_tree_basic t1tttt_c(folder+"*T1tttt*1200*800*");

  vector<TString> isocuts, cuts, othercuts;
  // isocuts.push_back("reliso_t_t");
  // isocuts.push_back("reliso_m_m");
  // isocuts.push_back("miniso_5_10");
  // isocuts.push_back("miniso_10_40");
  isocuts.push_back("Reliso");
  isocuts.push_back("Mini iso (0.2)");
  isocuts.push_back("Mini iso (0.4)");
  othercuts.push_back("lmt");
  othercuts.push_back("hmt");
  othercuts.push_back("hmt_hmj");
  othercuts.push_back("2l");
  for(unsigned iel(0); iel<othercuts.size(); iel++)
    for(unsigned imu(0); imu<isocuts.size(); imu++)
      //cuts.push_back(othercuts[iel]+"_"+isocuts[imu]);
      cuts.push_back(isocuts[imu]);

  elcuts.push_back(05);
  elcuts.push_back(10);
  elcuts.push_back(15);
  mucuts.push_back(10);
  //mucuts.push_back(20);
  //mucuts.push_back(30);
  mucuts.push_back(40);
  mucuts.push_back(50);
  for(unsigned iel(0); iel<elcuts.size(); iel++)
    for(unsigned imu(0); imu<mucuts.size(); imu++){
      TString stemp("miniiso_"); stemp+=elcuts[iel];
      stemp+="_"; stemp+=mucuts[imu];
      //cuts.push_back(stemp);
    }
  vector<TString> snames;
  vector<vector<float> > counts(cuts.size()), w2(cuts.size());
  ProcessTree(wjets, counts, w2, 0); snames.push_back("Wjets");
  ProcessTree(single, counts, w2, 0); snames.push_back("Single $t$");
  //ProcessTree(ttw, counts, w2, 0); snames.push_back("ttW");
  //ProcessTree(ttz, counts, w2, 0); snames.push_back("ttZ");
  ProcessTree(ttv, counts, w2, 0); snames.push_back("$t\\bar{t}$V");
  ProcessTree(other, counts, w2, 0); snames.push_back("Other");
  ProcessTree(ttbar, counts, w2, 4); snames.push_back("$t\\bar{t}$ (0$\\ell$)");
  ProcessTree(ttbar, counts, w2, 1); snames.push_back("$t\\bar{t}$ (1$\\ell$)");
  ProcessTree(ttbar, counts, w2, 2); snames.push_back("$t\\bar{t}$ ($\\ell$+$\\tau_h$)");
  ProcessTree(ttbar, counts, w2, 3); snames.push_back("$t\\bar{t}$ (2$\\ell$)");
  //ProcessTree(t1tttt_nc, counts, w2, 1); snames.push_back("T1tttt NC 1$\\ell$");
  ProcessTree(t1tttt_nc, counts, w2, 0); snames.push_back("T1tttt NC");
  ProcessTree(t1tttt_c, counts, w2, 0); snames.push_back("T1tttt C");

  MakeTable(counts, w2, cuts, snames);

  for(size_t icut = 0; icut < counts.size(); ++icut){
    //MakePie(counts.at(icut), cuts.at(icut), snames);
  }
}

void ProcessTree(small_tree_basic &tree, vector<vector<float> > &counts, 
		 vector<vector<float> > &w2, short cut_type){
  for(size_t icut = 0; icut < counts.size(); ++icut){
    counts.at(icut).push_back(0.);
    w2.at(icut).push_back(0.);
  }
  long num_entries = tree.GetEntries();
  Timer timer(num_entries, 1.);
  timer.Start();
  for(long entry = 0; entry < num_entries; ++entry){
    timer.Iterate();
    tree.GetEntry(entry);

    int nl = tree.ntruleps();
    int nth = tree.ntrutaush();
    short this_type = 1;
    if(nl==2){
      this_type = 3;
    }else if(nl==1 && nth==1){
      this_type = 2;
    }else if(nl==0){
      this_type = 4;
    }else {
      this_type = 1;
    }
    if(cut_type != 0 && cut_type != this_type) continue;
    
    if(tree.njets()<6 || tree.ht()<500.) continue;
    //if(tree.nbm()<2 || tree.njets()<6 || tree.ht()<500. || tree.met()<250 || tree.mj()<400) continue;
    //if(tree.nbm()<2 || tree.njets()<6 || tree.ht()<750. || tree.met()<250 || tree.mj()<600) continue;

    float weight = 4.*tree.weight();
    float mt, st, minmt, maxmt, minmj, maxmj, minmet;
    int nleps, lepcut, minnb, maxnb;
    int icut(0);

    for(int tcut(0); tcut<4; tcut++){
      switch(tcut) {
      case 0:
	lepcut=1;
	minmet=250.;
	minmt=0;
	maxmt=150;
	minmj=0;
	maxmj=99999.;
	minnb=2;
	maxnb=99;
	break;
      case 1:
	lepcut=1;
	minmet=250.;
	minmt=150;
	maxmt=999999;
	minmj=0;
	maxmj=99999.;
	minnb=2;
	maxnb=99;
	break;
      case 2:
	lepcut=1;
	minmet=400.;
	minmt=150;
	maxmt=999999;
	minmj=600;
	maxmj=99999.;
	minnb=2;
	maxnb=99;
	break;
      case 3:
	lepcut=2;
	minmet=250.;
	minmt=0;
	maxmt=999999;
	minmj=0;
	maxmj=99600.;
	minnb=1;
	maxnb=1;
	break;
      default:
	lepcut=2;
	minmet=250.;
	minmt=0;
	maxmt=999999;
	minmj=0;
	maxmj=99999.;
	minnb=2;
	maxnb=99;
	break;
      }
      CountRelIso(tree, nleps, mt, st, 0.074355, 0.090185, 0.12);
      if(nleps==lepcut && mt<maxmt && mt>=minmt && tree.mj() > minmj && tree.mj() < maxmj &&
	 tree.nbm() >= minnb && tree.nbm() <= maxnb && tree.met() >= minmet) {
	counts.at(icut).back() += weight; 
	w2.at(icut).back() += (weight*weight); 
      }
      icut++;
      CountMiniIso(tree, nleps, mt, st, 0.1, 0.2);
      if(nleps==lepcut && mt<maxmt && mt>=minmt && tree.mj() > minmj && tree.mj() < maxmj &&
	 tree.nbm() >= minnb && tree.nbm() <= maxnb && tree.met() >= minmet) {
	counts.at(icut).back() += weight; 
	w2.at(icut).back() += (weight*weight); 
      }
      icut++;
      CountMiniIso(tree, nleps, mt, st, 0.1, 0.4);
      if(nleps==lepcut && mt<maxmt && mt>=minmt && tree.mj() > minmj && tree.mj() < maxmj &&
	 tree.nbm() >= minnb && tree.nbm() <= maxnb && tree.met() >= minmet) {
	counts.at(icut).back() += weight; 
	w2.at(icut).back() += (weight*weight); 
      }
      icut++;


      // CountRelIso(tree, nleps, mt, st, 0.097213, 0.116708, 0.2);
      // if(nleps==lepcut && mt<maxmt && mt>=minmt && tree.mj() > minmj && tree.mj() < maxmj &&
      // tree.nbm() >= minnb && tree.nbm() <= maxnb && tree.met() >= minmet) {
      // 	counts.at(icut).back() += weight; 
      // 	w2.at(icut).back() += (weight*weight); 
      // }
      // icut++;
      // CountMiniIso(tree, nleps, mt, st, 0.05, 0.1);
      // if(nleps==lepcut && mt<maxmt && mt>=minmt && tree.mj() > minmj && tree.mj() < maxmj &&
      // tree.nbm() >= minnb && tree.nbm() <= maxnb && tree.met() >= minmet) {
      // 	counts.at(icut).back() += weight; 
      // 	w2.at(icut).back() += (weight*weight); 
      // }
      // icut++;

    //   for(unsigned iel(0); iel<elcuts.size(); iel++){
    // 	for(unsigned imu(0); imu<mucuts.size(); imu++){
    // 	CountMiniIso(tree, nleps, mt, st, 
    // 		     static_cast<float>(elcuts[iel])/100.,static_cast<float>(mucuts[imu])/100.);
    // 	if(nleps==1 && mt<150) counts.at(icut).back() += weight; 
    // 	icut++;
    //   }
    // }
    }
  }
}

void CountRelIso(small_tree_basic &tree, int &nleps, float &mt, float &st, 
		 float elcut_b, float elcut_e, float mucut){
  nleps = 0;
  mt = 0.;
  st = 0.;
  float high_pt = -1., phi = -1.;
  for(size_t i = 0; i < tree.mus_pt().size(); ++i){
    if(tree.mus_pt().at(i)>20.
       && tree.mus_sigid().at(i)
       && tree.mus_reliso().at(i)<mucut){
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
       && ((tree.els_eta().at(i)<=1.479 && tree.els_reliso().at(i)<elcut_b)
	   || (tree.els_eta().at(i)>1.479 && tree.els_reliso().at(i)<elcut_e))){
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

void CountMiniIso(small_tree_basic &tree, int &nleps, float &mt, float &st, float elcut, float mucut){
  nleps = 0;
  mt = 0.;
  st = 0.;
  float high_pt = -1., phi = -1.;
  for(size_t i = 0; i < tree.mus_pt().size(); ++i){
    if(tree.mus_pt().at(i)>20.
       && tree.mus_sigid().at(i)
       && tree.mus_miniso().at(i)<mucut){
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
       && tree.els_miniso().at(i)<elcut){
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

// void MakeTable(const vector<vector<float> > &counts,
// 	       const vector<TString> &cuts,
// 	       const vector<TString> &snames){
//   cout << setw(20) << ' ' << ' ';
//   for(size_t isample = 0; isample<snames.size(); ++isample){
//     cout << setw(12) << snames.at(isample) << ' ';
//   }
//   cout << setw(12) << " SNC zbi" << setw(12) << " SC zbi";
//   cout << endl;
//   for(size_t icut = 0; icut < counts.size(); ++icut){
//     double B(0.), SC(0.), SNC(0.);
//     cout << setw(20) << cuts.at(icut) << ' ';
//     for(size_t isample = 0; isample<counts.at(icut).size(); ++isample){
//       if(isample<counts.at(icut).size()-2) B+=counts.at(icut).at(isample);
//       if(isample==counts.at(icut).size()-2) SNC+=counts.at(icut).at(isample);
//       if(isample==counts.at(icut).size()-1) SC+=counts.at(icut).at(isample);
//       cout << setw(12) << RoundNumber(counts.at(icut).at(isample),2) << ' ';
//     }
//     cout << setw(12) << RoundNumber(RooStats::NumberCountingUtils::BinomialExpZ(SNC, B, 0.3),2)
// 	 << setw(12) << RoundNumber(RooStats::NumberCountingUtils::BinomialExpZ(SC, B, 0.3),2);
//     cout << endl;
//     if((icut+1)%4==0) cout<<endl;
//   }
// }

void MakeTable(vector<vector<float> > &counts, vector<vector<float> > &w2,
	       const vector<TString> &cuts,
	       const vector<TString> &snames){
  cout<<"\\begin{sidewaystable}[hp]\\centering"<<endl;
  for(size_t icut = 0; icut < counts.size(); ){
    cout<<"\\begin{tabular}{l | rrrrrrrr|r | r";
    if(icut==6) cout<<"r";
    cout<<" | r";
    if(icut==6) cout<<"r";
    cout<<"}\\hline\\hline"<<endl;
    cout << setw(10) << ' ' ;
    for(size_t isample = 0; isample<snames.size(); ++isample){
      cout << setw(10) << " & " << snames.at(isample);
      if(isample==counts.at(icut).size()-3)
	cout << setw(10) << " & Bkg. ";
      if(icut==6 && isample>=snames.size()-2)
	cout << setw(10) << " & ZBI ";
    }
    cout << "  \\\\ \\hline "<<endl;
    vector<float> numbers[3], errors[3];
    for(size_t count = 0; count < 3; count++, icut++){
      double B(0.), B2(0.);
      cout << setw(10) << cuts.at(icut) << ' ';
      for(size_t isample = 0; isample<counts.at(icut).size(); ++isample){
	float Num(counts.at(icut).at(isample));
	if(snames.at(isample).Contains("$t\\bar{t}$V")) {
	  Num /= 2.75; //Correcting the ttV xsec
	  w2.at(icut).at(isample) /= (2.75*2.75); 
	}
	if(isample<counts.at(icut).size()-2) {
	  B+=Num;
	  B2 += w2.at(icut).at(isample);
	}
	cout << setw(10) << " & "<<RoundNumber(Num,2) << ' ';
	numbers[count].push_back(Num);
	if(isample==counts.at(icut).size()-3){
	  errors[count].push_back(-1);
	  cout << setw(10) << " & "<<RoundNumber(B,2)<< " $\\pm$ "<< RoundNumber(sqrt(B2),2);
	  //cout << setw(10) << " & "<<RoundNumber(B,2);
	  numbers[count].push_back(B);
	  errors[count].push_back(B2);
	} else if(isample>=counts.at(icut).size()-2){
	   cout << " $\\pm$ "<< RoundNumber(sqrt(w2.at(icut).at(isample)),2);
	   errors[count].push_back(w2.at(icut).at(isample));
	}  else errors[count].push_back(-1);
	   
	if((icut==6 || icut==7 || icut==8) && isample>=snames.size()-2){
	  Num = RooStats::NumberCountingUtils::BinomialExpZ(Num, B, 0.3);
	  cout << setw(10) << " & " << RoundNumber(Num,2);
	  numbers[count].push_back(Num);
	  errors[count].push_back(-1);
	}
      }
      cout << "  \\\\ "<<endl;
    } // Loop count
    cout<< setw(10)<<"\\hline Increase ";
    for(size_t inum = 0; inum<numbers[0].size(); ++inum){
      //cout << setw(10) << " & "<<RoundNumber((numbers[1][inum]-numbers[0][inum])*100,1,numbers[0][inum]) << " ";
      cout << setw(10) << " & "<<RoundNumber(numbers[2][inum]-numbers[1][inum],2) << " ";
      if(errors[0][inum]>=0) cout<<"$\\pm$ "<<RoundNumber(sqrt(errors[1][inum]+errors[2][inum]),2);
    }
    cout << "  \\\\ \\hline\\hline"<<endl;
    cout<<"\\end{tabular} "<<endl;
    cout<<endl;
  }
    cout<<" \\end{sidewaystable}"<<endl<<endl;
}

void MakePie(const vector<float> &counts,
	     const string &cut,
	     const vector<string> &snames){
  const size_t buf_size = 64;
  char **names = new char*[buf_size];
  for(size_t i = 0; i < buf_size; ++i){
    names[i] = new char[snames.size()];
  }
    
  cout << cut << counts.back() << names[0][0] << endl;
}
