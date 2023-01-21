#ifndef BASE_H__
# define BASE_H__
# include <exception>
# include <iostream>
# include <string>
# include <cmath>
# include <random>

#define DEFAULT  "\033[0;39m"
#define GRAY  "\033[0;90m"
#define RED  "\033[0;91m"
#define GREEN  "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE  "\033[0;94m"
#define MAGENTA  "\033[0;95m"
#define CYAN  "\033[0;96m"
#define WHITE  "\033[0;97m"


class Base
{
	public:
		virtual ~Base(void) {};
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
