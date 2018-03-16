/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#pragma once

#ifndef __AddressBook_h
#define __AddressBook_h

#include "Address.h"

#include <Optional.h>

#include <deque>
#include <string>

class AddressBook {
  std::deque<Address> addresses_;

 public:
  void addAddress(std::string name);
  void addAddress(std::string name, unsigned age);

  Optional<Address> getByName(std::string const& name) const;
};

#endif //__AddressBook_h
