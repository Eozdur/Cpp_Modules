#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
    public:
        // Constructors and Destructor
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe& oth);
        PmergeMe& operator=(const PmergeMe& oth);
        // Static Sorting Methods
        template <typename it>
        static void merge(it first, it mid, it last)
        {
            std::vector<int> merged(std::distance(first, last));
            it left = first, right = mid;
            typename std::vector<int>::iterator merged_it = merged.begin();

            while (left != mid && right != last)
            {
                if (*left < *right) {
                    *merged_it = *left;
                    ++left;
                } 
                else {
                    *merged_it = *right;
                    ++right;
                }
                ++merged_it;
            }

            while (left != mid) {
                *merged_it = *left;
                ++left;
                ++merged_it;
            }

            while (right != last) {
                *merged_it = *right;
                ++right;
                ++merged_it;
            }

            std::copy(merged.begin(), merged.end(), first);
        
        }
        
        template <typename Iterator>
        static void insertionSort(Iterator first, Iterator last)
        {
            for (Iterator current = first + 1; current != last; ++current) 
            {
                typename Iterator::value_type key = *current;
                Iterator previous = current - 1;

                while (previous >= first && key < *previous)
                {
                    *(previous + 1) = *previous;
                    --previous;
                }
                *(previous + 1) = key;
            }   
        }

        template <typename it>
        static void fordJohnsonSort(it first, it last)
        {
            if(isSorted(first, last))
            {
                std::cout << "The sequence is already sorted." << std::endl;
                return;
            }
            size_t size = std::distance(first, last);
            //std::cout << "Size: " << size << std::endl;
            if (size < 16)
                insertionSort(first, last);
            else
            {
                it mid = first + size / 2;
                fordJohnsonSort(first, mid);
                fordJohnsonSort(mid, last);
                merge(first, mid, last);
            }
        
        }
        template <typename it>
        static bool isSorted(it first, it last)
        {
            if (first == last)
                return true;
            it next = first;
            while (++next != last)
            {
                if (*next < *first)
                    return false;
                ++first;
            }
            return true;
        }
};

template <typename Container>
void printContainer(const Container &container)
{
    typename Container::const_iterator it = container.begin();
    while (it != container.end())
    {
        std::cout << "[" << *it << "] ";
        ++it;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
#endif