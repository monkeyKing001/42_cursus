### freind
The friend keyword is used to allow a function or class to access private and protected members of another class. This can be useful when you want to overload the << operator, or any other operator, to be able to access the private or protected members of the class you are working with.

For example, let's say you have a class called Foo and you want to overload the << operator so that you can output the contents of an object of type Foo using the std::cout stream. You could do this by declaring the << operator as a friend of the Foo class, like this:

```
class Foo {
private:
    int a;
    int b;

public:
    friend std::ostream& operator<<(std::ostream& out, const Foo& f);
};

std::ostream& operator<<(std::ostream& out, const Foo& f) {
    out << f.a << ' ' << f.b;
    return out;
}
```
In this example, the operator<< function is able to access the private members a and b of the Foo class because it has been declared as a friend of the class. Without the friend keyword, the operator<< function would not have access to the private members of the Foo class, and you would not be able to output the contents of an object of type Foo using the std::cout stream.

It is important to note that the friend keyword should be used sparingly, as it can break the encapsulation of your class and make the code more difficult to maintain. You should only use the friend keyword when it is absolutely necessary, and you should consider other options, such as adding public getter and setter functions, if possible.
	-ChatGPT

# 1. inter-class
freind class can access my own member variables

# 2. inter-global function
global function can access my own member variables

# 3. operator overload
global overloaded function needs friends keyword
https://thrillfighter.tistory.com/283


### extern
In C++, the extern keyword is used to declare a variable or function that is defined in another source file. It tells the compiler that the variable or function is defined elsewhere, and that the definition should be linked to the current source file at the time of linking.

Here is an example of how the extern keyword is used to declare a variable in C++:
```
// Declare a variable with the extern keyword
extern int x;

int main() {
    // Use the variable
    x = 5;
    std::cout << x << std::endl;
    return 0;
}
```
In this example, the variable x is declared with the extern keyword. This tells the compiler that the variable is defined elsewhere, and that its definition should be linked to the current source file at the time of linking.

The extern keyword can also be used to declare a function in C++, like this:
```
// Declare a function with the extern keyword
extern void foo();

int main() {
    // Call the function
    foo();
    return 0;
}
```
In this example, the function foo is declared with the extern keyword. This tells the compiler that the function is defined elsewhere, and that its definition should be linked to the current source file at the time of linking.

It is important to note that the extern keyword does not define a variable or function, it only declares it. The actual definition of the variable or function must be provided in another source file.

Here is an example of how the extern keyword is used before a class declaration in C++:
```
// Declare a class with the extern keyword
extern class MyClass {
private:
    int a;
    int b;

public:
    void foo();
};

int main() {
    MyClass c;
    c.foo();
    return 0;
}
```
-ChatGPT

