/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:30:49 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/07 16:21:32 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

AForm::AForm(void) : _name("useless"), _gradeSign(150), _gradeExec(150), _signed(false)
{
	return ;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExec) :
	_name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHigh();
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLow();
}

AForm::AForm(const AForm &form) :  _name(form._name), _gradeSign(form._gradeSign), _gradeExec(form._gradeExec)
{
	*this = form;
}

AForm::~AForm()
{
	return ;
}

//overload

AForm	&AForm::operator=(const AForm &form)
{
	if (this != &form)
		_signed = form._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &flux, const AForm &form)
{
	flux << "[" << form.getName() << "]" << std::endl;
	flux << "\t" << "signed : " << form.getSigned() << std::endl;
	flux << "\t" << "grade needed to sign : " << form.getGradeSign() << std::endl;
	flux << "\t" << "grade needed to execute : " << form.getGradeExec() << std::endl;
	return (flux);
};

//member function

const std::string	AForm::getName(void) const
{
	return (_name);
}

int		AForm::getGradeSign(void) const
{
	return (_gradeSign);
}

int		AForm::getGradeExec(void) const
{
	return (_gradeExec);
}

bool	AForm::getSigned(void) const
{
	return (_signed);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLow();
	_signed = true;
}

void	AForm::executeCheck(const Bureaucrat &bureaucrat) const
{
	if (!this->getSigned())
		throw AForm::ExecuteNotSigned();
	if (this->getGradeExec() < bureaucrat.getGrade())
		throw AForm::GradeTooLow();
}