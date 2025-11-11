/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:41:42 by marvin            #+#    #+#             */
/*   Updated: 2025/11/11 19:41:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern Constructor called\n";
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Copy Intern constructor called\n";
	*this = copy;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Default Intern Destructor called\n";
}

AForm *Intern::makeForm(std::string form, std::string target) const
{
	int i = 0;
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	while (i < 3 && form != forms[i])
		i++;
	switch (i)
	{
	case 0:
		std::cout << "Intern created " << form  << " form" << std::endl;
		return (new ShrubberyCreationForm(target));
	case 1:
		std::cout << "Intern created " << form << " form" << std::endl;
		return (new RobotomyRequestForm(target));
	case 2:
		std::cout << "Intern created " << form  << " form" << std::endl;
		return (new PresidentialPardonForm (target));
	default:
		std::cout << "Form does not exist" << std::endl;
		return (NULL);
	}
}