# Reference `&`

References are used in C++ for a number of reasons, including:

- To avoid the overhead of using pointers. Accessing an object through a reference is generally faster than accessing it through a pointer, as there is no need to dereference the pointer.
- To make the code easier to read and understand. References can make the code more concise, as they allow you to access an object directly, rather than through a pointer.
- To make the code safer and less error-prone. References cannot be null, so you don't need to worry about checking for null pointers. In addition, references are automatically dereferenced when used, so you don't need to worry about forgetting to dereference a pointer.
- To allow functions to modify the objects passed to them. When you pass an object to a function using a reference, the function can modify the object directly, rather than having to return a modified copy of the object.


# Reference `&` vs pointer `*`

In C++, a reference is an alias for an existing object or variable. It is denoted by the symbol '&' in front of a variable's name. When you use a reference, you are accessing the object or variable directly, rather than through a pointer.

A pointer is a variable that stores the memory address of another object or variable. It is denoted by the symbol `*` in front of a variable's name. When you use a pointer, you are accessing the object or variable indirectly, through the memory address stored in the pointer.

Here are some key differences between references and pointers:

References cannot be null, whereas pointers can.
You cannot change the reference to refer to a different object or variable after it is initialized, whereas you can change the value of a pointer to point to a different memory address.
References are easier to use and less error-prone than pointers, as they do not require manual memory management.

Here is an example that demonstrates the difference between references and pointers:

```c++
#include <iostream>

int main()
{
	int num = 123;
	int& ref = num; // Declare a reference 'ref' to 'num'
	int* ptr = # // Declare a pointer 'ptr' to 'num'

	Copy code
	// Modify the value of 'num' using the reference
	ref = 456;
	std::cout << "num: " << num << std::endl;  // Output: num: 456

	// Modify the value of 'num' using the pointer
	*ptr = 789;
	std::cout << "num: " << num << std::endl;  // Output: num: 789

	return 0;
}
```

# summary
| category | pointer | reference |
| :--: | :--: | :--: |
| assign | `int a = 10, int *pa =  &a` | int a = 10, int &ra  = a |
| NULLABLE | NULLABLE | UNNULLABLE |
| address | &a != &pa, pa = &a | &a == &ra |
| valuse | a = 10, pa = 0x00...0a | a = 10, ra = 10 |
| access | can access from pa(0x00...0a) to everywhere(0xff...ff ~ 0x00...00) | can access only ref |
| register | use 1 register | use 1 register |
