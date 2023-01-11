#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int	main(void)
{
	std::cout << "\n================    Construction test    =============\n";
	ClapTrap a("A");

	ScavTrap DefaultScav;
	ScavTrap sa("ScavTrap1");
	ScavTrap sb("ScavTrap2");
	ScavTrap sc(sa);
	ScavTrap sd;
	sd = sb;

	//ClapTrap, ScavTrap attack
	std::cout << "\n================    overriding attack test    =============\n";
	a.attack("ScavTrap1");
	sa.attack("A");

	//ClapTrap takeDamage, repaired
	std::cout << "\n================    not overriding takeDamage test    =============\n";
	a.takeDamage(sa.getAttack());
	sa.takeDamage(a.getAttack());
	//instance's access to base case's protected var is not allowed! 
	//sa.takeDamage(a.Attack);
//	unsigned int sa_attack = sa.getAttack();
//	unsigned int a_attack = a.getAttack();
//	unsigned int a_attack = a.Attack;

	//ClapTrap takeDamage, repaired
	std::cout << "\n================    not overriding beRepaired test    =============\n";
	a.beRepaired(sa.getAttack());
	sa.beRepaired(a.getAttack());

	//ScavTrap guardGate
	std::cout << "\n================    not overriding guardGate test    =============\n";
	sa.guardGate();
	sb.guardGate();

	//sc, sd
	std::cout << "\n================    copy, assignment guardGate test    =============\n";
	sc.guardGate();
	sd.guardGate();
	return (0);
}
