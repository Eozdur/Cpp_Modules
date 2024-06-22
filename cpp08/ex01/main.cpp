#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);

	try
	{
		sp.addNumber(5);
		sp.addNumber(23);
		sp.addNumber(44);
		sp.addNumber(56);
		sp.addNumber(3);
		sp.addNumber(100);
		sp.addNumber(31);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	sp.print();
	std::cout << "***********" << std::endl;
	std::cout <<"Short Span:"<<sp.shortestSpan() << std::endl;
	std::cout <<"Long Span:" <<sp.longestSpan() << std::endl;

	return 0;
}