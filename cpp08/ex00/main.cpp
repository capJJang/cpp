#include "easyfind.hpp"

int main(void) {
  std::vector<int> v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  try {
    int ret = easyfind(v, 6);
    std::cout << "Target :" << ret << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}