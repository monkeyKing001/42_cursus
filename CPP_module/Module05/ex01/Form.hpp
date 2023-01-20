#ifndef FORM_H
#define FORM_H
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#define GRADE_MAX	1
#define GRADE_MIN	150

class Bureaucrat;

class Form
{

	private:
		const std::string _name;
		const int _grade_sign;
		const int _grade_exec;
		bool _signed;

	public:
		Form(void);
		Form(const Form& obj);
		Form& operator = (const Form& obj);
		~Form(void);
		Form(const std::string& name, const int& sign_grade, const int& exec_grade);

		//getter
		const std::string& getName(void) const;
		const int& getSignGrade(void) const;
		const int& getExecGrade(void) const;
		const bool& getSigned(void) const;

		//mem func
		void beSigned(const Bureaucrat& b);

		//throw
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};
std::ostream& operator<<(std::ostream& o, const Form& f);
#endif /* FORM_H */
