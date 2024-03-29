#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"

#define CAT "CAT"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat& c);
		virtual ~Cat(void);
		Cat& operator=(const Cat& c);
		void makeSound(void) const;
};

#endif /* CAT_H */
