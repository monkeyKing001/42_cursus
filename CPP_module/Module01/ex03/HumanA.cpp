#include "HumanA.hpp"

//initializer list
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
}

const std::string HumanA::getName() const { return (this -> name); }

const Weapon HumanA::getWeapon() const { return (this -> weapon); }
void HumanA::attack()
{
	std::cout << getName() << " attacks with " << getWeapon().getType() << std::endl;
}

HumanA::~HumanA(){}
