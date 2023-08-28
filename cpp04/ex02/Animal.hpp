#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
 protected:
  std::string _type;

 public:
  Animal(/* args */);
  Animal(std::string type);
  virtual ~Animal();

  virtual void makeSound() const = 0;
  std::string getType() const;
};

#endif
