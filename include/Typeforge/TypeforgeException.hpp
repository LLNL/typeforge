/**
 * Copyright 2020 Lawrence Livermore National Security, LLC and other Typeforge developers.
 * See the top-level NOTICE file for details.
 *
 * SPDX-License-Identifier: BSD-3
 */

#ifndef CODETHORN_EXCEPTION
#define CODETHORN_EXCEPTION

#include <exception>
#include <string>

namespace Typeforge {

  class Exception : public std::exception {
  public:
    Exception(std::string text) {
      this->text=text;
    }
    const char* what() const throw() {
      return text.c_str();
    }
    ~Exception() throw() {
    }
  private:
    std::string text;
  };

} // end of namespace Typeforge

#endif

