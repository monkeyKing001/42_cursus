#include <iostream>
int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Print memory address" << std::endl;
	std::cout << "str address       : " << &str << std::endl;
	std::cout << "stringPRT address : " << stringPTR << std::endl;
	std::cout << "stringREF address : " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "Print value of string" << std::endl;
	std::cout << "str value       : " << str << std::endl;
	std::cout << "stringPRT value : " << *stringPTR << std::endl;
	std::cout << "stringREF value : " << stringREF << std::endl;

	return (0);
}

//int	main(void)
//{
//	std::string	str = "HI THIS IS BRAIN";
//	std::string str2 = "HI THIS IS ANOTEHR BRAIN";
//	std::string	*stringPTR = &str;
//	std::string	*stringPTR2 = &str2;
//	//std::string &UNNULLABLE;
//	std::string	&stringREF = str;
//	std::string &stringREF2 = str2;
//
//	std::cout << "====================    ADDRESS      ===================\n";
//	std::cout << "Print memory address" << std::endl;
//	std::cout << "str address       : " << &str << std::endl;
//	std::cout << "str2 address       : " << &str2 << std::endl;
//	std::cout << "stringPRT address : " << stringPTR << std::endl;
//	std::cout << "stringPRT2 address : " << stringPTR2 << std::endl;
//	std::cout << "stringREF address : " << &stringREF << std::endl;
//	std::cout << "stringREF2 address : " << &stringREF2 << std::endl;
//	std::cout << std::endl;
//
//	std::cout << "====================    VALUE      ===================\n";
//	std::cout << "Print value of string" << std::endl;
//	std::cout << "str value       : " << str << std::endl;
//	std::cout << "str2 value       : " << str2 << std::endl;
//	std::cout << "stringPRT value : " << *stringPTR << std::endl;
//	std::cout << "stringPRT2 value : " << *stringPTR2 << std::endl;
//	std::cout << "stringREF value : " << stringREF << std::endl;
//	std::cout << "stringREF2 value : " << stringREF2 << std::endl;
//	std::cout << std::endl;
//
//	std::cout << "====================    CHANGE POINTER     ===================\n";
//	stringPTR2 = &str;
//	std::cout << "Print value of string" << std::endl;
//	std::cout << "str value       : " << str << std::endl;
//	std::cout << "str2 value       : " << str2 << std::endl;
//	std::cout << "stringPRT value : " << *stringPTR << std::endl;
//	std::cout << "stringPRT2 value : " << *stringPTR2 << std::endl;
//	std::cout << "stringREF value : " << stringREF << std::endl;
//	std::cout << "stringREF2 value : " << stringREF2 << std::endl;
//	std::cout << std::endl;
//
//	std::cout << "====================    CHANGE REFERENCE      ===================\n";
//	stringREF2 = str;
//	std::cout << "Print value of string" << std::endl;
//	std::cout << "str value       : " << str << std::endl;
//	std::cout << "str2 value       : " << str2 << std::endl;
//	std::cout << "stringPRT value : " << *stringPTR << std::endl;
//	std::cout << "stringPRT2 value : " << *stringPTR2 << std::endl;
//	std::cout << "stringREF value : " << stringREF << std::endl;
//	std::cout << "stringREF2 value : " << stringREF2 << std::endl;
//	std::cout << std::endl;
//
//	////     reorder!!!!  /////
//	stringPTR2  = &str2;
//	stringREF2 = str2;
//	std::cout << "====================    CHANGE POINTER's VALUE     ===================\n";
//	*stringPTR2 = "changed PTR2's value";
//	std::cout << "Print value of string" << std::endl;
//	std::cout << "str value       : " << str << std::endl;
//	std::cout << "str2 value       : " << str2 << std::endl;
//	std::cout << "stringPRT value : " << *stringPTR << std::endl;
//	std::cout << "stringPRT2 value : " << *stringPTR2 << std::endl;
//	std::cout << "stringREF value : " << stringREF << std::endl;
//	std::cout << "stringREF2 value : " << stringREF2 << std::endl;
//	std::cout << std::endl;
//
//	std::cout << "====================    CHANGE REFERENCE'S VALUE      ===================\n";
//	stringREF2 = "changed REF2's VALUE";
//	std::cout << "Print value of string" << std::endl;
//	std::cout << "str value       : " << str << std::endl;
//	std::cout << "str2 value       : " << str2 << std::endl;
//	std::cout << "stringPRT value : " << *stringPTR << std::endl;
//	std::cout << "stringPRT2 value : " << *stringPTR2 << std::endl;
//	std::cout << "stringREF value : " << stringREF << std::endl;
//	std::cout << "stringREF2 value : " << stringREF2 << std::endl;
//	std::cout << std::endl;
//
//
//	std::cout << "====================    MOVE POINTER and address      ===================\n";
//	stringPTR2 = &(str2) + 1;
//	(&stringREF2)++;
//	std::cout << "Print value of string" << std::endl;
//	std::cout << "str value       : " << str << std::endl;
//	std::cout << "str2 value       : " << str2 << std::endl;
//	std::cout << "stringPRT value : " << *stringPTR << std::endl;
//	std::cout << "stringPRT2 value : " << *stringPTR2 << std::endl;
//	std::cout << "stringREF value : " << stringREF << std::endl;
//	std::cout << "stringREF2 value : " << stringREF2 << std::endl;
//	std::cout << std::endl;
//	return (0);
//}
