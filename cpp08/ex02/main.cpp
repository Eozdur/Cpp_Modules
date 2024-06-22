#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top Element:"<< mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Stack size:"<< mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator itend = mstack.end();
    std::cout <<"BEGİN:"<< *it << std::endl;
    std::cout <<"END:"<< *itend << std::endl;

    ++it;
    --it;
    std::cout << "****MUTANT-STACK******" << std::endl;
    while (it != itend)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}
