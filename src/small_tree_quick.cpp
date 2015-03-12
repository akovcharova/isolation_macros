// small_tree_quick: quick version of small_tree_base to handle reduce tree ntuples
//File generated with generate_small_tree_base.exe

#include "small_tree_base.hpp"

#include "small_tree_quick.hpp"

#include <stdexcept>
#include <string>
#include <vector>

#include "TTree.h"
#include "TBranch.h"
#include "TChain.h"

using namespace std;

small_tree_quick::small_tree_quick():
  small_tree_base(),
  dphi_wlep_reliso_(0),
  b_dphi_wlep_reliso_(tree_.Branch("dphi_wlep_reliso", &dphi_wlep_reliso_)),
  c_dphi_wlep_reliso_(false),
  lep_pt_(0),
  b_lep_pt_(tree_.Branch("lep_pt", &lep_pt_)),
  c_lep_pt_(false),
  lep_pt_reliso_(0),
  b_lep_pt_reliso_(tree_.Branch("lep_pt_reliso", &lep_pt_reliso_)),
  c_lep_pt_reliso_(false),
  mht_(0),
  b_mht_(tree_.Branch("mht", &mht_)),
  c_mht_(false),
  mj_(0),
  b_mj_(tree_.Branch("mj", &mj_)),
  c_mj_(false),
  mt_reliso_(0),
  b_mt_reliso_(tree_.Branch("mt_reliso", &mt_reliso_)),
  c_mt_reliso_(false),
  st_(0),
  b_st_(tree_.Branch("st", &st_)),
  c_st_(false),
  st_reliso_(0),
  b_st_reliso_(tree_.Branch("st_reliso", &st_reliso_)),
  c_st_reliso_(false),
  nels_reliso_(0),
  b_nels_reliso_(tree_.Branch("nels_reliso", &nels_reliso_)),
  c_nels_reliso_(false),
  nfjets_(0),
  b_nfjets_(tree_.Branch("nfjets", &nfjets_)),
  c_nfjets_(false),
  nisotks_(0),
  b_nisotks_(tree_.Branch("nisotks", &nisotks_)),
  c_nisotks_(false),
  nleps_reliso_(0),
  b_nleps_reliso_(tree_.Branch("nleps_reliso", &nleps_reliso_)),
  c_nleps_reliso_(false),
  nmus_reliso_(0),
  b_nmus_reliso_(tree_.Branch("nmus_reliso", &nmus_reliso_)),
  c_nmus_reliso_(false),
  nvels_reliso_(0),
  b_nvels_reliso_(tree_.Branch("nvels_reliso", &nvels_reliso_)),
  c_nvels_reliso_(false),
  nvmus_reliso_(0),
  b_nvmus_reliso_(tree_.Branch("nvmus_reliso", &nvmus_reliso_)),
  c_nvmus_reliso_(false),
  els_d0_(0),
  p_els_d0_(&els_d0_),
  b_els_d0_(tree_.Branch("els_d0", &p_els_d0_)),
  c_els_d0_(false),
  els_dz_(0),
  p_els_dz_(&els_dz_),
  b_els_dz_(tree_.Branch("els_dz", &p_els_dz_)),
  c_els_dz_(false),
  els_miniso_10_(0),
  p_els_miniso_10_(&els_miniso_10_),
  b_els_miniso_10_(tree_.Branch("els_miniso_10", &p_els_miniso_10_)),
  c_els_miniso_10_(false),
  els_miniso_10_pfpu_(0),
  p_els_miniso_10_pfpu_(&els_miniso_10_pfpu_),
  b_els_miniso_10_pfpu_(tree_.Branch("els_miniso_10_pfpu", &p_els_miniso_10_pfpu_)),
  c_els_miniso_10_pfpu_(false),
  els_miniso_tr10_ch_(0),
  p_els_miniso_tr10_ch_(&els_miniso_tr10_ch_),
  b_els_miniso_tr10_ch_(tree_.Branch("els_miniso_tr10_ch", &p_els_miniso_tr10_ch_)),
  c_els_miniso_tr10_ch_(false),
  fjets_eta_(0),
  p_fjets_eta_(&fjets_eta_),
  b_fjets_eta_(tree_.Branch("fjets_eta", &p_fjets_eta_)),
  c_fjets_eta_(false),
  fjets_m_(0),
  p_fjets_m_(&fjets_m_),
  b_fjets_m_(tree_.Branch("fjets_m", &p_fjets_m_)),
  c_fjets_m_(false),
  fjets_nconst_(0),
  p_fjets_nconst_(&fjets_nconst_),
  b_fjets_nconst_(tree_.Branch("fjets_nconst", &p_fjets_nconst_)),
  c_fjets_nconst_(false),
  fjets_phi_(0),
  p_fjets_phi_(&fjets_phi_),
  b_fjets_phi_(tree_.Branch("fjets_phi", &p_fjets_phi_)),
  c_fjets_phi_(false),
  fjets_pt_(0),
  p_fjets_pt_(&fjets_pt_),
  b_fjets_pt_(tree_.Branch("fjets_pt", &p_fjets_pt_)),
  c_fjets_pt_(false),
  jets_islep_(0),
  p_jets_islep_(&jets_islep_),
  b_jets_islep_(tree_.Branch("jets_islep", &p_jets_islep_)),
  c_jets_islep_(false),
  mus_d0_(0),
  p_mus_d0_(&mus_d0_),
  b_mus_d0_(tree_.Branch("mus_d0", &p_mus_d0_)),
  c_mus_d0_(false),
  mus_dz_(0),
  p_mus_dz_(&mus_dz_),
  b_mus_dz_(tree_.Branch("mus_dz", &p_mus_dz_)),
  c_mus_dz_(false),
  mus_miniso_10_(0),
  p_mus_miniso_10_(&mus_miniso_10_),
  b_mus_miniso_10_(tree_.Branch("mus_miniso_10", &p_mus_miniso_10_)),
  c_mus_miniso_10_(false),
  mus_miniso_10_pfpu_(0),
  p_mus_miniso_10_pfpu_(&mus_miniso_10_pfpu_),
  b_mus_miniso_10_pfpu_(tree_.Branch("mus_miniso_10_pfpu", &p_mus_miniso_10_pfpu_)),
  c_mus_miniso_10_pfpu_(false),
  mus_miniso_tr10_ch_(0),
  p_mus_miniso_tr10_ch_(&mus_miniso_tr10_ch_),
  b_mus_miniso_tr10_ch_(tree_.Branch("mus_miniso_tr10_ch", &p_mus_miniso_tr10_ch_)),
  c_mus_miniso_tr10_ch_(false){
}

