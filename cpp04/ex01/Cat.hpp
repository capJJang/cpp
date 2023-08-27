#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain* brain;

 public:
  Cat(/* args */);
  ~Cat();
  Cat(const Cat& rhs);
  Cat& operator=(const Cat& rhs);

  void makeSound() const;
  std::string getType() const;
};

#endif
