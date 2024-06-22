#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> vec;
    std::deque<int> dq;
    if (argc > 1)
    {
            for (int i = 1; i < argc; ++i) 
            {
                int value = std::atoi(argv[i]);
                if (value < 1) 
                {
                    std::cerr << "Error: Invalid input value \"" << argv[i] << "\". Only positive integers are allowed." << std::endl;
                    exit(EXIT_FAILURE);
                }
                vec.push_back(value);
                dq.push_back(value);
            }
        std::cout << "Vector Before: ";
        printContainer(vec);

        clock_t start1 = clock();
        PmergeMe::fordJohnsonSort(vec.begin(), vec.end());
        clock_t end1 = clock();
        double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

        std::cout << "Deque Before: ";
        printContainer(dq);

        clock_t start2 = clock();
        PmergeMe::fordJohnsonSort(dq.begin(), dq.end());
        clock_t end2 = clock();
        double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

        std::cout << "Vector After: ";
        printContainer(vec);
        
        std::cout << " Deque After: ";
        printContainer(dq);

        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector container: " << time1 << " μs" << std::endl;
        std::cout << "Time to process a range of " << dq.size() << " elements with std::deque container: " << time2 << " μs" << std::endl;
        if (vec != std::vector<int>(dq.begin(), dq.end())) 
        {
            std::cerr << "The sorted sequences are not equal." << std::endl;
            return 1;
        }
        std::cout << "The sorted sequences are equal." << std::endl;
    }
    else
        std::cerr << "Error: Sequence is not given!" << std::endl;
    return 0;
}