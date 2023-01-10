#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
ScavTrap::ScavTrap(void) 
{
	this->Hit = 100;
	this->Energy = 50;
	this->Attack = 20;

	std::cout << "Called ScavTrap default constructor\n";
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->Hit = 100;
	this->Energy = 50;
	this->Attack = 20;
	std::cout << "ScavTrap ( " << name << " ) constructed\n";
}

ScavTrap::ScavTrap(const ScavTrap& obj) 
{
	this->name = obj.name;
	this->Attack = obj.Attack;
	this->Hit = obj.Hit;
	this->Energy = obj.Energy;
	std::cout << "ScavTrap ( " << name << " ) has been constructed by copy\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) 
{
	this->name = obj.name;
	this->Attack = obj.Attack;
	this->Hit = obj.Hit;
	this->Energy = obj.Energy;
	std::cout << "ScavTrap ( " << name << " ) has been constructed by = operator\n";
	return (*this);

}

ScavTrap::~ScavTrap(void) 
{
	std::cout << "ScavTrap " << this->name << " destructed\n";
}

void ScavTrap::guardGate(void)
{
	if (!this->Hit || !this->Energy)
	{
		std::cout << "ScavTrap " << this->name << " can not move...\n";
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " is now in gate keeper mode\n";
		this->Energy--;
	}
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->Hit || !this->Energy)
	{
		std::cout << "ScavTrap " << this->name << " can not move...\n";
	}
	else
	{
		std::cout	<< "ScavTrap " << this->name << " attacks " << target 
					<< ", causing " << this->Attack << " points of damage!\n";
		this->Energy--;
	}
}