small_tree_quick::small_tree_quick(const string &filename):
  small_tree_base(filename),
  dphi_wlep_reliso_(0),
  b_dphi_wlep_reliso_(NULL),
  c_dphi_wlep_reliso_(false),
  lep_pt_(0),
  b_lep_pt_(NULL),
  c_lep_pt_(false),
  lep_pt_reliso_(0),
  b_lep_pt_reliso_(NULL),
  c_lep_pt_reliso_(false),
  mht_(0),
  b_mht_(NULL),
  c_mht_(false),
  mj_(0),
  b_mj_(NULL),
  c_mj_(false),
  mt_reliso_(0),
  b_mt_reliso_(NULL),
  c_mt_reliso_(false),
  st_(0),
  b_st_(NULL),
  c_st_(false),
  st_reliso_(0),
  b_st_reliso_(NULL),
  c_st_reliso_(false),
  nels_reliso_(0),
  b_nels_reliso_(NULL),
  c_nels_reliso_(false),
  nfjets_(0),
  b_nfjets_(NULL),
  c_nfjets_(false),
  nisotks_(0),
  b_nisotks_(NULL),
  c_nisotks_(false),
  nleps_reliso_(0),
  b_nleps_reliso_(NULL),
  c_nleps_reliso_(false),
  nmus_reliso_(0),
  b_nmus_reliso_(NULL),
  c_nmus_reliso_(false),
  nvels_reliso_(0),
  b_nvels_reliso_(NULL),
  c_nvels_reliso_(false),
  nvmus_reliso_(0),
  b_nvmus_reliso_(NULL),
  c_nvmus_reliso_(false),
  els_d0_(0),
  p_els_d0_(&els_d0_),
  b_els_d0_(NULL),
  c_els_d0_(false),
  els_dz_(0),
  p_els_dz_(&els_dz_),
  b_els_dz_(NULL),
  c_els_dz_(false),
  els_miniso_10_(0),
  p_els_miniso_10_(&els_miniso_10_),
  b_els_miniso_10_(NULL),
  c_els_miniso_10_(false),
  els_miniso_10_pfpu_(0),
  p_els_miniso_10_pfpu_(&els_miniso_10_pfpu_),
  b_els_miniso_10_pfpu_(NULL),
  c_els_miniso_10_pfpu_(false),
  els_miniso_tr10_ch_(0),
  p_els_miniso_tr10_ch_(&els_miniso_tr10_ch_),
  b_els_miniso_tr10_ch_(NULL),
  c_els_miniso_tr10_ch_(false),
  fjets_eta_(0),
  p_fjets_eta_(&fjets_eta_),
  b_fjets_eta_(NULL),
  c_fjets_eta_(false),
  fjets_m_(0),
  p_fjets_m_(&fjets_m_),
  b_fjets_m_(NULL),
  c_fjets_m_(false),
  fjets_nconst_(0),
  p_fjets_nconst_(&fjets_nconst_),
  b_fjets_nconst_(NULL),
  c_fjets_nconst_(false),
  fjets_phi_(0),
  p_fjets_phi_(&fjets_phi_),
  b_fjets_phi_(NULL),
  c_fjets_phi_(false),
  fjets_pt_(0),
  p_fjets_pt_(&fjets_pt_),
  b_fjets_pt_(NULL),
  c_fjets_pt_(false),
  jets_islep_(0),
  p_jets_islep_(&jets_islep_),
  b_jets_islep_(NULL),
  c_jets_islep_(false),
  mus_d0_(0),
  p_mus_d0_(&mus_d0_),
  b_mus_d0_(NULL),
  c_mus_d0_(false),
  mus_dz_(0),
  p_mus_dz_(&mus_dz_),
  b_mus_dz_(NULL),
  c_mus_dz_(false),
  mus_miniso_10_(0),
  p_mus_miniso_10_(&mus_miniso_10_),
  b_mus_miniso_10_(NULL),
  c_mus_miniso_10_(false),
  mus_miniso_10_pfpu_(0),
  p_mus_miniso_10_pfpu_(&mus_miniso_10_pfpu_),
  b_mus_miniso_10_pfpu_(NULL),
  c_mus_miniso_10_pfpu_(false),
  mus_miniso_tr10_ch_(0),
  p_mus_miniso_tr10_ch_(&mus_miniso_tr10_ch_),
  b_mus_miniso_tr10_ch_(NULL),
  c_mus_miniso_tr10_ch_(false){
  chain_.SetBranchAddress("dphi_wlep_reliso", &dphi_wlep_reliso_, &b_dphi_wlep_reliso_);
  chain_.SetBranchAddress("lep_pt", &lep_pt_, &b_lep_pt_);
  chain_.SetBranchAddress("lep_pt_reliso", &lep_pt_reliso_, &b_lep_pt_reliso_);
  chain_.SetBranchAddress("mht", &mht_, &b_mht_);
  chain_.SetBranchAddress("mj", &mj_, &b_mj_);
  chain_.SetBranchAddress("mt_reliso", &mt_reliso_, &b_mt_reliso_);
  chain_.SetBranchAddress("st", &st_, &b_st_);
  chain_.SetBranchAddress("st_reliso", &st_reliso_, &b_st_reliso_);
  chain_.SetBranchAddress("nels_reliso", &nels_reliso_, &b_nels_reliso_);
  chain_.SetBranchAddress("nfjets", &nfjets_, &b_nfjets_);
  chain_.SetBranchAddress("nisotks", &nisotks_, &b_nisotks_);
  chain_.SetBranchAddress("nleps_reliso", &nleps_reliso_, &b_nleps_reliso_);
  chain_.SetBranchAddress("nmus_reliso", &nmus_reliso_, &b_nmus_reliso_);
  chain_.SetBranchAddress("nvels_reliso", &nvels_reliso_, &b_nvels_reliso_);
  chain_.SetBranchAddress("nvmus_reliso", &nvmus_reliso_, &b_nvmus_reliso_);
  chain_.SetBranchAddress("els_d0", &p_els_d0_, &b_els_d0_);
  chain_.SetBranchAddress("els_dz", &p_els_dz_, &b_els_dz_);
  chain_.SetBranchAddress("els_miniso_10", &p_els_miniso_10_, &b_els_miniso_10_);
  chain_.SetBranchAddress("els_miniso_10_pfpu", &p_els_miniso_10_pfpu_, &b_els_miniso_10_pfpu_);
  chain_.SetBranchAddress("els_miniso_tr10_ch", &p_els_miniso_tr10_ch_, &b_els_miniso_tr10_ch_);
  chain_.SetBranchAddress("fjets_eta", &p_fjets_eta_, &b_fjets_eta_);
  chain_.SetBranchAddress("fjets_m", &p_fjets_m_, &b_fjets_m_);
  chain_.SetBranchAddress("fjets_nconst", &p_fjets_nconst_, &b_fjets_nconst_);
  chain_.SetBranchAddress("fjets_phi", &p_fjets_phi_, &b_fjets_phi_);
  chain_.SetBranchAddress("fjets_pt", &p_fjets_pt_, &b_fjets_pt_);
  chain_.SetBranchAddress("jets_islep", &p_jets_islep_, &b_jets_islep_);
  chain_.SetBranchAddress("mus_d0", &p_mus_d0_, &b_mus_d0_);
  chain_.SetBranchAddress("mus_dz", &p_mus_dz_, &b_mus_dz_);
  chain_.SetBranchAddress("mus_miniso_10", &p_mus_miniso_10_, &b_mus_miniso_10_);
  chain_.SetBranchAddress("mus_miniso_10_pfpu", &p_mus_miniso_10_pfpu_, &b_mus_miniso_10_pfpu_);
  chain_.SetBranchAddress("mus_miniso_tr10_ch", &p_mus_miniso_tr10_ch_, &b_mus_miniso_tr10_ch_);
}

