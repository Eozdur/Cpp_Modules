#include <iostream>


//reference -> maskelenmiş pointer

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Str Adress: " << &str << std::endl;
    std::cout << "stringPTR Adress: " << stringPTR << std::endl;
    std::cout << "stringREF Adress: " << &stringREF << std::endl;
    std::cout << "\n**********************************\n" << std::endl;
    std::cout << "Str value : " << str << std::endl;
    std::cout << "stringPTR value : " << *stringPTR << std::endl;
    std::cout << "stringREF value : " << stringREF << std::endl;
    
}