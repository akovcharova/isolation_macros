// small_tree_base: base class to handle reduce tree ntuples
//File generated with generate_small_tree_base.exe

#include "small_tree_base.hpp"

#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>

#include "TROOT.h"
#include "TTree.h"
#include "TBranch.h"
#include "TChain.h"

using namespace std;

bool small_tree_base::VectorLoader::loaded_ = false;

small_tree_base::VectorLoader small_tree_base::vl_ = small_tree_base::VectorLoader();

small_tree_base::VectorLoader::VectorLoader(){
  if(!loaded_){
    gROOT->ProcessLine("#include <vector>");
    loaded_ = true;
  }
}

const double small_tree_base::bad_val_ = -999.;

small_tree_base::small_tree_base():
  chain_("junk", "junk"),
  tree_("tree", "tree"),
  entry_(0),
  read_only_(false),
  dphi_wlep_(0),
  b_dphi_wlep_(tree_.Branch("dphi_wlep", &dphi_wlep_)),
  c_dphi_wlep_(false),
  ht_(0),
  b_ht_(tree_.Branch("ht", &ht_)),
  c_ht_(false),
  met_(0),
  b_met_(tree_.Branch("met", &met_)),
  c_met_(false),
  met_phi_(0),
  b_met_phi_(tree_.Branch("met_phi", &met_phi_)),
  c_met_phi_(false),
  min_mt_bmet_(0),
  b_min_mt_bmet_(tree_.Branch("min_mt_bmet", &min_mt_bmet_)),
  c_min_mt_bmet_(false),
  min_mt_bmet_with_w_mass_(0),
  b_min_mt_bmet_with_w_mass_(tree_.Branch("min_mt_bmet_with_w_mass", &min_mt_bmet_with_w_mass_)),
  c_min_mt_bmet_with_w_mass_(false),
  mindphin_metjet_(0),
  b_mindphin_metjet_(tree_.Branch("mindphin_metjet", &mindphin_metjet_)),
  c_mindphin_metjet_(false),
  mt_(0),
  b_mt_(tree_.Branch("mt", &mt_)),
  c_mt_(false),
  ntrupv_mean_(0),
  b_ntrupv_mean_(tree_.Branch("ntrupv_mean", &ntrupv_mean_)),
  c_ntrupv_mean_(false),
  weight_(0),
  b_weight_(tree_.Branch("weight", &weight_)),
  c_weight_(false),
  event_(0),
  b_event_(tree_.Branch("event", &event_)),
  c_event_(false),
  lumiblock_(0),
  b_lumiblock_(tree_.Branch("lumiblock", &lumiblock_)),
  c_lumiblock_(false),
  nbl_(0),
  b_nbl_(tree_.Branch("nbl", &nbl_)),
  c_nbl_(false),
  nbm_(0),
  b_nbm_(tree_.Branch("nbm", &nbm_)),
  c_nbm_(false),
  nbt_(0),
  b_nbt_(tree_.Branch("nbt", &nbt_)),
  c_nbt_(false),
  nels_(0),
  b_nels_(tree_.Branch("nels", &nels_)),
  c_nels_(false),
  njets_(0),
  b_njets_(tree_.Branch("njets", &njets_)),
  c_njets_(false),
  nleps_(0),
  b_nleps_(tree_.Branch("nleps", &nleps_)),
  c_nleps_(false),
  nmus_(0),
  b_nmus_(tree_.Branch("nmus", &nmus_)),
  c_nmus_(false),
  npv_(0),
  b_npv_(tree_.Branch("npv", &npv_)),
  c_npv_(false),
  ntrupv_(0),
  b_ntrupv_(tree_.Branch("ntrupv", &ntrupv_)),
  c_ntrupv_(false),
  nvels_(0),
  b_nvels_(tree_.Branch("nvels", &nvels_)),
  c_nvels_(false),
  nvmus_(0),
  b_nvmus_(tree_.Branch("nvmus", &nvmus_)),
  c_nvmus_(false),
  run_(0),
  b_run_(tree_.Branch("run", &run_)),
  c_run_(false),
  els_ispf_(0),
  p_els_ispf_(&els_ispf_),
  b_els_ispf_(tree_.Branch("els_ispf", &p_els_ispf_)),
  c_els_ispf_(false),
  els_sigid_(0),
  p_els_sigid_(&els_sigid_),
  b_els_sigid_(tree_.Branch("els_sigid", &p_els_sigid_)),
  c_els_sigid_(false),
  els_tru_tm_(0),
  p_els_tru_tm_(&els_tru_tm_),
  b_els_tru_tm_(tree_.Branch("els_tru_tm", &p_els_tru_tm_)),
  c_els_tru_tm_(false),
  mus_sigid_(0),
  p_mus_sigid_(&mus_sigid_),
  b_mus_sigid_(tree_.Branch("mus_sigid", &p_mus_sigid_)),
  c_mus_sigid_(false),
  mus_tru_tm_(0),
  p_mus_tru_tm_(&mus_tru_tm_),
  b_mus_tru_tm_(tree_.Branch("mus_tru_tm", &p_mus_tru_tm_)),
  c_mus_tru_tm_(false),
  tks_from_tau_(0),
  p_tks_from_tau_(&tks_from_tau_),
  b_tks_from_tau_(tree_.Branch("tks_from_tau", &p_tks_from_tau_)),
  c_tks_from_tau_(false),
  tks_from_tauhad_(0),
  p_tks_from_tauhad_(&tks_from_tauhad_),
  b_tks_from_tauhad_(tree_.Branch("tks_from_tauhad", &p_tks_from_tauhad_)),
  c_tks_from_tauhad_(false),
  tks_from_taulep_(0),
  p_tks_from_taulep_(&tks_from_taulep_),
  b_tks_from_taulep_(tree_.Branch("tks_from_taulep", &p_tks_from_taulep_)),
  c_tks_from_taulep_(false),
  tks_from_w_(0),
  p_tks_from_w_(&tks_from_w_),
  b_tks_from_w_(tree_.Branch("tks_from_w", &p_tks_from_w_)),
  c_tks_from_w_(false),
  els_eta_(0),
  p_els_eta_(&els_eta_),
  b_els_eta_(tree_.Branch("els_eta", &p_els_eta_)),
  c_els_eta_(false),
  els_miniso_10_ch_(0),
  p_els_miniso_10_ch_(&els_miniso_10_ch_),
  b_els_miniso_10_ch_(tree_.Branch("els_miniso_10_ch", &p_els_miniso_10_ch_)),
  c_els_miniso_10_ch_(false),
  els_miniso_tr10_(0),
  p_els_miniso_tr10_(&els_miniso_tr10_),
  b_els_miniso_tr10_(tree_.Branch("els_miniso_tr10", &p_els_miniso_tr10_)),
  c_els_miniso_tr10_(false),
  els_miniso_tr10_pfpu_(0),
  p_els_miniso_tr10_pfpu_(&els_miniso_tr10_pfpu_),
  b_els_miniso_tr10_pfpu_(tree_.Branch("els_miniso_tr10_pfpu", &p_els_miniso_tr10_pfpu_)),
  c_els_miniso_tr10_pfpu_(false),
  els_mt_(0),
  p_els_mt_(&els_mt_),
  b_els_mt_(tree_.Branch("els_mt", &p_els_mt_)),
  c_els_mt_(false),
  els_phi_(0),
  p_els_phi_(&els_phi_),
  b_els_phi_(tree_.Branch("els_phi", &p_els_phi_)),
  c_els_phi_(false),
  els_pt_(0),
  p_els_pt_(&els_pt_),
  b_els_pt_(tree_.Branch("els_pt", &p_els_pt_)),
  c_els_pt_(false),
  els_reliso_(0),
  p_els_reliso_(&els_reliso_),
  b_els_reliso_(tree_.Branch("els_reliso", &p_els_reliso_)),
  c_els_reliso_(false),
  els_reliso_r01_(0),
  p_els_reliso_r01_(&els_reliso_r01_),
  b_els_reliso_r01_(tree_.Branch("els_reliso_r01", &p_els_reliso_r01_)),
  c_els_reliso_r01_(false),
  els_reliso_r015_(0),
  p_els_reliso_r015_(&els_reliso_r015_),
  b_els_reliso_r015_(tree_.Branch("els_reliso_r015", &p_els_reliso_r015_)),
  c_els_reliso_r015_(false),
  els_reliso_r02_(0),
  p_els_reliso_r02_(&els_reliso_r02_),
  b_els_reliso_r02_(tree_.Branch("els_reliso_r02", &p_els_reliso_r02_)),
  c_els_reliso_r02_(false),
  els_reliso_r03_(0),
  p_els_reliso_r03_(&els_reliso_r03_),
  b_els_reliso_r03_(tree_.Branch("els_reliso_r03", &p_els_reliso_r03_)),
  c_els_reliso_r03_(false),
  els_reliso_r04_(0),
  p_els_reliso_r04_(&els_reliso_r04_),
  b_els_reliso_r04_(tree_.Branch("els_reliso_r04", &p_els_reliso_r04_)),
  c_els_reliso_r04_(false),
  els_tru_dr_(0),
  p_els_tru_dr_(&els_tru_dr_),
  b_els_tru_dr_(tree_.Branch("els_tru_dr", &p_els_tru_dr_)),
  c_els_tru_dr_(false),
  jets_csv_(0),
  p_jets_csv_(&jets_csv_),
  b_jets_csv_(tree_.Branch("jets_csv", &p_jets_csv_)),
  c_jets_csv_(false),
  jets_eta_(0),
  p_jets_eta_(&jets_eta_),
  b_jets_eta_(tree_.Branch("jets_eta", &p_jets_eta_)),
  c_jets_eta_(false),
  jets_id_(0),
  p_jets_id_(&jets_id_),
  b_jets_id_(tree_.Branch("jets_id", &p_jets_id_)),
  c_jets_id_(false),
  jets_phi_(0),
  p_jets_phi_(&jets_phi_),
  b_jets_phi_(tree_.Branch("jets_phi", &p_jets_phi_)),
  c_jets_phi_(false),
  jets_pt_(0),
  p_jets_pt_(&jets_pt_),
  b_jets_pt_(tree_.Branch("jets_pt", &p_jets_pt_)),
  c_jets_pt_(false),
  mus_eta_(0),
  p_mus_eta_(&mus_eta_),
  b_mus_eta_(tree_.Branch("mus_eta", &p_mus_eta_)),
  c_mus_eta_(false),
  mus_miniso_10_ch_(0),
  p_mus_miniso_10_ch_(&mus_miniso_10_ch_),
  b_mus_miniso_10_ch_(tree_.Branch("mus_miniso_10_ch", &p_mus_miniso_10_ch_)),
  c_mus_miniso_10_ch_(false),
  mus_miniso_tr10_(0),
  p_mus_miniso_tr10_(&mus_miniso_tr10_),
  b_mus_miniso_tr10_(tree_.Branch("mus_miniso_tr10", &p_mus_miniso_tr10_)),
  c_mus_miniso_tr10_(false),
  mus_miniso_tr10_pfpu_(0),
  p_mus_miniso_tr10_pfpu_(&mus_miniso_tr10_pfpu_),
  b_mus_miniso_tr10_pfpu_(tree_.Branch("mus_miniso_tr10_pfpu", &p_mus_miniso_tr10_pfpu_)),
  c_mus_miniso_tr10_pfpu_(false),
  mus_mt_(0),
  p_mus_mt_(&mus_mt_),
  b_mus_mt_(tree_.Branch("mus_mt", &p_mus_mt_)),
  c_mus_mt_(false),
  mus_phi_(0),
  p_mus_phi_(&mus_phi_),
  b_mus_phi_(tree_.Branch("mus_phi", &p_mus_phi_)),
  c_mus_phi_(false),
  mus_pt_(0),
  p_mus_pt_(&mus_pt_),
  b_mus_pt_(tree_.Branch("mus_pt", &p_mus_pt_)),
  c_mus_pt_(false),
  mus_reliso_(0),
  p_mus_reliso_(&mus_reliso_),
  b_mus_reliso_(tree_.Branch("mus_reliso", &p_mus_reliso_)),
  c_mus_reliso_(false),
  mus_reliso_r01_(0),
  p_mus_reliso_r01_(&mus_reliso_r01_),
  b_mus_reliso_r01_(tree_.Branch("mus_reliso_r01", &p_mus_reliso_r01_)),
  c_mus_reliso_r01_(false),
  mus_reliso_r015_(0),
  p_mus_reliso_r015_(&mus_reliso_r015_),
  b_mus_reliso_r015_(tree_.Branch("mus_reliso_r015", &p_mus_reliso_r015_)),
  c_mus_reliso_r015_(false),
  mus_reliso_r02_(0),
  p_mus_reliso_r02_(&mus_reliso_r02_),
  b_mus_reliso_r02_(tree_.Branch("mus_reliso_r02", &p_mus_reliso_r02_)),
  c_mus_reliso_r02_(false),
  mus_reliso_r03_(0),
  p_mus_reliso_r03_(&mus_reliso_r03_),
  b_mus_reliso_r03_(tree_.Branch("mus_reliso_r03", &p_mus_reliso_r03_)),
  c_mus_reliso_r03_(false),
  mus_reliso_r04_(0),
  p_mus_reliso_r04_(&mus_reliso_r04_),
  b_mus_reliso_r04_(tree_.Branch("mus_reliso_r04", &p_mus_reliso_r04_)),
  c_mus_reliso_r04_(false),
  mus_tru_dr_(0),
  p_mus_tru_dr_(&mus_tru_dr_),
  b_mus_tru_dr_(tree_.Branch("mus_tru_dr", &p_mus_tru_dr_)),
  c_mus_tru_dr_(false),
  tks_eta_(0),
  p_tks_eta_(&tks_eta_),
  b_tks_eta_(tree_.Branch("tks_eta", &p_tks_eta_)),
  c_tks_eta_(false),
  tks_mt_(0),
  p_tks_mt_(&tks_mt_),
  b_tks_mt_(tree_.Branch("tks_mt", &p_tks_mt_)),
  c_tks_mt_(false),
  tks_phi_(0),
  p_tks_phi_(&tks_phi_),
  b_tks_phi_(tree_.Branch("tks_phi", &p_tks_phi_)),
  c_tks_phi_(false),
  tks_pt_(0),
  p_tks_pt_(&tks_pt_),
  b_tks_pt_(tree_.Branch("tks_pt", &p_tks_pt_)),
  c_tks_pt_(false),
  tks_r03_ch_(0),
  p_tks_r03_ch_(&tks_r03_ch_),
  b_tks_r03_ch_(tree_.Branch("tks_r03_ch", &p_tks_r03_ch_)),
  c_tks_r03_ch_(false),
  tks_tru_dp_(0),
  p_tks_tru_dp_(&tks_tru_dp_),
  b_tks_tru_dp_(tree_.Branch("tks_tru_dp", &p_tks_tru_dp_)),
  c_tks_tru_dp_(false),
  tks_tru_dr_(0),
  p_tks_tru_dr_(&tks_tru_dr_),
  b_tks_tru_dr_(tree_.Branch("tks_tru_dr", &p_tks_tru_dr_)),
  c_tks_tru_dr_(false),
  els_charge_(0),
  p_els_charge_(&els_charge_),
  b_els_charge_(tree_.Branch("els_charge", &p_els_charge_)),
  c_els_charge_(false),
  els_tru_id_(0),
  p_els_tru_id_(&els_tru_id_),
  b_els_tru_id_(tree_.Branch("els_tru_id", &p_els_tru_id_)),
  c_els_tru_id_(false),
  els_tru_momid_(0),
  p_els_tru_momid_(&els_tru_momid_),
  b_els_tru_momid_(tree_.Branch("els_tru_momid", &p_els_tru_momid_)),
  c_els_tru_momid_(false),
  mus_charge_(0),
  p_mus_charge_(&mus_charge_),
  b_mus_charge_(tree_.Branch("mus_charge", &p_mus_charge_)),
  c_mus_charge_(false),
  mus_tru_id_(0),
  p_mus_tru_id_(&mus_tru_id_),
  b_mus_tru_id_(tree_.Branch("mus_tru_id", &p_mus_tru_id_)),
  c_mus_tru_id_(false),
  mus_tru_momid_(0),
  p_mus_tru_momid_(&mus_tru_momid_),
  b_mus_tru_momid_(tree_.Branch("mus_tru_momid", &p_mus_tru_momid_)),
  c_mus_tru_momid_(false),
  tks_from_pv_(0),
  p_tks_from_pv_(&tks_from_pv_),
  b_tks_from_pv_(tree_.Branch("tks_from_pv", &p_tks_from_pv_)),
  c_tks_from_pv_(false),
  tks_id_(0),
  p_tks_id_(&tks_id_),
  b_tks_id_(tree_.Branch("tks_id", &p_tks_id_)),
  c_tks_id_(false),
  tks_num_prongs_(0),
  p_tks_num_prongs_(&tks_num_prongs_),
  b_tks_num_prongs_(tree_.Branch("tks_num_prongs", &p_tks_num_prongs_)),
  c_tks_num_prongs_(false),
  tks_tru_id_(0),
  p_tks_tru_id_(&tks_tru_id_),
  b_tks_tru_id_(tree_.Branch("tks_tru_id", &p_tks_tru_id_)),
  c_tks_tru_id_(false),
  mc_type_(0),
  b_mc_type_(tree_.Branch("mc_type", &mc_type_)),
  c_mc_type_(false){
}

