/**
 * Copyright 2020 Lawrence Livermore National Security, LLC and other Typeforge developers.
 * See the top-level NOTICE file for details.
 *
 * SPDX-License-Identifier: BSD-3
 */

#ifndef CAST_STATS_H
#define CAST_STATS_H

#include <string>
#include <map>

namespace Typeforge {

class CastStats {
public:
  void computeStats(SgNode* node);
  std::string toString();
  typedef std::tuple<SgType*, SgType*> CastTypes;
  typedef unsigned long int CastCountType;
private:
  std::string typeName(SgType* type);
  std::string toString(CastTypes ct, CastCountType num);
  void addCast(SgType* from, SgType* to);
  std::map<CastTypes,CastCountType> casts;
};

}

#endif
