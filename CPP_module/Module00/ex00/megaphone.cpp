# include <cctype>
# include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	 std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; j < argv[i][j]; j++)
				std::cout << static_cast<char>(toupper(argv[i][j]));
		}
		std::cout << std::endl;
	}
	return (0);
}
/*********************************/
/*********    casting    *********/
/*********************************/
//static_cast
// casting from c style primitive data type to another is allowed.
// inter-class casting alloewed. but from child to parents is dangerous
