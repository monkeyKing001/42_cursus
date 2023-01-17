#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

void Animal::setType(const std::string& type)
{
	_type = type;
}

std::string Animal::getType(void) const
{
	return _type;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal Sound Cry!!\n";
}

Animal& Animal::operator=(const Animal& a)
{
	if (this != &a)
		this -> _type = a.getType();
	std::cout
		<< "Animal "
		<< "Copy Assignment Constructor Called\n";
	return *this;
}

Animal::Animal(void) : _type(ANIMAL)
{
	std::cout
		<< "Animal "
		<< "Default Constructor Called\n";
}

Animal::Animal(const Animal& a) : _type(a.getType())
{
	std::cout
		<< "Animal "
		<< "Copy Constructor Called\n";
}

Animal::~Animal(void)
{
	std::cout
		<< "Animal "
		<< "Destructor Called\n";
}

std::ostream& operator<<(std::ostream& o, const Animal& a)
{
  return o << a.getType() << " ";
}
