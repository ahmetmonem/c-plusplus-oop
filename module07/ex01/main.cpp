#include "iter.hpp"


template <typename T>
void func(T &a)
{
    a++;
}

int main()
{
    int arr[] = {1, 2 , 3, 4 , 5};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    iter(arr , length, func<int>);
    for(int i = 0; i<length; i++)
        std::cout<<arr[i];
    
    char chararr[] = "abcdefg";
    size_t charlength = sizeof(chararr) / sizeof(chararr[0]);
    iter(chararr , charlength, func<char>);
    for(int i = 0; i<charlength; i++)
        std::cout<<chararr[i];

}