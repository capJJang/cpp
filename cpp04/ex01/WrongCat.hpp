#ifndef WrongCAT_HPP
#define WrongCAT_HPP

#include "Brain.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 private:
  Brain* brain;

 public:
  WrongCat(/* args */);
  ~WrongCat();
  WrongCat(const WrongCat& rhs);
  WrongCat& operator=(const WrongCat& rhs);

  void makeSound() const;
  std::string getType() const;
};

#endif
