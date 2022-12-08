#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	//var
	std::string	cmd;
	PhoneBook book;

	//book_init()
	book.init_book();
	while(argc > 0 && argv[0][0] && 1)
	{
		std::cout << "Input your command [ ADD / SEARCH / EXIT ] : ";
		//command doesn't need to interpret space
		//remove white space
		getline(std::cin >> std::ws, cmd);
		//to lowercase
		for (int i = 0; i < static_cast<int>(cmd.size()); i++)
			cmd[i] = static_cast<char>(tolower(cmd[i]));
		if (cmd.compare("add") == 0)
		{
			book.add_contact();
		}
		else if (cmd.compare("search") == 0)
		{
			book.print_book();
			book.select_contact();
		}
		else if (cmd.compare("exit") == 0)
		{
			std::cout << "exit\n";
			return (0);
		}
		else
		{
			std::cout << RED;
			std::cout << "Error : Invalid command\n";
			std::cout << DEFAULT;
			continue ;
		}
	}
	return (0);
}
