/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "AddressBook.h"

#include <iostream>
#include <string>

using std::cout;
using std::string;

void testIfAddressExists(AddressBook const & addressBook, string const & name) {
  auto address = addressBook.getByName(name);

  if (address) {
    cout << "Found address with name " << address.value().name();

    if (address.value().age()) {
      cout << " and age " << address.value().age().value();
    }
    cout << '\n';
  }
  else {
    cout << "Address was not found\n";
  }
}

int main() {
  AddressBook addressBook;

  // Check what happens if the address book is empty
  testIfAddressExists(addressBook, "Martin");

  addressBook.addAddress("Martin");

  // Check what happens now that the address exists
  testIfAddressExists(addressBook, "Martin");

  addressBook.addAddress("Joe", 23);

  // Check what happens if the address exists with an age
  testIfAddressExists(addressBook, "Joe");
}