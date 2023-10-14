#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

template <typename Container, typename PairContainer>
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
  PairContainer c;
  Container mainChain;
  Container pendingElements;
  int leftover;
  struct timeval start, end;

 public:
  // constuctor/destuctor
  PmergeMe(int argc, char **argv) : leftover(-1) {
    gettimeofday(&start, NULL);
    for (int i = 1; i < argc - 1; i += 2) {
      c.push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
    }
    if (argc % 2 == 0) leftover = std::atoi(argv[argc - 1]);
    // print();
  }

  ~PmergeMe() {}

  // compare for Container<pair>
  bool compareFirst(const std::pair<int, int> &a,
                    const std::pair<int, int> &b) {
    return a.first < b.first;
  }

  void insertElement() {
    typedef typename Container::iterator insertPosition;

    for (size_t i = 0; i < pendingElements.size(); ++i) {
      int target = pendingElements[i];
      insertPosition position =
          std::lower_bound(mainChain.begin(), mainChain.end(), target);
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
    insertElement();
    gettimeofday(&end, NULL);
  }

  void printSortedContainer() {
    std::cout << "After: ";
    for (unsigned long i = 0; i < mainChain.size(); ++i)
      std::cout << mainChain[i] << " ";
    std::cout << std::endl;
  }

  void printResult(int argc) {
    long long elapsedTime =
        (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
    std::string name = typeid(mainChain).name();
    if (std::strstr(name.c_str(), "vector"))
      name = "vector";
    else if (std::strstr(name.c_str(), "deque"))
      name = "deque";
    std::cout << "Time to process a range of " << argc << " with std::" << name
              << " : " << std::fixed << std::setprecision(6) << elapsedTime
              << " us" << std::endl;
  }
};

#endif