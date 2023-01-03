#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>
#include <sstream>

class Zombie
{
	public:
		//const
		Zombie(void);
		Zombie(std::string name);
		//dest
		~Zombie(void);
		//mem fun
		void announce(void);
		void set_name(std::string name);

	private:
		std::string	name;
};
Zombie *ZombieHorde(int N, std::string name);

#endif
