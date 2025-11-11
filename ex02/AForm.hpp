/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:59:08 by marvin            #+#    #+#             */
/*   Updated: 2025/11/07 16:59:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
			AForm();
			AForm(std::string name, int toSign, int toExecute);
			virtual ~AForm();
			AForm(const AForm &copy);
			AForm& operator=(const AForm &other);
			const std::string &getFormName() const;
			int getMinValueToExec() const;
			int getMinValueToSign() const;
			bool getSignature() const;
			void beSigned(const Bureaucrat &b);
			void execute(const Bureaucrat &executor) const;
			class GradeTooHighException : public std::exception
			{
				virtual const char *what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				virtual const char *what() const throw();
			};
			class AlreadySignedException : public std::exception
			{
				virtual const char *what() const throw();
			};
			class NotSignedException : public std::exception
			{
				virtual const char *what() const throw();
			};			

	private:
			const std::string 	_name;
			bool			_signed;
			const int		_toSign;
			const int		_toExecute;
			
	protected:
			virtual void 	executeAction() const = 0;		
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
