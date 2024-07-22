#include "RobotomyRequestForm.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("Robotomy request", 72, 45), _target("unknown")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("Robotomy request", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomy)
{
	*this = robotomy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

/*
**		OVERLOAD OPERATORS
*/

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomy)
{
	(void)robotomy;
	return (*this);
}

/*
**		MEMBER FUNCTIONS
*/

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	int	robotomized;

	this->AForm::executeCheck(bureaucrat);
	std::cout << "*rizZzzz BzzZz rZz* ";
	robotomized = rand() % 2;
	if (robotomized)
		std::cout << PURPLE << _target << END << " was robotomized" << std::endl;
	else
		std::cout << PURPLE << _target << END << " was not robotomized" << std::endl;
	
}