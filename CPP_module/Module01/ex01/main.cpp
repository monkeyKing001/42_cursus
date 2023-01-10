#include "Zombie.hpp"
int main(void)
{
	Zombie *horde;

	horde = ZombieHorde(10, "baby");
	horde[0].announce();
	horde[1].announce();
	horde[2].announce();
	horde[9].announce();
//	horde[11].announce();
	delete [] horde;
	return (0);
}
