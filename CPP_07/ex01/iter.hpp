/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:38:58 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/15 20:30:43 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, const int length, void (*f)(T&))
{

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