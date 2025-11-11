/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:12:22 by marvin            #+#    #+#             */
/*   Updated: 2025/11/11 15:12:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public: 
			RobotomyRequestForm();
			RobotomyRequestForm(const std::string &target);
			RobotomyRequestForm(const RobotomyRequestForm &copy);
			RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
			virtual ~RobotomyRequestForm();
			std::string getTarget() const;

	protected:
			virtual void executeAction() const;

	private:
			std::string _target;
};

#endif