void small_tree_quick::Fill(){
  small_tree_base::Fill();
  //Resetting variables
  dphi_wlep_reliso_ = static_cast<float>(bad_val_);
  lep_pt_ = static_cast<float>(bad_val_);
  lep_pt_reliso_ = static_cast<float>(bad_val_);
  mht_ = static_cast<float>(bad_val_);
  mj_ = static_cast<float>(bad_val_);
  mt_reliso_ = static_cast<float>(bad_val_);
  st_ = static_cast<float>(bad_val_);
  st_reliso_ = static_cast<float>(bad_val_);
  nels_reliso_ = static_cast<int>(bad_val_);
  nfjets_ = static_cast<int>(bad_val_);
  nisotks_ = static_cast<int>(bad_val_);
  nleps_reliso_ = static_cast<int>(bad_val_);
  nmus_reliso_ = static_cast<int>(bad_val_);
  nvels_reliso_ = static_cast<int>(bad_val_);
  nvmus_reliso_ = static_cast<int>(bad_val_);
  els_d0_.clear();
  els_dz_.clear();
  els_miniso_10_.clear();
  els_miniso_10_pfpu_.clear();
  els_miniso_tr10_ch_.clear();
  fjets_eta_.clear();
  fjets_m_.clear();
  fjets_nconst_.clear();
  fjets_phi_.clear();
  fjets_pt_.clear();
  jets_islep_.clear();
  mus_d0_.clear();
  mus_dz_.clear();
  mus_miniso_10_.clear();
  mus_miniso_10_pfpu_.clear();
  mus_miniso_tr10_ch_.clear();
}

