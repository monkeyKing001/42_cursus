#ifndef FORM_H
#define FORM_H
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#define GRADE_MAX	1
#define GRADE_MIN	150

#define DEFAULT  "\033[0;39m"
#define GRAY  "\033[0;90m"
#define RED  "\033[0;91m"
#define GREEN  "\033[0;92m"
#define YELLOW  "\033[0;93m"
#define BLUE  "\033[0;94m"
#define MAGENTA  "\033[0;95m"
#define CYAN  "\033[0;96m"
#define WHITE  "\033[0;97m"



class Bureaucrat;

class AForm
{

	private:
		const std::string _name;
		const int _grade_sign;
		const int _grade_exec;
		bool _signed;

	public:
		virtual ~AForm(void);
		AForm(const std::string& name, const int& sign_grade, const int& exec_grade);
		AForm(void);
		AForm(const AForm& obj);
		AForm& operator = (const AForm& obj);

		//getter
		const std::string& getName(void) const;
		const int& getSignGrade(void) const;
		const int& getExecGrade(void) const;
		const bool& getSigned(void) const;

		//mem func
		void beSigned(const Bureaucrat& b);
		void executable(const Bureaucrat& b) const;
		virtual void execute(const Bureaucrat& b) const = 0;

		//throw
		//throw 1. Over Grade Excpetion
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		//throw 2. Under Grade Excpetion
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		//throw 3. Not Signed Excpetion
		class NotSignedException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		//throw 4. Cannot Execute Exception
		class UnauthorizedExecutorException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		class FileOpenFailException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};
std::ostream& operator<<(std::ostream& o, const AForm& f);
#endif /* FORM_H */
