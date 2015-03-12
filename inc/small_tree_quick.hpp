// small_tree_quick: quick version of small_tree_base to handle reduce tree ntuples
// File generated with generate_small_tree_base.exe

#ifndef H_SMALL_TREE_QUICK
#define H_SMALL_TREE_QUICK

#include <vector>
#include <string>

#include "TTree.h"
#include "TChain.h"

#include "small_tree_base.hpp"

class small_tree_quick : public small_tree_base{
public:
  small_tree_quick(); // Constructor to create tree
  small_tree_quick(const std::string &filename); // Constructor to read tree

  virtual void GetEntry(const long entry);

  virtual void Fill();

  virtual std::string Type() const;

  virtual ~small_tree_quick();

  virtual float const & dphi_wlep_reliso() const;
  virtual float & dphi_wlep_reliso();
  virtual float const & lep_pt() const;
  virtual float & lep_pt();
  virtual float const & lep_pt_reliso() const;
  virtual float & lep_pt_reliso();
  virtual float const & mht() const;
  virtual float & mht();
  virtual float const & mj() const;
  virtual float & mj();
  virtual float const & mt_reliso() const;
  virtual float & mt_reliso();
  virtual float const & st() const;
  virtual float & st();
  virtual float const & st_reliso() const;
  virtual float & st_reliso();
  virtual int const & nels_reliso() const;
  virtual int & nels_reliso();
  virtual int const & nfjets() const;
  virtual int & nfjets();
  virtual int const & nisotks() const;
  virtual int & nisotks();
  virtual int const & nleps_reliso() const;
  virtual int & nleps_reliso();
  virtual int const & nmus_reliso() const;
  virtual int & nmus_reliso();
  virtual int const & nvels_reliso() const;
  virtual int & nvels_reliso();
  virtual int const & nvmus_reliso() const;
  virtual int & nvmus_reliso();
  virtual std::vector<float> const & els_d0() const;
  virtual std::vector<float> & els_d0();
  virtual std::vector<float> const & els_dz() const;
  virtual std::vector<float> & els_dz();
  virtual std::vector<float> const & els_miniso_10() const;
  virtual std::vector<float> & els_miniso_10();
  virtual std::vector<float> const & els_miniso_10_pfpu() const;
  virtual std::vector<float> & els_miniso_10_pfpu();
  virtual std::vector<float> const & els_miniso_tr10_ch() const;
  virtual std::vector<float> & els_miniso_tr10_ch();
  virtual std::vector<float> const & fjets_eta() const;
  virtual std::vector<float> & fjets_eta();
  virtual std::vector<float> const & fjets_m() const;
  virtual std::vector<float> & fjets_m();
  virtual std::vector<float> const & fjets_nconst() const;
  virtual std::vector<float> & fjets_nconst();
  virtual std::vector<float> const & fjets_phi() const;
  virtual std::vector<float> & fjets_phi();
  virtual std::vector<float> const & fjets_pt() const;
  virtual std::vector<float> & fjets_pt();
  virtual std::vector<float> const & jets_islep() const;
  virtual std::vector<float> & jets_islep();
  virtual std::vector<float> const & mus_d0() const;
  virtual std::vector<float> & mus_d0();
  virtual std::vector<float> const & mus_dz() const;
  virtual std::vector<float> & mus_dz();
  virtual std::vector<float> const & mus_miniso_10() const;
  virtual std::vector<float> & mus_miniso_10();
  virtual std::vector<float> const & mus_miniso_10_pfpu() const;
  virtual std::vector<float> & mus_miniso_10_pfpu();
  virtual std::vector<float> const & mus_miniso_tr10_ch() const;
  virtual std::vector<float> & mus_miniso_tr10_ch();

private:
  float dphi_wlep_reliso_;
  TBranch *b_dphi_wlep_reliso_;
  mutable bool c_dphi_wlep_reliso_;
  float lep_pt_;
  TBranch *b_lep_pt_;
  mutable bool c_lep_pt_;
  float lep_pt_reliso_;
  TBranch *b_lep_pt_reliso_;
  mutable bool c_lep_pt_reliso_;
  float mht_;
  TBranch *b_mht_;
  mutable bool c_mht_;
  float mj_;
  TBranch *b_mj_;
  mutable bool c_mj_;
  float mt_reliso_;
  TBranch *b_mt_reliso_;
  mutable bool c_mt_reliso_;
  float st_;
  TBranch *b_st_;
  mutable bool c_st_;
  float st_reliso_;
  TBranch *b_st_reliso_;
  mutable bool c_st_reliso_;
  int nels_reliso_;
  TBranch *b_nels_reliso_;
  mutable bool c_nels_reliso_;
  int nfjets_;
  TBranch *b_nfjets_;
  mutable bool c_nfjets_;
  int nisotks_;
  TBranch *b_nisotks_;
  mutable bool c_nisotks_;
  int nleps_reliso_;
  TBranch *b_nleps_reliso_;
  mutable bool c_nleps_reliso_;
  int nmus_reliso_;
  TBranch *b_nmus_reliso_;
  mutable bool c_nmus_reliso_;
  int nvels_reliso_;
  TBranch *b_nvels_reliso_;
  mutable bool c_nvels_reliso_;
  int nvmus_reliso_;
  TBranch *b_nvmus_reliso_;
  mutable bool c_nvmus_reliso_;
  std::vector<float> els_d0_;
  std::vector<float> *p_els_d0_;
  TBranch *b_els_d0_;
  mutable bool c_els_d0_;
  std::vector<float> els_dz_;
  std::vector<float> *p_els_dz_;
  TBranch *b_els_dz_;
  mutable bool c_els_dz_;
  std::vector<float> els_miniso_10_;
  std::vector<float> *p_els_miniso_10_;
  TBranch *b_els_miniso_10_;
  mutable bool c_els_miniso_10_;
  std::vector<float> els_miniso_10_pfpu_;
  std::vector<float> *p_els_miniso_10_pfpu_;
  TBranch *b_els_miniso_10_pfpu_;
  mutable bool c_els_miniso_10_pfpu_;
  std::vector<float> els_miniso_tr10_ch_;
  std::vector<float> *p_els_miniso_tr10_ch_;
  TBranch *b_els_miniso_tr10_ch_;
  mutable bool c_els_miniso_tr10_ch_;
  std::vector<float> fjets_eta_;
  std::vector<float> *p_fjets_eta_;
  TBranch *b_fjets_eta_;
  mutable bool c_fjets_eta_;
  std::vector<float> fjets_m_;
  std::vector<float> *p_fjets_m_;
  TBranch *b_fjets_m_;
  mutable bool c_fjets_m_;
  std::vector<float> fjets_nconst_;
  std::vector<float> *p_fjets_nconst_;
  TBranch *b_fjets_nconst_;
  mutable bool c_fjets_nconst_;
  std::vector<float> fjets_phi_;
  std::vector<float> *p_fjets_phi_;
  TBranch *b_fjets_phi_;
  mutable bool c_fjets_phi_;
  std::vector<float> fjets_pt_;
  std::vector<float> *p_fjets_pt_;
  TBranch *b_fjets_pt_;
  mutable bool c_fjets_pt_;
  std::vector<float> jets_islep_;
  std::vector<float> *p_jets_islep_;
  TBranch *b_jets_islep_;
  mutable bool c_jets_islep_;
  std::vector<float> mus_d0_;
  std::vector<float> *p_mus_d0_;
  TBranch *b_mus_d0_;
  mutable bool c_mus_d0_;
  std::vector<float> mus_dz_;
  std::vector<float> *p_mus_dz_;
  TBranch *b_mus_dz_;
  mutable bool c_mus_dz_;
  std::vector<float> mus_miniso_10_;
  std::vector<float> *p_mus_miniso_10_;
  TBranch *b_mus_miniso_10_;
  mutable bool c_mus_miniso_10_;
  std::vector<float> mus_miniso_10_pfpu_;
  std::vector<float> *p_mus_miniso_10_pfpu_;
  TBranch *b_mus_miniso_10_pfpu_;
  mutable bool c_mus_miniso_10_pfpu_;
  std::vector<float> mus_miniso_tr10_ch_;
  std::vector<float> *p_mus_miniso_tr10_ch_;
  TBranch *b_mus_miniso_tr10_ch_;
  mutable bool c_mus_miniso_tr10_ch_;
};

#endif
