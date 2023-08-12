#include <string>

class Zombie {
 private:
  std::string name;

 public:
  Zombie(/* args */);
  Zombie(std::string name_);
  ~Zombie();
  void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