small_tree_base::small_tree_base(const string &filename):
  chain_("tree","tree"),
  tree_("junk","junk"),
  entry_(0),
  read_only_(true),
  dphi_wlep_(0),
  b_dphi_wlep_(NULL),
  c_dphi_wlep_(false),
  ht_(0),
  b_ht_(NULL),
  c_ht_(false),
  met_(0),
  b_met_(NULL),
  c_met_(false),
  met_phi_(0),
  b_met_phi_(NULL),
  c_met_phi_(false),
  min_mt_bmet_(0),
  b_min_mt_bmet_(NULL),
  c_min_mt_bmet_(false),
  min_mt_bmet_with_w_mass_(0),
  b_min_mt_bmet_with_w_mass_(NULL),
  c_min_mt_bmet_with_w_mass_(false),
  mindphin_metjet_(0),
  b_mindphin_metjet_(NULL),
  c_mindphin_metjet_(false),
  mt_(0),
  b_mt_(NULL),
  c_mt_(false),
  ntrupv_mean_(0),
  b_ntrupv_mean_(NULL),
  c_ntrupv_mean_(false),
  weight_(0),
  b_weight_(NULL),
  c_weight_(false),
  event_(0),
  b_event_(NULL),
  c_event_(false),
  lumiblock_(0),
  b_lumiblock_(NULL),
  c_lumiblock_(false),
  nbl_(0),
  b_nbl_(NULL),
  c_nbl_(false),
  nbm_(0),
  b_nbm_(NULL),
  c_nbm_(false),
  nbt_(0),
  b_nbt_(NULL),
  c_nbt_(false),
  nels_(0),
  b_nels_(NULL),
  c_nels_(false),
  njets_(0),
  b_njets_(NULL),
  c_njets_(false),
  nleps_(0),
  b_nleps_(NULL),
  c_nleps_(false),
  nmus_(0),
  b_nmus_(NULL),
  c_nmus_(false),
  npv_(0),
  b_npv_(NULL),
  c_npv_(false),
  ntrupv_(0),
  b_ntrupv_(NULL),
  c_ntrupv_(false),
  nvels_(0),
  b_nvels_(NULL),
  c_nvels_(false),
  nvmus_(0),
  b_nvmus_(NULL),
  c_nvmus_(false),
  run_(0),
  b_run_(NULL),
  c_run_(false),
  els_ispf_(0),
  p_els_ispf_(&els_ispf_),
  b_els_ispf_(NULL),
  c_els_ispf_(false),
  els_sigid_(0),
  p_els_sigid_(&els_sigid_),
  b_els_sigid_(NULL),
  c_els_sigid_(false),
  els_tru_tm_(0),
  p_els_tru_tm_(&els_tru_tm_),
  b_els_tru_tm_(NULL),
  c_els_tru_tm_(false),
  mus_sigid_(0),
  p_mus_sigid_(&mus_sigid_),
  b_mus_sigid_(NULL),
  c_mus_sigid_(false),
  mus_tru_tm_(0),
  p_mus_tru_tm_(&mus_tru_tm_),
  b_mus_tru_tm_(NULL),
  c_mus_tru_tm_(false),
  tks_from_tau_(0),
  p_tks_from_tau_(&tks_from_tau_),
  b_tks_from_tau_(NULL),
  c_tks_from_tau_(false),
  tks_from_tauhad_(0),
  p_tks_from_tauhad_(&tks_from_tauhad_),
  b_tks_from_tauhad_(NULL),
  c_tks_from_tauhad_(false),
  tks_from_taulep_(0),
  p_tks_from_taulep_(&tks_from_taulep_),
  b_tks_from_taulep_(NULL),
  c_tks_from_taulep_(false),
  tks_from_w_(0),
  p_tks_from_w_(&tks_from_w_),
  b_tks_from_w_(NULL),
  c_tks_from_w_(false),
  els_eta_(0),
  p_els_eta_(&els_eta_),
  b_els_eta_(NULL),
  c_els_eta_(false),
  els_miniso_10_ch_(0),
  p_els_miniso_10_ch_(&els_miniso_10_ch_),
  b_els_miniso_10_ch_(NULL),
  c_els_miniso_10_ch_(false),
  els_miniso_tr10_(0),
  p_els_miniso_tr10_(&els_miniso_tr10_),
  b_els_miniso_tr10_(NULL),
  c_els_miniso_tr10_(false),
  els_miniso_tr10_pfpu_(0),
  p_els_miniso_tr10_pfpu_(&els_miniso_tr10_pfpu_),
  b_els_miniso_tr10_pfpu_(NULL),
  c_els_miniso_tr10_pfpu_(false),
  els_mt_(0),
  p_els_mt_(&els_mt_),
  b_els_mt_(NULL),
  c_els_mt_(false),
  els_phi_(0),
  p_els_phi_(&els_phi_),
  b_els_phi_(NULL),
  c_els_phi_(false),
  els_pt_(0),
  p_els_pt_(&els_pt_),
  b_els_pt_(NULL),
  c_els_pt_(false),
  els_reliso_(0),
  p_els_reliso_(&els_reliso_),
  b_els_reliso_(NULL),
  c_els_reliso_(false),
  els_reliso_r01_(0),
  p_els_reliso_r01_(&els_reliso_r01_),
  b_els_reliso_r01_(NULL),
  c_els_reliso_r01_(false),
  els_reliso_r015_(0),
  p_els_reliso_r015_(&els_reliso_r015_),
  b_els_reliso_r015_(NULL),
  c_els_reliso_r015_(false),
  els_reliso_r02_(0),
  p_els_reliso_r02_(&els_reliso_r02_),
  b_els_reliso_r02_(NULL),
  c_els_reliso_r02_(false),
  els_reliso_r03_(0),
  p_els_reliso_r03_(&els_reliso_r03_),
  b_els_reliso_r03_(NULL),
  c_els_reliso_r03_(false),
  els_reliso_r04_(0),
  p_els_reliso_r04_(&els_reliso_r04_),
  b_els_reliso_r04_(NULL),
  c_els_reliso_r04_(false),
  els_tru_dr_(0),
  p_els_tru_dr_(&els_tru_dr_),
  b_els_tru_dr_(NULL),
  c_els_tru_dr_(false),
  jets_csv_(0),
  p_jets_csv_(&jets_csv_),
  b_jets_csv_(NULL),
  c_jets_csv_(false),
  jets_eta_(0),
  p_jets_eta_(&jets_eta_),
  b_jets_eta_(NULL),
  c_jets_eta_(false),
  jets_id_(0),
  p_jets_id_(&jets_id_),
  b_jets_id_(NULL),
  c_jets_id_(false),
  jets_phi_(0),
  p_jets_phi_(&jets_phi_),
  b_jets_phi_(NULL),
  c_jets_phi_(false),
  jets_pt_(0),
  p_jets_pt_(&jets_pt_),
  b_jets_pt_(NULL),
  c_jets_pt_(false),
  mus_eta_(0),
  p_mus_eta_(&mus_eta_),
  b_mus_eta_(NULL),
  c_mus_eta_(false),
  mus_miniso_10_ch_(0),
  p_mus_miniso_10_ch_(&mus_miniso_10_ch_),
  b_mus_miniso_10_ch_(NULL),
  c_mus_miniso_10_ch_(false),
  mus_miniso_tr10_(0),
  p_mus_miniso_tr10_(&mus_miniso_tr10_),
  b_mus_miniso_tr10_(NULL),
  c_mus_miniso_tr10_(false),
  mus_miniso_tr10_pfpu_(0),
  p_mus_miniso_tr10_pfpu_(&mus_miniso_tr10_pfpu_),
  b_mus_miniso_tr10_pfpu_(NULL),
  c_mus_miniso_tr10_pfpu_(false),
  mus_mt_(0),
  p_mus_mt_(&mus_mt_),
  b_mus_mt_(NULL),
  c_mus_mt_(false),
  mus_phi_(0),
  p_mus_phi_(&mus_phi_),
  b_mus_phi_(NULL),
  c_mus_phi_(false),
  mus_pt_(0),
  p_mus_pt_(&mus_pt_),
  b_mus_pt_(NULL),
  c_mus_pt_(false),
  mus_reliso_(0),
  p_mus_reliso_(&mus_reliso_),
  b_mus_reliso_(NULL),
  c_mus_reliso_(false),
  mus_reliso_r01_(0),
  p_mus_reliso_r01_(&mus_reliso_r01_),
  b_mus_reliso_r01_(NULL),
  c_mus_reliso_r01_(false),
  mus_reliso_r015_(0),
  p_mus_reliso_r015_(&mus_reliso_r015_),
  b_mus_reliso_r015_(NULL),
  c_mus_reliso_r015_(false),
  mus_reliso_r02_(0),
  p_mus_reliso_r02_(&mus_reliso_r02_),
  b_mus_reliso_r02_(NULL),
  c_mus_reliso_r02_(false),
  mus_reliso_r03_(0),
  p_mus_reliso_r03_(&mus_reliso_r03_),
  b_mus_reliso_r03_(NULL),
  c_mus_reliso_r03_(false),
  mus_reliso_r04_(0),
  p_mus_reliso_r04_(&mus_reliso_r04_),
  b_mus_reliso_r04_(NULL),
  c_mus_reliso_r04_(false),
  mus_tru_dr_(0),
  p_mus_tru_dr_(&mus_tru_dr_),
  b_mus_tru_dr_(NULL),
  c_mus_tru_dr_(false),
  tks_eta_(0),
  p_tks_eta_(&tks_eta_),
  b_tks_eta_(NULL),
  c_tks_eta_(false),
  tks_mt_(0),
  p_tks_mt_(&tks_mt_),
  b_tks_mt_(NULL),
  c_tks_mt_(false),
  tks_phi_(0),
  p_tks_phi_(&tks_phi_),
  b_tks_phi_(NULL),
  c_tks_phi_(false),
  tks_pt_(0),
  p_tks_pt_(&tks_pt_),
  b_tks_pt_(NULL),
  c_tks_pt_(false),
  tks_r03_ch_(0),
  p_tks_r03_ch_(&tks_r03_ch_),
  b_tks_r03_ch_(NULL),
  c_tks_r03_ch_(false),
  tks_tru_dp_(0),
  p_tks_tru_dp_(&tks_tru_dp_),
  b_tks_tru_dp_(NULL),
  c_tks_tru_dp_(false),
  tks_tru_dr_(0),
  p_tks_tru_dr_(&tks_tru_dr_),
  b_tks_tru_dr_(NULL),
  c_tks_tru_dr_(false),
  els_charge_(0),
  p_els_charge_(&els_charge_),
  b_els_charge_(NULL),
  c_els_charge_(false),
  els_tru_id_(0),
  p_els_tru_id_(&els_tru_id_),
  b_els_tru_id_(NULL),
  c_els_tru_id_(false),
  els_tru_momid_(0),
  p_els_tru_momid_(&els_tru_momid_),
  b_els_tru_momid_(NULL),
  c_els_tru_momid_(false),
  mus_charge_(0),
  p_mus_charge_(&mus_charge_),
  b_mus_charge_(NULL),
  c_mus_charge_(false),
  mus_tru_id_(0),
  p_mus_tru_id_(&mus_tru_id_),
  b_mus_tru_id_(NULL),
  c_mus_tru_id_(false),
  mus_tru_momid_(0),
  p_mus_tru_momid_(&mus_tru_momid_),
  b_mus_tru_momid_(NULL),
  c_mus_tru_momid_(false),
  tks_from_pv_(0),
  p_tks_from_pv_(&tks_from_pv_),
  b_tks_from_pv_(NULL),
  c_tks_from_pv_(false),
  tks_id_(0),
  p_tks_id_(&tks_id_),
  b_tks_id_(NULL),
  c_tks_id_(false),
  tks_num_prongs_(0),
  p_tks_num_prongs_(&tks_num_prongs_),
  b_tks_num_prongs_(NULL),
  c_tks_num_prongs_(false),
  tks_tru_id_(0),
  p_tks_tru_id_(&tks_tru_id_),
  b_tks_tru_id_(NULL),
  c_tks_tru_id_(false),
  mc_type_(0),
  b_mc_type_(NULL),
  c_mc_type_(false){
  chain_.Add(filename.c_str());
  chain_.SetBranchAddress("dphi_wlep", &dphi_wlep_, &b_dphi_wlep_);
  chain_.SetBranchAddress("ht", &ht_, &b_ht_);
  chain_.SetBranchAddress("met", &met_, &b_met_);
  chain_.SetBranchAddress("met_phi", &met_phi_, &b_met_phi_);
  chain_.SetBranchAddress("min_mt_bmet", &min_mt_bmet_, &b_min_mt_bmet_);
  chain_.SetBranchAddress("min_mt_bmet_with_w_mass", &min_mt_bmet_with_w_mass_, &b_min_mt_bmet_with_w_mass_);
  chain_.SetBranchAddress("mindphin_metjet", &mindphin_metjet_, &b_mindphin_metjet_);
  chain_.SetBranchAddress("mt", &mt_, &b_mt_);
  chain_.SetBranchAddress("ntrupv_mean", &ntrupv_mean_, &b_ntrupv_mean_);
  chain_.SetBranchAddress("weight", &weight_, &b_weight_);
  chain_.SetBranchAddress("event", &event_, &b_event_);
  chain_.SetBranchAddress("lumiblock", &lumiblock_, &b_lumiblock_);
  chain_.SetBranchAddress("nbl", &nbl_, &b_nbl_);
  chain_.SetBranchAddress("nbm", &nbm_, &b_nbm_);
  chain_.SetBranchAddress("nbt", &nbt_, &b_nbt_);
  chain_.SetBranchAddress("nels", &nels_, &b_nels_);
  chain_.SetBranchAddress("njets", &njets_, &b_njets_);
  chain_.SetBranchAddress("nleps", &nleps_, &b_nleps_);
  chain_.SetBranchAddress("nmus", &nmus_, &b_nmus_);
  chain_.SetBranchAddress("npv", &npv_, &b_npv_);
  chain_.SetBranchAddress("ntrupv", &ntrupv_, &b_ntrupv_);
  chain_.SetBranchAddress("nvels", &nvels_, &b_nvels_);
  chain_.SetBranchAddress("nvmus", &nvmus_, &b_nvmus_);
  chain_.SetBranchAddress("run", &run_, &b_run_);
  chain_.SetBranchAddress("els_ispf", &p_els_ispf_, &b_els_ispf_);
  chain_.SetBranchAddress("els_sigid", &p_els_sigid_, &b_els_sigid_);
  chain_.SetBranchAddress("els_tru_tm", &p_els_tru_tm_, &b_els_tru_tm_);
  chain_.SetBranchAddress("mus_sigid", &p_mus_sigid_, &b_mus_sigid_);
  chain_.SetBranchAddress("mus_tru_tm", &p_mus_tru_tm_, &b_mus_tru_tm_);
  chain_.SetBranchAddress("tks_from_tau", &p_tks_from_tau_, &b_tks_from_tau_);
  chain_.SetBranchAddress("tks_from_tauhad", &p_tks_from_tauhad_, &b_tks_from_tauhad_);
  chain_.SetBranchAddress("tks_from_taulep", &p_tks_from_taulep_, &b_tks_from_taulep_);
  chain_.SetBranchAddress("tks_from_w", &p_tks_from_w_, &b_tks_from_w_);
  chain_.SetBranchAddress("els_eta", &p_els_eta_, &b_els_eta_);
  chain_.SetBranchAddress("els_miniso_10_ch", &p_els_miniso_10_ch_, &b_els_miniso_10_ch_);
  chain_.SetBranchAddress("els_miniso_tr10", &p_els_miniso_tr10_, &b_els_miniso_tr10_);
  chain_.SetBranchAddress("els_miniso_tr10_pfpu", &p_els_miniso_tr10_pfpu_, &b_els_miniso_tr10_pfpu_);
  chain_.SetBranchAddress("els_mt", &p_els_mt_, &b_els_mt_);
  chain_.SetBranchAddress("els_phi", &p_els_phi_, &b_els_phi_);
  chain_.SetBranchAddress("els_pt", &p_els_pt_, &b_els_pt_);
  chain_.SetBranchAddress("els_reliso", &p_els_reliso_, &b_els_reliso_);
  chain_.SetBranchAddress("els_reliso_r01", &p_els_reliso_r01_, &b_els_reliso_r01_);
  chain_.SetBranchAddress("els_reliso_r015", &p_els_reliso_r015_, &b_els_reliso_r015_);
  chain_.SetBranchAddress("els_reliso_r02", &p_els_reliso_r02_, &b_els_reliso_r02_);
  chain_.SetBranchAddress("els_reliso_r03", &p_els_reliso_r03_, &b_els_reliso_r03_);
  chain_.SetBranchAddress("els_reliso_r04", &p_els_reliso_r04_, &b_els_reliso_r04_);
  chain_.SetBranchAddress("els_tru_dr", &p_els_tru_dr_, &b_els_tru_dr_);
  chain_.SetBranchAddress("jets_csv", &p_jets_csv_, &b_jets_csv_);
  chain_.SetBranchAddress("jets_eta", &p_jets_eta_, &b_jets_eta_);
  chain_.SetBranchAddress("jets_id", &p_jets_id_, &b_jets_id_);
  chain_.SetBranchAddress("jets_phi", &p_jets_phi_, &b_jets_phi_);
  chain_.SetBranchAddress("jets_pt", &p_jets_pt_, &b_jets_pt_);
  chain_.SetBranchAddress("mus_eta", &p_mus_eta_, &b_mus_eta_);
  chain_.SetBranchAddress("mus_miniso_10_ch", &p_mus_miniso_10_ch_, &b_mus_miniso_10_ch_);
  chain_.SetBranchAddress("mus_miniso_tr10", &p_mus_miniso_tr10_, &b_mus_miniso_tr10_);
  chain_.SetBranchAddress("mus_miniso_tr10_pfpu", &p_mus_miniso_tr10_pfpu_, &b_mus_miniso_tr10_pfpu_);
  chain_.SetBranchAddress("mus_mt", &p_mus_mt_, &b_mus_mt_);
  chain_.SetBranchAddress("mus_phi", &p_mus_phi_, &b_mus_phi_);
  chain_.SetBranchAddress("mus_pt", &p_mus_pt_, &b_mus_pt_);
  chain_.SetBranchAddress("mus_reliso", &p_mus_reliso_, &b_mus_reliso_);
  chain_.SetBranchAddress("mus_reliso_r01", &p_mus_reliso_r01_, &b_mus_reliso_r01_);
  chain_.SetBranchAddress("mus_reliso_r015", &p_mus_reliso_r015_, &b_mus_reliso_r015_);
  chain_.SetBranchAddress("mus_reliso_r02", &p_mus_reliso_r02_, &b_mus_reliso_r02_);
  chain_.SetBranchAddress("mus_reliso_r03", &p_mus_reliso_r03_, &b_mus_reliso_r03_);
  chain_.SetBranchAddress("mus_reliso_r04", &p_mus_reliso_r04_, &b_mus_reliso_r04_);
  chain_.SetBranchAddress("mus_tru_dr", &p_mus_tru_dr_, &b_mus_tru_dr_);
  chain_.SetBranchAddress("tks_eta", &p_tks_eta_, &b_tks_eta_);
  chain_.SetBranchAddress("tks_mt", &p_tks_mt_, &b_tks_mt_);
  chain_.SetBranchAddress("tks_phi", &p_tks_phi_, &b_tks_phi_);
  chain_.SetBranchAddress("tks_pt", &p_tks_pt_, &b_tks_pt_);
  chain_.SetBranchAddress("tks_r03_ch", &p_tks_r03_ch_, &b_tks_r03_ch_);
  chain_.SetBranchAddress("tks_tru_dp", &p_tks_tru_dp_, &b_tks_tru_dp_);
  chain_.SetBranchAddress("tks_tru_dr", &p_tks_tru_dr_, &b_tks_tru_dr_);
  chain_.SetBranchAddress("els_charge", &p_els_charge_, &b_els_charge_);
  chain_.SetBranchAddress("els_tru_id", &p_els_tru_id_, &b_els_tru_id_);
  chain_.SetBranchAddress("els_tru_momid", &p_els_tru_momid_, &b_els_tru_momid_);
  chain_.SetBranchAddress("mus_charge", &p_mus_charge_, &b_mus_charge_);
  chain_.SetBranchAddress("mus_tru_id", &p_mus_tru_id_, &b_mus_tru_id_);
  chain_.SetBranchAddress("mus_tru_momid", &p_mus_tru_momid_, &b_mus_tru_momid_);
  chain_.SetBranchAddress("tks_from_pv", &p_tks_from_pv_, &b_tks_from_pv_);
  chain_.SetBranchAddress("tks_id", &p_tks_id_, &b_tks_id_);
  chain_.SetBranchAddress("tks_num_prongs", &p_tks_num_prongs_, &b_tks_num_prongs_);
  chain_.SetBranchAddress("tks_tru_id", &p_tks_tru_id_, &b_tks_tru_id_);
  chain_.SetBranchAddress("mc_type", &mc_type_, &b_mc_type_);
}

