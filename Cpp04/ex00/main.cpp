#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
    {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makesound(); //will output the cat sound!
    j->makesound();
    meta->makesound();
        
    delete meta;
    delete j;
    delete i;
    }
        //wrongAnimal
        std::cout << "---------------------" << std::endl;
        std::cout << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* cat = new WrongCat();

        std::cout << meta->getType() << " " << std::endl;
        std::cout << cat->getType() << " " << std::endl;
        cat->makesound(); //will output the cat sound!
        meta->makesound();
        delete meta;
        delete cat;
    }
}