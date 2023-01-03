# include "Zombie.hpp"

int	main(void)
{
	Zombie static_one = Zombie("static Zombie : 1");
	Zombie static_two = Zombie("static Zombie : 2");
	Zombie *dynamic_one = newZombie("dynamic alloacted : 1");
	Zombie *dynamic_two = newZombie("dynamic alloacted : 2");

	dynamic_one -> announce();
	dynamic_two -> announce();
	randomChump("dynamic allocated : 3");
	static_one.announce();
	static_two.announce();
	delete dynamic_one;
	return (0);
}
