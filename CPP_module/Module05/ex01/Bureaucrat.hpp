#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <iostream>
#include <string>
#include <exception>
#define GRADE_MAX	1
#define GRADE_MIN	150

class Form;

class Bureaucrat
{

	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator = (const Bureaucrat& obj);
		~Bureaucrat(void);
		Bureaucrat(const std::string &name, const int& grade);
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
		const std::string& getName(void) const;
		const int& getGrade(void) const;
		int& incrementGrade(void);
		int& decrementGrade(void);
		void signForm(const Form& form) const;
};
std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);
#endif /* BUREAUCRAT_H */