string small_tree_quick::Type() const{
  return "quick";
}

small_tree_quick::~small_tree_quick(){
}

void small_tree_quick::GetEntry(const long entry){
  small_tree_base::GetEntry(entry);

  c_dphi_wlep_reliso_ = false;
  c_lep_pt_ = false;
  c_lep_pt_reliso_ = false;
  c_mht_ = false;
  c_mj_ = false;
  c_mt_reliso_ = false;
  c_st_ = false;
  c_st_reliso_ = false;
  c_nels_reliso_ = false;
  c_nfjets_ = false;
  c_nisotks_ = false;
  c_nleps_reliso_ = false;
  c_nmus_reliso_ = false;
  c_nvels_reliso_ = false;
  c_nvmus_reliso_ = false;
  c_els_d0_ = false;
  c_els_dz_ = false;
  c_els_miniso_10_ = false;
  c_els_miniso_10_pfpu_ = false;
  c_els_miniso_tr10_ch_ = false;
  c_fjets_eta_ = false;
  c_fjets_m_ = false;
  c_fjets_nconst_ = false;
  c_fjets_phi_ = false;
  c_fjets_pt_ = false;
  c_jets_islep_ = false;
  c_mus_d0_ = false;
  c_mus_dz_ = false;
  c_mus_miniso_10_ = false;
  c_mus_miniso_10_pfpu_ = false;
  c_mus_miniso_tr10_ch_ = false;
}

