#include "ClapTrap.hpp"
int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");
	ClapTrap c(a);
	ClapTrap d = b;

	a.attack("B");
	b.takeDamage(a.getAttack());
	b.beRepaired(3);
	b.attack("A");
	a.takeDamage(b.getAttack());
	a.beRepaired(10);

	for (int i = 0; i < 20; i++)
	{
		a.beRepaired(10);
	}
	for (int i = 0; i < 20; i++)
	{
		b.attack("A");
		a.takeDamage(b.getAttack());
	}
	for (int i = 0; i < 20; i++)
	{
		c.beRepaired(10);
	}
	for (int i = 0; i < 20; i++)
	{
		d.attack("C");
		c.takeDamage(d.getAttack());
	}

	return (0);
}
