#include "Zombie.hpp"

Zombie::Zombie(void) { this -> name = "unnamed"; }
Zombie::Zombie(std::string name) { this -> name = name; }

void Zombie::announce(void) { std::cout << this -> name <<  ": BraiiiiiiinnnzzzZ..." << std::endl; }
void Zombie::set_name(std::string name) { this -> name = name; }
Zombie::~Zombie(void) { std::cout << this->name << " is dead" << std::endl; }
