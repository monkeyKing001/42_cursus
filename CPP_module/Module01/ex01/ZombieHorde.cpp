#include "Zombie.hpp"

Zombie *ZombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::stringstream temp;
		std::string idx_str;
		std::string n_name;
		temp << i;
		idx_str = temp.str();
		n_name = "horde's [" + idx_str + "] " + name;
		horde[i].set_name(n_name);
		std::cout << n_name << " is born\n";
	}
	return (horde);
}
