#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 private:
  /* data */
 public:
  WrongCat(/* args */);
  ~WrongCat();
  WrongCat(const WrongCat& rhs);
  WrongCat& operator=(const WrongCat& rhs);

  void makeSound() const;
  std::string getType() const;
};

#endif
