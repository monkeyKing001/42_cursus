#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>
#include <cmath>

class Fixed {
 private:
	int					value;
	const static int	bits = 8;
 public:
	//constructor, destructor
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed& obj);
	Fixed(const int integer);
	Fixed(const float flt);
	Fixed& operator = (const Fixed& obj);

	//overload operator
	//comapring operator
	bool operator>(const Fixed& f) const;
	bool operator<(const Fixed& f) const;
	bool operator>=(const Fixed& f) const;
	bool operator<=(const Fixed& f) const;
	bool operator==(const Fixed& f) const;
	bool operator!=(const Fixed& f) const;

	//arithmetic operations
	Fixed operator+(const Fixed& f);
	Fixed operator-(const Fixed& f);
	Fixed operator*(const Fixed& f);
	Fixed operator/(const Fixed& f);

	//increment/decrement arithmetic operations
	Fixed& operator++(void);
	Fixed& operator--(void);
	const Fixed operator++(int);
	const Fixed operator--(int);

	//getter setter
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;

	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static const Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);
	static const Fixed& max(Fixed& f1, Fixed& f2);
};
std::ostream& operator<<(std::ostream &out, const Fixed& fixed);
#endif
