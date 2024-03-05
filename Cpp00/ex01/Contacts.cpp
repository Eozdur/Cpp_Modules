#include <iostream>
#include "Contacts.hpp"

void Contacts::setting_name(std::string str)
{
    Name = str;
}
void Contacts::setting_surname(std::string str)
{
    Surname = str;
}
void Contacts::setting_nickname(std::string str)
{
    Nickname = str;
}
void Contacts::setting_phonenumber(std::string str)
{
    Phone_number = str;
}
void Contacts::setting_darkestsecret(std::string str)
{
    Darkest_secret = str;
}
std::string Contacts::get_name()const
{
    return (Name);
}
std::string Contacts::get_surname()const
{
    return (Surname);
}
std::string Contacts::get_nickname()const
{
    return (Nickname);
}
std::string Contacts::get_phonenumber()const
{
    return (Phone_number);
}
std::string Contacts::get_darkestsecret()const
{
    return (Darkest_secret);
}