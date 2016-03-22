#ifndef H_TABLE_RA4_MINI
#define H_TABLE_RA4_MINI

#include <string>
#include <vector>
#include "TString.h"

#include "small_tree_basic.hpp"

void ProcessTree(small_tree_basic &tree, std::vector<std::vector<float> > &counts, 
		 std::vector<std::vector<float> > &w2, short cut_type = 0);

void CountRelIso(small_tree_basic &tree, int &nleps, float &mt, float &st, 
		 float elcut_b, float elcut_e, float mucut);
void CountMiniIso(small_tree_basic &tree, int &nleps, float &mt, float &st, float elcut, float mucut);

void MakeTable(std::vector<std::vector<float> > &counts, std::vector<std::vector<float> > &w2,
	       const std::vector<TString> &cuts,
	       const std::vector<TString> &snames);

void MakePie(const std::vector<float> &counts,
	     const std::string &cut,
	     const std::vector<std::string> &snames);

#endif
