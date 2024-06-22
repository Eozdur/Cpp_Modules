#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat")
{
    this->grade = 99;
}

Bureaucrat::Bureaucrat(std::string name, int _grade) : name(name)
{
    try
    {
        if(_grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else if (_grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else
            this->grade = _grade;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
        this->grade = other.grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}        
void Bureaucrat::incrementGrade()
{
    try
    {
        if(this->grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        this->grade--;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::decrementGrade()
{
    try
    {
        if(this->grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            this->grade++;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) 
{
    if(bureaucrat.getGrade() >= 1 && bureaucrat.getGrade() <= 150)
        return (os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
    return os;
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too Low");
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::signAForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn’t sign" << form.getName() << " because " << e.what() << std::endl;
    }
}
