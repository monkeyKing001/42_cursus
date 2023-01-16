#ifndef ANIMAL_H
#define ANIMAL_H
#include <iomanip>
#include <iostream>
#include <string>
#define ANIMAL "ANIMAL"

class Animal {
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(const Animal& a);
		Animal& operator=(const Animal& a);
		virtual ~Animal(void);

		void	setType(const std::string& type);
		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

std::ostream& operator<<(std::ostream& o, const Animal& a);

#endif /* ANIMAL_H */
