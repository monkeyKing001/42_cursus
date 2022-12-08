#include "PhoneBook.hpp"
void	PhoneBook::init_book(void)
{
	this -> contact_num = 0;
}

void	PhoneBook::print_label(void)
{
	std::cout << YELLOW;
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Index";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "First name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Last name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Nick name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Cell phone";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Secret";
    std::cout << "|\n";
}

void	PhoneBook::print_field_w10(std::string _text)
{
    // std::sew = 너비 설정
    // std::right = 오른쪽 정렬
    if (_text.length() <= 10)
        std::cout << std::right << std::setw(10) << _text;
    else
    {
        _text =  _text.substr(0,9) + ".";
        std::cout << std::right << std::setw(10) << _text;
    }
}

void	PhoneBook::print_book(void)
{
	print_label();
	std::cout << GREEN;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout << YELLOW;
		print_field_w10(std::to_string(i));
		std::cout << GREEN;
		std::cout << "|";
		print_field_w10(this -> contacts[i].get_f_name());
		std::cout << "|";
		print_field_w10(this -> contacts[i].get_l_name());
		std::cout << "|";
		print_field_w10(this -> contacts[i].get_nick_name());
		std::cout << "|";
		print_field_w10(this -> contacts[i].get_num());
		std::cout << "|";
		print_field_w10(this -> contacts[i].get_dark_secret());
		std::cout << "|\n";
	}
	std::cout << DEFAULT;
}

void	PhoneBook::select_contact(void)
{
	std::string arg;
	int	index = 8;
	std::cout << "Select contact's index(0 ~ 7) : ";
	getline(std::cin, arg);
	while (arg.length() != 1)
	{
		std::cout << "Error : invalid length index!\nSelect contact's index : ";
		getline(std::cin, arg);
		while (!isdigit(arg[0]) || arg[0] - '0' < 0 || arg[0] - '0' > 7)
		{
			std::cout << "Error : invalid index!\nSelect contact's index : ";
			getline(std::cin, arg);
		}
	}
	index = arg[0] - '0';
	this -> contacts[index].print_contact();
}

void	PhoneBook::add_contact(void)
{
	int	index = (this -> contact_num) % 8;
	//after adding, num++
	this -> contacts[index].set_field();
	this -> contact_num++;
}
