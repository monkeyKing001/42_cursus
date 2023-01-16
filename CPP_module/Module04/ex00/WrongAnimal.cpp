#include "WrongAnimal.hpp"
void WrongAnimal::setType(const std::string& type)
{
	_type = type;
}

std::string WrongAnimal::getType(void) const
{
	return _type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal Sound Cry!!\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
	if (this != &a)
		_type = a.getType();
	std::cout
		<< "WrongAnimal "
		<< "Copy Assignment Constructor Called\n";
	return *this;
}

WrongAnimal::WrongAnimal(void) : _type(WRONG_ANIMAL)
{
	std::cout
		<< "WrongAnimal "
		<< "Default Constructor Called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) : _type(a.getType())
{
	std::cout
		<< "WrongAnimal "
		<< "Copy Constructor Called\n";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout
		<< "WrongAnimal "
		<< "Destructor Called\n";
}

std::ostream& operator<<(std::ostream& o, const WrongAnimal& a)
{
  return o << a.getType() << " ";
}
