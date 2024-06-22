#include "Span.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>

Span::Span() 
{
    this->maxSize = 0;
}

Span::Span(unsigned int N)
{
    this->maxSize = N;
}

Span::~Span() {}

Span::Span(const Span& other) 
{ 
    *this = other; 
}

Span &Span::operator=(const Span& other)
{
    vec = other.vec;
    maxSize = other.maxSize;
    return *this;
}

void Span::addNumber(int num)
{
    if (vec.size() >= maxSize)
        throw std::out_of_range("Span: is full");
    vec.push_back(num);
}

int Span::shortestSpan()
{
    if (maxSize <= 1)
        throw std::logic_error("Cannot find two number");
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    int span = tmp[1] - tmp[0];
    int distance = span;
    for (size_t i = 2; i < tmp.size(); ++i) 
    {
        distance = tmp[i] - tmp[i -1];
        if (distance < span)
            span = distance;
    }
    return span;
}


void Span::print()
{
    std::vector<int>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++) 
    {
        std::cout << *it << std::endl;
    }
}

int Span::longestSpan()
{
    if (maxSize <= 1)
        throw std::logic_error("Cannot find two number");
    return *std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end());
}
