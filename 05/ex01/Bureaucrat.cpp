/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:12:04 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/07 16:21:01 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighExeption();
	if (grade > 150)
		throw GradeTooLowExeption();
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
	flux << YELLOW << bureaucrat.getName() << END << ", grade " << bureaucrat.getGrade();
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
		throw GradeTooHighExeption();
	_grade--;
}

void	Bureaucrat::downGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowExeption();
	_grade++;
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << YELLOW << _name << END << " signs " << GREEN << form.getName() << END << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << YELLOW << _name << END << " couldn't sign " << GREEN << form.getName() << END <<  " because " << PURPLE << e.what() << END << std::endl;
	}
}