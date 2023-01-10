#include "HumanB.hpp"
HumanB::HumanB() { this -> name = "unnamed"; }
HumanB::HumanB(std::string name) { this -> name = name; }

//get
const Weapon* HumanB::getWeapon() const { return (this -> weapon); }
const std::string HumanB::getName() const { return (this -> name); }

//set
void HumanB::setWeapon(Weapon &weapon) { this -> weapon = &weapon; }

//mem func
void HumanB::attack()
{
	std::cout << getName() << " attacks with their " << getWeapon() -> getType() << std::endl;
}

HumanB::~HumanB(){}
