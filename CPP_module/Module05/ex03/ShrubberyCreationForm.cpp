#include "ShrubberyCreationForm.hpp"
#include <ostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(SHRU_NAME, SHRU_SIGN_GRADE, SHRU_EXEC_GRADE)
{
	this -> _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(SHRU_NAME, SHRU_SIGN_GRADE, SHRU_EXEC_GRADE)
{
	this -> _target = "None target";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& p) : AForm(SHRU_NAME, SHRU_SIGN_GRADE, SHRU_EXEC_GRADE)
{
	this -> _target = p.getTarget();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& p)
{
	this -> _target = p.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

const std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this -> _target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	executable(executor);
	std::stringstream fileName;
	fileName << getTarget() << "_shrubbery";
	std::ofstream out(fileName.str(), std::ofstream::out | std::ofstream::trunc);
	if (!out.good())
		throw FileOpenFailException();
	std::string my_shruberry = 
"                                              .         \n"
"                 .              .              ;%     ;;   \n"
"                   ,           ,                :;%  %;   \n"
"                    :         ;                   :;%;'     .,   \n"
"           ,.        %;     %;            ;        %;'    ,;\n"
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
"                `%;.     ;%;     %;'         `;%%;.%;'\n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
"                    `:%;.  :;bd%;          %;@%;'\n"
"                      `@%:.  :;%.         ;@@%;'   \n"
"                        `@%.  `;@%.      ;@@%;         \n"
"                          `@%%. `@%%    ;@@%;        \n"
"                            ;@%. :@%%  %@@%;       \n"
"                              %@bd%%%bd%%:;     \n"
"                                #@%%%%%:;;\n"
"                                %@@%%%::;\n"
"                                %@@@%(o);  . '         \n"
"                                %@@@o%;:(.,'         \n"
"                            `.. %@@@o%::;         \n"
"                               `)@@@o%::;         \n"
"                                %@@(o)::;        \n"
"                               .%@@@@%::;         \n"
"                               ;%@@@@%::;.          \n"
"                              ;%@@@@%%:;;;. \n"
"                          ...;%@@@@@%%:;;;;,..\n";
	out << my_shruberry;
	out.close();
	std::cout << "\n";
}

