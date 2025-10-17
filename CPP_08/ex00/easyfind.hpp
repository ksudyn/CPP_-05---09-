/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:11:09 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/17 20:48:50 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>// para std::find
#include <exception>// para lanzar excepciones

class ValueError : public std::exception
{
	public:
		const char *what() const throw()
        {
			return ("Value not found in container.");
	    }
};


// T es un contenedor de int (no de strings, no de pares, etc.).
// std::vector<int>, std::list<int>
// El primer parámetro es ese contenedor.
// El segundo parámetro es el valor entero que se busca
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
	if(it == container.end())
		throw (ValueError());
	return it;
}
// typename T::iterator -> define el tipo de retorno.
// Cada contenedor (std::vector, std::list, etc.)
// tiene su propio tipo iterator.
// Como T es genérico se usa typename para
// indicarle al compilador que T::iterator es un tipo
// (no una variable o función).
// T& container -> el contenedor donde buscará.
// int value -> el número que queremos encontrar

//std::find es un algoritmo, busca un valor en un rango [begin, end]


// La función busca un número (int value) dentro de un contenedor
// (como un std::vector<int> o un std::list<int>),
// usando una plantilla (template)
// para que funcione con cualquier tipo de contenedor,
// sin importar cuál

#endif