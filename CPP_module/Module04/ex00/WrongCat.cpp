#include "WrongCat.hpp"

void WrongCat::makeSound(void) const
{
	std::cout
		<< "I AM A "
		<< "WRONG_CAT"
		<< "!!!!!!!!!!!!!!\n";
}

WrongCat& WrongCat::operator=(const WrongCat& c)
{
	if (this != &c)
		_type = c.getType();
	std::cout
		<< "WrongCat "
		<< "Copy Assignment Constructor Called\n";
	return *this;
}

WrongCat::WrongCat(void) : WrongAnimal()
{
	_type = WRONG_CAT;
	std::cout
		<< "WrongCat "
		<< "Default Constructor Called\n";
}

WrongCat::WrongCat(const WrongCat& c) : WrongAnimal() {
	if (this != &c)
		_type = c.getType();
	std::cout
		<< "WrongCat "
		<< "Copy Constructor Called\n";
}

WrongCat::~WrongCat(void) {
	std::cout
		<< "WrongCat "
		<< "Destructor Called\n";
}

