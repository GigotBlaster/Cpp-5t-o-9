/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:32:05 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/07 16:57:58 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("Shrubbery creation", 145, 137), _target("unknown")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("Shrubbery creation", 145, 137), _target(target)
{
	return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyForm) : AForm(shrubberyForm)
{
	*this = shrubberyForm;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

//overload

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyForm)
{
	(void)shrubberyForm;
	return (*this);
}

//member function

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	std::ofstream	file;

	this->AForm::executeCheck(bureaucrat);
	file.open((_target + "_shrubbery").c_str());
	if (file.good() == false)
		throw FileOpeningFail();
	file << "              v .   ._, |_  .," << std::endl;
    file << "       \'-._\\/  .  \\ /    |/_" << std::endl;
    file << "           \\\\  _\\, y | \\//" << std::endl;
    file << "     _\\_.___\\\\, \\\\/ -.\\||" << std::endl;
    file << "       \'7-,--.\'._||  / / ," << std::endl;
    file << "       /\'     \'-.\'./ / |/_.\'" << std::endl;
    file << "                 |    |//" << std::endl;
    file << "                 |_    /   " << _target << std::endl;
    file << "                 |-   |" << std::endl;
    file << "                 |   =|" << std::endl;
    file << "                 |    |" << std::endl;
	file << "----------------/ ,  . \\--------._" << std::endl;
	file.close();
}