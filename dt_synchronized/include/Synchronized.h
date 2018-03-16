/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#pragma once

#ifndef __Synchronized_h
#define __Synchronized_h

#include <mutex>

template<typename T>
class Synchronized {
  T t_;
  std::mutex m_;

  class Locked {
    T &t_;
    std::mutex& m_;
   public:
    Locked(T &t, std::mutex &m) : t_(t), m_(m) { m_.lock(); }

    Locked(const Locked&) = delete;
    Locked(Locked&&) = default;

    Locked& operator=(const Locked&) = delete;
    Locked& operator=(Locked&&) = delete;

    ~Locked() { m_.unlock(); };

    T *operator->() { return &t_; }
  };

 public:
  Locked operator->() { return Locked(t_, m_); }

  void locked(std::function<void(T&)> f) { m_.lock(); f(t_); m_.unlock(); }
};

#endif // __Synchronized_h