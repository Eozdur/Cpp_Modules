#pragma once

#include <vector>
#include <iostream>

class Span {
    public:
        Span(unsigned int N);
        ~Span();
        Span();
        Span(const Span& other);
        Span &operator=(const Span& other);
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        void print();
    private:
        std::vector<int> vec;
        unsigned int maxSize;
};
