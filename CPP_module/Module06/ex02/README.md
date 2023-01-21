<details>
<summary> <font size="5"> Dynamic_cast </font> </summary>
<div markdown="1">

### `dynamic_cast`
---
`dynamic_cast` is a type-safe, runtime cast operator in C++ that can be used to perform a safe, downcast (i.e. casting from a base class to a derived class) of a polymorphic object. It is used to ensure that the object being cast is in fact an object of the derived class, and not just an object of the base class.

Here's an example of how `dynamic_cast` is used:

```c++
class Shape {};
class Circle : public Shape {};
class Square : public Shape {};

Shape* shape = new Circle();
Circle* circle = dynamic_cast<Circle*>(shape);
```

In this example, the variable shape points to an object of the `class Circle`, which is derived from the `class Shape`. The `dynamic_cast` operator is used to cast the pointer shape to a pointer of the `class Circle`. If the cast is successful, the variable circle will now point to the same object as shape, but with the type `Circle*`.

If the cast fails, because the object pointed to by shape is not actually an object of the `class Circle`, the `dynamic_cast` operator will return `nullptr`.

`dynamic_cast` can also be used with references:

```c++
Shape& shape = Circle();
Circle& circle = dynamic_cast<Circle&>(shape);
```
In this case, if the cast fails, it will throw `std::bad_cast` exception.

`dynamic_cast` can only be used on polymorphic types (i.e. types that have at least one virtual member function). If used on a non-polymorphic type, it will not perform any runtime check and will simply return the result of a standard C-style cast.

It is important to note that `dynamic_cast` has a runtime overhead and can make the code slower. It should be used judiciously and only when necessary. The `static_cast` operator should be used instead if the type of the object is already known at compile-time.

</div>
</details>
