#ifndef WrongANIMAL_HPP
#define WrongANIMAL_HPP

#include <string>

class WrongAnimal {
 protected:
  std::string _type;

 public:
  WrongAnimal(/* args */);
  WrongAnimal(std::string type);
  virtual ~WrongAnimal();

  void makeSound() const;
  std::string getType() const;
};

#endif
