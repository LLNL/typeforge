/**
 * Copyright 2020 Lawrence Livermore National Security, LLC and other Typeforge developers.
 * See the top-level NOTICE file for details.
 *
 * SPDX-License-Identifier: BSD-3
 */

#include "sage3basic.h"

#include "Typeforge/TypeforgeException.hpp"
#include "CommandLineOptions.hpp"

#include <sstream>
#include <iostream>

namespace Typeforge {

using namespace std;
/////////////////////////////////////////////////
// Command line processing global options
/////////////////////////////////////////////////

CommandLineOptions args;

std::vector<std::string> parse_args(int argc, char* argv[]) {
  if (argc == 1) {
    exit(0);
  }

  // Command line option handling.
#if USE_SAWYER_COMMANDLINE
  namespace po = Sawyer::CommandLine::Boost;
#else
  namespace po = boost::program_options;
#endif

  po::options_description all_desc("Supported Options");
  po::options_description desc("Main Options");
  po::options_description extra_desc("Extra Options");
  po::options_description hidden_desc("Hidden Options");

  desc.add_options()
    ("help,h", "Produce this help message.")
    ("help-experimental", "Produce help message for some additional experimental options.")
    ("version,v", "Display the version of Typeforge.")
    ("compile", "Run back end compiler.")
    ("plugin", po::value<vector<string> >(),"Names of Typeforge plugin files (JSON format)")
    ("source-file", po::value<vector<string> >(),"Names of source files.")
    ("typeforge-out", po::value< string >(),"Analysis results filename (JSON format).")
    ("typechain-detailed-dot", po::value< string >(), "Generate a detailed visualizaiton of the typechain graph (GraphViz DOT format).")
    ("typechain-compact-dot", po::value< string >(), "Generate a compact visualization of the typechain graph (GraphViz DOT format).")
    ("stats-csv", po::value< string >(),"Generate file with transformation statistics (CSV format).")
    ("stats", "Print transformation statistics on stdout.")
    ;

  extra_desc.add_options()
    ("spec-file", po::value<vector<string> >(),"[deprecated] Name of Typeforge specification file (use JSON plugin files instead).")
    ("opnet", "[experimental] Operand Network will eventually replace TypeChain. Generate GraphViz representations of the OpNet as it gets simplified.")
    ("explicit", "[experimental] Make all implicit casts explicit in generated code.")
    ("annotate", "[experimental] Add all implicit casts as comments in generated code.")
    ("cast-stats", "[experimental] Print cast operator statistics of built-in floating point types.")
    ;

  hidden_desc.add_options()
    ("trace", "Print program transformation operations as they are performed.")
    ;

  all_desc.add(desc).add(extra_desc).add(hidden_desc);

  po::positional_options_description pos;
  pos.add("source-file", -1);
  po::parsed_options parsed = po::command_line_parser(argc, argv).options(all_desc).positional(pos).allow_unregistered().run();
  po::store(parsed, args);
  po::notify(args);

  if (args.count("help")) {
    cout << "typeforge <filename> [OPTIONS]"<<endl;
    cout << desc << "\n";
    exit(0);
  }

  if (args.count("help-experimental"))  {
    cout << "typeforge <filename> [OPTIONS]"<<endl;
    cout << extra_desc << "\n";
    exit(0);
  }

  if (args.isUserProvided("version")) {
    cout << "typeforge version 1.0.0" << endl;
    cout << "Authors: Markus Schordan, Tristan Vanderbruggen, and Nathan Pinnow." << endl;
    exit(0);
  }

  return po::collect_unrecognized(parsed.options, po::include_positional);
}

/////////////////////////////////////////////////

bool CommandLineOptions::isDefined(string option) {
  return (find(option) != end());
}

bool CommandLineOptions::isDefaulted(string option) {
  ROSE_ASSERT(isDefined(option));
  return (*find(option)).second.defaulted();
}

bool CommandLineOptions::isUserProvided(string option) {
  return (isDefined(option) && !isDefaulted(option));
}

bool CommandLineOptions::getBool(string option) {
  if (!isDefined(option)) {
    throw Typeforge::Exception("Boolean command line option \"" + option + "\" accessed that is not defined.");
  }
  CommandLineOptions::iterator iter = find(option);
  try { 
    return iter->second.as<bool>();
  } catch(...) {
    throw Typeforge::Exception("Command line option \"" + option + "\" accessed as Boolean value, but has different type.");
  }
}

int CommandLineOptions::getInt(string option) {
  if (!isDefined(option)) {
    throw Typeforge::Exception("Integer command line option \"" + option + "\" accessed that is not defined.");
  }
  CommandLineOptions::iterator iter = find(option);
  try { 
    return iter->second.as<int>();
  } catch(...) {
    throw Typeforge::Exception("Command line option \"" + option + "\" accessed as integer value, but has different type.");
  }
}

string CommandLineOptions::getString(string option) {
  if (!isDefined(option)) {
    throw Typeforge::Exception("String command line option \"" + option + "\" accessed that is not defined.");
  }
  CommandLineOptions::iterator iter = find(option);
  try { 
    return iter->second.as<string>();
  } catch(...) {
    throw Typeforge::Exception("Command line option \"" + option + "\" accessed as string value, but has different type.");
  }
}

}

