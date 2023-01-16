#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"
#include "Brain.hpp"

#define CAT "CAT"

class Cat : public Animal {
	
	private:
		Brain *brain;

	public:
		void			setBrain(const Brain& b);
		Brain*	getBrain(void) const;

		Cat(void);
		Cat(const Cat& c);
		virtual ~Cat(void);
		Cat& operator=(const Cat& c);
		void makeSound(void) const;
};

#endif /* CAT_H */
