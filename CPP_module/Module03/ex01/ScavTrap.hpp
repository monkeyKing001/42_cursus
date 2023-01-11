#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"
#include <iostream>
#include <sstream>
#include <string>

class ScavTrap : public ClapTrap
{

	private:

	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& obj);
		ScavTrap(std::string name);
		ScavTrap& operator = (const ScavTrap& obj);
		~ScavTrap(void);
		void guardGate(void);
		void attack(std::string const& target);

};

#endif /* SCAVTRAP_H */
