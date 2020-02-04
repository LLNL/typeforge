Typeforge
=========

Typeforge is a tool for type refactoring of C/C++ programs. It enables users to change the type of any variable and determines all necessary additional (i.e. type-dependent) changes automatically. It guarantees the syntactic and semantic correctness of the generated code. Generated code will always compile.

# Getting Started

Typeforge uses [ROSE Compiler](http://rosecompiler.org/).
The following instructions assume that [ROSE is installed](https://github.com/rose-compiler/rose/wiki/How-to-Set-Up-ROSE) and the `rose-config` tool is on your path.

You can then follow these instructions to install Typeforge:
```
git clone https://github.com/LLNL/typeforge.git
cd typeforge
./build
mkdir build_tree
cd build_tree
../configure
make -j8
sudo make install
```
If you do not have administrative priviledge, add `--prefix=/path/to/install/typeforge` to the `configure` command.

# Getting Involved & Contributing

Github issue tracking and pull request will be leveraged to facilitate high quality contributions.
All contribution must be made under BSD-3 license.

## Reporting Issues

We will provide an issue reporting template and additional guideline soon.

## Making a Pull Request

Pull requests must be made toward the `develop` branch from a feature/issue branch (meaning that it has a meaningful feature name or GH issue number).

We will provide additional guidelines soon.

# Authors

Typeforge was developed at LLNL by:
 * Markus Schordan
 * Tristan Vanderbruggen
 * Nathan Pinnow

# Publications

Typeforge is used by research projects aimed at changing how C/C++ types are used in existing applications.

A list of publication will be provided soon.

# Release

Typeforge is distributed under the terms of the BSD-3 license. See [NOTICE](NOTICE) for details.

SPDX-License-Identifier: BSD-3

LLNL-CODE-799937
