#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB();
		HumanB(std::string name);

		//get
		const Weapon *getWeapon() const;
		const std::string getName() const;
		
		//set
		void setWeapon(Weapon &weapon);

		//mem func
		void attack();

		~HumanB();
};

#endif
