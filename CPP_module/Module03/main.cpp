#include "ClapTrap.hpp"
int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.beRepaired(3);
	b.attack("A");
	a.beRepaired(10);
	return (0);
}
