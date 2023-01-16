
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
<summary> <font size="5"> Upcasting, Downcasting of class instance </font> </summary>
<div markdown="1">

### Upcasting

Upcasting and downcasting are terms used to describe the process of casting a pointer or reference from a derived class to a base class, or vice versa.

Upcasting is the process of casting a pointer or reference from a derived class to its base class. This is considered safe because a derived class object is guaranteed to have all the properties of its base class. Upcasting is always possible, and in C++, it can be done using a simple assignment or using the static_cast operator.

```c++
class A {};
class B : public A {};
A a;
B b;
a = b;  // implicit upcasting
A* a_ptr = &b; // implicit upcasting

```

### Downcasting

Downcasting, on the other hand, is the process of casting a pointer or reference from a base class to a derived class. This is considered unsafe because a base class object may not have the properties of its derived class. Downcasting is not always possible and requires a cast operator to be used explicitly.

```c++
class A {};
class B : public A {};
A a;
B b;
B* b_ptr = static_cast<B*>(&a); // explicit downcasting 
```
It's not always possible to cast a base class object to a derived class object because the object may not actually have the properties of the derived class. If the object is not an instance of the derived class, the cast will result in undefined behavior. The behavior of the program will be unpredictable and can cause errors.

In C++, the dynamic_cast operator can be used to check if the cast is valid and only perform the cast if the object is an instance of the derived class. This is the recommended way to downcast.

```c++
B* b_ptr = dynamic_cast<B*>(&a); // check before downcasting
if (b_ptr != nullptr) {
    // do something with b_ptr
}
```
In summary, upcasting is always possible and is considered safe because it guarantees that a derived class object has all the properties of its base class. Downcasting, on the other hand, is not always possible and is considered unsafe because it may result in undefined behavior if the object does not have the properties of the derived class.

</div>
</details>
