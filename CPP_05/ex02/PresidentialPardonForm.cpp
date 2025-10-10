/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:05:44 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/10 20:20:51 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Empty_Presidential", 25, 5)
{
	this->_target = "nadie";
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) 
{
    if (this != &other) 
	{
		_target = other.getTarget();
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
try
	{
		if (!this->getIsSigned())//Si el formulario no está firmado → excepción.
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > this->getGradeToExecute())//Si el burócrata tiene un grado demasiado bajo → excepción
			throw AForm::GradeTooLowException();
		std::cout << _target << " HAS BEEN PARDONED BY ALL MIGHTY ZAPHOD BEEBLEBROX ✅" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}