/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:54:33 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/10 18:55:56 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

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