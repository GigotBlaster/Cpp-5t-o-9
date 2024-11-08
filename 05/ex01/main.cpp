#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form 		f("formular", 10, 4);
	Bureaucrat	manu("Manu", 11);

	std::cout << f << std::endl;
	std::cout << manu << std::endl;
	
	manu.signForm(f);
	manu.upGrade();
	manu.signForm(f);
	manu.signForm(f);

	std::cout << std::endl << f << std::endl;

	return (0);
}