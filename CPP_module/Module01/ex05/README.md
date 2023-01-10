#function pointer
In C++, function pointers are variables that store the address of a function. Function pointers can be used to call functions indirectly, through the stored address.

Here is an example of declaring a function pointer:
```c++
#include <iostream>

// Declare a function pointer type
typedef int (*FunctionPointer)(int, int);

// Declare a function that takes two integers as arguments
// and returns an integer
int add(int a, int b)
{
    return a + b;
}

int main()
{
    // Declare a function pointer and initialize it
    // with the address of the add function
    FunctionPointer fp = add;

    // Call the function indirectly through the function pointer
    int result = fp(10, 20);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```
