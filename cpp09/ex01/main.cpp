#include "RPN.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: need 1 polish notation" << std::endl;
    return 1;
  }
  std::string userInput(argv[1]);
  RPN test(userInput);
}