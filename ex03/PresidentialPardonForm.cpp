/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:45:56 by marvin            #+#    #+#             */
/*   Updated: 2025/11/11 18:45:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"



PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), _target("default")
{
	std::cout << "Default PresidentialPardonForm Constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other.getTarget();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{	
	std::cout << "Default PresidentialPardonForm Destructor called\n";
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
