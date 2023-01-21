#include "Base.hpp"
//class	D : public Base
//{
//	~D(void);
//};

int main(void)
{
	for (int i = 0 ; i < 10 ; ++i)
	{
		std::cout 
			<< YELLOW
			<< "\n======================      " 
			<< i 
			<< "'s case test begin       =====================\n"
			<< DEFAULT;
		Base*		base = generate();
		std::cout << "Generate a random instance among A/B/C\n";
		std::cout << "pointer p's address is : " << base << "\n";
		identify(base);
		identify(*base);
		delete base;
	}
//	{
//	std::cout 
//		<< GREEN
//		<< "\n======================      No pointer, reference" 
//		<< " case test begin       =====================\n"
//		<< DEFAULT;
//	Base *base = new D;
//	identify(base);
//	identify(*base);
//	delete base;
//	}

	return (0);
}
