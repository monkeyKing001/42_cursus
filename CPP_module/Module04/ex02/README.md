
<details>
<summary> <font size="5"> Pure Virutual </font> </summary>
<div markdown="1">

In C++, a pure virtual function is a virtual function that has no implementation in the base class and must be overridden in a derived class. The syntax for declaring a pure virtual function is to use the keyword = 0 at the end of the function declaration.

A class that contains a pure virtual function is called an abstract class, and it cannot be instantiated. Its purpose is to provide an interface that must be implemented by derived classes.

For example:

```c++
class Shape {
public:
    virtual void draw() = 0;
};
```
Here, the draw function is a pure virtual function. Since it has no implementation in the Shape class, the Shape class is an abstract class and cannot be instantiated. A derived class such as Circle or Square would have to provide an implementation for the draw function in order to be instantiated.

```c++
class Circle : public Shape {
    void draw() {
        // draw a circle
    }
};
```

It is important to note that if a class has at least one pure virtual function, this class is abstract and cannot be instantiated.

</div>
</details>


<details>
<summary> <font size="5"> Virtual table </font> </summary>
<div markdown="1">

In C++, a virtual function table (vftable) is a table of function pointers that is used to support virtual function calls in classes that use virtual functions. The vftable is typically stored in the memory of the program, and contains one entry for each virtual function that is defined in the class.

When a class is defined with one or more virtual functions, the compiler will automatically generate a vftable for the class. Each instance of the class will contain a pointer to its vftable, known as the virtual pointer (vptr).

The vftable is usually stored in the memory of the program in the data segment, which is a region of memory reserved for storing static data and global variables. The vftable is typically stored in a read-only section of the data segment, to prevent accidental modification during execution.

The vptr is stored in the instance of the class, which is created in the heap or stack, depending on the way it is created.

When a virtual function is called on an instance of a class, the vptr is used to locate the vftable for the class, and then the function pointer for the virtual function is looked up in the vftable and called.

It is important to note that, the layout and exact details of vftables and vptrs depend on the implementation of the C++ compiler you are using. Some compilers use a single vftable for all instances of a class, while others use a separate vftable for each instance.

</div>
</details>
