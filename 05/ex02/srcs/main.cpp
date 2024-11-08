/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:31:01 by npetitpi          #+#    #+#             */
/*   Updated: 2024/09/06 12:31:01 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>

static void     printTitle(std::string title)
{
        std::string     toPrint;
        int     size = 72;
        int     n;

        toPrint = " " + title + " ";
        n = toPrint.size();
        if (n > size)
        {
                toPrint = toPrint.substr(0, size - 2);
                toPrint[size - 4] = '.';
                toPrint[size - 3] = ' ';
                n = toPrint.size();
        }
        std::cout << std::endl << std::setfill('~') << std::setw(size) << "" << std::endl;
        std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
        std::cout << toPrint.substr(n / 2, n - n / 2);
        std::cout << std::setfill('~') << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
        std::cout << std::setfill('~') << std::setw(size) << "" << std::endl;
}


int	main(void)
{
	srand(time(NULL));

	printTitle("Shrubbery Creation");
	AForm		*shrub = new ShrubberyCreationForm("home");
	Bureaucrat	corr("Correcteur", 1);
	Bureaucrat	me("Shanley", 140);

	corr.executeForm(*shrub);
	corr.signForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << corr << std::endl;
	corr.executeForm(*shrub);
	me.executeForm(*shrub);
	delete shrub;


	printTitle("Robotomy Request");
	AForm		*robotomy = new RobotomyRequestForm("Correcteur");
	Bureaucrat	me2("Shanley", 1);

	me2.executeForm(*robotomy);
	me2.signForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	delete robotomy;
	
	
	printTitle("Presidential Pardon");
	AForm		*presidential = new PresidentialPardonForm("Correcteur");
	Bureaucrat	me3("Shanley", 6);

	me3.executeForm(*presidential);
	me3.signForm(*presidential);
	me3.executeForm(*presidential);
	me3.upGrade();
	me3.executeForm(*presidential);
	delete presidential;

	return (0);
}