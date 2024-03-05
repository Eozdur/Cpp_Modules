#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	//Animal animal; error
	Dog dog;
	Cat cat;
	std::cout << ": " << dog.getType() << std::endl;
	std::cout << ": " << cat.getType() << std::endl;
	dog.makesound();
	cat.makesound();

}
