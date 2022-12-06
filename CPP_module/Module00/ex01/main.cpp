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
		getline(std::cin, cmd);
		//to lowercase
		for (int i = 0; i < static_cast<int>(cmd.size()); i++)
			cmd[i] = static_cast<char>(tolower(cmd[i]));
		if (cmd.compare("add") == 0)
		{
			std::cout <<"add execution \n";
			book.add_contact();
		}
		else if (cmd.compare("search") == 0)
		{
			std::cout << "search execution \n";
			book.print_book();
		}
		else if (cmd.compare("exit") == 0)
		{
			std::cout << "exit\n";
			return (0);
		}
		else
			continue ;
	}
	return (0);
}
