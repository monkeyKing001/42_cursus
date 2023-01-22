//#include <iostream>
//#include "Array.hpp"
//
//#define MAX_VAL 750
//int main(int, char**)
//{
//    Array<int> numbers(MAX_VAL);
//    int* mirror = new int[MAX_VAL];
//    srand(time(NULL));
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        const int value = rand();
//        numbers[i] = value;
//        mirror[i] = value;
//    }
//    //SCOPE
//    {
//        Array<int> tmp = numbers;
//        Array<int> test(tmp);
//    }
//
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        if (mirror[i] != numbers[i])
//        {
//            std::cerr << "didn't save the same value!!" << std::endl;
//            return 1;
//        }
//    }
//    try
//    {
//        numbers[-2] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//    try
//    {
//        numbers[MAX_VAL] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        numbers[i] = rand();
//    }
//    delete [] mirror;//
//    return 0;
//}
#include <iostream>
#include <limits>
#include "Array.hpp"

#define SIZE 10

int main( void )
{
    std::cout << "--------------------------------------        TEST START         ----------------------------------" << "\n";

    std::cout << YELLOW << "\n######     CONSTURCTION  TEST     ######" << "\n" << DEFAULT;
	Array< int > defIntArr;
    Array< int > intArray( SIZE );
    for ( unsigned int i = 0; i < intArray.size(); i++ )
        intArray[i] = i * 2;
	defIntArr = intArray;
	Array< int > copyArr(defIntArr);

	std::cout << "intArray : \t" << intArray << "\n";
	std::cout << "defIntArr : \t" << defIntArr << "\n";
	std::cout << "copyArr : \t" << copyArr << "\n";


	std::cout << YELLOW << "\n######      DEEP COPY TEST     #########\n" << DEFAULT;
    for ( unsigned int i = 0; i < intArray.size(); i++ )
        intArray[i] = i * 3;
	std::cout << "intArray : \t" << intArray << "\n";
	std::cout << "defIntArr : \t" << defIntArr << "\n";
	std::cout << "copyArr : \t" << copyArr << "\n";


	std::cout << YELLOW << "\n######     [] operator test    #########\n" << DEFAULT;
	std::cout << "intArray[0] : "<<intArray[0] << "\n";
	std::cout << "intArray[2] : "<<intArray[2] << "\n";
	std::cout << "intArray[9] : "<<intArray[9] << "\n";

    std::cout << "defIntArr[0]: " << defIntArr[0] << "\n";
    std::cout << "defIntArr[1]: " << defIntArr[1] << "\n";
    std::cout << "defIntArr[5]: " << defIntArr[5] << "\n";

	std::cout << YELLOW << "\n######     unvailed index test    #########\n" << DEFAULT;
    try {
		std::cout << "intArray[-1] : "<< intArray[-1] << "\n";
    } catch ( Array< int >::OutOfBoundsException& e ) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << "\n";
    }
    try {
		std::cout << "intArray[-2] : "<< intArray[-2] << "\n";
    } catch ( Array< int >::OutOfBoundsException& e ) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << "\n";
    }
    try {
		std::cout << "intArray[10] : "<< intArray[10] << "\n";
    } catch ( Array< int >::OutOfBoundsException& e ) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << "\n";
    }
    try {
		std::cout << "UINT_MAX     : " << UINT_MAX  << "\n";
		std::cout << "UINT_MAX + 3 : " << UINT_MAX + 3 << "\n";
		std::cout << "intArray[UINT_MAX + 3] : "<< intArray[UINT_MAX + 3] << "\n";
    } catch ( Array< int >::OutOfBoundsException& e ) {
        std::cout << RED << "Error: " << e.what() << DEFAULT << "\n";
    }
//    try {
//		std::cout << "intArray[-1 - 4294967295] : "<< intArray[-1 - 4294967295]<< "\n";
//    } catch ( Array< int >::OutOfBoundsException& e ) {
//        std::cout << RED << "Error: " << e.what() << DEFAULT << "\n";
//    }
//    try {
//		std::cout << "-1 as unsigned int     : " << (unsigned int)-1  << "\n";
//		std::cout << "-1 as int     : " << (int)-1  << "\n";
//		std::cout << "UINT_MAX + 3 : " << UINT_MAX + 3 << "\n";
//		std::cout << "intArray[UINT_MAX + 3] : "<< intArray[UINT_MAX + 3] << "\n";
//    } catch ( Array< int >::OutOfBoundsException& e ) {
//        std::cout << RED << "Error: " << e.what() << DEFAULT << "\n";
//    }
    std::cout << "--------------------------           END OF TEST             -----------------------------------" << "\n";

    return ( 0 );
}
