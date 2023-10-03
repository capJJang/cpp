#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

#include "iostream"

template <typename T>
class MutantStack {
 private:
  std::deque<T> d;

 public:
  MutantStack(/* args */) {}
  ~MutantStack() {}
  MutantStack(const MutantStack &rhs) { *this = rhs; }
  MutantStack &operator=(const MutantStack &rhs) {
    if (this == &rhs) return;
    this->d = rhs.d;
    return *this;
  }

  class iterator {};

  void push(const T &target) { d.push_back(target); }
  void pop() { d.pop_back(); }
  const T &top() const { return d.back(); }
  size_t size() { return d.size(); }
  iterator begin() { return d.begin(); }
  iterator end() { return d.end(); }
};

#endif
