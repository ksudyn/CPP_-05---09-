/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:28:02 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/10 20:44:58 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private:
        const std::string	_name;
		int					_grade;
    public:
        Bureaucrat( void );
        Bureaucrat( std::string name, int grade );
        ~Bureaucrat();
        Bureaucrat( const Bureaucrat& before );
        Bureaucrat&	operator=( const Bureaucrat& before);
    
        class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
                {
                    return "Bureaucrat grade is too high!";
                }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
                {
                    return "Bureaucrat grade is too low!";
                }
		};

        void    incrementGrade(); // sube el rango → resta 1 al grade
        void    decrementGrade(); // baja el rango → suma 1 al grade
        int			getGrade() const;
		const std::string	getName() const;
        void    signAForm( AForm &form ) const;
        void    executeForm(AForm const &form) const;

};

std::ostream&	operator<<( std::ostream &out, Bureaucrat const &classToPrint );

#endif

// AForm abstracta con execute() virtual pura.

// Tres clases hijas (ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm).

// Cada una implementa su propia versión de execute() correctamente.

// Usas las excepciones (GradeTooLow, FormNotSigned, etc.).

// Comprobaciones de condiciones de ejecución (isSigned, gradeToExecute)