Datatype synchronized<>
=======================

Introduction
------------
The datatype _synchronized_ originates from Facebook's library [folly](https://github.com/facebook/folly).
It is meant to make concurrent access to objects safe by implicitly locking a mutex when a method is invoked on that object.
The benefit of this datatype is that the developer can see in the object declaration that it is protected and that the code is cleaner without the need to write (or forget) explicit locks.

Example
-------

### Without _synchronized_!

```
class State {
  mutex mutex_;
  int a_, b_;

 public:
  void fast(int a, int b) {
    lock_guard<mutex> lock(mutex_);

    a_ = a;
    b_ = b;
  }

  void slow(int a, int b) {
    lock_guard<mutex> lock(mutex_);

    a_ = a;
    sleep_for(seconds(1));
    b_ = b;
  }
};

int main() {
  State state;

  std::thread a([&state](){ state.slow(1, 2); });
  sleep_for(milliseconds(100));
  std::thread b([&state](){ state.fast(3, 4); });
  
  // ... What is the value of s.a and s.b?
}
```

### With _synchronized_!
```
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

  // ... What is the value of s.a and s.b?
}
```

Exercise
--------
Get familiar with the code in the example directory and think about use cases where you would use the datatype synchronized.
Identify potential problems with the datatype and what additional properties you would need.

Conclusions
-----------

_Here goes the feedback after the first workshop._