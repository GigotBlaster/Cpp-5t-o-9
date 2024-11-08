/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:31:08 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/07 16:37:19 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomy) : AForm(robotomy)
{
	*this = robotomy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

//overload

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomy)
{
	(void)robotomy;
	return (*this);
}

//member function

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	int	robotomized;

	this->AForm::executeCheck(bureaucrat);
	std::cout << "*Bzzzzt cling tic* ";
	robotomized = rand() % 2;
	if (robotomized)
		std::cout << BLUE << _target << END << " was robotomized" << std::endl;
	else
		std::cout << RED << _target << END << " was not robotomized" << std::endl;
	
}