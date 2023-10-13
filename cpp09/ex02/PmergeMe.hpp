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
  PmergeMe(const PmergeMe &rhs) {
    this->rawData = rhs.rawData;
    leftover = rhs.leftover;
  }
  PmergeMe &operator=(const PmergeMe &rhs) {
    this->rawData = rhs.rawData;
    leftover = rhs.leftover;
  }

  void pushMainChain(Container &mainChain) {
    for (size_t i = 0; i < c.size(); ++i) {
      mainChain.push_back(c[i].first);
    }
  }

  void pushPendingElements(Container &pendingElements) {
    for (size_t i = 0; i < c.size(); ++i) {
      pendingElements.push_back(c[i].second);
    }
  }

  // member vars
  //    typedef typename Container<std::pair<int, int> > raw_c;
  Container c;
  Container mainChain;
  Container pendingElements;
  int leftover;

 public:
  // constuctor/destuctor
  PmergeMe(int argc, char **argv) : leftover(-1) {
    for (int i = 1; i < argc - 1; i += 2) {
      c.push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
    }
    if (argc % 2 == 0) leftover = std::atoi(argv[argc - 1]);
    // print();
  }

  ~PmergeMe() {}

  // compare for vector<pair>
  bool compareFirst(const std::pair<int, int> &a,
                    const std::pair<int, int> &b) {
    return a.first < b.first;
  }

  void insertElement() {
    typedef typename Container::iterator insertPosition;

    for (size_t i = 0; i < pendingElements.size(); ++i) {
      insertPosition position = std::lower_bound(
          mainChain.begin(), mainChain.end(), pendingElements[i]);
      mainChain.insert(position, pendingElements[i]);
    }

    if (leftover != -1) {
      insertPosition position =
          std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
      mainChain.insert(position, leftover);
    }
  }

  void sort() {
    std::sort(c.begin(), c.end());
    pushMainChain(mainChain);
    pushPendingElements(pendingElements);
    // c.clear();
    insertElement();
    print(mainChain);
  }

  void print(const Container &_c) {
    for (size_t i = 0; i < _c.size(); ++i) {
      std::cout << _c[i] << " ";
    }
    std::cout << std::endl;
  }
};

#endif