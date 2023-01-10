#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int	main(void)
{
	//ClapTrap
//	ClapTrap a("A");
//	ClapTrap b("B");
//
//	//ScavTrap
//	ScavTrap DefaultScav;
//	ScavTrap sa("ScavTrap1");
//	ScavTrap sb("ScavTrap2");
//	ScavTrap sc(sa);
//	ScavTrap sd = sb;

	//FragTrap
	FragTrap fa("FragTrap1");
	FragTrap fb("FragTrap2");
	FragTrap fc = fa;
	FragTrap fd(fb);
	

	//methods
//	a.attack("B");
//	b.beRepaired(3);
//	b.attack("A");
//	a.beRepaired(10);
//	DefaultScav.attack("sa");
//	sa.attack("a");
//	sb.attack("b");
//	sa.guardGate();
//	sb.guardGate();
	
	fa.attack("FragTrap2");
	fb.attack("FragTrap1");
	fa.highFivesGuys();
	fb.highFivesGuys();

	return (0);
}
