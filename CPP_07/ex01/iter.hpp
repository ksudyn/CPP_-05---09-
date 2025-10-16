/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:38:58 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/16 14:01:19 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* array, const int length, F func)
{
    for(size_t i = 0; i < length; ++i)
        func(array[i]);
}


#endif

// Te pide implementar una función template llamada iter que:
// Recibe un array (primer parámetro).
// Recibe la longitud del array (segundo parámetro, como const).
// Recibe una función (tercer parámetro)
// que será aplicada a cada elemento del array.
// La función iter no devuelve nada (void).
// La idea es recorrer el array
// y aplicar la función pasada a cada elemento, sea cual sea su tipo.


// En C++ se puede pasar una función como parámetro usando punteros a función.
// La función puede tomar su argumento por referencia
// o por const referencia, dependiendo si quieres modificarlo o solo leerlo.
// Ejemplo de función que se puede pasar a iter:
// void printInt(const int &n)
//{
//     std::cout << n << std::endl;
//}
// void increment(int &n)
//{
//     n++;
// }