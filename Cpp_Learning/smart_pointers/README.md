#Smart Pointers

Hand-written implementation and standard usage of C++ smart pointers.

- custon_smart_ptr.cpp: Basic RAII smart pointer demo
- shared_ptr_impl.cpp: Full shared_ptr simulation with reference counting
- shared_ptr_test.cpp: Test cases (copy, assign, use_count, etc.)
- standard_usage.cpp: unique_ptr, shared_ptr, weak_ptr examples
- **smart_pointers/**: Hand-written shared_ptr + standard usage examples

Blog: [智能指针的使用及原理](https://blog.csdn.net/yuuki233233)

Compile example:
```bash
g++ -std=c++11 shared_ptr_impl.cpp -o shared_demo
./shared_demo
```