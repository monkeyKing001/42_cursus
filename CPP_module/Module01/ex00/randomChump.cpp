#include "Zombie.hpp"

void randomChump(std:: string name)
{
	Zombie *random = newZombie(name);
	random -> announce();
}
