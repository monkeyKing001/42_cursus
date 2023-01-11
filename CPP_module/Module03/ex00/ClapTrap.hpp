#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>
#include <string>

class ClapTrap
{

	private:
		unsigned int Hit;
		unsigned int Energy;
		unsigned int Attack;
		std::string name;
		

	public:
		//con, dest
		ClapTrap(void);
		ClapTrap(std::string);
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator = (const ClapTrap& obj);
		~ClapTrap(void);

		//mem func
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int getAttack(void) const;
};
#endif /* CLAPTRAP_H */
