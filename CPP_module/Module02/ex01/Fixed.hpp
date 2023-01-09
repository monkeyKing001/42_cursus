#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <ostream>
#include <string>
#include <type_traits>
#include <cmath>

class Fixed {
 private:
	int					value;
	const static int	bits = 8;
 public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed& obj);
	Fixed(const int integer);
	Fixed(const float flt);
	Fixed& operator = (const Fixed& obj);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
};
std::ostream& operator<<(std::ostream &out, const Fixed& fixed);

#endif
