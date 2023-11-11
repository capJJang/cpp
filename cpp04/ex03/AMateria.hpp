#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
 protected:
  std::string _type;
  AMateria();
  virtual ~AMateria();
  AMateria(const AMateria& rhs);
  AMateria& operator=(const AMateria& rhs);

 public:
  AMateria(std::string const& type);
  std::string const& getType() const;  // Returns the materia type
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif