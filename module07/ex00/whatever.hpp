#ifndef OPERATION_HPP
#define OPERATION_HPP

template <typename T>
void   swap(T &a, T &b)
{
    T swap;
    swap = a;
    a = b;
    b = swap;
}

template <typename T>
T   const & min(T &a, T &b)
{
    return (a < b) ? a : b;
}

template <typename T>
T   const & max(T &a, T &b)
{
    return (a > b) ? a : b;
}

#endif