#include "FragTrap.hpp"
FragTrap::FragTrap(void) 
{
	this->name = "default";
	this->Attack = 30;
	this->Hit = 100;
	this->Energy = 100;
	
	std::cout << "FragTrap ( " << name << " ) has been constructed by default\n";
}

FragTrap::FragTrap(const FragTrap& obj) 
{
	this->name = obj.name;
	this->Attack = obj.Attack;
	this->Hit = obj.Hit;
	this->Energy = obj.Energy;
	std::cout << "FragTrap ( " << name << " ) has been constructed by copy\n";
}

FragTrap& FragTrap::operator=(const FragTrap& obj) 
{
	this->name = obj.name;
	this->Attack = obj.Attack;
	this->Hit = obj.Hit;
	this->Energy = obj.Energy;
	std::cout << "FragTrap ( " << name << " ) has been constructed by = operator\n";
	return (*this);
}

FragTrap::~FragTrap(void) 
{
	std::cout << "FragTrap " << this->name << " destructed\n";

}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->Attack = 30;
	this->Hit = 100;
	this->Energy = 100;
	
	std::cout << "FragTrap ( " << name << " ) constructed\n";
}

void FragTrap::highFivesGuys(void)
{
	if (!this->Hit | !this->Energy) 
	{
		std::cout << "FragTrap " << this->name << " can not move..." << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->name << ": high five!\n";
	}
}
