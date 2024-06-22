
#include"ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}


ScalarConverter &ScalarConverter::operator=(const ScalarConverter &s)
{
	this->sc = s.sc;
	return (*this);
}

void ScalarConverter::convert(std::string str)
{
	std::cout << "char :",to_char(str);
	std::cout << "int :",to_int(str);
	std::cout << "float :",to_float(str);
	std::cout << "double :",to_double(str);
}

bool ScalarConverter::check(std::string &str)
{
	return (str == "nan" || str == "nanf" || str == "-inf" || str == "inf" || str == "+inf" || str == "-inff" || str == "inff" || str == "+inff");
}
bool ScalarConverter::is_wrong_number(std::string &s)
{
	size_t	i;

	if ((s[0] == '-' || s[0] == '+'))
		if ((std::count(s.begin(), s.end(), '-') + std::count(s.begin(), s.end(), '+')) != 1)
			return (true);
	if ((std::count(s.begin(), s.end(), 'f') > 1 || std::count(s.begin(), s.end(), '.') > 1) ||
		(std::count(s.begin(), s.end(), 'f') == 1 && s[s.size() - 1] != 'f'))
		return (true);
	for (i = 0 ; i < s.size() ; i++)
		if (!isdigit(s[i]) && s[0] != '-' && s[0] != '+' && (s[i] != 'f') && s[i] != '.')
		{
			return (true);
		}
	return (false);
}

void ScalarConverter::to_char(std::string &str)
{
	if(str.size() == 1 && !isdigit(str[0]))
	{
		std::cout << "'" << str[0] << "'" << std::endl;
		return;
	}
	char c = static_cast<char>(std::atoi(str.c_str()));

	if(ScalarConverter::check(str))
		std::cout << "impossible" <<std::endl;
	else if(c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout<< "'" << c << "'" << std::endl;
}

void ScalarConverter::to_int(std::string &str)
{
	if(str.size() == 1 && !isdigit(str[0]))
	{
		std::cout << static_cast<int>(str[0]) << std::endl;
		return;
	}
	if(ScalarConverter::check(str))
		std::cout << "impossible" <<std::endl;
	else
		std::cout << std::atoi(str.c_str()) << std::endl;
}

void ScalarConverter::to_float(std::string &str)
{
	float f = std::strtof(str.c_str(),0);

	if(f == static_cast<int>(f))
		std::cout << f << ".0f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}


void ScalarConverter::to_double(std::string&str)
{
	double d = std::strtod(str.c_str(),0);

	if(d == static_cast<int>(d))
		std::cout << d << ".0" <<std::endl;
	else
		std::cout << d << std::endl;
}

bool control_arg(std::string &str)
{
	if(ScalarConverter::check(str))
		return true;
	if(str.length() == 1 && isalpha(str[0]))
	{
		return (true);
	}
	if (ScalarConverter::is_wrong_number(str))
		return (false);
	return (true);
} 