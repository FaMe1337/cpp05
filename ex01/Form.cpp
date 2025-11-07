/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:59:04 by marvin            #+#    #+#             */
/*   Updated: 2025/11/07 16:59:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
			Form();
			Form(cenas);
			~Form();
			Form(Form &copy);
			Form& operator=(const Form &other);
			beSigned(const Bureaucrat &b)

	private:
			std::string _name;
			bool	_signed;
			int		_min_grade;
			int
};





std::ostream &operator<<(std::ostream &out, Form &f);

#endif-