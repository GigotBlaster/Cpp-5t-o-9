/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:31:44 by npetitpi          #+#    #+#             */
/*   Updated: 2024/09/13 16:14:08 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

Intern::Intern(void)
{
	return ;
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern::~Intern()
{
	return ;
}

//overload

Intern	&Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

//member function

static const std::string	lowerStr(const std::string str)
{
	std::string	res;

	for (unsigned int i = 0; i < str.size(); i++)
		res += tolower(str[i]);
	return (res);
}

static AForm	*newShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*newRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*newPresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static int		getFormNumber(const std::string formName)
{
	std::string		formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int				choosen = -1;

	for (int i = 0; i < 3; i++)
	{
		if (lowerStr(formName) == formNames[i])
		{
			choosen = i;
			break;
		}
	}
	return (choosen);
}

AForm	*Intern::makeForm(const std::string formName, const std::string target) const
{
	constructorPtr	funCreations[3] = {&newShrubbery, &newRobotomy, &newPresidential};
	int				choosen;
	AForm			*formPtr = NULL;

	choosen = getFormNumber(formName);
	std::cout << YELLOW << "Intern" << END;
	if (choosen >= 0)
	{
		formPtr = funCreations[choosen](target);
		std::cout << " creates " << GREEN << formPtr->getName() << END << " formular" << std::endl;
	}
	else
		std::cout << " cannot create " << GREEN << formName << END << " because " << BLUE << "it's unknown" << END << std::endl;
	return (formPtr);

}