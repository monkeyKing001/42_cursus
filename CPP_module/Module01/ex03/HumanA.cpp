#include "HumanA.hpp"
//HumanA::HumanA(void)
//{
//	this -> name = "none";
//}

//initializer list it's weapon is declared by ref so, unnullable
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
}

const std::string HumanA::getName() const { return (this -> name); }

const Weapon HumanA::getWeapon() const { return (this -> weapon); }
void HumanA::attack()
{
	std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}

HumanA::~HumanA(){}
