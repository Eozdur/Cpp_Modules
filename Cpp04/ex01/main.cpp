#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	{
		const Animal *shelter[10];
		int i = 0;
		while(i < 10)
		{
			if (i % 2 == 0)
				shelter[i] = new Dog();
			else
				shelter[i] = new Cat();
			i++;
		}
		std::cout << "**********************************" << std::endl;
		std::cout << shelter[0]->getType() << std::endl;
		std::cout << shelter[1]->getType() << std::endl;
		std::cout << "**********************************" << std::endl;
		i = 0;
		while(i < 10)
		{
			delete shelter[i];
			std::cout << std::endl;
			i++;
		}
	}
	{
		std::cout << "**********DEEP COPY CHECK***********" << std::endl;
		std::cout << "deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "REFERENCE DOG A : " << dogA->getbrain() << std::endl;
        std::cout << "REFERENCE DOG B : " << dogB->getbrain() << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------" << std::endl;
	{
		std::cout << "deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;
		
		*dogA = *dogB;
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "REFERENCE DOG A : " << dogA->getbrain() << std::endl;
        std::cout << "REFERENCE DOG B : " << dogB->getbrain() << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------" << std::endl;
	{
		std::cout << "deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat(*catA);
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "REFERENCE CAT A : " << catA->getbrain() << std::endl;
        std::cout << "REFERENCE CAT B : " << catB->getbrain() << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		delete catA;
		delete catB;
	}
	std::cout << "-------------------------------------" << std::endl;
	{
		std::cout << "deep copy of Cat class using assignment operator overload:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "REFERENCE CAT A : " << catA->getbrain() << std::endl;
        std::cout << "REFERENCE CAT B : " << catB->getbrain() << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		*catA = *catB;
		delete catA;
		delete catB;
	}
	{
		std::cout << "*****DEEP COPY CHECK VARIABLE*****" << std::endl;
		std::cout << std::endl;
		Dog *dog = new Dog();
		dog->getbrain()->setideas("Idea Dog",0);
		Dog *copydog = new Dog(*dog);
		Cat *cat = new Cat();
		Cat *copycat = new Cat();
		cat->getbrain()->setideas("Idea Cat",0);
		*copycat = *cat;
		// Dog check
		std::cout << "-------------------------------------" << std::endl;
		std::cout << dog->getbrain()->getideas(0) << std::endl;
		std::cout << copydog->getbrain()->getideas(0) << std::endl;
		dog->getbrain()->setideas("Idea Wrondog",0);
		std::cout << dog->getbrain()->getideas(0) << std::endl;
		std::cout << copydog->getbrain()->getideas(0) << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		// Cat check
		std::cout << "-------------------------------------" << std::endl;
		std::cout << cat->getbrain()->getideas(0) << std::endl;
		std::cout << copycat->getbrain()->getideas(0) << std::endl;
		cat->getbrain()->setideas("Idea Wrongcat",0);
		std::cout << cat->getbrain()->getideas(0) << std::endl;
		std::cout << copycat->getbrain()->getideas(0) << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		delete dog;
		delete copydog;
		delete cat;
		delete copycat;
	}
}
