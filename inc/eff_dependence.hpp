#ifndef H_EFF_DEPENDENCE
#define H_EFF_DEPENDENCE

#include "small_tree_basic.hpp"
#include <string>

bool passIsolation(const small_tree_basic &tree, int ilep, bool isElectron, bool isveto, TString isotype, const double coneiso_cut);

#endif
