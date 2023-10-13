#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

template <typename Container>
class PmergeMe {
 private:
  PmergeMe() {}
  PmergeMe(const PmergeMe &rhs) { this->rawData = rhs.rawData; }
  PmergeMe &operator=(const PmergeMe &rhs) { this->rawData = rhs.rawData; }

  //   typedef typename Container<std::pair<int, int> > raw_c;
  Container c;

 public:
  PmergeMe(int argc, char **argv) {
    for (int i = 1; i < argc - 1; i += 2) {
      c.push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
    }
    if (argc % 2 == 0) c.push_back(std::atoi(argv[argc]));
    print();
  }
  ~PmergeMe() {}
  void print() {
    for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
      std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
  }
};

#endif