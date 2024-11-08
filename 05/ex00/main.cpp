/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:16:31 by npetitpi          #+#    #+#             */
/*   Updated: 2024/11/07 19:02:24 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testName(void)
{
	std::cout << Bureaucrat() << std::endl;
}

void	testBasic(void)
{
	Bureaucrat	staff("Adrien", 94);

	std::cout << staff << std::endl;
	staff.downGrade();
	std::cout << staff << std::endl;
	staff.upGrade();
	staff.upGrade();
	staff.upGrade();
	staff.upGrade();
	std::cout << staff << std::endl;
}

void	testTooLow(void)
{
	Bureaucrat	staff("Adrien", 160);
}

void	testTooHigh(void)
{
	Bureaucrat	staff("Adrien", 0);
}

void	testDownGrade(void)
{
	Bureaucrat	staff("Adrien", 2);
	staff.upGrade();
	std::cout << staff << std::endl;
	staff.upGrade();
}

void	testUpGrade(void)
{
	Bureaucrat	staff("Adrien", 149);
	staff.downGrade();
	std::cout << staff << std::endl;
	staff.downGrade();
}

int	main(void)
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	
	try
	{
		testBasic();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		testTooLow();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		testTooHigh();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		testDownGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		testUpGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	return (0);
}