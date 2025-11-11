/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:59:04 by marvin            #+#    #+#             */
/*   Updated: 2025/11/07 16:59:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():_name("default"),
			_signed(false),
			_toSign(75),
			_toExecute(75)
{
	std::cout << "Default AForm Constructor called\n";
}

AForm::~AForm()
{
	std::cout << "Default AForm Destructor called\n";
}

AForm::AForm(std::string name, int toSign, int toExecute) : _name(name),  _signed(false), _toSign(toSign), _toExecute(toExecute)
{
	if (getMinValueToSign() < 1 || getMinValueToExec() < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (getMinValueToSign() > 150 || getMinValueToExec() > 150)
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << "AForm Constructor called\n";
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(false), _toSign(copy._toSign), _toExecute(copy._toExecute)
{
	std::cout << "Copy AForm constructor called\n";
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other.getSignature();
	return (*this);
}

const std::string &AForm::getFormName() const
{
	return (_name);
}

int AForm::getMinValueToExec() const
{
	return (_toExecute);
}

int AForm::getMinValueToSign() const
{
	return (_toSign);
}

bool AForm::getSignature() const
{
	return (_signed);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (getMinValueToSign() < b.getGrade())
		throw AForm::GradeTooLowException();	
	if (getSignature())
		throw AForm::AlreadySignedException();
	_signed = true;	
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
		throw AForm::NotSignedException();
	if (executor.getGrade() > _toExecute)
		throw AForm::GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return ("Form is already signed!");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	if (f.getSignature())
		out << f.getFormName() << " is signed, has a grade of " << f.getMinValueToSign() << " to be signed and a grade of " << f.getMinValueToExec() << " to be executed";
	else
		out << f.getFormName() << " is not signed, has a grade of " << f.getMinValueToSign() << " to be signed and a grade of " << f.getMinValueToExec() << " to be executed";
	return (out);
}
