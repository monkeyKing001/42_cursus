# `std::string::npos`
In the C++ programming language, std::string::npos is a constant value that is used to indicate that a string member function has not found a requested sub-string within a given string.

For example, the std::string::find() function returns the position of the first occurrence of a sub-string within a string. If the sub-string is not found, the function returns std::string::npos.

Here is an example of using std::string::find() and std::string::npos:

```c++
#include <string>
#include <iostream>

int main()
{
    std::string str = "Hello, world!";
    std::size_t pos = str.find("world");

    if (pos != std::string::npos)
    {
        std::cout << "Found sub-string at position: " << pos << std::endl;
    }
    else
    {
        std::cout << "Sub-string not found" << std::endl;
    }

    return 0;
}

```

output will be if find() succeed,
```c++
Found sub-string at position: 7
```
else

```c++
Sub-string not found
```
std::string::npos is defined as a value that is larger than the maximum size that a std::string object can have, so it can be used to indicate that a requested sub-string was not found in a string.
