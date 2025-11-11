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

#include "Form.hpp"

Form::Form():_name("default"),
			_signed(false),
			_toSign(75),
			_toExecute(75)
{
	std::cout << "Default Form Constructor called\n";
}

Form::~Form()
{
	std::cout << "Default Form Destructor called\n";
}

Form::Form(std::string name, int toSign, int toExecute) : _name(name),  _signed(false), _toSign(toSign), _toExecute(toExecute)
{
	if (getMinValueToSign() < 1 || getMinValueToExec() < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (getMinValueToSign() > 150 || getMinValueToExec() > 150)
	{
		throw Form::GradeTooLowException();
	}
	std::cout << "Form Constructor called\n";
}

Form::Form(const Form &copy) : _name(copy._name), _signed(false), _toSign(copy._toSign), _toExecute(copy._toExecute)
{
	std::cout << "Copy Form constructor called\n";
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other.getSignature();
	return (*this);
}

const std::string &Form::getFormName() const
{
	return (_name);
}

int Form::getMinValueToExec() const
{
	return (_toExecute);
}

int Form::getMinValueToSign() const
{
	return (_toSign);
}

bool Form::getSignature() const
{
	return (_signed);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (getMinValueToSign() < b.getGrade())
		throw Form::GradeTooLowException();	
	if (getSignature())
		throw Form::AlreadySignedException();
	_signed = true;	
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("Form is already signed!");
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	if (f.getSignature())
		out << f.getFormName() << " is signed, has a grade of " << f.getMinValueToSign() << " to be signed and a grade of " << f.getMinValueToExec() << " to be executed\n";
	else
		out << f.getFormName() << " is not signed, has a grade of " << f.getMinValueToSign() << " to be signed and a grade of " << f.getMinValueToExec() << " to be executed\n";
	return (out);
}