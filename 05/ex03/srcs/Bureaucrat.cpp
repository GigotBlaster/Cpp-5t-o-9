/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:31:35 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/07 16:22:27 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHigh();
	if (grade > 150)
		throw GradeTooLow();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

//overload

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
	{
		_grade = bureaucrat._grade;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &flux, const Bureaucrat &bureaucrat)
{
	flux << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
	return (flux);
}

//member function

const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::upGrade(void)
{
	if (_grade <= 1)
		throw GradeTooHigh();
	_grade--;
}

void	Bureaucrat::downGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLow();
	_grade++;
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << YELLOW << _name << END << " signs " << GREEN << form.getName() << END << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << YELLOW << _name << END << " cannot sign " << GREEN << form.getName() << END <<  " because " << BLUE << e.what() << END << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << YELLOW << _name << END << " executes " << GREEN << form.getName() << END << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << YELLOW << _name << END << " cannot executes " << GREEN << form.getName() << END <<  " because " << BLUE << e.what() << END << std::endl;
	}
}