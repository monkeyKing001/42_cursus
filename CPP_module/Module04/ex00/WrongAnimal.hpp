#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
#include <iomanip>
#include <iostream>
#include <string>

#define W_SIZE            12
#define WA_NAME           "WrongAnimal"

class WrongAnimal {
	protected:
		std::string _type;

	public:
		void setType(const std::string& type);
		std::string getType(void) const;
		void makeSound(void) const;

		WrongAnimal& operator=(const WrongAnimal& wa);
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& wa);
		virtual ~WrongAnimal(void);
};

std::ostream& operator<<(std::ostream& o, const WrongAnimal& wa);

#endif /* WRONGANIMAL_H */
