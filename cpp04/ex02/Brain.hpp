#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
 private:
  std::string ideas[100];

 public:
  Brain(/* args */);
  ~Brain();
  Brain(const Brain &rhs);
  Brain &operator=(const Brain &rhs);

  std::string getIdea(int i);
  void setIdea(std::string idea_, int i);
};

#endif
