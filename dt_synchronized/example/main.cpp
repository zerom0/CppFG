/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <Synchronized.h>

#include <iostream>
#include <thread>

using std::chrono::milliseconds;
using std::chrono::seconds;
using std::cout;
using std::this_thread::sleep_for;

class State {
  int a_, b_;

 public:
  void fast(int a, int b) {
    a_ = a;
    b_ = b;
  }

  void slow(int a, int b) {
    a_ = a;
    sleep_for(seconds(1));
    b_ = b;
  }

  int a() { return a_; }
  int b() { return b_; }
};

int main() {
  Synchronized<State> state;

  std::thread a([&state](){ state->slow(1, 2); });
  sleep_for(milliseconds(100));
  std::thread b([&state](){ state->fast(3, 4); });

  a.join();
  b.join();

  cout << "a = " << state->a() << " and b = " << state->b();
}