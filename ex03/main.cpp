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

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	
	std::cout << "=== TEST 1: ShrubberyCreationForm ===" << std::endl;
	try
	{
		Bureaucrat john("John", 137);
		ShrubberyCreationForm shrubbery("home");
		
		std::cout << john << std::endl;
		std::cout << shrubbery << std::endl;
		
		john.signForm(shrubbery);
		john.executeForm(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 2: RobotomyRequestForm - Multiple attempts ===" << std::endl;
	try
	{
		Bureaucrat engineer("Engineer", 40);
		RobotomyRequestForm robotomy("Bender");
		
		std::cout << engineer << std::endl;
		std::cout << robotomy << std::endl;
		
		engineer.signForm(robotomy);
		std::cout << "\nAttempt 1:" << std::endl;
		engineer.executeForm(robotomy);
		std::cout << "Attempt 2:" << std::endl;
		engineer.executeForm(robotomy);
		std::cout << "Attempt 3:" << std::endl;
		engineer.executeForm(robotomy);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 3: PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 4: Try to execute unsigned form ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrubbery("garden");
		
		std::cout << "Trying to execute unsigned form..." << std::endl;
		boss.executeForm(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 5: Grade too low to sign ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 100);
		PresidentialPardonForm pardon("Ford Prefect");
		
		std::cout << intern << std::endl;
		std::cout << pardon << std::endl;
		
		intern.signForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 6: Grade too low to execute ===" << std::endl;
	try
	{
		Bureaucrat manager("Manager", 10);
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Zaphod");
		
		president.signForm(pardon);
		
		std::cout << "\nManager tries to execute..." << std::endl;
		manager.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
