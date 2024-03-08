#include <cstdlib>
#include <iostream>
#include <memory>
#include "hello_cpp_defs.h"
#include "surakarta/surakarta_common.h"

namespace hello_cpp {

// learn google test

int Add(int a, int b) {
    // TODO: return a + b
    return 0;
}

// learn how to use std::unique_ptr and std::vector

std::unique_ptr<std::vector<SurakartaPosition>> GenerateAllPositions();

std::unique_ptr<std::vector<SurakartaPosition>> GenerateAllPositions() {
    // TODO: generate {0, 0}, {0, 1}, ..., {5, 5} in a vector, and return it.
    return nullptr;
}

//////////////////////////////////////////////////////////////////////////////////////////

// learn how to use std::shared_ptr, std::pair and class

class SmartPointerContainer : public Base {  // don't mind the "public Base" for now
   public:
    // pairs
    std::shared_ptr<std::pair<int, double>> ptr1_;
    std::shared_ptr<std::pair<int, double>> ptr2_;
    std::shared_ptr<std::pair<int, double>> ptr3_;

    SmartPointerContainer() = default;

    SmartPointerContainer(int a, double b, int c, double d, int e, double f) {
        // TODO: Initialize ptr1_, ptr2_, ptr3_ with the given values. {a, b}, {c, d}, {e, f}
    }

    // TODO: Create a member function named "DoSomething" that returns the sum of the pairs' first elements.
    // int DoSomething() {...}
};

int* DoSomething1(int* ptr) {
    if (rand() % 2 == 0) {  // We still use rand here but it's not recommended from C++11.
        *ptr = *ptr + 1;
    } else {
        *ptr = *ptr - 1;
    }
    return ptr;
}

std::unique_ptr<int> DoSomething2(std::unique_ptr<int> ptr) {
    if (rand() % 2 == 0) {  // We still use rand here but it's not recommended from C++11.
        *ptr = *ptr + 1;
    } else {
        *ptr = *ptr - 1;
    }
    return ptr;
}

int* LearningRawPtr() {
    int* raw_ptr = new int(1);
    DoSomething1(raw_ptr);
    std::cout << *raw_ptr << std::endl;
    return raw_ptr;  // If caller forgets to delete, memory leak occurs.
}

std::unique_ptr<int> LearningUniquePtr() {
    // TODO: Do the same thing as LearningRawPtr, but with std::unique_ptr.
    return nullptr;

    // Here is an implementation, please modify it to achieve the goal. (Fisrtly, you need to uncomment the code below.)

    // std::unique_ptr<int> u_ptr = std::make_unique<int>(1);
    // DoSomething2(u_ptr);
    // std::cout << *u_ptr << std::endl;
    // return u_ptr; // No memory leak will occur.
}

}  // namespace hello_cpp
