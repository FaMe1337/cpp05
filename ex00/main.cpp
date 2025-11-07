/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:00:00 by marvin            #+#    #+#             */
/*   Updated: 2025/11/07 14:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Test 1: Valid Bureaucrat ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade Too High (0) ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade Too Low (151) ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment Grade ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 2);
		std::cout << alice << std::endl;
		alice.setIncreaseGrade();
		std::cout << alice << std::endl;
		alice.setIncreaseGrade(); 
		std::cout << alice << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement Grade ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 149);
		std::cout << charlie << std::endl;
		charlie.setDecreaseGrade();
		std::cout << charlie << std::endl;
		charlie.setDecreaseGrade();
		std::cout << charlie << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n=== End of tests ===" << std::endl;
	return 0;
}