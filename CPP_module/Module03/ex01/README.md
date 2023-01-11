# class and inheritance
In C++, inheritance is a mechanism that allows one class (called the derived class) to inherit the members of another class (called the base class). The derived class can access and modify the members of the base class, and can also define its own members.

Inheritance is a useful way to reuse code and create a hierarchical structure of related classes. It allows you to define a common base class that provides some basic functionality, and then derive specialized classes from the base class that have additional functionality.

## Derived class
<details>
<summary> <font size="5", color = Gray> Definition </font> </summary>
<div markdown="1">

### Definition
---
In C++, a derived class is a class that is derived from another class, called the base class. The derived class inherits the members of the base class and can add its own members to them.

</div>
</details>

<details>
<summary> <font size="5", color = Gray> Syntax </font> </summary>
<div markdown="1">

### syntax
---
In C++, you can declare a derived class using the syntax:
```c++
class DerivedClassName: [access specifier] BaseClassName {
    // class body
};
```
Here, DerivedClassName is the name of the derived class, BaseClassName is the name of the base class, and access specifier is an optional keyword (such as public, protected, or private) that specifies the access level of the derived class members.

For example, consider the following base class and derived class:
```
class Base {
public:
    int a;
    void foo();
};

class Derived: public Base {
public:
    int b;
    void bar();
};
```


</div>
</details>


<details>
<summary> <font size="5", color = Gray> Protected keyword </font> </summary>
<div markdown="1">


### `protected` keyword
---
 in C++, the protected keyword is used to specify the member visibility of a class. 
 Members of a class that are declared protected are accessible from within the class itself and from derived classes,
but are not accessible from outside the class or from non-derived classes.

```c++
class Base {
protected:
    int a;
    int b;

public:
    void foo();
};

class Derived: public Base {
public:
    void bar() {
        a = 10;
        b = 20;
    }
};

int main() {
    Derived d;
    d.bar();
    return 0;
}
```
In this example, the Base class has two protected member variables, a and b, and a public member function, foo. The Derived class is derived from the Base class and has a public member function, bar.

Inside the bar function, the Derived class has access to the protected member variables a and b of the Base class. However, if we try to access these variables from outside the Derived class, we will get a compile error.

The protected keyword is often used in inheritance to allow derived classes to access the protected members of their base classes. This can be useful when you want to hide the implementation details of a class from the outside world, but still allow derived classes to access and modify certain members of the base class.

</div>
</details>

<details>
<summary> <font size="5", color = Gray> private vs protected </font> </summary>
<div markdown="1">

### `private` vs `protected`
---
In C++, the private and protected keywords are used to specify the member visibility of a class. Members of a class that are declared private are only accessible from within the class itself, while members of a class that are declared protected are accessible from within the class itself and from derived classes. However, access to the variable is allowed only for the class and its derived classes, not for other instances of other classes.

```c++
class Base {
private:
    int a;

protected:
    int b;

public:
    void foo();
};

class Derived: public Base {
public:
    void bar() {
        a = 10; // compile error: 'a' is private
        b = 20; // okay, 'b' is protected
    }
};

int main() {
    Base b;
    b.a = 10; // compile error: 'a' is private
    b.b = 20; // compile error: 'b' is protected
    return 0;
}

```

</div>
</details>

<details>
<summary> <font size="5", color = Gray> Virtual </font> </summary>
<div markdown="1">

### `virtual`
---
In C++, the virtual keyword is used to specify that a member function or destructor is virtual. A virtual function is a member function that can be overridden by derived classes.

The virtual keyword is most often used in conjunction with inheritance. When a class is derived from a base class and overrides a virtual function of the base class, the derived class function is called instead of the base class function when the function is called through a reference or pointer to the base class.

Here is an example of a base class with a virtual function and a derived class that overrides the virtual function:
```c++
#include <iostream>

class Base {
public:
    virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived: public Base {
public:
    void foo() {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main() {
    Base* b = new Derived;
    b->foo(); // prints "Derived::foo()"
    delete b;
    return 0;
}

```
In this example, the Base class has a virtual function foo, and the Derived class overrides the foo function. When we create a pointer to a Derived object and call the foo function through the pointer, the Derived version of the function is called, rather than the Base version.

The virtual keyword is also used to specify that a destructor is virtual. A virtual destructor ensures that the correct destructor is called when an object of a derived class is deleted through a pointer to the base class.

This mechanism is achieved by using a mechanism called virtual function table or vtable, it's a table of function pointers. Each class that has virtual function(s) has a vtable, and it's used to look up the correct implementation of a virtual function at runtime.

When a virtual function is called through a pointer or a reference to the base class, the runtime system looks up the vtable associated with the object's type to find the correct implementation of the function to call.

This allows for runtime polymorphism, where an object's behavior can be determined at runtime based on its actual type, rather than its declared type.
</div>
</details>


<details>
<summary> <font size="5", color=Gray> Destruction order </font> </summary>
<div markdown="1">

### destructor order
In C++, when an object of a derived class is destroyed, the destructors for the base class and the derived class are called in the opposite order in which the constructors were called.

This is because the destructors of the base class and derived class are responsible for releasing any resources (such as memory or file handles) that were allocated during the construction of the object. If the destructors were called in the same order as the constructors, the resources of the base class would be released before the resources of the derived class, which could cause problems if the derived class relies on the resources of the base class.

For example, consider the following base class and derived class:
```c++
#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
    }
    ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived: public Base {
public:
    Derived() {
        std::cout << "Derived constructor" << std::endl;
    }
    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main() {
    Derived d;
    return 0;
}

```
When the Derived object is created, the constructors for the Base class and the Derived class are called in the order in which they are declared. However, when the Derived object is destroyed, the destructors for the Derived class and the Base class are called in the opposite order:

```c++
Base constructor
Derived constructor
Derived destructor
Base destructor
```
This ensures that the resources of the derived class are released before the resources of the base class, which helps to prevent problems caused by resource dependencies.

</div>
</details>
