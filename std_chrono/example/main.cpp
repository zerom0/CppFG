/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono;
using namespace std::literals;

void usage_and_exit() {
  std::cout << "Usage: specify the duration and unit to wait some time ;-)\n"
               "  std_chrono 23 ms\n"
               "  std_chrono 7 s\n";
  exit(0);
}

int main(int argc, char** argv) {
  if (argc != 3) usage_and_exit();

  // we need to initialize delay with the highest resolution that will be assigned to it
  // as an assigment with truncation is not allowed without a duration_cast<>
  auto delay = milliseconds{}; // zero initialize the delay

  if (argv[2] == "s"s) delay = seconds{atoi(argv[1])}; // value gets converted into ms
  else if (argv[2] == "ms"s) delay = milliseconds{atoi(argv[1])}; // value remains in ms
  else usage_and_exit();

  auto t1 = high_resolution_clock::now();

  while (high_resolution_clock::now() - t1 < delay) { // comparing time points
    std::this_thread::sleep_for(1ms); // using UDL for duration in std library
  }

  auto t2 = high_resolution_clock::now(); // adding a duration to a time point

  // Substracting two time points leads to a duration.
  // Casting it to the desired resolution (high_resolution_clock is probably in ns).
  // Extract the raw number from a duration with .count()
  std::cout << "I waited for " << duration_cast<milliseconds>(t2 - t1).count() << " ms.\n";
}