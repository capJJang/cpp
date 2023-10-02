#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
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

  int getI() { return this->i; }
  int getN() { return this->N; }

  void addNumber(const int &num);
  int shortestSpan();
  int longestSpan();
};

#endif