/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:31:47 by npetitpi          #+#    #+#             */
/*   Updated: 2024/09/13 10:52:25 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iomanip>

static void     printTitle(std::string title)
{
        std::string     toPrint;
        int     size = 68;
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

	printTitle("Formular Creation");
	Bureaucrat	pres("President", 1);
	Intern		exploitedIntern;
	AForm		*forms[4];

	forms[0] = exploitedIntern.makeForm("shrubbery creation", "Target1");
	forms[1] = exploitedIntern.makeForm("robotomy request", "Target2");
	forms[2] = exploitedIntern.makeForm("presidential pardon", "Target3");
	forms[3] = exploitedIntern.makeForm("formular", "Target4");

	for (int i = 0; i < 4; i++)
	{
		if (forms[i])
		{
			std::cout << std::endl << *(forms[i]);
			pres.signForm(*(forms[i]));
			pres.executeForm(*(forms[i]));
		}
	}

	for (int i = 0; i < 4; i++)
		delete forms[i];
	return (0);
}