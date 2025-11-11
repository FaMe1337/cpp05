/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:35:52 by marvin            #+#    #+#             */
/*   Updated: 2025/11/07 13:35:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat 
{
	public:
			Bureaucrat();
			Bureaucrat(std::string name, int grade);
			Bureaucrat& operator=(const Bureaucrat &other);
			Bureaucrat(const Bureaucrat &copy);
			~Bureaucrat();
			int getGrade() const;
			void setIncreaseGrade();
			void setDecreaseGrade();
			const std::string& getName() const;
			void signForm(Form &form) const;
			class GradeTooHighException : public std::exception
			{
				public:
					virtual const char *what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				public:
					virtual const char *what() const throw();
			};

	private:
			const std::string _name;
			int	_grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif