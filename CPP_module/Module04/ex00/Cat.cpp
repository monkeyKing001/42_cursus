#include "Cat.hpp"

void Cat::makeSound(void) const
{
	std::cout
		<< "I AM A "
		<< "CAT"
		<< "!!!!!!!!!!!!!!\n";
}

Cat& Cat::operator=(const Cat& c)
{
	if (this != &c)
		_type = c.getType();
	std::cout
		<< "Cat "
		<< "Copy Assignment Constructor Called\n";
	return *this;
}

Cat::Cat(void) : Animal()
{
	_type = CAT;
	std::cout
		<< "Cat "
		<< "Default Constructor Called\n";
}

Cat::Cat(const Cat& c) : Animal() {
	if (this != &c)
		_type = c.getType();
	std::cout
		<< "Cat "
		<< "Copy Constructor Called\n";
}

Cat::~Cat(void) {
	std::cout
		<< "Cat "
		<< "Destructor Called\n";
}
