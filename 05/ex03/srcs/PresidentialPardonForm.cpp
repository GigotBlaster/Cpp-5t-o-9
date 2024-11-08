/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:31:51 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/07 16:57:19 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("Presidential pardon", 25, 5), _target("unknown")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("Presidential pardon", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidential) : AForm(presidential)
{
	*this = presidential;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

//overload

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &presidential)
{
	(void)presidential;
	return (*this);
}

//member function

void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	this->AForm::executeCheck(bureaucrat);
	std::cout << PURPLE << _target << END << " was forgiven by Zafor Beeblebrox" << std::endl;
}