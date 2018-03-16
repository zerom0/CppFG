/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "AddressBook.h"

Optional<Address> AddressBook::getByName(std::string const &name) const {
  for (auto const& address: addresses_) {
    if (address.name() == name) {
      return address;
    }
  }
  return Optional<Address>();
}
void AddressBook::addAddress(std::string name) {
  addresses_.emplace_back(name);
}

void AddressBook::addAddress(std::string name, unsigned age) {
  addresses_.emplace_back(name, age);
}