void small_tree_base::Fill(){
  if(read_only_){
    throw std::logic_error("Trying to write to read-only tree");
  }else{
    tree_.Fill();
  }

  //Resetting variables
  dphi_wlep_ = static_cast<float>(bad_val_);
  ht_ = static_cast<float>(bad_val_);
  met_ = static_cast<float>(bad_val_);
  met_phi_ = static_cast<float>(bad_val_);
  min_mt_bmet_ = static_cast<float>(bad_val_);
  min_mt_bmet_with_w_mass_ = static_cast<float>(bad_val_);
  mindphin_metjet_ = static_cast<float>(bad_val_);
  mt_ = static_cast<float>(bad_val_);
  ntrupv_mean_ = static_cast<float>(bad_val_);
  weight_ = static_cast<float>(bad_val_);
  event_ = static_cast<int>(bad_val_);
  lumiblock_ = static_cast<int>(bad_val_);
  nbl_ = static_cast<int>(bad_val_);
  nbm_ = static_cast<int>(bad_val_);
  nbt_ = static_cast<int>(bad_val_);
  nels_ = static_cast<int>(bad_val_);
  njets_ = static_cast<int>(bad_val_);
  nleps_ = static_cast<int>(bad_val_);
  nmus_ = static_cast<int>(bad_val_);
  npv_ = static_cast<int>(bad_val_);
  ntrupv_ = static_cast<int>(bad_val_);
  nvels_ = static_cast<int>(bad_val_);
  nvmus_ = static_cast<int>(bad_val_);
  run_ = static_cast<int>(bad_val_);
  els_ispf_.clear();
  els_sigid_.clear();
  els_tru_tm_.clear();
  mus_sigid_.clear();
  mus_tru_tm_.clear();
  tks_from_tau_.clear();
  tks_from_tauhad_.clear();
  tks_from_taulep_.clear();
  tks_from_w_.clear();
  els_eta_.clear();
  els_miniso_10_ch_.clear();
  els_miniso_tr10_.clear();
  els_miniso_tr10_pfpu_.clear();
  els_mt_.clear();
  els_phi_.clear();
  els_pt_.clear();
  els_reliso_.clear();
  els_reliso_r01_.clear();
  els_reliso_r015_.clear();
  els_reliso_r02_.clear();
  els_reliso_r03_.clear();
  els_reliso_r04_.clear();
  els_tru_dr_.clear();
  jets_csv_.clear();
  jets_eta_.clear();
  jets_id_.clear();
  jets_phi_.clear();
  jets_pt_.clear();
  mus_eta_.clear();
  mus_miniso_10_ch_.clear();
  mus_miniso_tr10_.clear();
  mus_miniso_tr10_pfpu_.clear();
  mus_mt_.clear();
  mus_phi_.clear();
  mus_pt_.clear();
  mus_reliso_.clear();
  mus_reliso_r01_.clear();
  mus_reliso_r015_.clear();
  mus_reliso_r02_.clear();
  mus_reliso_r03_.clear();
  mus_reliso_r04_.clear();
  mus_tru_dr_.clear();
  tks_eta_.clear();
  tks_mt_.clear();
  tks_phi_.clear();
  tks_pt_.clear();
  tks_r03_ch_.clear();
  tks_tru_dp_.clear();
  tks_tru_dr_.clear();
  els_charge_.clear();
  els_tru_id_.clear();
  els_tru_momid_.clear();
  mus_charge_.clear();
  mus_tru_id_.clear();
  mus_tru_momid_.clear();
  tks_from_pv_.clear();
  tks_id_.clear();
  tks_num_prongs_.clear();
  tks_tru_id_.clear();
  mc_type_ = static_cast<unsigned>(bad_val_);
}

void small_tree_base::Write(){
  if(read_only_){
    throw std::logic_error("Trying to write to read-only tree.");
  }else{
    tree_.Write();
  }
}

string small_tree_base::Type() const{
  return "";
}

small_tree_base::~small_tree_base(){
}

int small_tree_base::Add(const std::string &filename){
  if(!read_only_){
    throw std::logic_error("Trying to add files to tree opened for writing.");
  }
  return chain_.Add(filename.c_str());
}

long small_tree_base::GetEntries() const{
  if(read_only_){
    return chain_.GetEntries();
  }else{
    return tree_.GetEntries();
  }
}

void small_tree_base::GetEntry(const long entry){
  if(!read_only_){
    throw std::logic_error("Trying to read from write-only tree.");
  }

  c_dphi_wlep_ = false;
  c_ht_ = false;
  c_met_ = false;
  c_met_phi_ = false;
  c_min_mt_bmet_ = false;
  c_min_mt_bmet_with_w_mass_ = false;
  c_mindphin_metjet_ = false;
  c_mt_ = false;
  c_ntrupv_mean_ = false;
  c_weight_ = false;
  c_event_ = false;
  c_lumiblock_ = false;
  c_nbl_ = false;
  c_nbm_ = false;
  c_nbt_ = false;
  c_nels_ = false;
  c_njets_ = false;
  c_nleps_ = false;
  c_nmus_ = false;
  c_npv_ = false;
  c_ntrupv_ = false;
  c_nvels_ = false;
  c_nvmus_ = false;
  c_run_ = false;
  c_els_ispf_ = false;
  c_els_sigid_ = false;
  c_els_tru_tm_ = false;
  c_mus_sigid_ = false;
  c_mus_tru_tm_ = false;
  c_tks_from_tau_ = false;
  c_tks_from_tauhad_ = false;
  c_tks_from_taulep_ = false;
  c_tks_from_w_ = false;
  c_els_eta_ = false;
  c_els_miniso_10_ch_ = false;
  c_els_miniso_tr10_ = false;
  c_els_miniso_tr10_pfpu_ = false;
  c_els_mt_ = false;
  c_els_phi_ = false;
  c_els_pt_ = false;
  c_els_reliso_ = false;
  c_els_reliso_r01_ = false;
  c_els_reliso_r015_ = false;
  c_els_reliso_r02_ = false;
  c_els_reliso_r03_ = false;
  c_els_reliso_r04_ = false;
  c_els_tru_dr_ = false;
  c_jets_csv_ = false;
  c_jets_eta_ = false;
  c_jets_id_ = false;
  c_jets_phi_ = false;
  c_jets_pt_ = false;
  c_mus_eta_ = false;
  c_mus_miniso_10_ch_ = false;
  c_mus_miniso_tr10_ = false;
  c_mus_miniso_tr10_pfpu_ = false;
  c_mus_mt_ = false;
  c_mus_phi_ = false;
  c_mus_pt_ = false;
  c_mus_reliso_ = false;
  c_mus_reliso_r01_ = false;
  c_mus_reliso_r015_ = false;
  c_mus_reliso_r02_ = false;
  c_mus_reliso_r03_ = false;
  c_mus_reliso_r04_ = false;
  c_mus_tru_dr_ = false;
  c_tks_eta_ = false;
  c_tks_mt_ = false;
  c_tks_phi_ = false;
  c_tks_pt_ = false;
  c_tks_r03_ch_ = false;
  c_tks_tru_dp_ = false;
  c_tks_tru_dr_ = false;
  c_els_charge_ = false;
  c_els_tru_id_ = false;
  c_els_tru_momid_ = false;
  c_mus_charge_ = false;
  c_mus_tru_id_ = false;
  c_mus_tru_momid_ = false;
  c_tks_from_pv_ = false;
  c_tks_id_ = false;
  c_tks_num_prongs_ = false;
  c_tks_tru_id_ = false;
  c_mc_type_ = false;
  entry_ = chain_.LoadTree(entry);
}

