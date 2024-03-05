#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{   
    private:
        std::string ideas[100];
    public:
        Brain();
        virtual ~Brain();
        Brain(const Brain &r);
        Brain &operator=(const Brain &r);
        std::string &getideas(int i);
        void setideas(std::string idea,int i);

};
#endif