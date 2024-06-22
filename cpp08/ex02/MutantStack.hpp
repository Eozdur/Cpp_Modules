#pragma once

#include <iostream>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack()
    {

    }
    ~MutantStack()
    {

    }
    MutantStack(const MutantStack& other)
    {
        std::cout << "Copy constructor called" << std::endl;
       *this = other;
    }
    MutantStack &operator=(const MutantStack& other)
    {
        std::cout << "Assignation operator called" << std::endl;
        this->c = other.c;
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }
};
