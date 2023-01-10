#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	ScavTrap DefaultScav;
	ScavTrap sa("ScavTrap1");
	ScavTrap sb("ScavTrap2");
	ScavTrap sc(sa);
	ScavTrap sd = sb;

	a.attack("B");
	b.beRepaired(3);
	b.attack("A");
	a.beRepaired(10);
	DefaultScav.attack("sa");
	sa.attack("a");
	sb.attack("b");
	sa.guardGate();
	sb.guardGate();
	return (0);
}
