#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Bob", 150);
	std::cout << b << std::endl;
	b.incrementGrade();
	std::cout << b << std::endl;
	b.decrementGrade();
	std::cout << b << std::endl;
	Bureaucrat be("Jack", -8);
	std::cout << be << std::endl;
	return 0;
}