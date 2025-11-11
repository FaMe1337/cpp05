/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:04:48 by marvin            #+#    #+#             */
/*   Updated: 2025/11/11 19:04:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("default")
{
	std::cout << "Default ShrubberyCreationForm Constructor called\n";
}



ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor called\n";
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy ShrubberyCreationForm constructor called\n";
}



ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)	if (this != &other)
	{
		AForm::operator=(other);
		_target = other.getTarget();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default ShrubberyCreationForm Destructor called\n";
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}



void ShrubberyCreationForm::executeAction() const
{
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream myfile(filename.c_str());
	if (myfile.is_open())
	{

		myfile << "                                                         .\n";
		myfile << "                                              .         ;  \n";
		myfile << "                 .              .              ;%     ;;   \n";
		myfile << "                   ,           ,                :;%  %;   \n";
		myfile << "                    :         ;                   :;%;'     .,   \n";
		myfile << "           ,.        %;     %;            ;        %;'    ,;\n";
		myfile << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
		myfile << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
		myfile << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
		myfile << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
		myfile << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
		myfile << "                    `:%;.  :;bd%;          %;@%;'\n";
		myfile << "                      `@%:.  :;%.         ;@@%;'   \n";
		myfile << "                        `@%.  `;@%.      ;@@%;         \n";
		myfile << "                          `@%%. `@%%    ;@@%;        \n";
		myfile << "                            ;@%. :@%%  %@@%;       \n";
		myfile << "                              %@bd%%%bd%%:;     \n";
		myfile << "                                #@%%%%%:;;\n";
		myfile << "                                %@@%%%::;\n";
		myfile << "                                %@@@%(o);  . '         \n";
		myfile << "                                %@@@o%;:(.,'         \n";
		myfile << "                            `.. %@@@o%::;         \n";
		myfile << "                               `)@@@o%::;         \n";
		myfile << "                               .%@@@@%::;         \n";
		myfile << "                               ;%@@@@%::;.          \n";
		myfile << "                              ;%@@@@%%:;;;. \n";
		myfile << "                          ...;%@@@@@%%:;;;;,..    \n";

		myfile.close();
	}
}
