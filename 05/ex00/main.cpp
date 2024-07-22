#include "Bureaucrat.hpp"

void	testBasic(void)
{
	Bureaucrat	Paul("Paul", 10);

	std::cout << Paul << std::endl;
	Paul.downGrade();
	std::cout << Paul << std::endl;
	Paul.upGrade();
	Paul.upGrade();
	Paul.upGrade();
	Paul.upGrade();
	std::cout << Paul << std::endl;
}

void	testTooLow(void)
{
	Bureaucrat	Paul("Paul", 151);
}

void	testTooHigh(void)
{
	Bureaucrat	Paul("Paul", 0);
}

void	testDownGrade(void)
{
	Bureaucrat	Paul("Paul", 2);
	Paul.upGrade();
	std::cout << Paul << std::endl;
	Paul.upGrade();
}

void	testUpGrade(void)
{
	Bureaucrat	Paul("Paul", 149);
	Paul.downGrade();
	std::cout << Paul << std::endl;
	Paul.downGrade();
}

int	main(void)
{
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

	return (0);
}