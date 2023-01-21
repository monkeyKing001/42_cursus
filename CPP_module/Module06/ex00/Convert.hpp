#ifndef __CONVERT_H__
# define __CONVERT_H__

# include <cmath>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <exception>
# include <string>

#define NON_DISPLAYABLE	"Non displayable"
#define IMPOSSIBLE			"impossible"

#define DEFAULT  "\033[0;39m"
#define GRAY  "\033[0;90m"
#define RED  "\033[0;91m"
#define GREEN  "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE  "\033[0;94m"
#define MAGENTA  "\033[0;95m"
#define CYAN  "\033[0;96m"
#define WHITE  "\033[0;97m"

class Convert
{
	private:
		bool								_error;
		const std::string					_input;
		const double						_value;

		Convert(void);

	public:
		char								toChar(void) const;
		int									toInt(void) const;
		float								toFloat(void) const;
		double								toDouble(void) const;

		bool								getError(void) const;
		const double&						getValue(void) const;
		const std::string&					getInput(void) const;
		class ParsingException: public std::exception
		{
			public :
				const char* what(void) const throw();
		};


		Convert&	operator=(const Convert& c);
		Convert(const std::string& input);
		Convert(const Convert& c);
		~Convert(void);
};

std::ostream&	operator<<(std::ostream& o, const Convert& c);

#endif
