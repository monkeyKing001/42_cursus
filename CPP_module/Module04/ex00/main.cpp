#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <typeinfo>
int main()
{
	//upcasting
	std::cout << "\n===============       upcasting test       ===============\n";
	//implicit upcasting
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	// i can access only Animal's member

	std::cout << "\n===============       downacasting test       ===============\n";
	Animal* anim = new Animal();
	Dog *static_down_casting = static_cast<Dog*>(anim);
	static_down_casting -> makeSound();
	//const Cat* dc = new Animal();
	//const Dog* dd = new Animal();
	//Dog *dg_dwn = dynamic_cast< const_cast< <Dog*>(i) > >(i);

	std::cout << "\n===============       getType test       ===============\n";
	//type is animal but its member function is called from Cat
	const std::type_info &t = typeid(i);
	std::cout << t.name() << std::endl;
	std::cout << i -> getType() << " " << std::endl;
	std::cout << j -> getType() << " " << std::endl;

	std::cout << "\n===============       makeSound test       ===============\n";
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();

//	std::cout << "\n===============     overiding test after downacasting     ===============\n";
//	//Animal *del_cnst = const_cast<Animal *>(i);
//	//Dog *dg_dwn = dynamic_cast<Dog *>(del_cnst);
//	Dog *dg_dwn_del_cnst = dynamic_cast<Dog *>(const_cast<Animal *>(i));
//	dg_dwn_del_cnst->makeSound();

	std::cout << "\n===============       No Virtual Keyword Test       ===============\n";
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	const std::type_info &t1 = typeid(wa);
	const std::type_info &t2 = typeid(wc);
	wa->makeSound();
	wc->makeSound();
	std::cout << t1.name() << " " << std::endl;
	std::cout << t2.name() << " " << std::endl;
	std::cout << wa -> getType() << " " << std::endl;
	std::cout << wc -> getType() << " " << std::endl;
	wa -> makeSound();
	wc -> makeSound();

	std::cout << "\n===============       Make No Virtual Keyword Tests work!       ===============\n";
	WrongAnimal *dn_cst = const_cast<WrongAnimal *>(wa);
	WrongCat *dn_cat = static_cast<WrongCat *>(dn_cst);
	dn_cat->makeSound();

	std::cout << "\n===============       destruction test       ===============\n";
	delete meta;
	delete i;
	delete j;
	delete wa;
	delete wc;
	delete anim;
//	delete static_down_casting;
//	delete dg_dwn_del_cnst;

	return 0;
}
