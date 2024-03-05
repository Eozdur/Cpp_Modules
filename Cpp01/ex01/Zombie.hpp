#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie()
        {
            std::cout << "Zombie Created !!!" << std::endl;
        };
        ~Zombie();
        void announce();
        void setname(std::string name);
};
Zombie *zombieHorde(int N,std::string name);