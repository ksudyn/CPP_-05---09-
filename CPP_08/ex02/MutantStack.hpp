/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:41:03 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/22 20:43:25 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iterator>
#include <stack>
// El ejercicio trata de crear tu propia versión del contenedor std::stack,
// llamada MutantStack,
// que tenga todo lo que tiene una pila normal
// (push, pop, top, size, etc.),
// pero con una nueva característica:

// Que sea iterable
// (o sea, que puedas recorrer sus elementos con un iterador como en un vector o list)


template <class T>
class MutantStack : public std::stack<T>
{
    // Si heredas de std::stack, puedes acceder a this->c.
    // Eso te permite obtener iteradores del contenedor interno.
    private:

    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);

        iterator begin();
        iterator end();
	
        const_iterator begin() const;
        const_iterator end() const;
        
};

#include "Makefile"

#endif