float const & small_tree_base::dphi_wlep() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_dphi_wlep_ && b_dphi_wlep_){
    b_dphi_wlep_->GetEntry(entry_);
    c_dphi_wlep_ = true;
  }
  return dphi_wlep_;
}

float const & small_tree_base::ht() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_ht_ && b_ht_){
    b_ht_->GetEntry(entry_);
    c_ht_ = true;
  }
  return ht_;
}

float const & small_tree_base::met() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_met_ && b_met_){
    b_met_->GetEntry(entry_);
    c_met_ = true;
  }
  return met_;
}

float const & small_tree_base::met_phi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_met_phi_ && b_met_phi_){
    b_met_phi_->GetEntry(entry_);
    c_met_phi_ = true;
  }
  return met_phi_;
}

float const & small_tree_base::min_mt_bmet() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_min_mt_bmet_ && b_min_mt_bmet_){
    b_min_mt_bmet_->GetEntry(entry_);
    c_min_mt_bmet_ = true;
  }
  return min_mt_bmet_;
}

float const & small_tree_base::min_mt_bmet_with_w_mass() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_min_mt_bmet_with_w_mass_ && b_min_mt_bmet_with_w_mass_){
    b_min_mt_bmet_with_w_mass_->GetEntry(entry_);
    c_min_mt_bmet_with_w_mass_ = true;
  }
  return min_mt_bmet_with_w_mass_;
}

float const & small_tree_base::mindphin_metjet() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mindphin_metjet_ && b_mindphin_metjet_){
    b_mindphin_metjet_->GetEntry(entry_);
    c_mindphin_metjet_ = true;
  }
  return mindphin_metjet_;
}

float const & small_tree_base::mt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mt_ && b_mt_){
    b_mt_->GetEntry(entry_);
    c_mt_ = true;
  }
  return mt_;
}

float const & small_tree_base::ntrupv_mean() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_ntrupv_mean_ && b_ntrupv_mean_){
    b_ntrupv_mean_->GetEntry(entry_);
    c_ntrupv_mean_ = true;
  }
  return ntrupv_mean_;
}

float const & small_tree_base::weight() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_weight_ && b_weight_){
    b_weight_->GetEntry(entry_);
    c_weight_ = true;
  }
  return weight_;
}

int const & small_tree_base::event() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_event_ && b_event_){
    b_event_->GetEntry(entry_);
    c_event_ = true;
  }
  return event_;
}

int const & small_tree_base::lumiblock() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_lumiblock_ && b_lumiblock_){
    b_lumiblock_->GetEntry(entry_);
    c_lumiblock_ = true;
  }
  return lumiblock_;
}

int const & small_tree_base::nbl() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nbl_ && b_nbl_){
    b_nbl_->GetEntry(entry_);
    c_nbl_ = true;
  }
  return nbl_;
}

int const & small_tree_base::nbm() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nbm_ && b_nbm_){
    b_nbm_->GetEntry(entry_);
    c_nbm_ = true;
  }
  return nbm_;
}

int const & small_tree_base::nbt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nbt_ && b_nbt_){
    b_nbt_->GetEntry(entry_);
    c_nbt_ = true;
  }
  return nbt_;
}

int const & small_tree_base::nels() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nels_ && b_nels_){
    b_nels_->GetEntry(entry_);
    c_nels_ = true;
  }
  return nels_;
}

int const & small_tree_base::njets() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_njets_ && b_njets_){
    b_njets_->GetEntry(entry_);
    c_njets_ = true;
  }
  return njets_;
}

int const & small_tree_base::nleps() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nleps_ && b_nleps_){
    b_nleps_->GetEntry(entry_);
    c_nleps_ = true;
  }
  return nleps_;
}

int const & small_tree_base::nmus() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nmus_ && b_nmus_){
    b_nmus_->GetEntry(entry_);
    c_nmus_ = true;
  }
  return nmus_;
}

int const & small_tree_base::npv() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_npv_ && b_npv_){
    b_npv_->GetEntry(entry_);
    c_npv_ = true;
  }
  return npv_;
}

int const & small_tree_base::ntrupv() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_ntrupv_ && b_ntrupv_){
    b_ntrupv_->GetEntry(entry_);
    c_ntrupv_ = true;
  }
  return ntrupv_;
}

int const & small_tree_base::nvels() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nvels_ && b_nvels_){
    b_nvels_->GetEntry(entry_);
    c_nvels_ = true;
  }
  return nvels_;
}

int const & small_tree_base::nvmus() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_nvmus_ && b_nvmus_){
    b_nvmus_->GetEntry(entry_);
    c_nvmus_ = true;
  }
  return nvmus_;
}

int const & small_tree_base::run() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_run_ && b_run_){
    b_run_->GetEntry(entry_);
    c_run_ = true;
  }
  return run_;
}

std::vector<bool> const & small_tree_base::els_ispf() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_ispf_ && b_els_ispf_){
    b_els_ispf_->GetEntry(entry_);
    c_els_ispf_ = true;
  }
  return els_ispf_;
}

std::vector<bool> const & small_tree_base::els_sigid() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_sigid_ && b_els_sigid_){
    b_els_sigid_->GetEntry(entry_);
    c_els_sigid_ = true;
  }
  return els_sigid_;
}

std::vector<bool> const & small_tree_base::els_tru_tm() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_tru_tm_ && b_els_tru_tm_){
    b_els_tru_tm_->GetEntry(entry_);
    c_els_tru_tm_ = true;
  }
  return els_tru_tm_;
}

std::vector<bool> const & small_tree_base::mus_sigid() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_sigid_ && b_mus_sigid_){
    b_mus_sigid_->GetEntry(entry_);
    c_mus_sigid_ = true;
  }
  return mus_sigid_;
}

std::vector<bool> const & small_tree_base::mus_tru_tm() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_tru_tm_ && b_mus_tru_tm_){
    b_mus_tru_tm_->GetEntry(entry_);
    c_mus_tru_tm_ = true;
  }
  return mus_tru_tm_;
}

std::vector<bool> const & small_tree_base::tks_from_tau() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_from_tau_ && b_tks_from_tau_){
    b_tks_from_tau_->GetEntry(entry_);
    c_tks_from_tau_ = true;
  }
  return tks_from_tau_;
}

std::vector<bool> const & small_tree_base::tks_from_tauhad() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_from_tauhad_ && b_tks_from_tauhad_){
    b_tks_from_tauhad_->GetEntry(entry_);
    c_tks_from_tauhad_ = true;
  }
  return tks_from_tauhad_;
}

std::vector<bool> const & small_tree_base::tks_from_taulep() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_from_taulep_ && b_tks_from_taulep_){
    b_tks_from_taulep_->GetEntry(entry_);
    c_tks_from_taulep_ = true;
  }
  return tks_from_taulep_;
}

std::vector<bool> const & small_tree_base::tks_from_w() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_from_w_ && b_tks_from_w_){
    b_tks_from_w_->GetEntry(entry_);
    c_tks_from_w_ = true;
  }
  return tks_from_w_;
}

std::vector<float> const & small_tree_base::els_eta() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_eta_ && b_els_eta_){
    b_els_eta_->GetEntry(entry_);
    c_els_eta_ = true;
  }
  return els_eta_;
}

std::vector<float> const & small_tree_base::els_miniso_10_ch() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_miniso_10_ch_ && b_els_miniso_10_ch_){
    b_els_miniso_10_ch_->GetEntry(entry_);
    c_els_miniso_10_ch_ = true;
  }
  return els_miniso_10_ch_;
}

std::vector<float> const & small_tree_base::els_miniso_tr10() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_miniso_tr10_ && b_els_miniso_tr10_){
    b_els_miniso_tr10_->GetEntry(entry_);
    c_els_miniso_tr10_ = true;
  }
  return els_miniso_tr10_;
}

std::vector<float> const & small_tree_base::els_miniso_tr10_pfpu() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_miniso_tr10_pfpu_ && b_els_miniso_tr10_pfpu_){
    b_els_miniso_tr10_pfpu_->GetEntry(entry_);
    c_els_miniso_tr10_pfpu_ = true;
  }
  return els_miniso_tr10_pfpu_;
}

std::vector<float> const & small_tree_base::els_mt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_mt_ && b_els_mt_){
    b_els_mt_->GetEntry(entry_);
    c_els_mt_ = true;
  }
  return els_mt_;
}

std::vector<float> const & small_tree_base::els_phi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_phi_ && b_els_phi_){
    b_els_phi_->GetEntry(entry_);
    c_els_phi_ = true;
  }
  return els_phi_;
}

std::vector<float> const & small_tree_base::els_pt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_pt_ && b_els_pt_){
    b_els_pt_->GetEntry(entry_);
    c_els_pt_ = true;
  }
  return els_pt_;
}

std::vector<float> const & small_tree_base::els_reliso() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_reliso_ && b_els_reliso_){
    b_els_reliso_->GetEntry(entry_);
    c_els_reliso_ = true;
  }
  return els_reliso_;
}

std::vector<float> const & small_tree_base::els_reliso_r01() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_reliso_r01_ && b_els_reliso_r01_){
    b_els_reliso_r01_->GetEntry(entry_);
    c_els_reliso_r01_ = true;
  }
  return els_reliso_r01_;
}

std::vector<float> const & small_tree_base::els_reliso_r015() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_reliso_r015_ && b_els_reliso_r015_){
    b_els_reliso_r015_->GetEntry(entry_);
    c_els_reliso_r015_ = true;
  }
  return els_reliso_r015_;
}

std::vector<float> const & small_tree_base::els_reliso_r02() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_reliso_r02_ && b_els_reliso_r02_){
    b_els_reliso_r02_->GetEntry(entry_);
    c_els_reliso_r02_ = true;
  }
  return els_reliso_r02_;
}

std::vector<float> const & small_tree_base::els_reliso_r03() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_reliso_r03_ && b_els_reliso_r03_){
    b_els_reliso_r03_->GetEntry(entry_);
    c_els_reliso_r03_ = true;
  }
  return els_reliso_r03_;
}

std::vector<float> const & small_tree_base::els_reliso_r04() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_reliso_r04_ && b_els_reliso_r04_){
    b_els_reliso_r04_->GetEntry(entry_);
    c_els_reliso_r04_ = true;
  }
  return els_reliso_r04_;
}

std::vector<float> const & small_tree_base::els_tru_dr() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_tru_dr_ && b_els_tru_dr_){
    b_els_tru_dr_->GetEntry(entry_);
    c_els_tru_dr_ = true;
  }
  return els_tru_dr_;
}

std::vector<float> const & small_tree_base::jets_csv() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_jets_csv_ && b_jets_csv_){
    b_jets_csv_->GetEntry(entry_);
    c_jets_csv_ = true;
  }
  return jets_csv_;
}

std::vector<float> const & small_tree_base::jets_eta() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_jets_eta_ && b_jets_eta_){
    b_jets_eta_->GetEntry(entry_);
    c_jets_eta_ = true;
  }
  return jets_eta_;
}

std::vector<float> const & small_tree_base::jets_id() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_jets_id_ && b_jets_id_){
    b_jets_id_->GetEntry(entry_);
    c_jets_id_ = true;
  }
  return jets_id_;
}

std::vector<float> const & small_tree_base::jets_phi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_jets_phi_ && b_jets_phi_){
    b_jets_phi_->GetEntry(entry_);
    c_jets_phi_ = true;
  }
  return jets_phi_;
}

std::vector<float> const & small_tree_base::jets_pt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_jets_pt_ && b_jets_pt_){
    b_jets_pt_->GetEntry(entry_);
    c_jets_pt_ = true;
  }
  return jets_pt_;
}

std::vector<float> const & small_tree_base::mus_eta() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_eta_ && b_mus_eta_){
    b_mus_eta_->GetEntry(entry_);
    c_mus_eta_ = true;
  }
  return mus_eta_;
}

std::vector<float> const & small_tree_base::mus_miniso_10_ch() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_miniso_10_ch_ && b_mus_miniso_10_ch_){
    b_mus_miniso_10_ch_->GetEntry(entry_);
    c_mus_miniso_10_ch_ = true;
  }
  return mus_miniso_10_ch_;
}

std::vector<float> const & small_tree_base::mus_miniso_tr10() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_miniso_tr10_ && b_mus_miniso_tr10_){
    b_mus_miniso_tr10_->GetEntry(entry_);
    c_mus_miniso_tr10_ = true;
  }
  return mus_miniso_tr10_;
}

std::vector<float> const & small_tree_base::mus_miniso_tr10_pfpu() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_miniso_tr10_pfpu_ && b_mus_miniso_tr10_pfpu_){
    b_mus_miniso_tr10_pfpu_->GetEntry(entry_);
    c_mus_miniso_tr10_pfpu_ = true;
  }
  return mus_miniso_tr10_pfpu_;
}

std::vector<float> const & small_tree_base::mus_mt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_mt_ && b_mus_mt_){
    b_mus_mt_->GetEntry(entry_);
    c_mus_mt_ = true;
  }
  return mus_mt_;
}

std::vector<float> const & small_tree_base::mus_phi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_phi_ && b_mus_phi_){
    b_mus_phi_->GetEntry(entry_);
    c_mus_phi_ = true;
  }
  return mus_phi_;
}

std::vector<float> const & small_tree_base::mus_pt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_pt_ && b_mus_pt_){
    b_mus_pt_->GetEntry(entry_);
    c_mus_pt_ = true;
  }
  return mus_pt_;
}

std::vector<float> const & small_tree_base::mus_reliso() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_reliso_ && b_mus_reliso_){
    b_mus_reliso_->GetEntry(entry_);
    c_mus_reliso_ = true;
  }
  return mus_reliso_;
}

std::vector<float> const & small_tree_base::mus_reliso_r01() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_reliso_r01_ && b_mus_reliso_r01_){
    b_mus_reliso_r01_->GetEntry(entry_);
    c_mus_reliso_r01_ = true;
  }
  return mus_reliso_r01_;
}

std::vector<float> const & small_tree_base::mus_reliso_r015() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_reliso_r015_ && b_mus_reliso_r015_){
    b_mus_reliso_r015_->GetEntry(entry_);
    c_mus_reliso_r015_ = true;
  }
  return mus_reliso_r015_;
}

std::vector<float> const & small_tree_base::mus_reliso_r02() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_reliso_r02_ && b_mus_reliso_r02_){
    b_mus_reliso_r02_->GetEntry(entry_);
    c_mus_reliso_r02_ = true;
  }
  return mus_reliso_r02_;
}

