/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:12:47 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/07 16:20:32 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("useless"), _gradeSign(150), _gradeExec(150), _signed(false)
{
	return ;
}

Form::Form(const std::string name, int gradeSign, int gradeExec) :
	_name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighExeption();
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowExeption();
}

Form::Form(const Form &form) : _name(form._name), _gradeSign(form._gradeSign), _gradeExec(form._gradeExec)
{
	*this = form;
}

Form::~Form()
{
	return ;
}

//overload

Form	&Form::operator=(const Form &form)
{
	if (this != &form)
		_signed = form._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &flux, const Form &form)
{
	flux << "[" << form.getName() << "]" << std::endl;
	flux << "\t" << "signed : " << form.getSigned() << std::endl;
	flux << "\t" << "grade needed to sign : " << form.getGradeSign() << std::endl;
	flux << "\t" << "grade needed to execute : " << form.getGradeExec() << std::endl;
	return (flux);
};

//member function

const std::string	Form::getName(void) const
{
	return (_name);
}

int		Form::getGradeSign(void) const
{
	return (_gradeSign);
}

int		Form::getGradeExec(void) const
{
	return (_gradeExec);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowExeption();
	_signed = true;
}