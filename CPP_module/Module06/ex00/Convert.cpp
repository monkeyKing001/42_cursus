#include "Convert.hpp"
#include <cctype>
#include <limits>

char	Convert::toChar(void) const
{
	return (static_cast<char>(_value));
}

int		Convert::toInt(void) const
{
	return (static_cast<int>(_value));
}

float	Convert::toFloat(void) const
{
	return (static_cast<float>(_value));
}

double	Convert::toDouble(void) const
{
	return (static_cast<double>(_value));
}

bool	Convert::getError(void) const
{
	return (_error);
}

const double& 	Convert::getValue(void) const
{
	return (_value);
}

const std::string&	Convert::getInput(void) const
{
	return (_input);
}

Convert&	Convert::operator = (const Convert& c)
{
	if (this != &c)
	{
		_error = c.getError();
		*(const_cast<std::string*>(&_input)) = c.getInput();
		*(const_cast<double*>(&_value)) = c.getValue();
	}
	return (*this);
}

Convert::Convert(void)
	:	_error(false), _input(""), _value(0.0) {}

Convert::Convert(const std::string& input)
	:	_error(false), _input(input), _value(0.0)
{
	try
	{
		char	*ptr = NULL;
		*(const_cast<double*>(&_value)) = std::strtod(_input.c_str(), &ptr);
//		std::cout << "Converted ";
//		std::cout << _input;
//		std::cout << " To ";
//		std::cout << ptr << "\n";
		if (_value == 0.0 && (_input[0] != '-' && _input[0] != '+' && !std::isdigit(_input[0])))
			throw (ParsingException());
		if (*ptr && std::strcmp(ptr, "f"))
			throw (ParsingException());
	}
	catch (std::exception& e)
	{
		_error = true;
		std::cout << e.what();
	}
}

Convert::Convert(const Convert& c) : _error(false), _input(c.getInput()), _value(c.getValue()) {}

Convert::~Convert(void) {}

static void	printToChar(std::ostream& o, const Convert& c)
{
	o << "char: ";
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
		o << IMPOSSIBLE << std::endl;
	else
	{
		if (c.getValue() > std::numeric_limits<char>::max())
			o << "overflow value ";
		else if (c.getValue() < std::numeric_limits<char>::min())
			o << "underflow value ";
		if (std::isprint(c.toChar()))
			o << "'" << c.toChar() << "'" << std::endl;
		else
			o << NON_DISPLAYABLE << std::endl;
	}
}

static void	printToInt(std::ostream& o, const Convert& c)
{
	o << "int: ";
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
		o << IMPOSSIBLE << std::endl;
	else
	{
		if (c.getValue() > std::numeric_limits<int>::max())
			o << "overflow value ";
		else if (c.getValue() < std::numeric_limits<int>::min())
			o << "underflow value ";
		o << c.toInt() << std::endl;
	}
}

static void	printToFloat(std::ostream& o, const Convert& c)
{
	//nan or inf case
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
	{
		o << "float: " << std::showpos << c.toFloat() << "f" << std::endl;
		o << "double: " << std::showpos << c.toDouble() << std::endl;
		return ;
	}
	//float print
	//when float is represent as int
	if (c.toFloat() == static_cast<long long>(c.toFloat()))
		o << "float: " << c.toFloat() << ".0f" << std::endl;
	else
	 	o << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << c.toFloat() << "f" << std::endl;
	//double print
	//when double is represent as int
	if (c.toDouble() == static_cast<long long>(c.toDouble()))
		o << "double: " << c.toDouble() << ".0" << std::endl;
	else
		o << "double: " << std::setprecision(std::numeric_limits<double>::digits10) << c.toDouble() << std::endl;
}

std::ostream& operator << (std::ostream& o, const Convert& c)
{
	if (c.getError())
	{
		o << RED << " Cannot convert " << c.getInput() << "\n" << DEFAULT;
		return (o);
	}
	printToChar(o, c);
	printToInt(o, c);
	printToFloat(o, c);
	return (o);
}

const char* Convert::ParsingException::what(void) const throw()
{
	return "\033[0;91mLiteral is not valid.\033[0;39m";
}
