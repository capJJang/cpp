#include "Span.hpp"

Span::Span(/* args */) : N(0) {}

Span::Span(const Span &rhs) : N(rhs.N), i(rhs.i), s(rhs.s) {}

Span::Span(unsigned int N_) : N(N_), i(0) {}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
  if (this == &rhs) return *this;
  this->N = rhs.N;
  this->i = rhs.i;
  this->s = rhs.s;
  return *this;
}

void Span::addNumber(const int num) {
  if (i >= N) throw std::runtime_error("Set is full");

  std::pair<std::set<int>::iterator, bool> result = this->s.insert(num);
  if (result.second) this->i++;
}

int Span::shortestSpan() {
  if (this->s.size() < 2) throw std::runtime_error("Size too small");
  int minDifference = INT_MAX;
  int prevValue = *s.begin();

  for (std::set<int>::const_iterator it = ++s.begin(); it != s.end(); ++it) {
    int currentValue = *it;
    int difference = currentValue - prevValue;
    minDifference = std::min(minDifference, difference);
    prevValue = currentValue;
  }
  return minDifference;
}

int Span::longestSpan() {
  if (this->s.size() < 2) throw std::runtime_error("Size too small");
  return (*this->s.rbegin() - *this->s.begin());
}

void storeNum(int &num) {
  static int n = 0;
  num = n++;
}

// void Span::my_for_each(std::set<int>::iterator first,
//                        std::set<int>::iterator last, void (*f)(int &)) {
//   for (; first != last; ++first) {
//     int &mutableRef = const_cast<int &>(*first);
//     f(mutableRef);
//   }
// }

void Span::fillSet() {
  // my_for_each(this->s.begin(), this->s.end(), storeNum); transform
  for (unsigned int i = 0; i < this->N; i++) this->addNumber(i);
}
