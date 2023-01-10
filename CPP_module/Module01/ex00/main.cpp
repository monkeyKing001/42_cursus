# include "Zombie.hpp"

int	main(void)
{
	Zombie static_and_default_one = Zombie();
	Zombie static_one = Zombie("static Zombie : 1");
	Zombie *dynamic_one = newZombie("dynamic alloacted : 1");

	dynamic_one -> announce();
	static_and_default_one.announce();
	randomChump("announcing by randomChump!!");
	static_one.announce();
	delete dynamic_one;
	return (0);
}
