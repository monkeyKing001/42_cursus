#include "Dog.hpp"
void Dog::setBrain(const Brain &b)
{
	if (!this -> brain)
		this -> brain = new Brain();
	*(this -> brain) = b;
}

Brain* Dog::getBrain() const
{
	if (this -> brain)
		return (this -> brain);
	return (NULL);
}

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
	{
		_type = d.getType();
		delete (this -> brain);
		this -> brain = new Brain();
		*this -> brain = *d.getBrain();
	}
	std::cout
		<< "Dog "
		<< "Copy Assignment Constructor Called\n";
	return *this;
}

Dog::Dog(void) : Animal()
{
	_type = DOG;
	this -> brain = new Brain();
	std::cout
		<< "Dog "
		<< "Default Constructor Called\n";
}

Dog::Dog(const Dog& d) : Animal(), brain(new Brain()) {
	if (this != &d)
	{
		_type = d.getType();
		*this -> brain = *d.getBrain();
	}
	std::cout
		<< "Dog "
		<< "Copy Constructor Called\n";
}

Dog::~Dog(void) {
	std::cout
		<< "Dog "
		<< "Destructor Called\n";
	delete (this -> brain);
}
