#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"
#include "Brain.hpp"

#define DOG "DOG"

class Dog : public Animal {

	private:
		Brain *brain;

	public:
		void			setBrain(const Brain& b);
		Brain*	getBrain(void) const;

		void makeSound(void) const;
		Dog& operator=(const Dog& d);
		Dog(void);
		Dog(const Dog& d);
		virtual ~Dog(void);
};

#endif /* DOG_H */
