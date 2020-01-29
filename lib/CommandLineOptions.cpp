/**
 * Copyright 2020 Lawrence Livermore National Security, LLC and other Typeforge developers.
 * See the top-level NOTICE file for details.
 *
 * SPDX-License-Identifier: BSD-3
 */

#include "sage3basic.h"

#include "Typeforge/CommandLineOptions.hpp"
#include "Typeforge/TypeforgeException.hpp"

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
    ("version,v", "Display the version of Typeforge.")
    ("compile", "Run back end compiler.")
    ("plugin", po::value<vector<string> >(),"Name of Typeforge plugin files.")
    ("source-file", po::value<vector<string> >(),"Name of source files.")
    ("typeforge-out", po::value< string >(),"File to store output inside of JSON.")
    ;

  extra_desc.add_options()
    ("spec-file", po::value<vector<string> >(),"Name of Typeforge specification file.")
    ("csv-stats-file", po::value< string >(),"Generate file [args] with transformation statistics.")
    ("opnet", "[Experimental] Operand Network will eventually replace TypeChain. Generate GraphViz representations of the OpNet as it get simplified.")
    ("stats", "Print statistics on performed changes to the program.")
    ("explicit", "Make all implicit casts explicit.")
    ("cast-stats", "Print statistics on casts of built-in floating point types.")
    ("typechain-graphviz", "Generate the Typechain in GraphViz format then quit.")
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

  if (args.isUserProvided("version")) {
    cout << "typeforge version 1.0.0" << endl;
    cout << "authors: Markus Schordan, Tristan Vanderbruggen, and Nathan Pinnow" << endl;
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

