#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(std::string name, Weapon &weapon);

		//get weapon
		const Weapon getWeapon() const;
		const std::string getName() const;
		void attack();

		~HumanA();
};
#endif
