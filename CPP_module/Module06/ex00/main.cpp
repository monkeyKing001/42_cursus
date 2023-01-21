#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Error : Arguments count error occured. \nusage : $> ./convert <Argument>\n";
	else
		std::cout << Convert(argv[1]);
	return (0);
}
