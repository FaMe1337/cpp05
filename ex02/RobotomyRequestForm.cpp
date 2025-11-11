/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:12:20 by marvin            #+#    #+#             */
/*   Updated: 2025/11/11 15:12:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), _target("default")
{
	std::cout << "Default RobotomyRequestForm Constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default RobotomyRequestForm Destructor called\n";
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* DRILLING NOISES *" << std::endl;
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed but " << getTarget() << " successfully became a vegetable!" << std::endl;
}
