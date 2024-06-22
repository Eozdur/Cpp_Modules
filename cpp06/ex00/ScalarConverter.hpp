
#pragma once

#include<iostream>

class ScalarConverter {

	private:
		std::string sc;
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &s);
	public:
		static void convert(std::string str);
		static bool check(std::string &str);
		static bool is_wrong_number(std::string &str);
		static void to_char(std::string &str);
		static void to_int(std::string &str);
		static void to_float(std::string &str);
		static void to_double(std::string &str);
};
bool control_arg(std::string &str);