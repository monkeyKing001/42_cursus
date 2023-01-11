#include "Cat.hpp"

void Cat::makeSound(void) const
{
	std::cout
		<< "I am a"
		<< _type
		<< "!!!!!!!!!!!!!!\n";
}

Cat& Cat::operator=(const Cat& c) {
  if (this != &c)
    _type = c.getType();
  std::cout
	  << _type
	  << " Copy Assignment Constructor Called\n";
  return *this;
}

Cat::Cat(void)
  : Animal() {
  _type = CAT;
  std::cout << " [ " << std::setw(W_SIZE) << CAT << " ] "
    << "Default constructed" << std::endl;
}

Cat::Cat(const Cat& c)
  : Animal() {
  _type = c.getType();
  std::cout << " [ " << std::setw(W_SIZE) << CAT << " ] "
        << "Copy constructed" << std::endl;
}

Cat::~Cat(void) {
  std::cout << " [ " << std::setw(W_SIZE) << CAT << " ] "
      << "Destructed" << std::endl;
}
