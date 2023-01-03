#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <limits>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"

#define PB_SIZE			8
#define PADD_SIZE		10
#define FIRST_NAME		F_MODE
#define LAST_NAME		L_MODE
#define NICK_NAME		N_MODE
#define PHONE_NUMBER	P_MODE
#define DARK_SECRET		D_MODE

#define	F_MODE			0
#define	L_MODE			1
#define	N_MODE			2	
#define	P_MODE			3
#define	D_MODE			4

/*************************************************/
/****************      color       ***************/
/*************************************************/
#define RED              "\033[0;31m"
#define YELLOW           "\033[1;33m"
#define GREEN            "\033[0;32m"
#define BLUE             "\033[0;34m"
#define DEFAULT	         "\033[0;0m"
#define WHITE_SPACE		" \t\r\n\v\f"

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
		Contact contacts[PB_SIZE];

	public:
		void	init_book(void);
		void	add_contact(void);
		void	print_book(void);
		void	print_label(void);
		void	print_field_w10(std::string _text);
		void	select_contact(void);
};
#endif
