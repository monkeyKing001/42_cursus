<details>
<summary> <font size="5"> Casting </font> </summary>
<div markdown="1">

### - Implicit
 Implicit casting, also known as type promotion, is a type of casting that occurs automatically when a value of one type is assigned to a variable of a different type. For example, when an `int` is assigned to a `double` variable, the `int` is implicitly cast to a `double`.

 | Type of Casting | Description | Example |
 | --- | --- | --- |
 | Implicit Casting | Occurs automatically when a value of one type is assigned to a variable of a different type. | `double x = 3;` |


### - Explicit
Explicit casting, also known as type casting, is a type of casting that is done explicitly using a cast operator. There are several types of explicit casting in C++, including

 | Type of Casting | Description | Example |
 | --- | --- | --- |
 | `static_cast` | The most basic type of explicit casting, can be used to perform any type of casting, including upcasting and downcasting, as well as casting between arithmetic types. | `int x = 3; double y = static_cast<double>(x);` |
 | `dynamic_cast` |  Performs a run-time check before performing a downcast. It allows you to check if an object is an instance of a derived class before casting it to that class.| `A *a = new B(); B* b = dynamic_cast<B*>(a);` |
 | `const_cast` | Removes the const or volatile qualification from a variable. | `const int x = 3; int y = const_cast<int&>(x);` |
 | `reinterpret_cast` | Casts between two types with no regard for their actual values. Typically used for casting between pointer types or between an integral type and a pointer type. | `int x = 3; char* y = reinterpret_cast<char*>(&x);` |

* Keep in mind that,
When ever you are in doubt about the safety of the casting use dynamic_cast
reinterpret_cast is considered as the most dangerous cast and it should be used with caution
const_cast is used when you want to change the constness of an object.


</div>
</details>


<details>
<summary> <font size="5"> static_cast </font> </summary>
<div markdown="1">

### `static_cast`
---
`static_cast` is a C++ operator that allows you to convert a value of one type to a value of another type, as long as the conversion is defined and can be done at compile-time. It is used to convert between related types, such as a base class to a derived class, or a floating-point value to an integer value.

The general syntax of static_cast is as follows:

```c++
static_cast<new_type>(expression)
```
Where new_type is the type to which you want to convert the expression and expression is the value that you want to cast.

static_cast can be used to perform the following types of conversions:

1. Converting a value of a base class to a value of a derived class or vice versa
2. Converting a value of a non-const type to a value of a const type or vice versa
3. Converting a value of a fundamental data type (e.g. int, float, char) to a value of a different fundamental data type
4. Converting a value of a pointer or reference type to a value of a different pointer or reference type
static_cast will also perform any necessary conversions between related user-defined types, such as converting a derived class to a base class, or converting a class to its non-const version.

It's worth noting that static_cast performs type checking at compile-time, and will generate an error if the conversion is not defined or cannot be done at compile-time. This makes static_cast safer than reinterpret_cast, which does not perform any type checking and can result in undefined behavior if used incorrectly.


For example, if you want to convert a float variable to an int variable, you can use the following code:

```c++
float my_float = 3.14;
int my_int = static_cast<int>(my_float);
This will convert my_float to an int, discarding the decimal part and truncating the value to the nearest integer.
```

It's also worth noting that `static_cast` can't be used to cast between pointer and reference types. In order to cast between pointer and reference types you should use reinterpret_cast.

---
Summary
1. `static_cast` converts a value of one type to another.
2. Usually used in convertin bewtween related fundamental types(int-float-double-char etc.) and based-derived class's pointers.
3. It also can convert non-const to const or vice versa
4. It happens in compile time.
5. It cannot convert between pointer and reference. you should use `reinterpret_cast`.
6. Data loss with using `static_cast` is responsible for programmer.

</div>
</details>

<details>
<summary> <font size="5"> const_cast </font> </summary>
<div markdown="1">

### `const_cast`
---
 `const_cast` is a C++ operator that is used to remove the const or volatile qualifier from a variable. It is used when you want to modify a constant variable or when you want to access a non-const member function of an object through a const reference or pointer.

The syntax for const_cast is as follows:
```c++
const_cast<type>(expression);
```
type is the type that you want to cast the expression to, and expression is the expression that you want to cast. The type can be a pointer or a reference, and it must match the type of the expression.

For example, suppose you have a constant integer x and you want to modify it. You can use const_cast to remove the const qualifier and assign a new value to it:

```c++
const int x = 10;
int& y = const_cast<int&>(x);
y = 20;
```

In the above example, const_cast is used to remove the const qualifier from x and assign it to a non-const reference y, so that y can be modified.

It's also worth noting that const_cast can be used to cast away the const or volatile qualifier from pointers and references, but it is not recommended to use it for this purpose and should be done with caution.

It is important to note that const_cast only changes the top level const or volatile qualifier, it does not change underlying type, and it does not change the const or volatile qualifiers of the underlying object.

It is also important to note that if you use const_cast to remove const from a pointer, you are responsible for ensuring that the object pointed to remains valid for the lifetime of the pointer, and that the pointer is not used to modify the object if it is const.

You should use const_cast with caution and only when you are certain that it is safe and necessary to remove the const or volatile qualifier.

---
- Summary
 1. `const_cast` removes `const` qualifier.
 2. Expression : `const_cast<type>(src);`
 3. Be cuation. The responsibility is within programmer.
</div>
</details>


<details>
<summary> <font size="5"> strtod </font> </summary>
<div markdown="1">

strtod is a C library function that converts a string to a double-precision floating-point number. It is a part of the C standard library and is defined in the <stdlib.h> header file.

The function takes two arguments:

1. A pointer to a null-terminated string that represents the number to be converted.
2. A pointer to a char variable that will store the address of the first invalid character encountered in the string.
The function returns the converted double-precision floating-point number as a value of type double.

