#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &r)
{
    *this = r;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &r)
{
    if (this != &r)
    {
        *this = r;
    }
    return *this;
}