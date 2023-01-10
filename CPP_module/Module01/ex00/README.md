# difference between stack and heap
In general, stack memory is used for storing function arguments, local variables, and return addresses. It is faster to access and allocate memory in the stack, but it has limited capacity. When the stack is full, it can cause a stack overflow error.

Heap memory, on the other hand, is used for dynamic allocation of memory at runtime. It has a larger capacity than the stack, but it is slower to access and allocate memory in the heap. Memory allocated in the heap is not automatically deallocated when it goes out of scope, so it is the programmer's responsibility to manually deallocate the memory when it is no longer needed to prevent memory leaks.
