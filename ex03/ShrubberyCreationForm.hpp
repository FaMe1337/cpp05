/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:00:08 by marvin            #+#    #+#             */
/*   Updated: 2025/11/11 19:00:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(const std::string target);
			ShrubberyCreationForm(const ShrubberyCreationForm &copy);
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
			virtual ~ShrubberyCreationForm();
			std::string getTarget() const;

	protected:
			virtual void executeAction() const;

	private:
			std::string _target;

};

#endif
