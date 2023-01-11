#include "ClapTrap.hpp"
ClapTrap::ClapTrap(void) 
{
	this->name = "none";
	this->Attack = 0;
	this->Hit = 10;
	this->Energy = 10;
	std::cout << "ClapTrap ( " << name << " ) constructed by default\n";
}

ClapTrap::ClapTrap(std::string name) 
{
	this->name = name;
	this->Attack = 0;
	this->Hit = 10;
	this->Energy = 10;
	std::cout << "ClapTrap ( " << name << " ) constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap& obj) 
{
	this->name = obj.name;
	this->Attack = obj.Attack;
	this->Hit = obj.Hit;
	this->Energy = obj.Energy;
	std::cout << "ClapTrap ( " << name << " ) has been constructed by copy\n";

}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) 
{
	this->name = obj.name;
	this->Attack = obj.Attack;
	this->Hit = obj.Hit;
	this->Energy = obj.Energy;
	std::cout << "ClapTrap ( " << name << " ) has been constructed by = operator\n";
	return (*this);
}

ClapTrap::~ClapTrap(void) 
{
	std::cout << "ClapTrap " << this->name << " destructed\n";
}


void ClapTrap::attack(const std::string &target)
{
	if (!this->Hit || !this->Energy)
	{
		std::cout << "ClapTrap " << this->name << " can not move...\n";
	}
	else
	{
		std::cout	<< "ClapTrap " << this->name << " attacks " << target 
					<< ", causing " << this->Attack << " points of damage!\n";
		this->Energy--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->Hit)
		this->Hit = 0;
	else
		this->Hit -= amount;
	std::cout	<< "ClapTrap " << this->name << " has taken " 
				<< amount << " damage in HP\n";
	if (!this->Hit)
	{
		std::cout	<< "ClapTrap " << this->name << " is dead\n"; 
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->Hit || !this->Energy)
	{
		std::cout << "ClapTrap " << this->name << " can not move...\n";
	}
	else
	{
		this->Hit += amount;
		this->Energy--;
		std::cout	<< "ClapTrap " << this->name << " has repaired itself by " 
					<< amount << " Hit points. Its Hit points are now " << this->Hit 
					<< " and Energy is " << this -> Energy <<"\n";
	}
}
unsigned int ClapTrap::getAttack(void) const
{
	return (this -> Attack);
}
