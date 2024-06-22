#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat_1("Manager", 3);
	Bureaucrat bureaucrat_2("Assistant", 43);
	std::cout << bureaucrat_1 << std::endl;
	std::cout << bureaucrat_2 << std::endl;

	Form form_1("Form_1", 5, 10); // Form_1'in imzalanması için 5, uygulanması için 10 puan gereklidir.
	std::cout << "--------------------------------------" << std::endl;
	std::cout << form_1 << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	
	Form form_2("Form_2", 5499, 10);
	std::cout << "--------------------------------------" << std::endl;
	
	bureaucrat_1.signForm(form_1);

	std::cout << form_1 << std::endl;
	
	bureaucrat_2.signForm(form_1);
	
	std::cout << form_1 << std::endl;
	return 0;
}