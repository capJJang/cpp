#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  (void)argc;
  if (argc != 2) {
    std::cerr << "Need input file." << std::endl;
    exit(1);
  }
  BitcoinExchange ex(argv[1]);
}