Here is an example of how to use the strtod function:
```c++
const char* str = "3.14";
char* endptr;
double num = strtod(str, &endptr);
```
In this example, strtod converts the string "3.14" to the double-precision floating-point number 3.14, and assigns the address of the null terminator ('\0') to the variable endptr.

It is important to note that strtod can also be used to parse a string that contains a number and additional characters, in which case the number of characters that are used to parse the number can be determined by comparing the addresses of the input string and endptr.

It is also worth noting that strtod can set the global variable `errno` to indicate an error if the input string cannot be parsed as a valid number, such as if the string contains characters that are not numeric. So it is always recommended to check the value of errno after calling strtod to make sure that it has not been set.

Here is an example of how to check the value of errno after calling strtod:
```c++
const char* str = "not a number";
char* endptr;
double num = strtod(str, &endptr);
if (errno == ERANGE)
    std::cout << "The number is out of range for a double" << std::endl;
else if (errno == EINVAL)
    std::cout << "The input string is not a valid number" << std::endl;
else if (num == 0 && endptr == str)
    std::cout << "No number was found in the input string" << std::endl;
else
    std::cout << "The converted number is: " << num << std::endl;
```
In this example, if the input string "not a number" is not a valid number, the call to strtod will set errno to EINVAL and the message "The input string is not a valid number" will be printed.

It is important to check the value of errno only after the call to strtod function, because strtod can change the value of errno if the input string is not valid.

Also, it is important to note that errno is a global variable and its value may be affected by other functions that you call in your program, so it is recommended to save the value of errno before calling strtod and restore it after you have finished checking for errors.

---
Summary
1. `strtod` converts string to double
2. Expression : 
```c++
const char* str = "3.14";
char* endptr;
double num = strtod(str, &endptr);
```
after storing parsed and converted string in `endptr`,`strtod` returns its value as double type. 

3. if `strtod` cannot parse the value because of unvalid literal(not numeric etc.), it will set global vairalbe `errno`.
4. `errno == ERANGE` -> out of range. `errno == EINVAL` -> not a valid number. (return_value == 0 && endptr == str) -> no number was found in input string

</div>
</details>


<details>
<summary> <font size="5"> NAN </font> </summary>
<div markdown="1">

### `NAN`
---
In C++, the std::numeric_limits<double>::quiet_NaN() function can be used to represent a "Not a Number" (NaN) value with a double type. This function is defined in the <limits> header.

Here's an example of how to use it:
```c++
#include <limits>

double nan_value = std::numeric_limits<double>::quiet_NaN();
std::cout << "nan value: " << nan_value << std::endl;
```
It's worth noting that NaN is not equal to any other numeric value, including itself. So you can use std::isnan() to check if a value is NaN.

In C++, the bit representation of a "Not a Number" (NaN) value for a double and float type is not specified by the standard. However, the most common representation is to use the highest bit of the mantissa (the fractional part of the number) to indicate that the value is NaN.

For example, in the IEEE 754 standard, which is widely used in modern computers, the bit representation of NaN for a double type is as follows:

1. The sign bit is 0 for positive NaN, and 1 for negative NaN.
2. The exponent bits are all set to 1 (11...1 in binary), indicating that the value is not a finite number.
3. The mantissa bits can be any value other than all 0s.

For float type, the bit representation is similar, the exponent bits is all set to 1 (111..1 in binary) and the mantissa bits can be any value other than all 0s.

It's worth noting that there are different types of NaN, such as quiet NaN and signaling NaN, which are indicated by different bit patterns in the mantissa.
Also, the bit representation of NaN can also depend on the specific implementation of the floating-point hardware, like the IEEE 754 standard, but it can vary from one system to another.
</div>
</details>


<details>
<summary> <font size="5"> INF </font> </summary>
<div markdown="1">

### `INF`
---
In C++, the std::numeric_limits<double>::infinity() function can be used to represent positive infinity value with a double type. This function is defined in the <limits> header.

Here's an example of how to use it:

```c++
#include <limits>

double inf_value = std::numeric_limits<double>::infinity();
std::cout << "infinity value: " << inf_value << std::endl;
```

It's worth noting that infinity is not equal to any other numeric value, including itself. So you can use std::isinf() to check if a value is infinity.

```c++
if (std::isinf(inf_value)) 
  std::cout << "inf_value is infinity" << std::endl;
```
You can also represent negative infinity by multiplying infinity with -1
```c++
double negative_inf_value = -1 * std::numeric_limits<double>::infinity();

```
It's worth noting that infinity is a special value that indicates that the result of a mathematical operation is too large to be represented as a finite number.

In C++, the bit representation of positive infinity for a double and float type is not specified by the standard. However, the most common representation is to use the highest bit of the exponent (the power of 2 by which the mantissa is multiplied) to indicate that the value is positive infinity.

For example, in the IEEE 754 standard, which is widely used in modern computers, the bit representation of positive infinity for a double type is as follows:

1. The sign bit is 0 for positive infinity, and 1 for negative infinity.
2. The exponent bits are all set to 1 (11...1 in binary), indicating that the value is not a finite number.
3. The mantissa bits are all set to 0 (00...0 in binary), indicating that the value is infinity.

For float type, the bit representation is similar, the exponent bits is all set to 1 (111..1 in binary) and the mantissa bits are all set to 0 (00...0 in binary)

It's worth noting that the bit representation of infinity can also depend on the specific implementation of the floating-point hardware, like the IEEE 754 standard, but it can vary from one system to another.

It's also worth noting that infinity is different from NaN, and infinity is considered to be a valid value, while NaN represents an undefined or unrepresentable value.
</div>
</details>
