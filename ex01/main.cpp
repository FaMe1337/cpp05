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
#include "Form.hpp"

int main()
{
	std::cout << "=== TEST 1: Creating Forms with valid grades ===" << std::endl;
	try
	{
		Form form1("Tax Form", 50, 25);
		std::cout << form1 << std::endl;
		
		Form form2("Presidential Pardon", 5, 5);
		std::cout << form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 2: Creating Forms with invalid grades ===" << std::endl;
	try
	{
		Form badForm1("Too High", 0, 50);
		std::cout << badForm1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try
	{
		Form badForm2("Too Low", 50, 151);
		std::cout << badForm2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 3: Successful signing (bureaucrat has sufficient grade) ===" << std::endl;
	try
	{
		Bureaucrat john("John", 10);
		Form form("Budget Report", 50, 25);
		
		std::cout << john << std::endl;
		std::cout << form << std::endl;
		
		john.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 4: Failed signing (bureaucrat grade too low) ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 100);
		Form importantForm("Nuclear Launch Codes", 10, 5);
		
		std::cout << intern << std::endl;
		std::cout << importantForm << std::endl;
		
		intern.signForm(importantForm);
		std::cout << importantForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 5: Trying to sign an already signed form ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Form contract("Employment Contract", 50, 25);
		
		std::cout << boss << std::endl;
		std::cout << "Before signing: " << contract << std::endl;
		
		boss.signForm(contract);
		std::cout << "After first sign: " << contract << std::endl;
		
		boss.signForm(contract);
		std::cout << "After second sign: " << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 6: Multiple bureaucrats, same form ===" << std::endl;
	try
	{
		Bureaucrat high("HighRank", 5);
		Bureaucrat low("LowRank", 100);
		Form secretForm("Top Secret", 50, 25);
		
		std::cout << secretForm << std::endl;
		
		low.signForm(secretForm);
		high.signForm(secretForm);
		
		std::cout << secretForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 7: Edge cases (grade 1 and 150) ===" << std::endl;
	try
	{
		Bureaucrat ceo("CEO", 1);
		Bureaucrat janitor("Janitor", 150);
		
		Form easyForm("Coffee Request", 150, 150);
		Form hardForm("World Domination Plan", 1, 1);
		
		std::cout << "\n--- Janitor tries easy form ---" << std::endl;
		janitor.signForm(easyForm);
		std::cout << easyForm << std::endl;
		
		std::cout << "\n--- Janitor tries hard form ---" << std::endl;
		janitor.signForm(hardForm);
		
		std::cout << "\n--- CEO tries hard form ---" << std::endl;
		ceo.signForm(hardForm);
		std::cout << hardForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}