
<details>
<summary> <font size="5"> Factoty Function </font> </summary>
<div markdown="1">

# Factoty Function

 A factory function is a function that creates and returns an object of a specific class. It is often used as a way to create objects without exposing the details of their construction to the client code. The factory function usually takes some arguments that are used to construct the object, such as the constructor arguments.

A factory function pointer is a pointer that points to a factory function. It can be used to call the factory function and create an object dynamically. The factory function pointer has the same signature as the factory function it points to, which includes the return type and the parameter types.

Here is an example of a factory function and a factory function pointer:

```c++
class MyClass {
public:
    MyClass(std::string s) : m_str(s) {}
    void print() { std::cout << m_str << std::endl; }

private:
    std::string m_str;
};

MyClass* createMyClass(std::string s) {
    return new MyClass(s);
}

int main() {
    MyClass* (*fptr)(std::string) = &createMyClass;
    MyClass* myClass = fptr("Hello World");
    myClass->print();
    delete myClass;
}
```
In this example, MyClass* (*fptr)(std::string) declares a function pointer fptr that points to a function that takes a std::string argument and returns a pointer to a MyClass. The function pointer fptr is assigned the address of the createMyClass function using the function name preceded by an '&' sign. The function is called using the pointer fptr("Hello World") and the returned value is stored in the myClass variable and after that, the class's member function is called through the pointer and the memory is freed up using delete operator.

It's worth noting that since the function createMyClass is returning a pointer, it's important to use the delete operator to free up the memory after the use of the pointer.

It's also worth noting that you can use std::unique_ptr or std::shared_ptr instead of raw pointer and new operator to handle the memory management automatically.

</div>
</details>
