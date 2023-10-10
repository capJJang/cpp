#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  (void)argc;
  if (argc != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    exit(1);
  }
  BitcoinExchange ex(argv[1]);
}