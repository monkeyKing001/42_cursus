## `const` after member function
The const keyword after a member function's name indicates that the function does not modify the object's state. This means that the member function cannot change the values of any non-static member variables within the object.

The use of const member functions can be beneficial for several reasons. For example:

They can be called on const objects, which can be useful if you want to ensure that the object's state is not modified.
They can be called from within const member functions of other classes.
They can be called from within const functions in general.

## initialization list
An initialization list is a list of initial values for the member variables of a class, struct, or union, specified in the order in which they are declared in the class definition. It is used to initialize member variables of a class or struct before the constructor of the class or struct is called.

There are several reasons why you might want to use an initialization list:

Efficiency: When initializing member variables with an initialization list, the values are directly assigned to the member variables, rather than being assigned through the assignment operator after the object has been constructed. This can be more efficient, especially for large objects or objects with expensive assignment operators.

Const correctness: When initializing a const member variable, or a reference member variable, you must use an initialization list, as these types of variables cannot be modified after the object has been constructed.

Order of initialization: When initializing member variables with an initialization list, the order of initialization is determined by the order in which the variables are declared in the class definition, rather than the order in which they appear in the initialization list. This can be important if the member variables have dependencies on each other and need to be initialized in a specific order.

Default member initializers: C++11 introduced the ability to specify default member initializers in the class definition. This allows you to specify a default value for a member variable that will be used if no value is provided in the initialization list.

## member variable by Reference vs Pointer
### HumanA -> Reference
1. need initializer for constructor
초기화 리스트는 객체의 생성 후 값을 대입하는 것이 아닌, 객체의 생성과 동시에 값을 지정할 수 있게 한다. 이렇게 초기화 리스트를 사용하는 것은 direct initialization 또는 uniform initialization으로 초기화하는 것과 거의 동일하다.
```cpp
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
```
2. access weapon class's member fun with .
```cpp
getWeapon().getType() 
```

## HumannB -> Pointer
1. don't need initializer (NULLABLE)
2. access weapon class's member fun with ->
```cpp
getWeapon() -> getType() 
```
