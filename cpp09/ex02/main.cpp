#include "PmergeMe.hpp"

static int countDigits(int number) {
  if (number == 0) return 1;
  int numDigits = static_cast<int>(log10(std::abs(number)) + 1);

  return numDigits;
}

static bool isValidArgv(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    std::stringstream ss(argv[i]);
    int temp;
    std::string input(argv[i]);

    ss >> temp;
    if (ss.fail()) return false;
    if (countDigits(std::atol(argv[i])) != static_cast<long>(input.size()))
      return false;
  }
  return true;
}

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cerr << "Error" << std::endl;
    exit(1);
  }
  if (isValidArgv(argc, argv) == false) {
    std::cerr << "Error" << std::endl;
    exit(1);
  }
  PmergeMe<std::vector<int> > test1(argc, argv);
  test1.sort();
  //   PmergeMe<std::deque<int> > test2(argc, argv);
}

// std::vector<std::pair<int, int>> test;
// std::vector<int> test2;