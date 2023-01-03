### Canonical class form
The orthodox canonical class form before C++11
In C++98 and C++03 the OCCF had four different methods that the C++ compiler is willing to generate:

Default constructor
Copy constructor
Destructor
Copy assignment operator
A standard class should look like the following code:

```
	class A final
	{
	   public:
		  A ();
		  A (const A &a);
		  ~A ();
		  A & operator = (const A &a);
	};
```
### copy constructor vs operator =
copy constructor execute deep copy whereas operator does shallow copy in heap memory var;
```
class Person
{
	private :
		int age;
		char *name;

	public:
		...constructor...
}
person A(30, "name is A");
person B(25, "name is B");

//copy(deep copy)
B(A);
strcpy(B.name, "another B");
cout << A.name; // "A"
cout << B.name; // "another B"


//operator =
B = A;
strcpy(B.name, "another B");
cout << A.name; // "another B"
cout << B.name; // "another B"
```


*Q. Why copy constructor take argument as reference? A. to avoid loop construction. Class(Class a) -> Class(Class (Class a)) ...*
*Q. why operator = return pointer? A. it is because of the C++ convention. C++ assumes right associative. ex) x = y = z = 15 -----> x = (y = ( z = 15 )). it means '= operator' returns left argument's reference  *

( https://www.francescmm.com/orthodox-canonical-class-form/ )


### Fixed point Float point
## Fixed point
In computing, a fixed-point number representation is a way to represent numbers with a fixed number of digits after the decimal point. This is in contrast to a floating-point representation, where the decimal point can "float" to any position within the number.

Fixed-point numbers are often used in situations where the precision of floating-point numbers is not necessary, or where the use of floating-point numbers is not practical or efficient. For example, in some embedded systems or microcontrollers, fixed-point numbers may be used because they require less hardware and computational resources than floating-point numbers.

To represent a fixed-point number, we can use a signed integer type and specify the number of digits after the decimal point. For example, to represent a fixed-point number with 2 digits after the decimal point, we can use a signed 16-bit integer and divide it by 100 to get the actual value of the number. The following table shows some examples of fixed-point numbers represented as signed 16-bit integers:
Integer value	Fixed-point value
100				1.00
1000			10.00
-1000			-10.00
10100			101.00

## Float point
On the other hand, a floating-point number representation uses a fixed number of bits to represent the exponent and the mantissa (or significand) of a number. The exponent determines the position of the decimal point, and the mantissa determines the precision of the number. Floating-point numbers are typically represented using the IEEE 754 standard, which defines different precisions for single-precision (32 bits), double-precision (64 bits), and extended-precision (80 bits) floating-point numbers.

Here are some examples of floating-point numbers represented in single-precision format (using the notation s eeeeeeee mmmmmmmmmmmmmmmmmmmmmmm to represent the sign, exponent, and mantissa bits, respectively):
	
Single-precision value	Decimal value
bit
|1|   8	  |   mantissa 23	      |
0 10000000 00000000000000000000000	+0.0
0 10000000 00000000000000000000001	+1.17549435e-38
0 11111111 00000000000000000000000	+infinity
1 11111111 00000000000000000000000	-infinity
0 11111111 00000000000000000000001	NaN (not a number)

For example, consider the single-precision floating-point representation defined by the IEEE 754 standard, which uses a 24-bit mantissa. In this case, the mantissa is represented as a binary fraction with 23 bits after the binary point. For example, the mantissa 1010101010101010101010101 represents the binary fraction 1.01010101010101010101010101, which is equivalent to the decimal value 0.5 + 0.125 + 0.0625 + ... + 2^(-23).

To represent a floating-point number using the IEEE 754 standard, we need to combine the mantissa with an exponent and a sign bit. The exponent determines the position of the decimal point, and the sign bit determines whether the number is positive or negative. The following table shows an example of a single-precision floating-point number representation, using the notation s eeeeeeee mmmmmmmmmmmmmmmmmmmmmmm to represent the sign, exponent, and mantissa bits, respectively:

```
(-1)^s * 2^(e-127) * (1.f)
```
0 10000001 01010101010101010101010
Using the above expression, we can calculate the value of this number as follows:

```
(-1)^0 * 2^(129-127) * (1.0101010101010101010101010)
  = 1 * 2^2 * (1.0101010101010101010101010)
  = 4 * (1.0101010101010101010101010)
  = 4.21484375
```
* binary and point (https://dataonair.or.kr/db-tech-reference/d-lounge/expert-column/?mod=document&uid=52381)



### `#pragma once` vs `#ifndef`

## `#pragma once`
when compiler reads `#pragma once`, it doesn't complier below code lines.
it works Visual C++ 5.0

## `ifndef`
when complier reads `#define ~` it copies `ifndef ~` too. 

for compatibility, `#ifndef` is recommanded
