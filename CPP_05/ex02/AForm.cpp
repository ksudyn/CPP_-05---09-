/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:04:07 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/24 18:03:50 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _gradeToSign(150),_gradeToExecute(150)
{
    this->_isSigned = 0;
    std::cout << "Default Form Constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "Default Form Destructor called" << std::endl;
}

AForm::AForm( const AForm& before ) : _name(before._name),  _isSigned(before._isSigned), _gradeToSign(before._gradeToSign),  _gradeToExecute(before._gradeToExecute)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = before;
}

AForm &AForm::operator=(const AForm &before)
{
    if (this != &before)
    {
        _isSigned = before.getIsSigned();
    }
    return *this;
}


std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &t)
{
    os << "Form: " << t.getName()
       << " | Signed: " << (t.getIsSigned() ? "yes" : "no")
       << " | Grade to sign: " << t.getGradeToSign()
       << " | Grade to execute: " << t.getGradeToExecute();
    return os;
}

std::string AForm::getTarget() const
{
    return _target;    
}
