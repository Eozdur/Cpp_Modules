#include "Form.hpp"

Form::Form(): name("Default Form"), _isSigned(false), gradeToSign(1), gradeToExecute(10)
{
}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), _isSigned(false), gradeToSign(signGrade), gradeToExecute(executeGrade)
{
    try
    {
        if(this->gradeToSign > 150 || this->gradeToExecute > 150)
            throw Form::GradeTooLowException();
        if(this->gradeToSign < 1 || this->gradeToExecute < 1)
            throw Form::GradeTooHighException();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

Form::~Form()
{
    
}

Form::Form(const Form &other) : name(other.name), _isSigned(other._isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    if(this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

void Form::beSigned(Bureaucrat const &other)
{
    if(other.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    else
        this->_isSigned = true;
}


std::string Form::getName() const
{
	return this->name;
}

bool Form::getSigned() const
{
    return this->_isSigned;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form name: " << form.getName() << std::endl;
    out << "Form sign grade: " << form.getGradeToSign() << std::endl;
    out << "Form execute grade: " << form.getGradeToExecute() << std::endl;
    out << "Form signed: " << form.getSigned() << std::endl;
    return out;
}