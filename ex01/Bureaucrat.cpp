/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:35:54 by marvin            #+#    #+#             */
/*   Updated: 2025/11/07 13:35:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(75)
{
	std::cout << "Default Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called\n";
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Copy Bureaucrat constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat destructor for " << getName() << " called\n";
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::setIncreaseGrade()
{
	if (getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::setDecreaseGrade()
{
	if (getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getFormName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't sign " << form.getFormName()
				  << " because " << e.what() << std::endl;
	}
}