float const & small_tree_quick::dphi_wlep_reliso() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_dphi_wlep_reliso_ && b_dphi_wlep_reliso_){
    b_dphi_wlep_reliso_->GetEntry(entry_);
    c_dphi_wlep_reliso_ = true;
  }
  return dphi_wlep_reliso_;
}

float const & small_tree_quick::lep_pt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_lep_pt_ && b_lep_pt_){
    b_lep_pt_->GetEntry(entry_);
    c_lep_pt_ = true;
  }
  return lep_pt_;
}

float const & small_tree_quick::lep_pt_reliso() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_lep_pt_reliso_ && b_lep_pt_reliso_){
    b_lep_pt_reliso_->GetEntry(entry_);
    c_lep_pt_reliso_ = true;
  }
  return lep_pt_reliso_;
}

float const & small_tree_quick::mht() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mht_ && b_mht_){
    b_mht_->GetEntry(entry_);
    c_mht_ = true;
  }
  return mht_;
}

float const & small_tree_quick::mj() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mj_ && b_mj_){
    b_mj_->GetEntry(entry_);
    c_mj_ = true;
  }
  return mj_;
}

float const & small_tree_quick::mt_reliso() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mt_reliso_ && b_mt_reliso_){
    b_mt_reliso_->GetEntry(entry_);
    c_mt_reliso_ = true;
  }
  return mt_reliso_;
}

float const & small_tree_quick::st() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_st_ && b_st_){
    b_st_->GetEntry(entry_);
    c_st_ = true;
  }
  return st_;
}

float const & small_tree_quick::st_reliso() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_st_reliso_ && b_st_reliso_){
    b_st_reliso_->GetEntry(entry_);
    c_st_reliso_ = true;
  }
  return st_reliso_;
}

int const & small_tree_quick::nels_reliso() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nels_reliso_ && b_nels_reliso_){
    b_nels_reliso_->GetEntry(entry_);
    c_nels_reliso_ = true;
  }
  return nels_reliso_;
}

int const & small_tree_quick::nfjets() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nfjets_ && b_nfjets_){
    b_nfjets_->GetEntry(entry_);
    c_nfjets_ = true;
  }
  return nfjets_;
}

int const & small_tree_quick::nisotks() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nisotks_ && b_nisotks_){
    b_nisotks_->GetEntry(entry_);
    c_nisotks_ = true;
  }
  return nisotks_;
}

int const & small_tree_quick::nleps_reliso() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nleps_reliso_ && b_nleps_reliso_){
    b_nleps_reliso_->GetEntry(entry_);
    c_nleps_reliso_ = true;
  }
  return nleps_reliso_;
}

int const & small_tree_quick::nmus_reliso() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nmus_reliso_ && b_nmus_reliso_){
    b_nmus_reliso_->GetEntry(entry_);
    c_nmus_reliso_ = true;
  }
  return nmus_reliso_;
}

int const & small_tree_quick::nvels_reliso() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nvels_reliso_ && b_nvels_reliso_){
    b_nvels_reliso_->GetEntry(entry_);
    c_nvels_reliso_ = true;
  }
  return nvels_reliso_;
}

int const & small_tree_quick::nvmus_reliso() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nvmus_reliso_ && b_nvmus_reliso_){
    b_nvmus_reliso_->GetEntry(entry_);
    c_nvmus_reliso_ = true;
  }
  return nvmus_reliso_;
}

std::vector<float> const & small_tree_quick::els_d0() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_d0_ && b_els_d0_){
    b_els_d0_->GetEntry(entry_);
    c_els_d0_ = true;
  }
  return els_d0_;
}

