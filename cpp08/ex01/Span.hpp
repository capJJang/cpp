#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <set>
#include <stdexcept>

class Span {
 private:
  unsigned int N;
  unsigned int i;
  std::set<int> s;

  Span(/* args */);

 public:
  Span(unsigned int N_);
  Span(const Span &rhs);
  ~Span();
  Span &operator=(const Span &rhs);

  void addNumber(const int num);
  // void my_for_each(std::set<int>::iterator first, std::set<int>::iterator
  // last,
  //  void (*f)(int &));
  void fillSet();
  int shortestSpan();
  int longestSpan();
};

#endif