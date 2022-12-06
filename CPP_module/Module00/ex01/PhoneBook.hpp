#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <limits>
#include <iomanip>
#include <iostream>
#include <string>
#include "Contact.hpp"

#define CMD_NO_MATCH     -1
#define CMD_EXIT         0
#define CMD_ADD          1
#define CMD_SEARCH       2

#define F_F_NAME         0
#define F_L_NAME         1
#define F_ALIAS          2
#define F_PHONE          3
#define F_SECRET         4

#define PB_SIZE          8
#define PADD_SIZE        10

/*************************************************/
/****************      color       ***************/
/*************************************************/
#define RED              "\033[0;31m"
#define YELLOW           "\033[1;33m"
#define GREEN            "\033[0;32m"
#define BLUE             "\033[0;34m"
#define DEFAULT	         "\033[0;0m"

/*************************************************/
/****************      class       ***************/
/*************************************************/
class PhoneBook{
	private:
//		const std::string exit;
//		const std::string add;
//		const std::string search;
		int	contact_num;
		std::string cmd;
		Contact contacts[8];

	public:
		void	init_book(void);
		void	add_contact(void);
		void	print_book(void);
		void	print_label(void);
		void	print_field_w10(std::string _text);
		void	select_contact(void);
};
#endif
