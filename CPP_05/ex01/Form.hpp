/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:28:45 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/10 17:13:58 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
        Form();
        Form( std::string name, int gradeToSign, int gradeToExecute );
        ~Form();
        Form( const Form& before );
        Form& operator=( const Form& before );
		
        class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
                {
                    return ("Form grade is too high");
                }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
                {
                    return ("Form grade is too low");
                }
		};
		
		void				beSigned( Bureaucrat bureaucrat );
		std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

};

std::ostream&	operator<<( std::ostream &out, Form const &classToPrint );

#endif

// Este ejercicio introduce una nueva clase llamada Form,
// que representa un formulario que un Bureaucrat puede firmar si tiene el rango suficiente.

// Vas a mantener la clase Bureaucrat (la usas sin modificar lo que ya funciona).
// Vas a crear una nueva clase Form con su propia lógica y excepciones.
// Luego vas a añadir un método nuevo en Bureaucrat
// que le permita intentar firmar un Form.

// beSigned(const Bureaucrat &b)
// Este método intenta firmar el formulario:

// Si el grade del Bureaucrat es menor o igual al requerido el formulario se firma.

// Si no lanza una Form::GradeTooLowException