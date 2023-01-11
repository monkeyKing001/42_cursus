#include "Fixed.hpp"
Fixed::Fixed(void) 
{
//	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
//	std::cout << "Copy constructor called\n";
	setRawBits(fixed.getRawBits());
}

Fixed& Fixed::operator = (const Fixed& obj)
{
//	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
	{
		setRawBits(obj.getRawBits());
	}
	return (*this);
}

std::ostream& operator << (std::ostream &out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed:: Fixed(const int integer)
{
//	std::cout << "Int constructor called\n";
	this -> value = integer << this -> bits;
}

Fixed:: Fixed(const float flt)
{
//	std::cout << "Float constructor called\n";
	this->value = roundf(flt * (1 << (this -> bits)));
}
//######################################################################
//################        Comparing Operator       #####################
//######################################################################

bool	Fixed::operator>(Fixed const &ref) const
{
	return (this->getRawBits() > ref.getRawBits());
}

bool	Fixed::operator<(Fixed const &ref) const
{
	return (this->getRawBits() < ref.getRawBits());
}

bool	Fixed::operator>=(Fixed const &ref) const
{
	return (this->getRawBits() >= ref.getRawBits());
}

bool	Fixed::operator<=(Fixed const &ref) const
{
	return (this->getRawBits() <= ref.getRawBits());
}

bool	Fixed::operator==(Fixed const &ref) const
{
	return (this->getRawBits() == ref.getRawBits());
}

bool	Fixed::operator!=(Fixed const &ref) const
{
	return (this->getRawBits() != ref.getRawBits());
}

//######################################################################
//################        Arithmetic Operator      #####################
//######################################################################

Fixed	Fixed::operator+(Fixed const &ref)
{
	Fixed ret(this->toFloat() + ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator-(Fixed const &ref)
{
	Fixed ret(this->toFloat() - ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator*(Fixed const &ref)
{
	Fixed ret(this->toFloat() * ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &ref)
{
	Fixed ret(this->toFloat() / ref.toFloat());
	return (ret);
}

//######################################################################
//#############        incre/decrement Operator        #################
//######################################################################
//pre
Fixed&	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}
//post
const Fixed	Fixed::operator++(int)
{
	const Fixed	ret(*this);

	this->value++;
	return (ret);
}

//pre
Fixed&	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

//post
const Fixed	Fixed::operator--(int)
{
	const Fixed	ret(*this);

	this->value--;
	return (ret);
}
//pre
//Fixed&	Fixed::operator++(int)
//{
//	this->value++;
//	return (*this);
//}
////post
//const Fixed	Fixed::operator++(void)
//{
//	const Fixed	ret(*this);
//
//	this->value++;
//	return (ret);
//}
//
////pre
//Fixed&	Fixed::operator--(int)
//{
//	this->value--;
//	return (*this);
//}
//
////post
//const Fixed	Fixed::operator--(void)
//{
//	const Fixed	ret(*this);
//
//	this->value--;
//	return (ret);
//}
//######################################################################
//#############         Oveloading min/max func         #################
//######################################################################

const Fixed&	Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed& Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed&	Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
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
//	std::cout << "Destructor called\n";
}

int Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->bits));
}

