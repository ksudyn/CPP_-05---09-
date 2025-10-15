/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:37:34 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/15 20:12:52 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}
// T &x, T &y -> pasamos referencias para que la función modifique las variables originales.
// T temp -> se crea una variable temporal del mismo tipo para hacer el intercambio.
// Esta misma función funciona para int, double, std::string, etc

template <typename T>
T min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

// Estas funciones funcionan con cualquier tipo que soporte los operadores < y >.
// Retornan el valor menor o mayor respectivamente.
// El enunciado dice que si son iguales, deben devolver el segundo parámetro:

#endif

// Un template (plantilla) en C++
// es una forma de escribir funciones o clases de manera genérica,
// sin especificar el tipo exacto que van a manejar.

// En lugar de escribir la misma función para int, float y std::string,
// puedes escribir una sola versión que funcione para todos los tipos.


// Tipos de templates:
// Templates de función -> para funciones.
// Templates de clase -> para clases.

// template <typename T> -> le dice al compilador que T es un tipo genérico.

// T a, T b -> los parámetros son del tipo T.

// T puede ser cualquier tipo: int, float, std::string,
// o incluso tus propias clases, siempre que soporten las operaciones que uses


// Por qué los templates se definen en cabeceras (.hpp)
// El compilador necesita ver la definición completa de la template cuando la usa.
// No se pueden poner solo en un .cpp y luego linkearlo, porque C++ no genera código hasta que se usa la template con un tipo concreto.
// Por eso siempre se ponen en .hpp:

// Todos los parámetros deben ser del mismo tipo (a menos que uses varias templates).
// El tipo debe soportar las operaciones que usas (asignación, comparación, suma, etc.).
// Definir templates en .hpp o en el mismo archivo donde se usan