#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>

int main()
{
    std::vector<int> vec;
    std::deque<int> deque;

    for (size_t i = 1; i <= 5; ++i) {
        vec.push_back(i);
        deque.push_back(i);
        deque.push_front(i);
    }

    try 
    {
        std::cout << "Number:"<< ::easyfind(vec, 5) << std::endl;
        std::cout << "Number:"<< ::easyfind(deque, 3)  << std::endl;
        std::cout << "Number:" << ::easyfind(deque, 6) << std::endl;
    } 
    catch (std::exception & e) 
    {
        std::cout << e.what() << std::endl;
    }

    std::cout <<"\nDeque elements:"<< std::endl;
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    
    std::cout << "Vector elements: \n";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    std::cout << "Vector Size: " << vec.size() << std::endl;
    std::cout << "Deque Size: " << deque.size() << std::endl;
    std::cout << "Vector Capacity: " << vec.capacity() << std::endl;
    return 0;
}
