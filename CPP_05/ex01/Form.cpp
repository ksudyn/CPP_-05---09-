/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:28:55 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/24 17:30:51 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _gradeToSign(150), _gradeToExecute(150)
{
    this->_isSigned = 0;
    std::cout << "Default Form Constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
    throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
    throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Default Form Destructor called" << std::endl;
}

Form::Form( const Form& before ) : _name(before._name),  _isSigned(before._isSigned), _gradeToSign(before._gradeToSign),  _gradeToExecute(before._gradeToExecute)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = before;
}

Form &Form::operator=(const Form &before)
{
    if (this != &before)
    {
        _isSigned = before.getIsSigned();
    }
    return *this;
}


std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &t)
{
    os << "Form: " << t.getName()
       << " | Signed: " << (t.getIsSigned() ? "yes" : "no")
       << " | Grade to sign: " << t.getGradeToSign()
       << " | Grade to execute: " << t.getGradeToExecute();
    return os;
}

