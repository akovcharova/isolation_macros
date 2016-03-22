#ifndef H_PLOT_PIECHART
#define H_PLOT_PIECHART

#include <string>
#include <vector>

#include "small_tree_basic.hpp"

void ProcessTree(small_tree_basic &tree, std::vector<std::vector<float> > &counts, short cut_type = 0);

void CountRelIso(small_tree_basic &tree, int &nleps, float &mt, float &st);
void CountMiniIso(small_tree_basic &tree, int &nleps, float &mt, float &st);

void MakeTable(const std::vector<std::vector<float> > &counts,
	       const std::vector<std::string> &cuts,
	       const std::vector<std::string> &snames);

void MakePie(std::vector<float> counts,
	     const std::string &cut,
	     const std::vector<std::string> &snames,
	     std::vector<int> colors);

#endif
