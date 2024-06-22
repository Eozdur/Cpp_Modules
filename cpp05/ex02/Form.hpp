#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"


class Bureaucrat;
class Form
{
    private:
        const std::string name;
        bool _isSigned;
	    const int gradeToSign;
	    const int gradeToExecute;
    public:
        class GradeTooHighException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

    public:
        Form();
        ~Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        Form(std::string name, int gradeToSign, int gradeToExecute);
        void beSigned(Bureaucrat const &other);

		std::string	getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif