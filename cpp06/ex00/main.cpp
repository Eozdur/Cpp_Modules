#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cout << "bad number of args" << std::endl;
		return 0;
	}
	std::string str = (std::string)av[1];
	if(control_arg(str))
		ScalarConverter::convert(str);
	else if(str.length() == 1 && isprint(str[0]))
	{
		ScalarConverter::convert(std::to_string(static_cast<int>(str[0])));
	}
	else
		std::cout << "Invalid" << std::endl;
}
