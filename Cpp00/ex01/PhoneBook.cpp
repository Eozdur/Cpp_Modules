#include <iostream>
#include <string>
#include <iomanip>
#include "Phonebook.hpp"

void PhoneBook::incrementindex()
{
    indexofbook++;
}
void PhoneBook::add()
{
    std::string str;
    static int index = 0;
    if(index == 8)
        index = 0;
    while(str.empty())
    {
        std::cout << "Name : ";
        std::getline(std::cin,str);
        new_contacts[index].setting_name(str);
    }
    str.clear();
    while(str.empty())
    {
        std::cout << "surname : ";
        std::getline(std::cin,str);
        new_contacts[index].setting_surname(str);
    }
    str.clear();
    while(str.empty())
    {
        std::cout << "nickname : ";
        std::getline(std::cin,str);
        new_contacts[index].setting_nickname(str);
    }
    str.clear();
    while(str.empty())
    {
        std::cout << "phonenumber : ";
        std::getline(std::cin,str);
        new_contacts[index].setting_phonenumber(str);
    }
    str.clear();
    while(str.empty())
    {
        std::cout << "secret : ";
        std::getline(std::cin,str);
        new_contacts[index].setting_darkestsecret(str);
    }
    incrementindex();
    index++;
}
int is_numeric(std::string val)
{
    int i = 0;
    while(i<val.length())
    {
        if(val[i] < '0' || val[i] > '9')  
            return 0;
        i++;
    }
    return 1;
}
void printheaderbook()
{
    std::cout << "\n\n                 PHONEBOOK               " << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|    INDEX|      NAME|   SURNAME|  NICKNAME|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}

void printformat(std::string str)
{
    unsigned int len = str.length();
    unsigned int i = 0;
    if(len < 10)
        std::cout << std::right << std::setw(10) << str;
    else
        std::cout << str.substr(0,9) << ".";
}
void PhoneBook::search()
{
    int i = indexofbook;
    int j = 0;
    std::string tmp;
    printheaderbook();
    if(i>7)
        i=8;
    while(j<i)
    {
        printformat(std::to_string(j+1));
        std::cout << "|";
        printformat(new_contacts[j].get_name());
        std::cout << "|";
        printformat(new_contacts[j].get_surname());
        std::cout << "|";
        printformat(new_contacts[j].get_nickname());
        std::cout << "|";
        j++;
        std::cout << std::endl;
    }
    if(indexofbook > 0)
    {
        std::cout << "Enter İndex : ";
        std::cin >> tmp;
        if(is_numeric(tmp))
            i = std::stoi(tmp);
        else
        {
            std::cout << "The value is not a number" << std::endl;
            return;
        }
        i--;
        if(i < indexofbook && i >= 0 && i <= 7)
        {
            std::cout << "Name   : " << new_contacts[i].get_name() << std::endl;
            std::cout << "Surname   : " << new_contacts[i].get_surname() << std::endl;
            std::cout << "Nİckname   : " << new_contacts[i].get_nickname() << std::endl;
            std::cout << "Phonenumber   : " << new_contacts[i].get_phonenumber() << std::endl;
            std::cout << "Secret   : " << new_contacts[i].get_darkestsecret() << std::endl;
        }
        else
            std::cout << "index not found "<< std::endl;
    }
}