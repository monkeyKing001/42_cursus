#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
	public:
		FragTrap (void);
		FragTrap (const FragTrap & obj);
		FragTrap & operator = (const FragTrap & obj);
		~FragTrap (void);
		FragTrap (std::string name);
		void highFivesGuys(void);

};

#endif /* FRAGTRAP_H */
