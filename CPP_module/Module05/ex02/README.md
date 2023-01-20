### why should I write `throw()` at the end of my customized exception what(void) function?

The throw() keyword is used to specify the exception specification for a function. An exception specification is a list of exception types that a function can throw. The throw() keyword is used to indicate that a function will not throw any exceptions.

When you write throw() at the end of a function, you are indicating to the compiler that the function will not throw any exceptions. This can be useful in situations where you want to ensure that a specific function will not throw an exception, or when you want to override the exception specification of a virtual function.

For example, when you define a custom exception class, you might want to override the what() method of the std::exception class, but you don't want the overridden method to throw any exceptions. In this case, you can specify the throw() exception specification at the end of the what() method.

```c++
class MyException : public std::exception {
public:
    const char* what() const throw() override {
        return "My exception occurred";
    }
};
```

It's worth noting that the use of exception specification is not recommended, as it can lead to unexpected behavior, and it's better to use noexcept (C++11) or [[nodiscard]] attribute.

Also, it's worth noting that the exception specification is part of the function signature, so if you change it, you'll have to update all the calls to that function accordingly.

- summary
---
1. when overiding what function and write `throw(type)` it means the exception throw function will throws argument type when the defineed exception occurs.
2. with `throw(void)` it will not return any exception return type but the exception class itself.
3. after C++11, the `throw()` keyword is not recommended and after C++17, it has been depreciated.
4. instead of using `throw()`, use `noexcept`
