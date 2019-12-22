/**
 * Copyright 2020 Lawrence Livermore National Security, LLC and other Typeforge developers.
 * See the top-level NOTICE file for details.
 *
 * SPDX-License-Identifier: BSD-3
 */

#ifndef COMMAND_LINE_OPTIONS_H
#define COMMAND_LINE_OPTIONS_H

#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>

#ifndef USE_SAWYER_COMMANDLINE
#  define USE_SAWYER_COMMANDLINE 0
#endif
#if USE_SAWYER_COMMANDLINE
#  include "Sawyer/CommandLineBoost.h"
#else
#  include <boost/program_options.hpp>
#endif

namespace Typeforge {

std::vector<std::string> parse_args(int argc, char* argv[]);

class CommandLineOptions 
#if USE_SAWYER_COMMANDLINE
  : public Sawyer::CommandLine::Boost::variables_map
#else
  : public boost::program_options::variables_map
#endif
  {
public:
  /// Returns true iff "option" is available.
  bool isDefined(std::string option);
  /// Returns true iff "option" is available, but was not set explicitly.
  /** Note that an exlicit selection of the default value will cause this function to return false. */
  bool isDefaulted(std::string option);
  /// Returns true iff "option" was provided by the user.
  bool isUserProvided(std::string option);
  /// Returns the value of the Boolean option with name "option".
  bool getBool(std::string option);
  /// Returns the value of the integer option with name "option".
  int getInt(std::string option);
  /// Returns the value of the string option with name "option".
  std::string getString(std::string option);
  /// (Over-)writes the current entry for "option" with "value".
  template<typename T> void setOption(std::string option, T value);
};

extern CommandLineOptions args; // defined in CommandLineOptions.C

extern int option_debug_mode;


// template function implementation
#include "Typeforge/TypeforgeException.hpp"
using namespace std;

template<typename T>
void CommandLineOptions::setOption(string option, T value) {
  if (count(option) < 1) {
    throw Typeforge::Exception("Trying to set command line option \"" + option + "\" that does not exist.");
  }
  const_cast<boost::program_options::variable_value&>(operator[](option)) = 
    boost::program_options::variable_value(boost::any(value), false);
}

}

#endif

