/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:07:09 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/10 21:08:31 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery_Form", 145, 137)
{
	_target = "nadie";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery_Form", 145, 137)
{
	_target = target;
} 

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other) 
	{
		this->_target = other.getTarget();
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    // Primero comprobamos si se puede ejecutar (heredado de AForm)
    if (!getIsSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    // Abrimos archivo para escribir el dibujo
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs)
        throw std::runtime_error("Error: could not open file");

    print_tree(ofs);

    ofs.close();
    std::cout << "Shrubbery created at " << _target + "_shrubbery" << std::endl;
}

void ShrubberyCreationForm::print_tree(std::ofstream &ofs) const
{
    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~" << std::endl;
    ofs << "_- -   | | _- _" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "      // \\\\" << std::endl;
}
