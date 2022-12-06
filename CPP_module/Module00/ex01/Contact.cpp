#include "Contact.hpp"
void	Contact::set_field(void)
{
	set_f_name();
	set_l_name();
	set_nick_name();
	set_phone_num();
	set_dark_secret();
}

void	Contact::set_f_name(void)
{
	std::string f_name;
	std::cout << "Input first name : ";
	getline(std::cin, f_name);
	//check empty field!!
	this -> f_name = f_name;
}

void	Contact::set_l_name(void)
{
	std::string l_name;
	std::cout << "Input last name : ";
	getline(std::cin, l_name);
	this -> l_name = l_name;
}

void	Contact::set_nick_name(void)
{
	std::string arg;
	std::cout << "Input nick name : ";
	getline(std::cin, arg);
	this -> nick_name = arg;
}

void	Contact::set_phone_num(void)
{
	std::string arg;
	std::cout << "Input phone_num : ";
	getline(std::cin, arg);
	this -> phone_num = arg;
}

void	Contact::set_dark_secret(void)
{
	std::string arg;
	std::cout << "Input dark_secret : ";
	getline(std::cin, arg);
	this -> dark_secret = arg;
}

std::string	Contact::get_f_name(void)
{
	return (this -> f_name);
}

std::string	Contact::get_l_name(void)
{
	return (this -> l_name);
}

std::string	Contact::get_nick_name(void)
{
	return (this -> nick_name);
}

std::string	Contact::get_num(void)
{
	return (this -> phone_num);
}

std::string	Contact::get_dark_secret(void)
{
	return (this -> dark_secret);
}

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

//void	Contact::set_f_name(std::string arg)
//{
//	this -> f_name = arg;
//}
//
//void	Contact::set_l_name(std::string arg)
//{
//	this -> l_name = arg;
//}
//
//void	Contact::set_nick_name(std::string arg)
//{
//	this -> nick_name = arg;
//}
//
//void	Contact::set_phone_num(std::string arg)
//{
//	this -> phone_num = arg;
//}
//void	Contact::set_dark_secret(std::string arg)
//{
//	this -> dark_secret = arg;
//}
