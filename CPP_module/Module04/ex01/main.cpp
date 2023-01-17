#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
void address_cat_test(Cat *cat, std::string name)
{
	std::cout
		<< name
		<< " cat's Address : \t"
		<< cat
		<< "\n"
		<< name
		<< " cat's Brain Address : \t"
		<< cat -> getBrain()
		<< "\n";
}

void address_dog_test(Dog* dog, std::string name)
{
	std::cout
		<< name
		<< " dog's Address : \t"
		<< dog
		<< "\n"
		<< name
		<< " dog's Brain Address : \t"
		<< dog -> getBrain()
		<< "\n";
}

int main() {

	std::cout << "\n==========    Basic Test    ===========\n";
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	i -> makeSound();
	j -> makeSound();

	std::cout << "\n==========    Downcast Test    ===========\n";
	//i -> setBrain(brain_in_cat); //i is Animal pointer so, cannot call setBrain() fucntion
	//j -> setBrain(brain_in_cat); //j is Animal pointer so, cannot call setBrain() fucntion
	Cat* dw_cst_cat = dynamic_cast<Cat*>(const_cast <Animal *> (i));
	Dog* dw_cst_dog = dynamic_cast<Dog *>(const_cast <Animal *> (j));
	dw_cst_cat -> getBrain() -> brain_scan();

	std::cout << "\n==========    Default Brain Test    ===========\n";
	std::cout << "dw_cst_cat's 0's Idea : "<<dw_cst_cat -> getBrain() -> getIdea(0) << "\n";
	dw_cst_cat -> getBrain() -> setIdea((const int)0, "GET ME CHEWRRRR!!");
	std::cout << "dw_cst_cat's 0's Idea : "<<dw_cst_cat -> getBrain() -> getIdea(0) << "\n";

	std::cout << "\n==========    Brain'=operator' Test    ===========\n";
	std::cout << dw_cst_dog -> getBrain() -> getIdea(0) << "\n";
	//pull out dog's brain;
	Brain *dog_brain = dw_cst_dog -> getBrain();
	*dog_brain = *dw_cst_cat -> getBrain();
	std::cout << "dog_brain's 0's Idea : "<< dog_brain -> getIdea(0) << "\n";

	std::cout << "\n==========   Set, Get Brain Test after copy   ===========\n";
	dw_cst_dog -> setBrain(*dog_brain);
	std::cout << dw_cst_dog -> getBrain() -> getIdea(0) << "\n";
	std::cout << "dw_cst_dog's 0's Idea : "<<dw_cst_cat -> getBrain() -> getIdea(0) << "\n";

	std::cout << "\n==========   Cat, Dog Deep Copy Test   ===========\n";
	Brain *brain_in_android_cat = new Brain();
	brain_in_android_cat -> setIdea(0, "Destory the Earth");
	Cat *android_cat = new Cat();
	//copy assignment test;
	android_cat -> setBrain(*brain_in_android_cat);
	std::cout << android_cat -> getBrain() -> getIdea(0) << "\n";
	*dw_cst_cat = *android_cat;
	std::cout << "After '='operator, dw_cst_cat's First Idea became : ";
	std::cout << dw_cst_cat -> getBrain() -> getIdea(0) << "\n";
	//copy test;
	Brain *brain_in_android_dog = new Brain();
	brain_in_android_dog -> setIdea(0, "Destory all the Android Cats");
	Dog *android_dog = new Dog();
	android_dog->setBrain(*brain_in_android_dog);
	Dog *android_dog2 = new Dog(*android_dog);
	std::cout << "android_dog's 0's Idea : "<< android_dog -> getBrain() -> getIdea(0) << "\n";
	std::cout << "android_dog2's 0's Idea : "<< android_dog2 -> getBrain() -> getIdea(0) << "\n";

	std::cout << "\n==========   Deep Address Test   ===========\n";
	address_cat_test(dw_cst_cat, "dw_cst_cat");
	address_dog_test(dw_cst_dog, "dw_cst_dog");
	address_cat_test(android_cat, "android_cat");
	address_dog_test(android_dog, "android_dog");
	address_dog_test(android_dog2, "android_dog2");

	std::cout << "\n==========    Animal array test    ===========\n";
	Animal *cats_n_dogs[4];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			cats_n_dogs[i] = new Dog();
		else
			cats_n_dogs[i] = new Cat();
	}

	std::cout << "\n==========    Animal array destory test    ===========\n";
	for (int i = 0; i < 4; i++)
		delete cats_n_dogs[i];

	delete i;
	i = NULL;
	delete j;//should not create a leak delete i;
	j = NULL;
	delete android_cat;
	android_cat = NULL;
	delete android_dog;
	android_dog = NULL;
	delete android_dog2;
	android_dog2 = NULL;
	return 0;
}