std::vector<float> const & small_tree_base::mus_reliso_r03() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_reliso_r03_ && b_mus_reliso_r03_){
    b_mus_reliso_r03_->GetEntry(entry_);
    c_mus_reliso_r03_ = true;
  }
  return mus_reliso_r03_;
}

std::vector<float> const & small_tree_base::mus_reliso_r04() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_reliso_r04_ && b_mus_reliso_r04_){
    b_mus_reliso_r04_->GetEntry(entry_);
    c_mus_reliso_r04_ = true;
  }
  return mus_reliso_r04_;
}

std::vector<float> const & small_tree_base::mus_tru_dr() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_tru_dr_ && b_mus_tru_dr_){
    b_mus_tru_dr_->GetEntry(entry_);
    c_mus_tru_dr_ = true;
  }
  return mus_tru_dr_;
}

std::vector<float> const & small_tree_base::tks_eta() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_eta_ && b_tks_eta_){
    b_tks_eta_->GetEntry(entry_);
    c_tks_eta_ = true;
  }
  return tks_eta_;
}

std::vector<float> const & small_tree_base::tks_mt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_mt_ && b_tks_mt_){
    b_tks_mt_->GetEntry(entry_);
    c_tks_mt_ = true;
  }
  return tks_mt_;
}

std::vector<float> const & small_tree_base::tks_phi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_phi_ && b_tks_phi_){
    b_tks_phi_->GetEntry(entry_);
    c_tks_phi_ = true;
  }
  return tks_phi_;
}

std::vector<float> const & small_tree_base::tks_pt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_pt_ && b_tks_pt_){
    b_tks_pt_->GetEntry(entry_);
    c_tks_pt_ = true;
  }
  return tks_pt_;
}

std::vector<float> const & small_tree_base::tks_r03_ch() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_r03_ch_ && b_tks_r03_ch_){
    b_tks_r03_ch_->GetEntry(entry_);
    c_tks_r03_ch_ = true;
  }
  return tks_r03_ch_;
}

std::vector<float> const & small_tree_base::tks_tru_dp() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_tru_dp_ && b_tks_tru_dp_){
    b_tks_tru_dp_->GetEntry(entry_);
    c_tks_tru_dp_ = true;
  }
  return tks_tru_dp_;
}

std::vector<float> const & small_tree_base::tks_tru_dr() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_tru_dr_ && b_tks_tru_dr_){
    b_tks_tru_dr_->GetEntry(entry_);
    c_tks_tru_dr_ = true;
  }
  return tks_tru_dr_;
}

std::vector<int> const & small_tree_base::els_charge() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_charge_ && b_els_charge_){
    b_els_charge_->GetEntry(entry_);
    c_els_charge_ = true;
  }
  return els_charge_;
}

std::vector<int> const & small_tree_base::els_tru_id() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_tru_id_ && b_els_tru_id_){
    b_els_tru_id_->GetEntry(entry_);
    c_els_tru_id_ = true;
  }
  return els_tru_id_;
}

std::vector<int> const & small_tree_base::els_tru_momid() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_els_tru_momid_ && b_els_tru_momid_){
    b_els_tru_momid_->GetEntry(entry_);
    c_els_tru_momid_ = true;
  }
  return els_tru_momid_;
}

std::vector<int> const & small_tree_base::mus_charge() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_charge_ && b_mus_charge_){
    b_mus_charge_->GetEntry(entry_);
    c_mus_charge_ = true;
  }
  return mus_charge_;
}

std::vector<int> const & small_tree_base::mus_tru_id() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_tru_id_ && b_mus_tru_id_){
    b_mus_tru_id_->GetEntry(entry_);
    c_mus_tru_id_ = true;
  }
  return mus_tru_id_;
}

std::vector<int> const & small_tree_base::mus_tru_momid() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mus_tru_momid_ && b_mus_tru_momid_){
    b_mus_tru_momid_->GetEntry(entry_);
    c_mus_tru_momid_ = true;
  }
  return mus_tru_momid_;
}

std::vector<int> const & small_tree_base::tks_from_pv() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_from_pv_ && b_tks_from_pv_){
    b_tks_from_pv_->GetEntry(entry_);
    c_tks_from_pv_ = true;
  }
  return tks_from_pv_;
}

std::vector<int> const & small_tree_base::tks_id() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_id_ && b_tks_id_){
    b_tks_id_->GetEntry(entry_);
    c_tks_id_ = true;
  }
  return tks_id_;
}

std::vector<int> const & small_tree_base::tks_num_prongs() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_num_prongs_ && b_tks_num_prongs_){
    b_tks_num_prongs_->GetEntry(entry_);
    c_tks_num_prongs_ = true;
  }
  return tks_num_prongs_;
}

std::vector<int> const & small_tree_base::tks_tru_id() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_tks_tru_id_ && b_tks_tru_id_){
    b_tks_tru_id_->GetEntry(entry_);
    c_tks_tru_id_ = true;
  }
  return tks_tru_id_;
}

unsigned const & small_tree_base::mc_type() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_mc_type_ && b_mc_type_){
    b_mc_type_->GetEntry(entry_);
    c_mc_type_ = true;
  }
  return mc_type_;
}

float & small_tree_base::dphi_wlep(){
  if(read_only_ && !c_dphi_wlep_ && b_dphi_wlep_){
    b_dphi_wlep_->GetEntry(entry_);
    c_dphi_wlep_ = true;
  }
  return dphi_wlep_;
}

float & small_tree_base::ht(){
  if(read_only_ && !c_ht_ && b_ht_){
    b_ht_->GetEntry(entry_);
    c_ht_ = true;
  }
  return ht_;
}

float & small_tree_base::met(){
  if(read_only_ && !c_met_ && b_met_){
    b_met_->GetEntry(entry_);
    c_met_ = true;
  }
  return met_;
}

float & small_tree_base::met_phi(){
  if(read_only_ && !c_met_phi_ && b_met_phi_){
    b_met_phi_->GetEntry(entry_);
    c_met_phi_ = true;
  }
  return met_phi_;
}

float & small_tree_base::min_mt_bmet(){
  if(read_only_ && !c_min_mt_bmet_ && b_min_mt_bmet_){
    b_min_mt_bmet_->GetEntry(entry_);
    c_min_mt_bmet_ = true;
  }
  return min_mt_bmet_;
}

float & small_tree_base::min_mt_bmet_with_w_mass(){
  if(read_only_ && !c_min_mt_bmet_with_w_mass_ && b_min_mt_bmet_with_w_mass_){
    b_min_mt_bmet_with_w_mass_->GetEntry(entry_);
    c_min_mt_bmet_with_w_mass_ = true;
  }
  return min_mt_bmet_with_w_mass_;
}

float & small_tree_base::mindphin_metjet(){
  if(read_only_ && !c_mindphin_metjet_ && b_mindphin_metjet_){
    b_mindphin_metjet_->GetEntry(entry_);
    c_mindphin_metjet_ = true;
  }
  return mindphin_metjet_;
}

float & small_tree_base::mt(){
  if(read_only_ && !c_mt_ && b_mt_){
    b_mt_->GetEntry(entry_);
    c_mt_ = true;
  }
  return mt_;
}

float & small_tree_base::ntrupv_mean(){
  if(read_only_ && !c_ntrupv_mean_ && b_ntrupv_mean_){
    b_ntrupv_mean_->GetEntry(entry_);
    c_ntrupv_mean_ = true;
  }
  return ntrupv_mean_;
}

float & small_tree_base::weight(){
  if(read_only_ && !c_weight_ && b_weight_){
    b_weight_->GetEntry(entry_);
    c_weight_ = true;
  }
  return weight_;
}

int & small_tree_base::event(){
  if(read_only_ && !c_event_ && b_event_){
    b_event_->GetEntry(entry_);
    c_event_ = true;
  }
  return event_;
}

int & small_tree_base::lumiblock(){
  if(read_only_ && !c_lumiblock_ && b_lumiblock_){
    b_lumiblock_->GetEntry(entry_);
    c_lumiblock_ = true;
  }
  return lumiblock_;
}

int & small_tree_base::nbl(){
  if(read_only_ && !c_nbl_ && b_nbl_){
    b_nbl_->GetEntry(entry_);
    c_nbl_ = true;
  }
  return nbl_;
}

int & small_tree_base::nbm(){
  if(read_only_ && !c_nbm_ && b_nbm_){
    b_nbm_->GetEntry(entry_);
    c_nbm_ = true;
  }
  return nbm_;
}

int & small_tree_base::nbt(){
  if(read_only_ && !c_nbt_ && b_nbt_){
    b_nbt_->GetEntry(entry_);
    c_nbt_ = true;
  }
  return nbt_;
}

int & small_tree_base::nels(){
  if(read_only_ && !c_nels_ && b_nels_){
    b_nels_->GetEntry(entry_);
    c_nels_ = true;
  }
  return nels_;
}

int & small_tree_base::njets(){
  if(read_only_ && !c_njets_ && b_njets_){
    b_njets_->GetEntry(entry_);
    c_njets_ = true;
  }
  return njets_;
}

int & small_tree_base::nleps(){
  if(read_only_ && !c_nleps_ && b_nleps_){
    b_nleps_->GetEntry(entry_);
    c_nleps_ = true;
  }
  return nleps_;
}

int & small_tree_base::nmus(){
  if(read_only_ && !c_nmus_ && b_nmus_){
    b_nmus_->GetEntry(entry_);
    c_nmus_ = true;
  }
  return nmus_;
}

int & small_tree_base::npv(){
  if(read_only_ && !c_npv_ && b_npv_){
    b_npv_->GetEntry(entry_);
    c_npv_ = true;
  }
  return npv_;
}

int & small_tree_base::ntrupv(){
  if(read_only_ && !c_ntrupv_ && b_ntrupv_){
    b_ntrupv_->GetEntry(entry_);
    c_ntrupv_ = true;
  }
  return ntrupv_;
}

int & small_tree_base::nvels(){
  if(read_only_ && !c_nvels_ && b_nvels_){
    b_nvels_->GetEntry(entry_);
    c_nvels_ = true;
  }
  return nvels_;
}

int & small_tree_base::nvmus(){
  if(read_only_ && !c_nvmus_ && b_nvmus_){
    b_nvmus_->GetEntry(entry_);
    c_nvmus_ = true;
  }
  return nvmus_;
}

int & small_tree_base::run(){
  if(read_only_ && !c_run_ && b_run_){
    b_run_->GetEntry(entry_);
    c_run_ = true;
  }
  return run_;
}

std::vector<bool> & small_tree_base::els_ispf(){
  if(read_only_ && !c_els_ispf_ && b_els_ispf_){
    b_els_ispf_->GetEntry(entry_);
    c_els_ispf_ = true;
  }
  return els_ispf_;
}

std::vector<bool> & small_tree_base::els_sigid(){
  if(read_only_ && !c_els_sigid_ && b_els_sigid_){
    b_els_sigid_->GetEntry(entry_);
    c_els_sigid_ = true;
  }
  return els_sigid_;
}

std::vector<bool> & small_tree_base::els_tru_tm(){
  if(read_only_ && !c_els_tru_tm_ && b_els_tru_tm_){
    b_els_tru_tm_->GetEntry(entry_);
    c_els_tru_tm_ = true;
  }
  return els_tru_tm_;
}

std::vector<bool> & small_tree_base::mus_sigid(){
  if(read_only_ && !c_mus_sigid_ && b_mus_sigid_){
    b_mus_sigid_->GetEntry(entry_);
    c_mus_sigid_ = true;
  }
  return mus_sigid_;
}

std::vector<bool> & small_tree_base::mus_tru_tm(){
  if(read_only_ && !c_mus_tru_tm_ && b_mus_tru_tm_){
    b_mus_tru_tm_->GetEntry(entry_);
    c_mus_tru_tm_ = true;
  }
  return mus_tru_tm_;
}

std::vector<bool> & small_tree_base::tks_from_tau(){
  if(read_only_ && !c_tks_from_tau_ && b_tks_from_tau_){
    b_tks_from_tau_->GetEntry(entry_);
    c_tks_from_tau_ = true;
  }
  return tks_from_tau_;
}

std::vector<bool> & small_tree_base::tks_from_tauhad(){
  if(read_only_ && !c_tks_from_tauhad_ && b_tks_from_tauhad_){
    b_tks_from_tauhad_->GetEntry(entry_);
    c_tks_from_tauhad_ = true;
  }
  return tks_from_tauhad_;
}

std::vector<bool> & small_tree_base::tks_from_taulep(){
  if(read_only_ && !c_tks_from_taulep_ && b_tks_from_taulep_){
    b_tks_from_taulep_->GetEntry(entry_);
    c_tks_from_taulep_ = true;
  }
  return tks_from_taulep_;
}

std::vector<bool> & small_tree_base::tks_from_w(){
  if(read_only_ && !c_tks_from_w_ && b_tks_from_w_){
    b_tks_from_w_->GetEntry(entry_);
    c_tks_from_w_ = true;
  }
  return tks_from_w_;
}

std::vector<float> & small_tree_base::els_eta(){
  if(read_only_ && !c_els_eta_ && b_els_eta_){
    b_els_eta_->GetEntry(entry_);
    c_els_eta_ = true;
  }
  return els_eta_;
}

std::vector<float> & small_tree_base::els_miniso_10_ch(){
  if(read_only_ && !c_els_miniso_10_ch_ && b_els_miniso_10_ch_){
    b_els_miniso_10_ch_->GetEntry(entry_);
    c_els_miniso_10_ch_ = true;
  }
  return els_miniso_10_ch_;
}

std::vector<float> & small_tree_base::els_miniso_tr10(){
  if(read_only_ && !c_els_miniso_tr10_ && b_els_miniso_tr10_){
    b_els_miniso_tr10_->GetEntry(entry_);
    c_els_miniso_tr10_ = true;
  }
  return els_miniso_tr10_;
}

std::vector<float> & small_tree_base::els_miniso_tr10_pfpu(){
  if(read_only_ && !c_els_miniso_tr10_pfpu_ && b_els_miniso_tr10_pfpu_){
    b_els_miniso_tr10_pfpu_->GetEntry(entry_);
    c_els_miniso_tr10_pfpu_ = true;
  }
  return els_miniso_tr10_pfpu_;
}

std::vector<float> & small_tree_base::els_mt(){
  if(read_only_ && !c_els_mt_ && b_els_mt_){
    b_els_mt_->GetEntry(entry_);
    c_els_mt_ = true;
  }
  return els_mt_;
}

std::vector<float> & small_tree_base::els_phi(){
  if(read_only_ && !c_els_phi_ && b_els_phi_){
    b_els_phi_->GetEntry(entry_);
    c_els_phi_ = true;
  }
  return els_phi_;
}

std::vector<float> & small_tree_base::els_pt(){
  if(read_only_ && !c_els_pt_ && b_els_pt_){
    b_els_pt_->GetEntry(entry_);
    c_els_pt_ = true;
  }
  return els_pt_;
}

std::vector<float> & small_tree_base::els_reliso(){
  if(read_only_ && !c_els_reliso_ && b_els_reliso_){
    b_els_reliso_->GetEntry(entry_);
    c_els_reliso_ = true;
  }
  return els_reliso_;
}

