# `switch`
In C++, the switch statement is a control structure that allows you to choose from multiple different options or cases. It is often used as an alternative to a series of if-else statements.

Here is the general syntax for a switch statement in C++:

```c++
switch (expression) {
  case value1:
    // code to be executed if expression == value1
    break;
  case value2:
    // code to be executed if expression == value2
    break;
  ...
  default:
    // code to be executed if expression does not match any of the cases
}
```
The expression is evaluated and compared to each of the case values. If a match is found, the code block associated with that case is executed. If no match is found, the code in the default case is executed (if it is provided). The break statement is used to exit the switch statement and prevent the code in the following cases from being executed.

 Note that the case values must be constants (e.g. integers, characters, or enum) and cannot be expressions. Also, the default case is optional and does not have to be the last case in the switch statement.

In C++, the value in a switch statement must be of an integral type (such as an int, char, or enum) or a class type that has an explicit conversion to an integral type. It cannot be of a floating-point type (such as float or double).
