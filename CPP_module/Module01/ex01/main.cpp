#include "Zombie.hpp"
int main(void)
{
	Zombie *horde;

	horde = ZombieHorde(10, "test");
	horde[0].announce();
	horde[1].announce();
	horde[2].announce();
	delete [] horde;
	return (0);
}
