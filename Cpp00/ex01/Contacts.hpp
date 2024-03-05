#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
class Contacts
{
private:
    std::string Name;
    std::string Surname;
    std::string Nickname;
    std::string Phone_number;
    std::string Darkest_secret;
public:
    std::string get_name()const;
    std::string get_surname()const;
    std::string get_nickname()const;
    std::string get_phonenumber()const;
    std::string get_darkestsecret()const;
    void setting_name(std::string);
    void setting_surname(std::string);
    void setting_nickname(std::string);
    void setting_phonenumber(std::string);
    void setting_darkestsecret(std::string);
};
#endif