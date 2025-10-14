/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:28:02 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/14 15:31:35 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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
                    return "Grade is too high!";
                }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
                {
                    return "Grade is too low!";
                }
		};

        void incrementGrade(); // sube el rango → resta 1 al grade
        void decrementGrade(); // baja el rango → suma 1 al grade
        int			getGrade() const;
		const std::string	getName() const;

};

std::ostream&	operator<<( std::ostream &out, Bureaucrat const &classToPrint );

#endif

// Clases, encapsulamiento y atributos constantes

// Tienes una clase con atributos privados (name, grade) y métodos públicos.
// const std::string name significa que una vez inicializado, no puede cambiarse.
// Por eso se debe inicializar en la lista de inicialización del constructor:

// Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)

// - Clases anidadas (nested classes)

// Estas son tus excepciones dentro de Bureaucrat:

// class GradeTooHighException : public std::exception { ... };
// class GradeTooLowException : public std::exception { ... };

// Esto encapsula las excepciones dentro de la clase que las usa.
// En otras palabras: esas excepciones solo tienen sentido dentro del contexto de Bureaucrat,
// así que están “guardadas” dentro de ella.


// - Sobrecarga de operadores

// Definiste: std::ostream& operator<<(std::ostream &out, Bureaucrat const &b)

// Esto te enseña a hacer que tus clases se integren bien con la sintaxis de C++:

// std::cout << b;
// funciona igual que con tipos nativos (int, std::string, etc.).


// - Qué es throw

// throw sirve para lanzar una excepción cuando ocurre un error o algo inesperado.

// Por ejemplo:

// if (grade < 1)
//     throw Bureaucrat::GradeTooHighException();

// Esto detiene la ejecución normal y
// “salta” al bloque catch más cercano que pueda manejar el error.


// - Qué hace std::exception

// Es una clase base de la biblioteca estándar que permite definir errores personalizados.
// Solo necesitas sobrescribir la función:

// const char* what() const throw();


// que devuelve un mensaje de error (tipo texto).

// Por eso tus clases anidadas heredan de ella:

// class GradeTooHighException : public std::exception