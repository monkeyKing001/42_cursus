#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"

#define DOG "DOG"

class Dog : public Animal {
	public:
		void makeSound(void) const;
		Dog& operator=(const Dog& d);
		Dog(void);
		Dog(const Dog& d);
		virtual ~Dog(void);
};

#endif /* DOG_H */