std::vector<float> const & small_tree_quick::els_dz() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_dz_ && b_els_dz_){
    b_els_dz_->GetEntry(entry_);
    c_els_dz_ = true;
  }
  return els_dz_;
}

std::vector<float> const & small_tree_quick::els_miniso_10() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_miniso_10_ && b_els_miniso_10_){
    b_els_miniso_10_->GetEntry(entry_);
    c_els_miniso_10_ = true;
  }
  return els_miniso_10_;
}

std::vector<float> const & small_tree_quick::els_miniso_10_pfpu() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_miniso_10_pfpu_ && b_els_miniso_10_pfpu_){
    b_els_miniso_10_pfpu_->GetEntry(entry_);
    c_els_miniso_10_pfpu_ = true;
  }
  return els_miniso_10_pfpu_;
}

std::vector<float> const & small_tree_quick::els_miniso_tr10_ch() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_miniso_tr10_ch_ && b_els_miniso_tr10_ch_){
    b_els_miniso_tr10_ch_->GetEntry(entry_);
    c_els_miniso_tr10_ch_ = true;
  }
  return els_miniso_tr10_ch_;
}

std::vector<float> const & small_tree_quick::fjets_eta() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_fjets_eta_ && b_fjets_eta_){
    b_fjets_eta_->GetEntry(entry_);
    c_fjets_eta_ = true;
  }
  return fjets_eta_;
}

std::vector<float> const & small_tree_quick::fjets_m() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_fjets_m_ && b_fjets_m_){
    b_fjets_m_->GetEntry(entry_);
    c_fjets_m_ = true;
  }
  return fjets_m_;
}

std::vector<float> const & small_tree_quick::fjets_nconst() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_fjets_nconst_ && b_fjets_nconst_){
    b_fjets_nconst_->GetEntry(entry_);
    c_fjets_nconst_ = true;
  }
  return fjets_nconst_;
}

std::vector<float> const & small_tree_quick::fjets_phi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_fjets_phi_ && b_fjets_phi_){
    b_fjets_phi_->GetEntry(entry_);
    c_fjets_phi_ = true;
  }
  return fjets_phi_;
}

std::vector<float> const & small_tree_quick::fjets_pt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_fjets_pt_ && b_fjets_pt_){
    b_fjets_pt_->GetEntry(entry_);
    c_fjets_pt_ = true;
  }
  return fjets_pt_;
}

std::vector<float> const & small_tree_quick::jets_islep() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_jets_islep_ && b_jets_islep_){
    b_jets_islep_->GetEntry(entry_);
    c_jets_islep_ = true;
  }
  return jets_islep_;
}

std::vector<float> const & small_tree_quick::mus_d0() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_d0_ && b_mus_d0_){
    b_mus_d0_->GetEntry(entry_);
    c_mus_d0_ = true;
  }
  return mus_d0_;
}

std::vector<float> const & small_tree_quick::mus_dz() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_dz_ && b_mus_dz_){
    b_mus_dz_->GetEntry(entry_);
    c_mus_dz_ = true;
  }
  return mus_dz_;
}

std::vector<float> const & small_tree_quick::mus_miniso_10() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_miniso_10_ && b_mus_miniso_10_){
    b_mus_miniso_10_->GetEntry(entry_);
    c_mus_miniso_10_ = true;
  }
  return mus_miniso_10_;
}

std::vector<float> const & small_tree_quick::mus_miniso_10_pfpu() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_miniso_10_pfpu_ && b_mus_miniso_10_pfpu_){
    b_mus_miniso_10_pfpu_->GetEntry(entry_);
    c_mus_miniso_10_pfpu_ = true;
  }
  return mus_miniso_10_pfpu_;
}

std::vector<float> const & small_tree_quick::mus_miniso_tr10_ch() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_miniso_tr10_ch_ && b_mus_miniso_tr10_ch_){
    b_mus_miniso_tr10_ch_->GetEntry(entry_);
    c_mus_miniso_tr10_ch_ = true;
  }
  return mus_miniso_tr10_ch_;
}

