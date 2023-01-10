#include "Fixed.hpp"

Fixed::Fixed(void) 
{
	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	setRawBits(fixed.getRawBits());
}
Fixed& Fixed::operator = (const Fixed& obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
	{
		setRawBits(obj.getRawBits());
	}
	return (*this);
}

Fixed:: Fixed(const int integer)
{
	std::cout << "Int constructor called\n";
	this -> value = integer << this -> bits;
}

//roundf returns the nearst integer as float type
//why roundf? float point is not enough to represent point itself.
Fixed:: Fixed(const float flt)

{
	std::cout << "Float constructor called\n";
	this->value = roundf(flt * (1 << (this -> bits)));
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called\n";
	return (this -> value);
}

void Fixed::setRawBits(int const value)
{
	this -> value = value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->bits));
}

std::ostream& operator << (std::ostream &out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
