#include "iter.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, print);
    std::cout << "-------" << std::endl;
    std::string arr2[5] = {"one", "two", "three", "four", "five"};
    iter(arr2, 5, print);
    return 0;
}