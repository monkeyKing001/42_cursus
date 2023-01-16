#include "Cat.hpp"
void Cat::setBrain(const Brain &b)
{
//	if (!this -> brain)
//		this -> brain = new Brain();
	delete (this -> brain);
	this -> brain = new Brain();
	*(this -> brain) = b;
}

Brain* Cat::getBrain() const
{
	if (this -> brain)
		return (this -> brain);
	return (NULL);
}

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
	{
		_type = c.getType();
		delete (this -> brain);
		this -> brain = new Brain();
		*this -> brain = *c.getBrain();
	}
	std::cout
		<< "Cat "
		<< "Copy Assignment Constructor Called\n";
	return *this;
}

Cat::Cat(void) : Animal()
{
	_type = CAT;
	this -> brain = new Brain();
	std::cout
		<< "Cat "
		<< "Default Constructor Called\n";
}

Cat::Cat(const Cat& c) : Animal(), brain(new Brain()) {
	if (this != &c)
	{
		_type = c.getType();
		*this -> brain = *c.getBrain();
	}
	std::cout
		<< "Cat "
		<< "Copy Constructor Called\n";
}

Cat::~Cat(void) {
	std::cout
		<< "Cat "
		<< "Destructor Called\n";
	delete (this -> brain);
}
