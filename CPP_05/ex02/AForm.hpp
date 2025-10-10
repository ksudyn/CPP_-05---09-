/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:04:19 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/10 20:51:51 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	protected:
		std::string _target;

	public:
        AForm();
        AForm( std::string name, int gradeToSign, int gradeToExecute );
        ~AForm();
        AForm( const AForm& before );
        AForm& operator=( const AForm& before );
		
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

		class FormNotSignedException : public std::exception
    	{
    		public:
        		const char *what() const throw()
				{
					return("The Form Dont Signed ");
				}
    	};
		
		void				beSigned( const Bureaucrat& bureaucrat );
		std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		std::string getTarget() const;
		virtual void execute(Bureaucrat const &executor) const = 0;

};

std::ostream&	operator<<( std::ostream &out, AForm const &classToPrint );

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