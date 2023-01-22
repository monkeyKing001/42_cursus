#include "iter.hpp"
#define N 5

int main( void )
{

    std::cout << "\n=========================          test 1 int arr1           ====================\n";
    int arr1[] = { 1, 2, 3, 4, 5 };
    iter(arr1, N, &::print);

    std::cout << "\n=========================          test 2 double arr2            ====================\n";
    double arr2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    iter(arr2, N, &::print);

    std::cout << "\n=========================          test 3 char arr3            ====================\n";
    char arr3[] = { 'a', 'b', 'c', 'd', 'e' };
    iter(arr3, N, &::print);

    std::cout << "\n=========================          test 4 string arr4            ====================\n";
    std::string arr4[] = { "one", "two", "three", "four", "five" };
    iter(arr4, N, &::print);

    return 0;
}