std::vector<float> & small_tree_base::els_reliso_r01(){
  if(read_only_ && !c_els_reliso_r01_ && b_els_reliso_r01_){
    b_els_reliso_r01_->GetEntry(entry_);
    c_els_reliso_r01_ = true;
  }
  return els_reliso_r01_;
}

std::vector<float> & small_tree_base::els_reliso_r015(){
  if(read_only_ && !c_els_reliso_r015_ && b_els_reliso_r015_){
    b_els_reliso_r015_->GetEntry(entry_);
    c_els_reliso_r015_ = true;
  }
  return els_reliso_r015_;
}

std::vector<float> & small_tree_base::els_reliso_r02(){
  if(read_only_ && !c_els_reliso_r02_ && b_els_reliso_r02_){
    b_els_reliso_r02_->GetEntry(entry_);
    c_els_reliso_r02_ = true;
  }
  return els_reliso_r02_;
}

std::vector<float> & small_tree_base::els_reliso_r03(){
  if(read_only_ && !c_els_reliso_r03_ && b_els_reliso_r03_){
    b_els_reliso_r03_->GetEntry(entry_);
    c_els_reliso_r03_ = true;
  }
  return els_reliso_r03_;
}

std::vector<float> & small_tree_base::els_reliso_r04(){
  if(read_only_ && !c_els_reliso_r04_ && b_els_reliso_r04_){
    b_els_reliso_r04_->GetEntry(entry_);
    c_els_reliso_r04_ = true;
  }
  return els_reliso_r04_;
}

std::vector<float> & small_tree_base::els_tru_dr(){
  if(read_only_ && !c_els_tru_dr_ && b_els_tru_dr_){
    b_els_tru_dr_->GetEntry(entry_);
    c_els_tru_dr_ = true;
  }
  return els_tru_dr_;
}

std::vector<float> & small_tree_base::jets_csv(){
  if(read_only_ && !c_jets_csv_ && b_jets_csv_){
    b_jets_csv_->GetEntry(entry_);
    c_jets_csv_ = true;
  }
  return jets_csv_;
}

std::vector<float> & small_tree_base::jets_eta(){
  if(read_only_ && !c_jets_eta_ && b_jets_eta_){
    b_jets_eta_->GetEntry(entry_);
    c_jets_eta_ = true;
  }
  return jets_eta_;
}

std::vector<float> & small_tree_base::jets_id(){
  if(read_only_ && !c_jets_id_ && b_jets_id_){
    b_jets_id_->GetEntry(entry_);
    c_jets_id_ = true;
  }
  return jets_id_;
}

std::vector<float> & small_tree_base::jets_phi(){
  if(read_only_ && !c_jets_phi_ && b_jets_phi_){
    b_jets_phi_->GetEntry(entry_);
    c_jets_phi_ = true;
  }
  return jets_phi_;
}

std::vector<float> & small_tree_base::jets_pt(){
  if(read_only_ && !c_jets_pt_ && b_jets_pt_){
    b_jets_pt_->GetEntry(entry_);
    c_jets_pt_ = true;
  }
  return jets_pt_;
}

std::vector<float> & small_tree_base::mus_eta(){
  if(read_only_ && !c_mus_eta_ && b_mus_eta_){
    b_mus_eta_->GetEntry(entry_);
    c_mus_eta_ = true;
  }
  return mus_eta_;
}

std::vector<float> & small_tree_base::mus_miniso_10_ch(){
  if(read_only_ && !c_mus_miniso_10_ch_ && b_mus_miniso_10_ch_){
    b_mus_miniso_10_ch_->GetEntry(entry_);
    c_mus_miniso_10_ch_ = true;
  }
  return mus_miniso_10_ch_;
}

std::vector<float> & small_tree_base::mus_miniso_tr10(){
  if(read_only_ && !c_mus_miniso_tr10_ && b_mus_miniso_tr10_){
    b_mus_miniso_tr10_->GetEntry(entry_);
    c_mus_miniso_tr10_ = true;
  }
  return mus_miniso_tr10_;
}

std::vector<float> & small_tree_base::mus_miniso_tr10_pfpu(){
  if(read_only_ && !c_mus_miniso_tr10_pfpu_ && b_mus_miniso_tr10_pfpu_){
    b_mus_miniso_tr10_pfpu_->GetEntry(entry_);
    c_mus_miniso_tr10_pfpu_ = true;
  }
  return mus_miniso_tr10_pfpu_;
}

std::vector<float> & small_tree_base::mus_mt(){
  if(read_only_ && !c_mus_mt_ && b_mus_mt_){
    b_mus_mt_->GetEntry(entry_);
    c_mus_mt_ = true;
  }
  return mus_mt_;
}

std::vector<float> & small_tree_base::mus_phi(){
  if(read_only_ && !c_mus_phi_ && b_mus_phi_){
    b_mus_phi_->GetEntry(entry_);
    c_mus_phi_ = true;
  }
  return mus_phi_;
}

std::vector<float> & small_tree_base::mus_pt(){
  if(read_only_ && !c_mus_pt_ && b_mus_pt_){
    b_mus_pt_->GetEntry(entry_);
    c_mus_pt_ = true;
  }
  return mus_pt_;
}

std::vector<float> & small_tree_base::mus_reliso(){
  if(read_only_ && !c_mus_reliso_ && b_mus_reliso_){
    b_mus_reliso_->GetEntry(entry_);
    c_mus_reliso_ = true;
  }
  return mus_reliso_;
}

std::vector<float> & small_tree_base::mus_reliso_r01(){
  if(read_only_ && !c_mus_reliso_r01_ && b_mus_reliso_r01_){
    b_mus_reliso_r01_->GetEntry(entry_);
    c_mus_reliso_r01_ = true;
  }
  return mus_reliso_r01_;
}

std::vector<float> & small_tree_base::mus_reliso_r015(){
  if(read_only_ && !c_mus_reliso_r015_ && b_mus_reliso_r015_){
    b_mus_reliso_r015_->GetEntry(entry_);
    c_mus_reliso_r015_ = true;
  }
  return mus_reliso_r015_;
}

std::vector<float> & small_tree_base::mus_reliso_r02(){
  if(read_only_ && !c_mus_reliso_r02_ && b_mus_reliso_r02_){
    b_mus_reliso_r02_->GetEntry(entry_);
    c_mus_reliso_r02_ = true;
  }
  return mus_reliso_r02_;
}

std::vector<float> & small_tree_base::mus_reliso_r03(){
  if(read_only_ && !c_mus_reliso_r03_ && b_mus_reliso_r03_){
    b_mus_reliso_r03_->GetEntry(entry_);
    c_mus_reliso_r03_ = true;
  }
  return mus_reliso_r03_;
}

std::vector<float> & small_tree_base::mus_reliso_r04(){
  if(read_only_ && !c_mus_reliso_r04_ && b_mus_reliso_r04_){
    b_mus_reliso_r04_->GetEntry(entry_);
    c_mus_reliso_r04_ = true;
  }
  return mus_reliso_r04_;
}

std::vector<float> & small_tree_base::mus_tru_dr(){
  if(read_only_ && !c_mus_tru_dr_ && b_mus_tru_dr_){
    b_mus_tru_dr_->GetEntry(entry_);
    c_mus_tru_dr_ = true;
  }
  return mus_tru_dr_;
}

std::vector<float> & small_tree_base::tks_eta(){
  if(read_only_ && !c_tks_eta_ && b_tks_eta_){
    b_tks_eta_->GetEntry(entry_);
    c_tks_eta_ = true;
  }
  return tks_eta_;
}

std::vector<float> & small_tree_base::tks_mt(){
  if(read_only_ && !c_tks_mt_ && b_tks_mt_){
    b_tks_mt_->GetEntry(entry_);
    c_tks_mt_ = true;
  }
  return tks_mt_;
}

std::vector<float> & small_tree_base::tks_phi(){
  if(read_only_ && !c_tks_phi_ && b_tks_phi_){
    b_tks_phi_->GetEntry(entry_);
    c_tks_phi_ = true;
  }
  return tks_phi_;
}

std::vector<float> & small_tree_base::tks_pt(){
  if(read_only_ && !c_tks_pt_ && b_tks_pt_){
    b_tks_pt_->GetEntry(entry_);
    c_tks_pt_ = true;
  }
  return tks_pt_;
}

std::vector<float> & small_tree_base::tks_r03_ch(){
  if(read_only_ && !c_tks_r03_ch_ && b_tks_r03_ch_){
    b_tks_r03_ch_->GetEntry(entry_);
    c_tks_r03_ch_ = true;
  }
  return tks_r03_ch_;
}

std::vector<float> & small_tree_base::tks_tru_dp(){
  if(read_only_ && !c_tks_tru_dp_ && b_tks_tru_dp_){
    b_tks_tru_dp_->GetEntry(entry_);
    c_tks_tru_dp_ = true;
  }
  return tks_tru_dp_;
}

std::vector<float> & small_tree_base::tks_tru_dr(){
  if(read_only_ && !c_tks_tru_dr_ && b_tks_tru_dr_){
    b_tks_tru_dr_->GetEntry(entry_);
    c_tks_tru_dr_ = true;
  }
  return tks_tru_dr_;
}

std::vector<int> & small_tree_base::els_charge(){
  if(read_only_ && !c_els_charge_ && b_els_charge_){
    b_els_charge_->GetEntry(entry_);
    c_els_charge_ = true;
  }
  return els_charge_;
}

std::vector<int> & small_tree_base::els_tru_id(){
  if(read_only_ && !c_els_tru_id_ && b_els_tru_id_){
    b_els_tru_id_->GetEntry(entry_);
    c_els_tru_id_ = true;
  }
  return els_tru_id_;
}

std::vector<int> & small_tree_base::els_tru_momid(){
  if(read_only_ && !c_els_tru_momid_ && b_els_tru_momid_){
    b_els_tru_momid_->GetEntry(entry_);
    c_els_tru_momid_ = true;
  }
  return els_tru_momid_;
}

std::vector<int> & small_tree_base::mus_charge(){
  if(read_only_ && !c_mus_charge_ && b_mus_charge_){
    b_mus_charge_->GetEntry(entry_);
    c_mus_charge_ = true;
  }
  return mus_charge_;
}

std::vector<int> & small_tree_base::mus_tru_id(){
  if(read_only_ && !c_mus_tru_id_ && b_mus_tru_id_){
    b_mus_tru_id_->GetEntry(entry_);
    c_mus_tru_id_ = true;
  }
  return mus_tru_id_;
}

std::vector<int> & small_tree_base::mus_tru_momid(){
  if(read_only_ && !c_mus_tru_momid_ && b_mus_tru_momid_){
    b_mus_tru_momid_->GetEntry(entry_);
    c_mus_tru_momid_ = true;
  }
  return mus_tru_momid_;
}

std::vector<int> & small_tree_base::tks_from_pv(){
  if(read_only_ && !c_tks_from_pv_ && b_tks_from_pv_){
    b_tks_from_pv_->GetEntry(entry_);
    c_tks_from_pv_ = true;
  }
  return tks_from_pv_;
}

std::vector<int> & small_tree_base::tks_id(){
  if(read_only_ && !c_tks_id_ && b_tks_id_){
    b_tks_id_->GetEntry(entry_);
    c_tks_id_ = true;
  }
  return tks_id_;
}

std::vector<int> & small_tree_base::tks_num_prongs(){
  if(read_only_ && !c_tks_num_prongs_ && b_tks_num_prongs_){
    b_tks_num_prongs_->GetEntry(entry_);
    c_tks_num_prongs_ = true;
  }
  return tks_num_prongs_;
}

std::vector<int> & small_tree_base::tks_tru_id(){
  if(read_only_ && !c_tks_tru_id_ && b_tks_tru_id_){
    b_tks_tru_id_->GetEntry(entry_);
    c_tks_tru_id_ = true;
  }
  return tks_tru_id_;
}

unsigned & small_tree_base::mc_type(){
  if(read_only_ && !c_mc_type_ && b_mc_type_){
    b_mc_type_->GetEntry(entry_);
    c_mc_type_ = true;
  }
  return mc_type_;
}

float const & small_tree_base::dphi_wlep_reliso() const{
  throw std::logic_error("dphi_wlep_reliso does not exist in this small_tree_base version.");
}

float const & small_tree_base::ht30() const{
  throw std::logic_error("ht30 does not exist in this small_tree_base version.");
}

float const & small_tree_base::lep_pt() const{
  throw std::logic_error("lep_pt does not exist in this small_tree_base version.");
}

float const & small_tree_base::lep_pt_reliso() const{
  throw std::logic_error("lep_pt_reliso does not exist in this small_tree_base version.");
}

float const & small_tree_base::mht() const{
  throw std::logic_error("mht does not exist in this small_tree_base version.");
}

