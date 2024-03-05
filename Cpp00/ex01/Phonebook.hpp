#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contacts.hpp"

class PhoneBook
{
private:
    int indexofbook;
public:
    Contacts new_contacts[8];
    void init()
    {
        indexofbook = 0;
    }
    void add();
    void search();
    void incrementindex();
};
void printheaderbook();
int is_numeric(std::string);
void printformat(std::string);
#endif