#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H
#include <iostream>
#include <string>

class DiamondTrap
{

	private:
		int Energy;
		int Hit;
		int Attack;

	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap& operator = (const DiamondTrap& obj);
		~DiamondTrap(void);

};

#endif /* DIAMONDTRAP_H */
