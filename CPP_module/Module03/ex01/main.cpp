#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int	main(void)
{
	ClapTrap a("A");

	ScavTrap DefaultScav;
	ScavTrap sa("ScavTrap1");
	ScavTrap sb("ScavTrap2");
	ScavTrap sc(sa);
	ScavTrap sd = sb;

	//ScavTrap attack
	sa.attack("ScavTrap2");
	//ClapTrap takeDamage, repaired
	sb.takeDamage(sa.getAttack());
	sb.beRepaired(10);
	//ScavTrap guardGate
	sa.guardGate();
	sb.guardGate();

	//sc, sd
	DefaultScav.attack("sa");
	sa.attack("a");
	sb.attack("b");
	return (0);
}
