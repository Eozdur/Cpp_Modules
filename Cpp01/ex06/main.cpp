#include "Harl.hpp"

int main(int ac,char **av)
{
    if(ac == 2)
    {
        Harl new_harl;
        new_harl.complain(av[1]);
    }
    else
    {
        std::cout << "Only 2 Arguments !!!" << std::endl;
        return 0;
    }
}