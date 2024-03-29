#include "Dog.hpp"

void Dog::makeSound(void) const
{
	std::cout
		<< "I AM A "
		<< "DOG"
		<< "!!!!!!!!!!!!!!\n";
}

Dog& Dog::operator=(const Dog& d)
{
	if (this != &d)
		_type = d.getType();
	std::cout
		<< "Dog "
		<< "Copy Assignment Constructor Called\n";
	return *this;
}

Dog::Dog(void) : Animal()
{
	_type = DOG;
	std::cout
		<< "Dog "
		<< "Default Constructor Called\n";
}

Dog::Dog(const Dog& c) : Animal() {
	if (this != &c)
		_type = c.getType();
	std::cout
		<< "Dog "
		<< "Copy Constructor Called\n";
}

Dog::~Dog(void) {
	std::cout
		<< "Dog "
		<< "Destructor Called\n";
}
