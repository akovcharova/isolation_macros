#ifndef H_ISOEFFPARAM
#define H_ISOEFFPARAM

#include "small_tree.hpp"
#include <string>

bool passIsolation(const small_tree &tree, int ilep, bool isElectron, bool isveto, TString isotype, const double coneiso_cut);

#endif
