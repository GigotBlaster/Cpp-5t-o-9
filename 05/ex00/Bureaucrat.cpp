/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:15:34 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/08 12:24:38 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighExeption();
	if (grade > 150)
		throw GradeTooLowExeption();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat&Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	if (this != &bureaucrat)
	{
		_grade = bureaucrat._grade;
	}
	return (*this);
}

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
		throw GradeTooHighExeption();
	_grade--;
}

void	Bureaucrat::downGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowExeption();
	_grade++;
}

std::ostream	&operator<<(std::ostream &flux, Bureaucrat const &bureaucrat)
{
	flux << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (flux);
}
