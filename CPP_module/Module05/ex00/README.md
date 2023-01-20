
<details>
<summary> <font size="5"> Try, Catch </font> </summary>
<div markdown="1">

In C++, the try-catch statement is used to handle exceptions, which are events that occur during the execution of a program that disrupt the normal flow of control. When an exception is thrown, the program's execution jumps to the nearest enclosing catch block that can handle the exception.

The try block contains the code that may throw an exception. If an exception is thrown, the program's execution jumps to the catch block that follows the try block.

The catch block contains the code that will handle the exception. It specifies the type of exception that it can handle, and the exception object is passed to the catch block as a parameter.

```c++
try {
    // code that may throw an exception
} catch (ExceptionType e) {
    // code to handle the exception
}
```
It is also possible to have multiple catch blocks to handle different types of exceptions, and a catch block with no parameter can be used to catch any exception.

```c++
try {
    // code that may throw an exception
} catch (ExceptionType1 e) {
    // code to handle ExceptionType1
} catch (ExceptionType2 e) {
    // code to handle ExceptionType2
} catch (...) {
    // code to handle any other exceptions
}

```
It's also worth noting that when an exception is thrown and not caught, the program will terminate.
</div>
</details>


<details>
<summary> <font size="5"> std::exception </font> </summary>
<div markdown="1">

The what() function in std::exception is a virtual function that returns a null-terminated character string, which describes the exception. You can override this function in a custom exception class to provide a more informative error message.

### std::exception::what
`virtual const char* what() const throw();` (until C++11)
`virtual const char* what() const noexcept;` (since C++11)
Returns the explanatory string.

#### Parameters
---
(none)

#### Return value
---
Pointer to a null-terminated string with explanatory information. The pointer is guaranteed to be valid at least until the exception object from which it is obtained is destroyed, or until a non-const member function on the exception object is called.

</div>
</details>


<details>
<summary> <font size="5"> Stack unwinding </font> </summary>
<div markdown="1">

In C++, when an exception is thrown, the program's execution jumps to the nearest enclosing catch block that can handle the exception. This process is called "stack unwinding".

When an exception is thrown, the program starts searching for a catch block that can handle the exception. The search starts with the innermost function call and goes outwards, unwinding the stack as it goes. The program checks each function's stack frame for a matching catch block, and when a match is found, the program transfers control to that catch block.

As the stack is unwound, the program calls the destructors for all objects with automatic storage duration that were created within the scope of the function being unwound. This is important because it allows objects to clean up any resources they have acquired, such as dynamically allocated memory or open files.

When the catch block completes its execution, the program continues executing at the point following the try-catch statement. If the catch block did not handle the exception, the process of stack unwinding continues until a matching catch block is found or until the program terminates.

It's worth noting that stack unwinding happens only for exception of classes that inherit from std::exception, and if it can't find any matching catch block, the program will terminate by calling std::terminate function, if the exception is not handled.

Also, it's worth mentioning that stack unwinding can be halted by re-throwing an exception, by calling std::terminate() function, or by executing a return statement before the end of the function.

example)
```c++
#include <iostream>
using namespace std;

void f3(int& n){
    if (n<5) throw n;
    cout << n << endl;
}

void f2(int& n){
    f3(++n);
    cout << n << endl;
}

void f1(int& n){
    try {
        f2(++n);
    }
    catch(int n){
        throw n+3;
    }
    cout << n << endl;
}

int main(){
    int n = 1;
    try {
        f1(++n);
    }
    catch(int n){
        cout << n << endl;
    }
    cout << n << endl;
    
    return 0;
}
```

catch statement with ellipsis arguments can catch any type of execption during program.
```c++
catch(...)
{
}
```

- summary 
1. When program catches exception, it jumps to nearset catch black and unwinds functions and codes stacked in try block.
2. With unwinding stacks, `automatic` resources(dynamic memory, open files etc.) used in try-catch statement automatically will be freed but heap memory(`new`, `malloc`) will not.
3. After catching exception, program continues excuting at the point following try-catch statement. 
4. Stack unwound will not happen if try-catch statement doesn't exist.
5. If exception cannot meet the program will terminate by calling `std::terminate` function.
6. By `return` statement, stack unwinding can be halted
7. catch statement with ellipsis arguments can catch any type of execption during program.

</div>
</details>
