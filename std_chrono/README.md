std::chrono
===========

Introduction
------------

std::chrono provides a type save way of handling clocks, time points and durations.
Therefore it doesn't provide implicit conversion to and from integers and prevents 
assignments to duration types of lower precision.

Example
-------

```c++
#include <chrono>
#include <iostream>

using namespace std::chrono;
using namespace std::literals;

int main() {
  auto t1 = high_resolution_clock::now(); // first time point

  "This is a string"s.find("nothing");

  auto t2 = high_resolution_clock::now(); // second time point

  // substracting time points leads to a duration
  // the duration_cast converts it into the desired time base
  std::cout << duration_cast<microseconds>(t2 - t1).count() << " us\n";
}
```

Excercise
---------

Write a command line application that take a number and time unit (e.g. s and ms) and 
make it wait for that amount of time until it returns.

Conclusions
-----------

_Here goes the feedback after the first workshop._