float & small_tree_quick::dphi_wlep_reliso(){
  if(read_only_ && !c_dphi_wlep_reliso_ && b_dphi_wlep_reliso_){
    b_dphi_wlep_reliso_->GetEntry(entry_);
    c_dphi_wlep_reliso_ = true;
  }
  return dphi_wlep_reliso_;
}

float & small_tree_quick::lep_pt(){
  if(read_only_ && !c_lep_pt_ && b_lep_pt_){
    b_lep_pt_->GetEntry(entry_);
    c_lep_pt_ = true;
  }
  return lep_pt_;
}

float & small_tree_quick::lep_pt_reliso(){
  if(read_only_ && !c_lep_pt_reliso_ && b_lep_pt_reliso_){
    b_lep_pt_reliso_->GetEntry(entry_);
    c_lep_pt_reliso_ = true;
  }
  return lep_pt_reliso_;
}

float & small_tree_quick::mht(){
  if(read_only_ && !c_mht_ && b_mht_){
    b_mht_->GetEntry(entry_);
    c_mht_ = true;
  }
  return mht_;
}

float & small_tree_quick::mj(){
  if(read_only_ && !c_mj_ && b_mj_){
    b_mj_->GetEntry(entry_);
    c_mj_ = true;
  }
  return mj_;
}

float & small_tree_quick::mt_reliso(){
  if(read_only_ && !c_mt_reliso_ && b_mt_reliso_){
    b_mt_reliso_->GetEntry(entry_);
    c_mt_reliso_ = true;
  }
  return mt_reliso_;
}

float & small_tree_quick::st(){
  if(read_only_ && !c_st_ && b_st_){
    b_st_->GetEntry(entry_);
    c_st_ = true;
  }
  return st_;
}

float & small_tree_quick::st_reliso(){
  if(read_only_ && !c_st_reliso_ && b_st_reliso_){
    b_st_reliso_->GetEntry(entry_);
    c_st_reliso_ = true;
  }
  return st_reliso_;
}

int & small_tree_quick::nels_reliso(){
  if(read_only_ && !c_nels_reliso_ && b_nels_reliso_){
    b_nels_reliso_->GetEntry(entry_);
    c_nels_reliso_ = true;
  }
  return nels_reliso_;
}

int & small_tree_quick::nfjets(){
  if(read_only_ && !c_nfjets_ && b_nfjets_){
    b_nfjets_->GetEntry(entry_);
    c_nfjets_ = true;
  }
  return nfjets_;
}

int & small_tree_quick::nisotks(){
  if(read_only_ && !c_nisotks_ && b_nisotks_){
    b_nisotks_->GetEntry(entry_);
    c_nisotks_ = true;
  }
  return nisotks_;
}

int & small_tree_quick::nleps_reliso(){
  if(read_only_ && !c_nleps_reliso_ && b_nleps_reliso_){
    b_nleps_reliso_->GetEntry(entry_);
    c_nleps_reliso_ = true;
  }
  return nleps_reliso_;
}

int & small_tree_quick::nmus_reliso(){
  if(read_only_ && !c_nmus_reliso_ && b_nmus_reliso_){
    b_nmus_reliso_->GetEntry(entry_);
    c_nmus_reliso_ = true;
  }
  return nmus_reliso_;
}

int & small_tree_quick::nvels_reliso(){
  if(read_only_ && !c_nvels_reliso_ && b_nvels_reliso_){
    b_nvels_reliso_->GetEntry(entry_);
    c_nvels_reliso_ = true;
  }
  return nvels_reliso_;
}

int & small_tree_quick::nvmus_reliso(){
  if(read_only_ && !c_nvmus_reliso_ && b_nvmus_reliso_){
    b_nvmus_reliso_->GetEntry(entry_);
    c_nvmus_reliso_ = true;
  }
  return nvmus_reliso_;
}

std::vector<float> & small_tree_quick::els_d0(){
  if(read_only_ && !c_els_d0_ && b_els_d0_){
    b_els_d0_->GetEntry(entry_);
    c_els_d0_ = true;
  }
  return els_d0_;
}

std::vector<float> & small_tree_quick::els_dz(){
  if(read_only_ && !c_els_dz_ && b_els_dz_){
    b_els_dz_->GetEntry(entry_);
    c_els_dz_ = true;
  }
  return els_dz_;
}

