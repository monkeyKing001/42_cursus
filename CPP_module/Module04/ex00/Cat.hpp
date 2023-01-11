#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"

#define CAT "CAT"

class Cat : public Animal {
	public:
		void makeSound(void) const;
		Cat& operator=(const Cat& c);
		Cat(void);
		Cat(const Cat& c);
		virtual ~Cat(void);
};

#endif /* CAT_H */
