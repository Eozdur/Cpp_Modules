#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat &r);
        Cat &operator=(const Cat &r);
        void makesound()const;
        Brain *getbrain()const;
};
#endif