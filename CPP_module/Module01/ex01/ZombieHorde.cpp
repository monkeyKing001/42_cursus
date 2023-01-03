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
		horde[i].set_name(name + "_" + idx_str);
		std::cout << "Input " << idx_str << "'s name : " << name << std::endl; 
	}
	return (horde);
}
