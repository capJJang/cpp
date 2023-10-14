#include "easyfind.hpp"

int main(void) {
  std::vector<int> v;
  std::list<int> l;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);

  l.push_back(1);
  l.push_back(2);
  try {
    int ret = easyfind(l, 1);
    std::cout << "Target :" << ret << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}