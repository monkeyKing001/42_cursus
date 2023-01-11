#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal* meta = new Animal();
	//upcasting
	std::cout << "\n===============       upcasting test       ===============\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* WrongAnimal = new WrongAnimal();
	const Animal* WrongCat = new WrongCat();

	std::cout << "\n===============       getType test       ===============\n";
	std::cout << j -> getType() << " " << std::endl;
	std::cout << i -> getType() << " " << std::endl;

	std::cout << "\n===============       makeSound test       ===============\n";
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n===============       destruction test       ===============\n";
	return 0;
}
