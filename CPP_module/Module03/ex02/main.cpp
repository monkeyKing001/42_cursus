#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int	main(void)
{
	std::cout << "\n================    Construction test    =============\n";
	ClapTrap a("A");
	ScavTrap sa("ScavTrap1");
	FragTrap fa("FragTrap1");
	FragTrap fb("FragTrap2");
	FragTrap fc;
	fc = fa;
	FragTrap fd(fb);

	
	//attack mem_func
	std::cout << "\n================    overriding attack test    =============\n";
	a.attack("ScavTrap1");
	sa.attack("A");
	fa.attack("A");

	//highFivesGuys
	fa.highFivesGuys();
	fb.highFivesGuys();
//	a.highFivesGuys();

	return (0);
}
