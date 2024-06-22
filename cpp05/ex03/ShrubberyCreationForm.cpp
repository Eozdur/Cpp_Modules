#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target("ShrubberyCreationForm")
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("Shrubbery Creation Form", 145, 137), target(_target)
{

}

void ShrubberyCreationForm::write_ascii_tree() const
{
    std::ofstream outputFile;
    try
    {
        outputFile.open(this->target + "_shrubbery");
        if(!outputFile.is_open())
            throw std::runtime_error("File not open");
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    outputFile <<
            "                                  # #### ####\n"
            "                                ### \\/#|### |/####\n"
            "                               ##\\/#/ \\||/##/_/##/_#\n"
            "                             ###  \\/###|/ \\/ # ###\n"
            "                           ##_\\/_\\##| #/###_/_####\n"
            "                          ## #### # \\ #| /  #### ##/##\n"
            "                           __#_--###`  |{,###---###-~\n"
            "                              |      \\ }{        |\n"
            "                              |        }}{        |\n"
            "                             42        }}{       42\n"          
            "                                      {{}\n"
            "                                , -=-~{ .-^- _\n";
    outputFile.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    try
    {
        if(this->getSigned())
        {
            if(this->getGradeToExecute() > executor.getGrade())
            {
                this->write_ascii_tree();
                std::cout << this->target << "_shruberry tree has been created" << std::endl;
            }
            else
                throw AForm::GradeTooLowException();
            
        }
        else
            throw std::runtime_error("Form not signed");
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if(this != &other)
    {
        this->target = other.target;
    }
    return *this;
}