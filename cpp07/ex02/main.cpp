#include "Array.hpp"
int main()
{
    Array<int> a(5);

    unsigned int sizeofarr = a.size();
    std::cout << "Size of array: " << sizeofarr << std::endl;
    for (unsigned int i = 0; i < sizeofarr; i++)
        a[i] = i;
    for (unsigned int i = 0; i < sizeofarr; i++)
        std::cout << a[i] << std::endl;
    
    std::cout << "---------------------" << std::endl;

    try
    {
        std::cout << "Trying to access a -> ";
        std::cout << a[4] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}