std::vector<float> & small_tree_quick::els_miniso_10(){
  if(read_only_ && !c_els_miniso_10_ && b_els_miniso_10_){
    b_els_miniso_10_->GetEntry(entry_);
    c_els_miniso_10_ = true;
  }
  return els_miniso_10_;
}

std::vector<float> & small_tree_quick::els_miniso_10_pfpu(){
  if(read_only_ && !c_els_miniso_10_pfpu_ && b_els_miniso_10_pfpu_){
    b_els_miniso_10_pfpu_->GetEntry(entry_);
    c_els_miniso_10_pfpu_ = true;
  }
  return els_miniso_10_pfpu_;
}

std::vector<float> & small_tree_quick::els_miniso_tr10_ch(){
  if(read_only_ && !c_els_miniso_tr10_ch_ && b_els_miniso_tr10_ch_){
    b_els_miniso_tr10_ch_->GetEntry(entry_);
    c_els_miniso_tr10_ch_ = true;
  }
  return els_miniso_tr10_ch_;
}

std::vector<float> & small_tree_quick::fjets_eta(){
  if(read_only_ && !c_fjets_eta_ && b_fjets_eta_){
    b_fjets_eta_->GetEntry(entry_);
    c_fjets_eta_ = true;
  }
  return fjets_eta_;
}

std::vector<float> & small_tree_quick::fjets_m(){
  if(read_only_ && !c_fjets_m_ && b_fjets_m_){
    b_fjets_m_->GetEntry(entry_);
    c_fjets_m_ = true;
  }
  return fjets_m_;
}

std::vector<float> & small_tree_quick::fjets_nconst(){
  if(read_only_ && !c_fjets_nconst_ && b_fjets_nconst_){
    b_fjets_nconst_->GetEntry(entry_);
    c_fjets_nconst_ = true;
  }
  return fjets_nconst_;
}

std::vector<float> & small_tree_quick::fjets_phi(){
  if(read_only_ && !c_fjets_phi_ && b_fjets_phi_){
    b_fjets_phi_->GetEntry(entry_);
    c_fjets_phi_ = true;
  }
  return fjets_phi_;
}

std::vector<float> & small_tree_quick::fjets_pt(){
  if(read_only_ && !c_fjets_pt_ && b_fjets_pt_){
    b_fjets_pt_->GetEntry(entry_);
    c_fjets_pt_ = true;
  }
  return fjets_pt_;
}

std::vector<float> & small_tree_quick::jets_islep(){
  if(read_only_ && !c_jets_islep_ && b_jets_islep_){
    b_jets_islep_->GetEntry(entry_);
    c_jets_islep_ = true;
  }
  return jets_islep_;
}

std::vector<float> & small_tree_quick::mus_d0(){
  if(read_only_ && !c_mus_d0_ && b_mus_d0_){
    b_mus_d0_->GetEntry(entry_);
    c_mus_d0_ = true;
  }
  return mus_d0_;
}

std::vector<float> & small_tree_quick::mus_dz(){
  if(read_only_ && !c_mus_dz_ && b_mus_dz_){
    b_mus_dz_->GetEntry(entry_);
    c_mus_dz_ = true;
  }
  return mus_dz_;
}

std::vector<float> & small_tree_quick::mus_miniso_10(){
  if(read_only_ && !c_mus_miniso_10_ && b_mus_miniso_10_){
    b_mus_miniso_10_->GetEntry(entry_);
    c_mus_miniso_10_ = true;
  }
  return mus_miniso_10_;
}

std::vector<float> & small_tree_quick::mus_miniso_10_pfpu(){
  if(read_only_ && !c_mus_miniso_10_pfpu_ && b_mus_miniso_10_pfpu_){
    b_mus_miniso_10_pfpu_->GetEntry(entry_);
    c_mus_miniso_10_pfpu_ = true;
  }
  return mus_miniso_10_pfpu_;
}

std::vector<float> & small_tree_quick::mus_miniso_tr10_ch(){
  if(read_only_ && !c_mus_miniso_tr10_ch_ && b_mus_miniso_tr10_ch_){
    b_mus_miniso_tr10_ch_->GetEntry(entry_);
    c_mus_miniso_tr10_ch_ = true;
  }
  return mus_miniso_tr10_ch_;
}

