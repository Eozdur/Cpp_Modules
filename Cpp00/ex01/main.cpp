#include "Phonebook.hpp"

int main()
{    
    PhoneBook new_phone;
    new_phone.init();
    while(1)
    {
        std::string input_val;
        std::cout << "Please Enter Command (ADD,SEARCH,EXIT) -> ";
        std::cin >> input_val;
        if(input_val == "ADD")
        {
            new_phone.add();
        }
        else if (input_val == "SEARCH")
        {
            new_phone.search();
        }
        else if (input_val == "EXIT")
        {
            std::cout << "Exiting the program..." << std::endl;
            return 0;
        }
        else
            std::cout << "Wrong input pls try again" << std::endl;

    }
}
