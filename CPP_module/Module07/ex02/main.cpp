#include <iostream>
#include "Array.hpp"

// #define MAX_VAL 750

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));

// /*
//     std::cout << "numbers : ";
//     for (int i = 0; i < 10; i++)
//     {
//         std::cout << numbers[i] << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "mirrors : ";
//     for (int i = 0; i < 10; i++)
//     {
//         std::cout << mirror[i] << " ";
//     }
//     std::cout << std::endl;
// */

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }

//     std::cerr << " ----------- here 1 -----------------\n";
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
// /*
//     std::cout << "numbers : ";
//     for (int i = 0; i < 10; i++)
//     {
//         std::cout << numbers[i] << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "mirrors : ";
//     for (int i = 0; i < 10; i++)
//     {
//         std::cout << mirror[i] << " ";
//     }
//     std::cout << std::endl;
// */

//     std::cerr << " ----------- here 2 -----------------\n";
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     std::cerr << " ----------- here 3 -----------------\n";
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     std::cerr << " ----------- here 4 -----------------\n";
//     delete [] mirror;//
//     return 0;
// }


#define SIZE 10

int main( void )
{
    std::cout << "-----------------------------------------------------" << std::endl;

    Array< int > intArray( SIZE );
    Array< int > intArray2( SIZE - 5 );

    for ( unsigned int i = 0; i < intArray.size(); i++ )
        intArray[i] = i * 2;

    std::cout << "Int Array 1 size: " << intArray.size() << std::endl;
    std::cout << "Int Array 1: " << intArray << std::endl;
	std::cout << "intArray[0] : "<<intArray[0] << "\n";
	std::cout << "intArray[4294967297] : "<<intArray[4294967297] << "\n";

    std::cout << std::endl;
    intArray2 = intArray;

    std::cout << "Int Array 2 size: " << intArray2.size() << std::endl;
    std::cout << "int Array 2: " << intArray2 << std::endl;
    std::cout << std::endl;

    try {
        std::cout << "Accessing a valid index: " << intArray[5] << std::endl;
        std::cout << "Accessing an invalid index: " << intArray[SIZE] << std::endl;
    } catch ( Array< int >::OutOfBoundsException& e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------------------------" << std::endl;

    return ( 0 );
}
