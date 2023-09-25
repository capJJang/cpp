#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "utils.h"

int main() {
  Base *test = generate();
  identify(test);
  identify(*test);
  delete test;
}