#ifndef WRONGCAT_H
#define WRONGCAT_H
#include "WrongAnimal.hpp"

#define WRONG_CAT "WRONG_CAT"

class WrongCat : public WrongAnimal {
	public:
		void makeSound(void) const;

		WrongCat& operator=(const WrongCat& wc);
		WrongCat(void);
		WrongCat(const WrongCat& wc);
		virtual ~WrongCat(void);
};

#endif /* WRONGCAT_H */
