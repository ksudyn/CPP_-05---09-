/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:43:05 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/10 21:09:05 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name(""), _grade(150)
{
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	std::cout << "Bureaucrat " << (std::string)this->_name
                << " Constructor called" << std::endl;
	try
    {
        if (grade > 150)
            throw GradeTooLowException();
        if (grade < 1)
            throw GradeTooHighException();
        _grade = grade;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& before ) : _name(before._name)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = before;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& before)
{
	if(this != &before)
	{
		std::cout << "Copy Assigment operator called" << std::endl;
		const_cast <std::string&> (this->_name) = before.getName();
		this->_grade = before.getGrade();
	}
	return (*this);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
	this->_grade++;
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}

void Bureaucrat::signAForm(AForm &form) const
{
    try
	{
        form.beSigned(*this);
     	if (!form.getIsSigned())
			throw AForm::GradeTooLowException();
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
	{
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
	catch (std::exception &e)
	{
        std::cout << _name << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
