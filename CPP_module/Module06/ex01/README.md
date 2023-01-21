<details>
<summary> <font size="5"> Reinterpret_cast </font> </summary>
<div markdown="1">

### `reinterpret_cast`
---
`reinterpret_cast` is a C++ operator that allows you to convert a pointer or a reference to an object of one type to a pointer or reference to an object of another type, without changing the underlying bit pattern. It is used to interpret the binary data of an object in a different way.

The general syntax of `reinterpret_cast` is as follows:

```c++
reinterpret_cast<new_type>(expression)
Where new_type is the type to which you want to convert the expression and expression is the pointer or reference to an object that you want to reinterpret.
```

`reinterpret_cast` can be used to convert pointers to different types of objects, such as:

1. Converting a pointer to a base class to a pointer to a derived class or vice versa
2. Converting a pointer to a non-virtual member function to a pointer to a virtual member function or vice versa
3. Converting a pointer to an object to a pointer to a function or vice versa
4. Converting a pointer to a data member to a pointer to a member function or vice versa

`reinterpret_cast` can also be used to convert references to different types of objects. However, it should be used with caution, because it can result in undefined behavior if the resulting type does not have the same size and alignment requirements as the original type.

It's worth noting that `reinterpret_cast` does not perform any type checking, so it can be dangerous if used incorrectly. Since it doesn't change the underlying bit pattern, it can produce unexpected results if the original value was not a pointer or reference of the type being casted to.

It's also important to note that `reinterpret_cast` cannot be used to cast non-pointer types to pointer types, or pointer types to non-pointer types. It can only be used to cast between pointer and reference types.

---
Summary
1. `reinterpret_cast` converts bit value as pointer or reference.
2. base class <-> derived class
3. virtual <-> non virtual memberfunction.
4. ojbect pointer <-> function pointer.
5. data member <-> member function.
6. But cannot convert between not pointer type <-> pointer type.
7. Be caution when using `reinterpret_cast` in case converted two objects have different size.
8. reinterpret does not perform any on type checking.
9. Be caution for any other undefined behavior.

</div>
</details>
