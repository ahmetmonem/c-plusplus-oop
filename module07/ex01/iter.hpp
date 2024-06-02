#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* address, size_t length, F func) {
    for (size_t i = 0; i < length; ++i) {
        func(address[i]);
    }
}

#endif