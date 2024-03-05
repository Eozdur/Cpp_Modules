#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat &r);
        Cat &operator=(const Cat &r);
        void makesound()const;
};
#endif