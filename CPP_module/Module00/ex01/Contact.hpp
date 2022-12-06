#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>

class Contact{
	private:
		std::string f_name;
		std::string l_name;
		std::string nick_name;
		std::string phone_num;
		std::string	dark_secret;

	public:
		//setter
		void	init_contact(int mode, std::string *in, std::string &phrase);
		void	set_field(void);
		void	set_f_name(void);
		void	set_l_name(void);
		void	set_nick_name(void);
		void	set_phone_num(void);
		void	set_dark_secret(void);
//		void	set_f_name(std::string);
//		void	set_l_name(std::string);
//		void	set_nick_name(std::string);
//		void	set_phone_num(std::string);
//		void	set_dark_secret(std::string);

		//getter
		std::string get_f_name(void);
		std::string get_l_name(void);
		std::string get_nick_name(void);
		std::string get_num(void);
		std::string get_dark_secret(void);

		//print
		void	print_contact(void);
};

#endif
