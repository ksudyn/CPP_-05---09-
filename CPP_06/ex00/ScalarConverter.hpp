/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:51:04 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/14 19:59:37 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <climits>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter& operator=( const ScalarConverter& before );
		ScalarConverter( const ScalarConverter& before );
	public:
		static void convert(std::string const &str);

};

#endif

// Este ejercicio trata de conversión de tipos (casts) en C++.
// Debes crear una clase llamada ScalarConverter que pueda tomar un literal
// (una cadena con un valor tipo char, int, float o double)
// y mostrar su valor convertido a los otros tipos escalares básicos de C++.

// En otras palabras, si le pasas "42.0f",
// el programa debe reconocer que es un float,
// convertirlo a los demás tipos (char, int, double) y mostrar los resultados

// La clase debe detectar el tipo del literal que recibe como std::string.

// 'a' → tipo char
// "42" → tipo int
// "4.2f" → tipo float
// "4.2" → tipo double
// "nan", "nanf", "+inf", "-inff" → valores especiales (NaN, infinito)


// Este ejercicio te hace practicar principalmente tres conceptos:

// 1. Casts (conversiones entre tipos en C++)

// Conversión explícita con static_cast, dynamic_cast,
// reinterpret_cast, const_cast.

// Aquí usarás static_cast casi siempre:

// float f = static_cast<float>(i);
// int i = static_cast<int>(d);
// char c = static_cast<char>(i);

// También entenderás cómo las conversiones pueden perder precisión
// o no tener sentido (por ejemplo, nan a int).



// 2. Detección del tipo del literal (parsing de strings)

// Tendrás que analizar la cadena (std::string) para determinar su tipo:
// Si tiene una 'f' al final -> float
// Si tiene un punto . pero no 'f' -> double
// Si está entre comillas ' ' -> char
// Si no tiene punto -> int
// Si es "nan", "inf", "nanf", "inff" -> valores especiales


// 3. Manejo de conversiones y límites numéricos

// Necesitarás <limits> para saber los valores máximos/mínimos:

// #include <limits>
// std::numeric_limits<int>::max();
// std::numeric_limits<float>::infinity();


// También para decidir si algo es “imposible” o fuera de rango.