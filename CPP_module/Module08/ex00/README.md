<details>
<summary> <font size="5"> Vector, List </font> </summary>
<div markdown="1">

### Vector, List
---
In C++, both `std::vector` and `std::list` are container classes that store elements in memory.

A `std::vector` stores its elements in a contiguous block of memory, where each element is placed next to the previous one. This allows for fast random access to any element, but also means that adding or removing elements from the middle of the vector can be costly, as it may require shifting all the elements after the insertion or deletion point. To mitigate this, vectors typically have a larger amount of memory allocated than their current size, so that new elements can be added without the need to move all existing elements.

A `std::list` stores its elements in a doubly-linked list, where each element is stored as a separate node that contains a pointer to the next and previous elements. This allows for fast insertion and removal of elements at any position, but means that random access to elements is slower as it requires traversing the list to find the desired element.

In general, when you have a dynamic array that needs to be resized frequently, `std::vector` may be more efficient, while if you have a lot of insertion and deletion operation `std::list` may be more efficient.

In terms of memory view, a vector is stored in contiguous memory, meaning that all of its elements are stored in a single, continuous block of memory. This makes it easy to access elements quickly by using pointer arithmetic, but it also means that resizing a vector can be costly, as it may require allocating a new block of memory and copying all of the elements to the new block.

On the other hand, a list is stored as a series of linked nodes, where each node contains a value and pointers to the next and previous nodes. This allows for efficient insertion and deletion of elements, as only the pointers need to be updated, but it also means that accessing elements can be slower, as it requires traversing the list one node at a time.

In terms of performance, vector is generally faster than list when it comes to operations that involve random access to elements, such as indexing, since vector's elements are stored contiguously. However, list is generally faster than vector when it comes to inserting and deleting elements, since only the pointers need to be updated.

The choice between a vector and a list depends on the specific use case. If you need fast random access to elements, a vector is probably a better choice. If you need to frequently insert and delete elements, a list is probably a better choice.

Here's a table that compares the memory view and performance of std::vector and std::list in C++:


|Feature|std::vector|std::list|
|:--|:--|:--|
|Memory View	| Elements are stored in contiguous memory locations.	|  Elements are stored in a doubly-linked list structure. |
| Performance	| Fast random access and insertion/deletion at the end. Slow insertion/deletion in the middle.|  	Slow random access, but fast insertion/deletion anywhere in the list. |
|`size()`|O(1)|O(n)|
|`push_back()`|O(1) amortized|O(1)|
|`insert()`|O(n)|O(1)|
|`erase()`|O(n)|O(1)|
|`[] operator`|	O(1)	|N/A|

`std::vector` is a dynamic array, which means that its elements are stored in contiguous memory locations. This makes it very fast for random access, but slow for insertion and deletion in the middle of the container.
`std::list` is a doubly-linked list, which means that each element has a pointer to the next element. This makes it very fast for insertion and deletion anywhere in the container, but slow for random access.
`std::vector` generally use more memory than `std::list` due to its contiguous memory allocation.

It's important to note that the choice between `std::vector` and `std::list` depends on the specific use case and the trade-offs that you're willing to make. If you need fast random access and don't mind slower insertion/deletion in the middle, std::vector may be a better choice. If you need fast insertion/deletion anywhere in the container and don't mind slower random access, std::list may be a better choice.


</div>
</details>

<details>
<summary> <font size="5"> Iterator </font> </summary>
<div markdown="1">

### Iterator
---
An iterator is an object that can be used to traverse through a container (such as an array or a list) and access its elements. It is a generalization of a pointer, which can only be used to traverse through an array. An iterator is a more abstract concept that can be used with different types of containers, and it can be implemented in different ways depending on the type of container.

Iterators provide a consistent way of accessing elements in a container, regardless of the type of container. They are also useful for implementing algorithms that need to traverse through a container and perform some operation on each element. For example, the standard library algorithms such as std::sort, std::find, std::count, std::for_each use iterators as their input and output.


Iterators also allow you to write more generic code that can work with different types of containers. For example, you can write a function that takes two iterators as its input, and it can work with any container that supports iterators, such as a vector or a list.

In C++, iterators are implemented as classes that provide a set of operations such as `++`, `--`, `*`, and `->`. The standard library provides a set of iterator categories, such as `std::input_iterator_tag, std::output_iterator_tag, std::forward_iterator_tag, std::bidirectional_iterator_tag, std::random_access_iterator_tag`, that indicate the capabilities of an iterator.


In summary, iterators are a powerful tool in C++ that allow you to write more generic and efficient code by providing a consistent way of accessing elements in a container and traversing through them.

---
Summary
1. `iterator` is used to traverse through a container(list, vector, deque).
2. Using `iteraotr`, we can more generic code that can work with differnt types of containers.
3. iterators are classes and `++`, `--`, `*`, `->` are also implemented in them.
4. iterator categories are `std::input_iterator_tag, std::output_iterator_tag, std::forward_iterator_tag, std::bidirectional_iterator_tag, std::random_access_iterator_tag`. they indicate the capabilities of an iterator.
</div>
</details>

