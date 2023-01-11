### member function calling ref vs this
## this
`this` is pointer. so to call the this class' member function, use `->`

## ref
`ref` is instacne, use `.`

### `const`
#### `const non-member var`
```
const int num1 = 1;
int const num2 = 2;

//num 2 = 3; compile error!, const var is unmutable
```

#### `const member var`
```
class Foo
{
	const int num; //not mem allocation
 
	Foo(void) : num(1) // const int num = 1; initalizing list
	{
	}
};
 
class Bar
{
	const int num;
 
	Bar(void)
	{
		num = 1; // Compile Error. this action is mutation of const mem var
		// const int num;
		// num = 1;
		// over C++11, can assign const mem var in class constructor
	}
};
```

#### `const pointer`
##### `#1 const <TYPE>* var_name`
```
int num = 1;
const int* ptr = &num; // *ptr's value is constant
 
*ptr= 2; // Compile Error
num = 2;  // Pass
```

##### `#2 <TYPE>* const var_name`
```
int num1 = 1;
int num2 = 2;
int* const ptr = &num1; // ptr is constnt
 
ptr = &num2; // Compile Error
```

```
	int c = 0;
	int d = 0;

	const int* ptr;
	ptr = &c;
	ptr = &d;
	*ptr = 1;// compile err

	//int* const ptr3; //compile err
	int* const ptr3 = &c; //initalizing neccassary
	//ptr3 = &c; //compile err
	//ptr3 = &d; //compile err
	*ptr3 = 1;
			
	int const *ptr4;
	ptr4 = &c;
	ptr4 = &d;
	*ptr4 = 1; //compile err

```

#### `const function`
```
int GetString(void) const; //Compile Error. only member func can be const
 
class Foo
{
	int num = 1;
 
	int GetNum(void) const // <------const mem func make every member var in class as const 
	{
		int a = 1;
		a++;   //local var is mutable
 
		num++; // Compile Error. me var is unmutable
		return num;
	}
};
```
*if member function is using another mem-func and it is taking arguments as const, the first mem-function also be declared as const*

### rvalue lvalue
In C++, the terms "rvalue" and "lvalue" refer to the value category of an expression. The value category of an expression determines whether it refers to an object with a specific memory location (lvalue) or whether it is a temporary value with no specific memory location (rvalue).

An lvalue is an expression that refers to an object with a specific memory location. An lvalue can be used on the left-hand side of an assignment operator, as it refers to a specific memory location that can be modified. Examples of lvalues include variables, array elements, and object members.

An rvalue is an expression that does not refer to an object with a specific memory location. An rvalue is a temporary value that does not have a specific memory location and can only be used on the right-hand side of an assignment operator. Examples of rvalues include literals, constants, and the results of expressions.

Rvalues are usually created as the result of an expression and are not associated with a variable. They are generally temporary and can be moved from. Lvalues, on the other hand, are associated with a variable and refer to a specific memory location.

The concept of rvalue and lvalue is important in C++ because it determines whether an object can be modified or not, and it also affects the behavior of various language constructs, such as the move semantics, universal references and overloading of functions, operators and constructors. This is why when you overload an operator like ++ or --, you need to specify the value category of the returned type, which can be lvalue or rvalue.


### postfix prefix
When overloading the prefix and postfix increment and decrement operators (operator++ and operator--) in C++, you can declare them as member functions of a class and have them take no arguments for the prefix version and single int argument for the postfix version.

1. `operator++(void)` vs `operator++(int)`
	- oveloading operations with `(void)` compiled as prefix
	- oveloading operations with `(arg)` compiled as postfix
2. reference return vs value return
	- prefix op must return lvalue (in this project, reference) so it can chain execution.
	- postfix op must return rvalue (in this project, const) so it cannot chain execution.
	- prefix op must return reference so it can chain execution

## Q. Why default construct is 0.00390625?
	fraction bit 1.0000 * 2^-8;
#### postfix

#### prefix
