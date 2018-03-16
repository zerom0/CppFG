/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#pragma once

#ifndef __Address_h
#define __Address_h

#include <Optional.h>

#include <string>

class Address{
  std::string name_;
  Optional<unsigned> age_;

 public:
  Address() = default;
  Address(std::string name) : name_(name) {}
  Address(std::string name, unsigned age) : name_(name), age_(age) {}

  std::string name() const { return name_; }
  Optional<unsigned> age() const { return age_; }
};

#endif //__Address_h
