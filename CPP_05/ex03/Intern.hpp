/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:54:33 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/13 17:15:26 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
    private:

    public:
	    Intern();
    	~Intern();
    	Intern(Intern const &other);
    	Intern &operator=(Intern const &other);

    	AForm *makeForm(const std::string &name, const std::string &target);

    	class FormNotFound : public std::exception
	    {
    	public:
            const char* what() const throw()
            {
                return "Form dont Found";
            }
	    };
};

#endif

// Tu clase Intern es una “fábrica” de formularios (Factory pattern).
// El objetivo es que, dependiendo del nombre (name),
// el becario (Intern) construya y devuelva un nuevo objeto del tipo correcto, heredado de AForm