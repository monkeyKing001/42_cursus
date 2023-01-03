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
*if member function is using another mem-func and it is taking arguments as const, the first mem-function also be declared as const