float const & small_tree_base::mht30() const{
  throw std::logic_error("mht30 does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj() const{
  throw std::logic_error("mj does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_10() const{
  throw std::logic_error("mj_10 does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_20() const{
  throw std::logic_error("mj_20 does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_30() const{
  throw std::logic_error("mj_30 does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_40() const{
  throw std::logic_error("mj_40 does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_cands() const{
  throw std::logic_error("mj_cands does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_cands_trim() const{
  throw std::logic_error("mj_cands_trim does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_eta25() const{
  throw std::logic_error("mj_eta25 does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_nolep_30() const{
  throw std::logic_error("mj_nolep_30 does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_r08() const{
  throw std::logic_error("mj_r08 does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_r10() const{
  throw std::logic_error("mj_r10 does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_r14() const{
  throw std::logic_error("mj_r14 does not exist in this small_tree_base version.");
}

float const & small_tree_base::mj_siglep_30() const{
  throw std::logic_error("mj_siglep_30 does not exist in this small_tree_base version.");
}

float const & small_tree_base::mt_reliso() const{
  throw std::logic_error("mt_reliso does not exist in this small_tree_base version.");
}

float const & small_tree_base::st() const{
  throw std::logic_error("st does not exist in this small_tree_base version.");
}

float const & small_tree_base::st_reliso() const{
  throw std::logic_error("st_reliso does not exist in this small_tree_base version.");
}

int const & small_tree_base::nbl30() const{
  throw std::logic_error("nbl30 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nbm30() const{
  throw std::logic_error("nbm30 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nbt30() const{
  throw std::logic_error("nbt30 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nels_reliso() const{
  throw std::logic_error("nels_reliso does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets() const{
  throw std::logic_error("nfjets does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_10() const{
  throw std::logic_error("nfjets_10 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_20() const{
  throw std::logic_error("nfjets_20 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_30() const{
  throw std::logic_error("nfjets_30 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_40() const{
  throw std::logic_error("nfjets_40 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_cands() const{
  throw std::logic_error("nfjets_cands does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_cands_trim() const{
  throw std::logic_error("nfjets_cands_trim does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_eta25() const{
  throw std::logic_error("nfjets_eta25 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_nolep_30() const{
  throw std::logic_error("nfjets_nolep_30 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_r08() const{
  throw std::logic_error("nfjets_r08 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_r10() const{
  throw std::logic_error("nfjets_r10 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_r14() const{
  throw std::logic_error("nfjets_r14 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nfjets_siglep_30() const{
  throw std::logic_error("nfjets_siglep_30 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nisotk10() const{
  throw std::logic_error("nisotk10 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nisotk10_mt100() const{
  throw std::logic_error("nisotk10_mt100 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nisotk15() const{
  throw std::logic_error("nisotk15 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nisotk15_mt100() const{
  throw std::logic_error("nisotk15_mt100 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nisotks() const{
  throw std::logic_error("nisotks does not exist in this small_tree_base version.");
}

int const & small_tree_base::njets30() const{
  throw std::logic_error("njets30 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nleps_reliso() const{
  throw std::logic_error("nleps_reliso does not exist in this small_tree_base version.");
}

int const & small_tree_base::nmc_els() const{
  throw std::logic_error("nmc_els does not exist in this small_tree_base version.");
}

int const & small_tree_base::nmc_htaus() const{
  throw std::logic_error("nmc_htaus does not exist in this small_tree_base version.");
}

int const & small_tree_base::nmc_ltaus() const{
  throw std::logic_error("nmc_ltaus does not exist in this small_tree_base version.");
}

int const & small_tree_base::nmc_mus() const{
  throw std::logic_error("nmc_mus does not exist in this small_tree_base version.");
}

int const & small_tree_base::nmus_reliso() const{
  throw std::logic_error("nmus_reliso does not exist in this small_tree_base version.");
}

int const & small_tree_base::ntaus() const{
  throw std::logic_error("ntaus does not exist in this small_tree_base version.");
}

int const & small_tree_base::ntaus_againstEMu() const{
  throw std::logic_error("ntaus_againstEMu does not exist in this small_tree_base version.");
}

int const & small_tree_base::ntaus_againstEMu_mt100() const{
  throw std::logic_error("ntaus_againstEMu_mt100 does not exist in this small_tree_base version.");
}

int const & small_tree_base::ntaus_mt100() const{
  throw std::logic_error("ntaus_mt100 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nvels10() const{
  throw std::logic_error("nvels10 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nvels_reliso() const{
  throw std::logic_error("nvels_reliso does not exist in this small_tree_base version.");
}

int const & small_tree_base::nvmus10() const{
  throw std::logic_error("nvmus10 does not exist in this small_tree_base version.");
}

int const & small_tree_base::nvmus_reliso() const{
  throw std::logic_error("nvmus_reliso does not exist in this small_tree_base version.");
}

std::vector<bool> const & small_tree_base::jets_bhad() const{
  throw std::logic_error("jets_bhad does not exist in this small_tree_base version.");
}

std::vector<bool> const & small_tree_base::jets_bhad_tru() const{
  throw std::logic_error("jets_bhad_tru does not exist in this small_tree_base version.");
}

std::vector<bool> const & small_tree_base::jets_blep() const{
  throw std::logic_error("jets_blep does not exist in this small_tree_base version.");
}

std::vector<bool> const & small_tree_base::jets_blep_tru() const{
  throw std::logic_error("jets_blep_tru does not exist in this small_tree_base version.");
}

std::vector<bool> const & small_tree_base::mc_els_id() const{
  throw std::logic_error("mc_els_id does not exist in this small_tree_base version.");
}

std::vector<bool> const & small_tree_base::mc_els_reco() const{
  throw std::logic_error("mc_els_reco does not exist in this small_tree_base version.");
}

std::vector<bool> const & small_tree_base::mc_mus_id() const{
  throw std::logic_error("mc_mus_id does not exist in this small_tree_base version.");
}

std::vector<bool> const & small_tree_base::mc_mus_reco() const{
  throw std::logic_error("mc_mus_reco does not exist in this small_tree_base version.");
}

std::vector<bool> const & small_tree_base::taus_againstEMu() const{
  throw std::logic_error("taus_againstEMu does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_d0() const{
  throw std::logic_error("els_d0 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_dz() const{
  throw std::logic_error("els_dz does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_mindr_0() const{
  throw std::logic_error("els_mindr_0 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_mindr_25() const{
  throw std::logic_error("els_mindr_25 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_mindr_rem_0() const{
  throw std::logic_error("els_mindr_rem_0 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_mindr_rem_25() const{
  throw std::logic_error("els_mindr_rem_25 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_miniso_10() const{
  throw std::logic_error("els_miniso_10 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_miniso_10_pfpu() const{
  throw std::logic_error("els_miniso_10_pfpu does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_miniso_15() const{
  throw std::logic_error("els_miniso_15 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_miniso_tr07() const{
  throw std::logic_error("els_miniso_tr07 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_miniso_tr07_ch() const{
  throw std::logic_error("els_miniso_tr07_ch does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_miniso_tr10_ch() const{
  throw std::logic_error("els_miniso_tr10_ch does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_ptrel_0() const{
  throw std::logic_error("els_ptrel_0 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_ptrel_25() const{
  throw std::logic_error("els_ptrel_25 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_ptrel_rem_0() const{
  throw std::logic_error("els_ptrel_rem_0 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::els_ptrel_rem_25() const{
  throw std::logic_error("els_ptrel_rem_25 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_10_eta() const{
  throw std::logic_error("fjets_10_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_10_m() const{
  throw std::logic_error("fjets_10_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_10_phi() const{
  throw std::logic_error("fjets_10_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_10_pt() const{
  throw std::logic_error("fjets_10_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_20_eta() const{
  throw std::logic_error("fjets_20_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_20_m() const{
  throw std::logic_error("fjets_20_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_20_phi() const{
  throw std::logic_error("fjets_20_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_20_pt() const{
  throw std::logic_error("fjets_20_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_30_eta() const{
  throw std::logic_error("fjets_30_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_30_m() const{
  throw std::logic_error("fjets_30_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_30_phi() const{
  throw std::logic_error("fjets_30_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_30_pt() const{
  throw std::logic_error("fjets_30_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_40_eta() const{
  throw std::logic_error("fjets_40_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_40_m() const{
  throw std::logic_error("fjets_40_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_40_phi() const{
  throw std::logic_error("fjets_40_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_40_pt() const{
  throw std::logic_error("fjets_40_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_cands_eta() const{
  throw std::logic_error("fjets_cands_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_cands_m() const{
  throw std::logic_error("fjets_cands_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_cands_phi() const{
  throw std::logic_error("fjets_cands_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_cands_pt() const{
  throw std::logic_error("fjets_cands_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_cands_trim_eta() const{
  throw std::logic_error("fjets_cands_trim_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_cands_trim_m() const{
  throw std::logic_error("fjets_cands_trim_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_cands_trim_phi() const{
  throw std::logic_error("fjets_cands_trim_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_cands_trim_pt() const{
  throw std::logic_error("fjets_cands_trim_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_eta() const{
  throw std::logic_error("fjets_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_eta25_eta() const{
  throw std::logic_error("fjets_eta25_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_eta25_m() const{
  throw std::logic_error("fjets_eta25_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_eta25_phi() const{
  throw std::logic_error("fjets_eta25_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_eta25_pt() const{
  throw std::logic_error("fjets_eta25_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_m() const{
  throw std::logic_error("fjets_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_nconst() const{
  throw std::logic_error("fjets_nconst does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_nolep_30_eta() const{
  throw std::logic_error("fjets_nolep_30_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_nolep_30_m() const{
  throw std::logic_error("fjets_nolep_30_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_nolep_30_phi() const{
  throw std::logic_error("fjets_nolep_30_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_nolep_30_pt() const{
  throw std::logic_error("fjets_nolep_30_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_phi() const{
  throw std::logic_error("fjets_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_pt() const{
  throw std::logic_error("fjets_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r08_eta() const{
  throw std::logic_error("fjets_r08_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r08_m() const{
  throw std::logic_error("fjets_r08_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r08_phi() const{
  throw std::logic_error("fjets_r08_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r08_pt() const{
  throw std::logic_error("fjets_r08_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r10_eta() const{
  throw std::logic_error("fjets_r10_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r10_m() const{
  throw std::logic_error("fjets_r10_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r10_phi() const{
  throw std::logic_error("fjets_r10_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r10_pt() const{
  throw std::logic_error("fjets_r10_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r14_eta() const{
  throw std::logic_error("fjets_r14_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r14_m() const{
  throw std::logic_error("fjets_r14_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r14_phi() const{
  throw std::logic_error("fjets_r14_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_r14_pt() const{
  throw std::logic_error("fjets_r14_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_siglep_30_eta() const{
  throw std::logic_error("fjets_siglep_30_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_siglep_30_m() const{
  throw std::logic_error("fjets_siglep_30_m does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_siglep_30_phi() const{
  throw std::logic_error("fjets_siglep_30_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::fjets_siglep_30_pt() const{
  throw std::logic_error("fjets_siglep_30_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::isotk_dzpv() const{
  throw std::logic_error("isotk_dzpv does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::isotk_eta() const{
  throw std::logic_error("isotk_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::isotk_iso() const{
  throw std::logic_error("isotk_iso does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::isotk_mt() const{
  throw std::logic_error("isotk_mt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::isotk_pt() const{
  throw std::logic_error("isotk_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::jets_dphi_lep() const{
  throw std::logic_error("jets_dphi_lep does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::jets_dphi_met() const{
  throw std::logic_error("jets_dphi_met does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::jets_dphi_sum() const{
  throw std::logic_error("jets_dphi_sum does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::jets_islep() const{
  throw std::logic_error("jets_islep does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_els_eta() const{
  throw std::logic_error("mc_els_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_els_mpdr() const{
  throw std::logic_error("mc_els_mpdr does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_els_pt() const{
  throw std::logic_error("mc_els_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_eta() const{
  throw std::logic_error("mc_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_htaus_eta() const{
  throw std::logic_error("mc_htaus_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_htaus_mpdr() const{
  throw std::logic_error("mc_htaus_mpdr does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_htaus_pt() const{
  throw std::logic_error("mc_htaus_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_ltaus_eta() const{
  throw std::logic_error("mc_ltaus_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_ltaus_mpdr() const{
  throw std::logic_error("mc_ltaus_mpdr does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_ltaus_pt() const{
  throw std::logic_error("mc_ltaus_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_mus_eta() const{
  throw std::logic_error("mc_mus_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_mus_mpdr() const{
  throw std::logic_error("mc_mus_mpdr does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_mus_pt() const{
  throw std::logic_error("mc_mus_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_phi() const{
  throw std::logic_error("mc_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mc_pt() const{
  throw std::logic_error("mc_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_d0() const{
  throw std::logic_error("mus_d0 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_dz() const{
  throw std::logic_error("mus_dz does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_mindr_0() const{
  throw std::logic_error("mus_mindr_0 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_mindr_25() const{
  throw std::logic_error("mus_mindr_25 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_mindr_rem_0() const{
  throw std::logic_error("mus_mindr_rem_0 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_mindr_rem_25() const{
  throw std::logic_error("mus_mindr_rem_25 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_miniso_10() const{
  throw std::logic_error("mus_miniso_10 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_miniso_10_pfpu() const{
  throw std::logic_error("mus_miniso_10_pfpu does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_miniso_15() const{
  throw std::logic_error("mus_miniso_15 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_miniso_tr07() const{
  throw std::logic_error("mus_miniso_tr07 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_miniso_tr07_ch() const{
  throw std::logic_error("mus_miniso_tr07_ch does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_miniso_tr10_ch() const{
  throw std::logic_error("mus_miniso_tr10_ch does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_ptrel_0() const{
  throw std::logic_error("mus_ptrel_0 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_ptrel_25() const{
  throw std::logic_error("mus_ptrel_25 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_ptrel_rem_0() const{
  throw std::logic_error("mus_ptrel_rem_0 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::mus_ptrel_rem_25() const{
  throw std::logic_error("mus_ptrel_rem_25 does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::taus_CombinedIsolationDeltaBetaCorrRaw3Hits() const{
  throw std::logic_error("taus_CombinedIsolationDeltaBetaCorrRaw3Hits does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::taus_chargedIsoPtSum() const{
  throw std::logic_error("taus_chargedIsoPtSum does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::taus_eta() const{
  throw std::logic_error("taus_eta does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::taus_mt() const{
  throw std::logic_error("taus_mt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::taus_phi() const{
  throw std::logic_error("taus_phi does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::taus_pt() const{
  throw std::logic_error("taus_pt does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::tks_mini_ch() const{
  throw std::logic_error("tks_mini_ch does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::tks_mini_ne() const{
  throw std::logic_error("tks_mini_ne does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::tks_r02_ch() const{
  throw std::logic_error("tks_r02_ch does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::tks_r02_ne() const{
  throw std::logic_error("tks_r02_ne does not exist in this small_tree_base version.");
}

std::vector<float> const & small_tree_base::tks_r03_ne() const{
  throw std::logic_error("tks_r03_ne does not exist in this small_tree_base version.");
}

std::vector<int> const & small_tree_base::mc_id() const{
  throw std::logic_error("mc_id does not exist in this small_tree_base version.");
}

std::vector<int> const & small_tree_base::taus_decayMode() const{
  throw std::logic_error("taus_decayMode does not exist in this small_tree_base version.");
}

std::vector<int> const & small_tree_base::taus_n_pfcands() const{
  throw std::logic_error("taus_n_pfcands does not exist in this small_tree_base version.");
}

std::vector<size_t> const & small_tree_base::mc_mom() const{
  throw std::logic_error("mc_mom does not exist in this small_tree_base version.");
}

float & small_tree_base::dphi_wlep_reliso(){
  throw std::logic_error("dphi_wlep_reliso does not exist in this small_tree_base version.");
}

float & small_tree_base::ht30(){
  throw std::logic_error("ht30 does not exist in this small_tree_base version.");
}

float & small_tree_base::lep_pt(){
  throw std::logic_error("lep_pt does not exist in this small_tree_base version.");
}

float & small_tree_base::lep_pt_reliso(){
  throw std::logic_error("lep_pt_reliso does not exist in this small_tree_base version.");
}

float & small_tree_base::mht(){
  throw std::logic_error("mht does not exist in this small_tree_base version.");
}

float & small_tree_base::mht30(){
  throw std::logic_error("mht30 does not exist in this small_tree_base version.");
}

float & small_tree_base::mj(){
  throw std::logic_error("mj does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_10(){
  throw std::logic_error("mj_10 does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_20(){
  throw std::logic_error("mj_20 does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_30(){
  throw std::logic_error("mj_30 does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_40(){
  throw std::logic_error("mj_40 does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_cands(){
  throw std::logic_error("mj_cands does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_cands_trim(){
  throw std::logic_error("mj_cands_trim does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_eta25(){
  throw std::logic_error("mj_eta25 does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_nolep_30(){
  throw std::logic_error("mj_nolep_30 does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_r08(){
  throw std::logic_error("mj_r08 does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_r10(){
  throw std::logic_error("mj_r10 does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_r14(){
  throw std::logic_error("mj_r14 does not exist in this small_tree_base version.");
}

float & small_tree_base::mj_siglep_30(){
  throw std::logic_error("mj_siglep_30 does not exist in this small_tree_base version.");
}

float & small_tree_base::mt_reliso(){
  throw std::logic_error("mt_reliso does not exist in this small_tree_base version.");
}

float & small_tree_base::st(){
  throw std::logic_error("st does not exist in this small_tree_base version.");
}

float & small_tree_base::st_reliso(){
  throw std::logic_error("st_reliso does not exist in this small_tree_base version.");
}

int & small_tree_base::nbl30(){
  throw std::logic_error("nbl30 does not exist in this small_tree_base version.");
}

int & small_tree_base::nbm30(){
  throw std::logic_error("nbm30 does not exist in this small_tree_base version.");
}

int & small_tree_base::nbt30(){
  throw std::logic_error("nbt30 does not exist in this small_tree_base version.");
}

int & small_tree_base::nels_reliso(){
  throw std::logic_error("nels_reliso does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets(){
  throw std::logic_error("nfjets does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_10(){
  throw std::logic_error("nfjets_10 does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_20(){
  throw std::logic_error("nfjets_20 does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_30(){
  throw std::logic_error("nfjets_30 does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_40(){
  throw std::logic_error("nfjets_40 does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_cands(){
  throw std::logic_error("nfjets_cands does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_cands_trim(){
  throw std::logic_error("nfjets_cands_trim does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_eta25(){
  throw std::logic_error("nfjets_eta25 does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_nolep_30(){
  throw std::logic_error("nfjets_nolep_30 does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_r08(){
  throw std::logic_error("nfjets_r08 does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_r10(){
  throw std::logic_error("nfjets_r10 does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_r14(){
  throw std::logic_error("nfjets_r14 does not exist in this small_tree_base version.");
}

int & small_tree_base::nfjets_siglep_30(){
  throw std::logic_error("nfjets_siglep_30 does not exist in this small_tree_base version.");
}

int & small_tree_base::nisotk10(){
  throw std::logic_error("nisotk10 does not exist in this small_tree_base version.");
}

int & small_tree_base::nisotk10_mt100(){
  throw std::logic_error("nisotk10_mt100 does not exist in this small_tree_base version.");
}

int & small_tree_base::nisotk15(){
  throw std::logic_error("nisotk15 does not exist in this small_tree_base version.");
}

int & small_tree_base::nisotk15_mt100(){
  throw std::logic_error("nisotk15_mt100 does not exist in this small_tree_base version.");
}

int & small_tree_base::nisotks(){
  throw std::logic_error("nisotks does not exist in this small_tree_base version.");
}

int & small_tree_base::njets30(){
  throw std::logic_error("njets30 does not exist in this small_tree_base version.");
}

int & small_tree_base::nleps_reliso(){
  throw std::logic_error("nleps_reliso does not exist in this small_tree_base version.");
}

int & small_tree_base::nmc_els(){
  throw std::logic_error("nmc_els does not exist in this small_tree_base version.");
}

int & small_tree_base::nmc_htaus(){
  throw std::logic_error("nmc_htaus does not exist in this small_tree_base version.");
}

int & small_tree_base::nmc_ltaus(){
  throw std::logic_error("nmc_ltaus does not exist in this small_tree_base version.");
}

int & small_tree_base::nmc_mus(){
  throw std::logic_error("nmc_mus does not exist in this small_tree_base version.");
}

int & small_tree_base::nmus_reliso(){
  throw std::logic_error("nmus_reliso does not exist in this small_tree_base version.");
}

int & small_tree_base::ntaus(){
  throw std::logic_error("ntaus does not exist in this small_tree_base version.");
}

int & small_tree_base::ntaus_againstEMu(){
  throw std::logic_error("ntaus_againstEMu does not exist in this small_tree_base version.");
}

int & small_tree_base::ntaus_againstEMu_mt100(){
  throw std::logic_error("ntaus_againstEMu_mt100 does not exist in this small_tree_base version.");
}

int & small_tree_base::ntaus_mt100(){
  throw std::logic_error("ntaus_mt100 does not exist in this small_tree_base version.");
}

int & small_tree_base::nvels10(){
  throw std::logic_error("nvels10 does not exist in this small_tree_base version.");
}

int & small_tree_base::nvels_reliso(){
  throw std::logic_error("nvels_reliso does not exist in this small_tree_base version.");
}

int & small_tree_base::nvmus10(){
  throw std::logic_error("nvmus10 does not exist in this small_tree_base version.");
}

int & small_tree_base::nvmus_reliso(){
  throw std::logic_error("nvmus_reliso does not exist in this small_tree_base version.");
}

std::vector<bool> & small_tree_base::jets_bhad(){
  throw std::logic_error("jets_bhad does not exist in this small_tree_base version.");
}

std::vector<bool> & small_tree_base::jets_bhad_tru(){
  throw std::logic_error("jets_bhad_tru does not exist in this small_tree_base version.");
}

std::vector<bool> & small_tree_base::jets_blep(){
  throw std::logic_error("jets_blep does not exist in this small_tree_base version.");
}

std::vector<bool> & small_tree_base::jets_blep_tru(){
  throw std::logic_error("jets_blep_tru does not exist in this small_tree_base version.");
}

std::vector<bool> & small_tree_base::mc_els_id(){
  throw std::logic_error("mc_els_id does not exist in this small_tree_base version.");
}

std::vector<bool> & small_tree_base::mc_els_reco(){
  throw std::logic_error("mc_els_reco does not exist in this small_tree_base version.");
}

std::vector<bool> & small_tree_base::mc_mus_id(){
  throw std::logic_error("mc_mus_id does not exist in this small_tree_base version.");
}

std::vector<bool> & small_tree_base::mc_mus_reco(){
  throw std::logic_error("mc_mus_reco does not exist in this small_tree_base version.");
}

std::vector<bool> & small_tree_base::taus_againstEMu(){
  throw std::logic_error("taus_againstEMu does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_d0(){
  throw std::logic_error("els_d0 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_dz(){
  throw std::logic_error("els_dz does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_mindr_0(){
  throw std::logic_error("els_mindr_0 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_mindr_25(){
  throw std::logic_error("els_mindr_25 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_mindr_rem_0(){
  throw std::logic_error("els_mindr_rem_0 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_mindr_rem_25(){
  throw std::logic_error("els_mindr_rem_25 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_miniso_10(){
  throw std::logic_error("els_miniso_10 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_miniso_10_pfpu(){
  throw std::logic_error("els_miniso_10_pfpu does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_miniso_15(){
  throw std::logic_error("els_miniso_15 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_miniso_tr07(){
  throw std::logic_error("els_miniso_tr07 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_miniso_tr07_ch(){
  throw std::logic_error("els_miniso_tr07_ch does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_miniso_tr10_ch(){
  throw std::logic_error("els_miniso_tr10_ch does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_ptrel_0(){
  throw std::logic_error("els_ptrel_0 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_ptrel_25(){
  throw std::logic_error("els_ptrel_25 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_ptrel_rem_0(){
  throw std::logic_error("els_ptrel_rem_0 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::els_ptrel_rem_25(){
  throw std::logic_error("els_ptrel_rem_25 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_10_eta(){
  throw std::logic_error("fjets_10_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_10_m(){
  throw std::logic_error("fjets_10_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_10_phi(){
  throw std::logic_error("fjets_10_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_10_pt(){
  throw std::logic_error("fjets_10_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_20_eta(){
  throw std::logic_error("fjets_20_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_20_m(){
  throw std::logic_error("fjets_20_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_20_phi(){
  throw std::logic_error("fjets_20_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_20_pt(){
  throw std::logic_error("fjets_20_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_30_eta(){
  throw std::logic_error("fjets_30_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_30_m(){
  throw std::logic_error("fjets_30_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_30_phi(){
  throw std::logic_error("fjets_30_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_30_pt(){
  throw std::logic_error("fjets_30_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_40_eta(){
  throw std::logic_error("fjets_40_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_40_m(){
  throw std::logic_error("fjets_40_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_40_phi(){
  throw std::logic_error("fjets_40_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_40_pt(){
  throw std::logic_error("fjets_40_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_cands_eta(){
  throw std::logic_error("fjets_cands_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_cands_m(){
  throw std::logic_error("fjets_cands_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_cands_phi(){
  throw std::logic_error("fjets_cands_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_cands_pt(){
  throw std::logic_error("fjets_cands_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_cands_trim_eta(){
  throw std::logic_error("fjets_cands_trim_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_cands_trim_m(){
  throw std::logic_error("fjets_cands_trim_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_cands_trim_phi(){
  throw std::logic_error("fjets_cands_trim_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_cands_trim_pt(){
  throw std::logic_error("fjets_cands_trim_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_eta(){
  throw std::logic_error("fjets_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_eta25_eta(){
  throw std::logic_error("fjets_eta25_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_eta25_m(){
  throw std::logic_error("fjets_eta25_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_eta25_phi(){
  throw std::logic_error("fjets_eta25_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_eta25_pt(){
  throw std::logic_error("fjets_eta25_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_m(){
  throw std::logic_error("fjets_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_nconst(){
  throw std::logic_error("fjets_nconst does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_nolep_30_eta(){
  throw std::logic_error("fjets_nolep_30_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_nolep_30_m(){
  throw std::logic_error("fjets_nolep_30_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_nolep_30_phi(){
  throw std::logic_error("fjets_nolep_30_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_nolep_30_pt(){
  throw std::logic_error("fjets_nolep_30_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_phi(){
  throw std::logic_error("fjets_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_pt(){
  throw std::logic_error("fjets_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r08_eta(){
  throw std::logic_error("fjets_r08_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r08_m(){
  throw std::logic_error("fjets_r08_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r08_phi(){
  throw std::logic_error("fjets_r08_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r08_pt(){
  throw std::logic_error("fjets_r08_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r10_eta(){
  throw std::logic_error("fjets_r10_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r10_m(){
  throw std::logic_error("fjets_r10_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r10_phi(){
  throw std::logic_error("fjets_r10_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r10_pt(){
  throw std::logic_error("fjets_r10_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r14_eta(){
  throw std::logic_error("fjets_r14_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r14_m(){
  throw std::logic_error("fjets_r14_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r14_phi(){
  throw std::logic_error("fjets_r14_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_r14_pt(){
  throw std::logic_error("fjets_r14_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_siglep_30_eta(){
  throw std::logic_error("fjets_siglep_30_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_siglep_30_m(){
  throw std::logic_error("fjets_siglep_30_m does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_siglep_30_phi(){
  throw std::logic_error("fjets_siglep_30_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::fjets_siglep_30_pt(){
  throw std::logic_error("fjets_siglep_30_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::isotk_dzpv(){
  throw std::logic_error("isotk_dzpv does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::isotk_eta(){
  throw std::logic_error("isotk_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::isotk_iso(){
  throw std::logic_error("isotk_iso does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::isotk_mt(){
  throw std::logic_error("isotk_mt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::isotk_pt(){
  throw std::logic_error("isotk_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::jets_dphi_lep(){
  throw std::logic_error("jets_dphi_lep does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::jets_dphi_met(){
  throw std::logic_error("jets_dphi_met does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::jets_dphi_sum(){
  throw std::logic_error("jets_dphi_sum does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::jets_islep(){
  throw std::logic_error("jets_islep does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_els_eta(){
  throw std::logic_error("mc_els_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_els_mpdr(){
  throw std::logic_error("mc_els_mpdr does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_els_pt(){
  throw std::logic_error("mc_els_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_eta(){
  throw std::logic_error("mc_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_htaus_eta(){
  throw std::logic_error("mc_htaus_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_htaus_mpdr(){
  throw std::logic_error("mc_htaus_mpdr does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_htaus_pt(){
  throw std::logic_error("mc_htaus_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_ltaus_eta(){
  throw std::logic_error("mc_ltaus_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_ltaus_mpdr(){
  throw std::logic_error("mc_ltaus_mpdr does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_ltaus_pt(){
  throw std::logic_error("mc_ltaus_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_mus_eta(){
  throw std::logic_error("mc_mus_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_mus_mpdr(){
  throw std::logic_error("mc_mus_mpdr does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_mus_pt(){
  throw std::logic_error("mc_mus_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_phi(){
  throw std::logic_error("mc_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mc_pt(){
  throw std::logic_error("mc_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_d0(){
  throw std::logic_error("mus_d0 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_dz(){
  throw std::logic_error("mus_dz does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_mindr_0(){
  throw std::logic_error("mus_mindr_0 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_mindr_25(){
  throw std::logic_error("mus_mindr_25 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_mindr_rem_0(){
  throw std::logic_error("mus_mindr_rem_0 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_mindr_rem_25(){
  throw std::logic_error("mus_mindr_rem_25 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_miniso_10(){
  throw std::logic_error("mus_miniso_10 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_miniso_10_pfpu(){
  throw std::logic_error("mus_miniso_10_pfpu does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_miniso_15(){
  throw std::logic_error("mus_miniso_15 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_miniso_tr07(){
  throw std::logic_error("mus_miniso_tr07 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_miniso_tr07_ch(){
  throw std::logic_error("mus_miniso_tr07_ch does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_miniso_tr10_ch(){
  throw std::logic_error("mus_miniso_tr10_ch does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_ptrel_0(){
  throw std::logic_error("mus_ptrel_0 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_ptrel_25(){
  throw std::logic_error("mus_ptrel_25 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_ptrel_rem_0(){
  throw std::logic_error("mus_ptrel_rem_0 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::mus_ptrel_rem_25(){
  throw std::logic_error("mus_ptrel_rem_25 does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::taus_CombinedIsolationDeltaBetaCorrRaw3Hits(){
  throw std::logic_error("taus_CombinedIsolationDeltaBetaCorrRaw3Hits does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::taus_chargedIsoPtSum(){
  throw std::logic_error("taus_chargedIsoPtSum does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::taus_eta(){
  throw std::logic_error("taus_eta does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::taus_mt(){
  throw std::logic_error("taus_mt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::taus_phi(){
  throw std::logic_error("taus_phi does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::taus_pt(){
  throw std::logic_error("taus_pt does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::tks_mini_ch(){
  throw std::logic_error("tks_mini_ch does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::tks_mini_ne(){
  throw std::logic_error("tks_mini_ne does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::tks_r02_ch(){
  throw std::logic_error("tks_r02_ch does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::tks_r02_ne(){
  throw std::logic_error("tks_r02_ne does not exist in this small_tree_base version.");
}

std::vector<float> & small_tree_base::tks_r03_ne(){
  throw std::logic_error("tks_r03_ne does not exist in this small_tree_base version.");
}

std::vector<int> & small_tree_base::mc_id(){
  throw std::logic_error("mc_id does not exist in this small_tree_base version.");
}

std::vector<int> & small_tree_base::taus_decayMode(){
  throw std::logic_error("taus_decayMode does not exist in this small_tree_base version.");
}

std::vector<int> & small_tree_base::taus_n_pfcands(){
  throw std::logic_error("taus_n_pfcands does not exist in this small_tree_base version.");
}

std::vector<size_t> & small_tree_base::mc_mom(){
  throw std::logic_error("mc_mom does not exist in this small_tree_base version.");
}

#include "small_tree_quick.hpp"
small_tree_base* NewTree(const std::type_info &type){

  if(type == typeid(small_tree_base)) return new small_tree_base;
  else if(type == typeid(small_tree_quick)) return static_cast<small_tree_base*>(new small_tree_quick);
  else return new small_tree_base;
}

