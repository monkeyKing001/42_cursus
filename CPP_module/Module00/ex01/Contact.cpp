#include "Contact.hpp"
#include "PhoneBook.hpp"
void	Contact::set_field(void)
{
	set_str_var(this -> f_name, F_MODE);
	set_str_var(this -> l_name, L_MODE);
	set_str_var(this -> nick_name, N_MODE);
	set_str_var(this -> phone_num, P_MODE);
	set_str_var(this -> dark_secret, D_MODE);
}

void	Contact::set_str_var(std::string &mem_var, int MODE)
{
	std::string arg;
	std::string prompt;
	//std::string mem;

	//mode check
	switch (MODE)
	{
		case F_MODE:
			prompt = "First Name : ";
			break ;
		case L_MODE:
			prompt = "Last Name : ";
			break ;
		case N_MODE:
			prompt = "Nick Name : ";
			break ;
		case P_MODE:
			prompt = "Phone Number : ";
			break ;
		case D_MODE:
			prompt = "Dark Secret : ";
			break ;
	}
	std::cout << prompt;
	getline(std::cin, arg);
	//check empty field
	arg.erase(arg.find_last_not_of(WHITE_SPACE) + 1);
	while (arg.size() == 0)
	{
		std::cout << RED;
		std::cout << "Error : field cannot be empty.\n";
		std::cout << DEFAULT;
		std::cout << prompt;
		getline(std::cin, arg);
		arg.erase(arg.find_last_not_of(WHITE_SPACE) + 1);
	}
	//replace all of white spcase that is not just space to space
	for (int i = 1; i < 6; i++)
	{
		char	to_be_rplc = WHITE_SPACE[i];
		size_t	pos = arg.find(to_be_rplc);
		while (pos != std::string::npos)
		{
			arg[pos] = ' ';	
			pos = arg.find(to_be_rplc);
		}
	}
	mem_var = arg;
}

std::string	Contact::get_f_name(void){ return (this -> f_name); }

std::string	Contact::get_l_name(void){ return (this -> l_name); }

std::string	Contact::get_nick_name(void){ return (this -> nick_name); }

std::string	Contact::get_num(void){ return (this -> phone_num); }

std::string	Contact::get_dark_secret(void) { return (this -> dark_secret); }

void	Contact::print_contact(void)
{
	std::cout
		<< "First name : "
		<< get_f_name()
		<< "\n"
		<< "Last name : "
		<< get_l_name()
		<< "\n"
		<< "Nick name : "
		<< get_nick_name()
		<< "\n"
		<< "Phone number : "
		<< get_num()
		<< "\n"
		<< "Dark secret : "
		<< get_dark_secret()
		<< "\n";
}
