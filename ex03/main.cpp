/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:59:14 by marvin            #+#    #+#             */
/*   Updated: 2025/11/07 16:59:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


int main()
{
	std::srand(std::time(NULL));
	
	std::cout << "=== TEST 1: Intern creates Shrubbery form ===" << std::endl;
	try
	{
		Intern intern;
		Bureaucrat john("John", 137);
		AForm *form;
		
		form = intern.makeForm("shrubbery creation", "home");
		if (form)
		{
			std::cout << *form << std::endl;
			john.signForm(*form);
			john.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 2: Intern creates Robotomy form ===" << std::endl;
	try
	{
		Intern intern;
		Bureaucrat engineer("Engineer", 40);
		AForm *form;
		
		form = intern.makeForm("robotomy request", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;
			engineer.signForm(*form);
			engineer.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 3: Intern creates Presidential form ===" << std::endl;
	try
	{
		Intern intern;
		Bureaucrat president("President", 1);
		AForm *form;
		
		form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form)
		{
			std::cout << *form << std::endl;
			president.signForm(*form);
			president.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 4: Intern tries to create unknown form ===" << std::endl;
	try
	{
		Intern intern;
		AForm *form;
		
		form = intern.makeForm("vacation request", "Bahamas");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 5: Multiple forms from same intern ===" << std::endl;
	try
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm *form1 = intern.makeForm("shrubbery creation", "office");
		AForm *form2 = intern.makeForm("robotomy request", "Employee");
		AForm *form3 = intern.makeForm("presidential pardon", "Zaphod");
		
		if (form1)
		{
			boss.signForm(*form1);
			boss.executeForm(*form1);
			delete form1;
		}
		if (form2)
		{
			boss.signForm(*form2);
			boss.executeForm(*form2);
			delete form2;
		}
		if (form3)
		{
			boss.signForm(*form3);
			boss.executeForm(*form3);
			delete form3;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
