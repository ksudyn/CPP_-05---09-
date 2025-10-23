/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:41:03 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/23 15:10:05 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iterator>
#include <stack>
#include <iostream>

// El ejercicio trata de crear tu propia versión del contenedor std::stack,
// llamada MutantStack,
// que tenga todo lo que tiene una pila normal
// (push, pop, top, size, etc.),
// pero con una nueva característica:

// Que sea iterable
// (o sea, que puedas recorrer sus elementos con un iterador como en un vector o list)


template <typename T>
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


        // - Typedef sirve para ponerle un "apodo" a lo que vamos a poner a continuacion
        // - typename sirve para decir que lo que vamos a pasar es un typo de algo
        // - std::stack<T> lo onemos para dcir que vamos a sacar algo de la clase stack
        // y que puede ser cualquier typo de cosa <T>
        // - Dentro de esa clase vamos a usar esto "container_type::iterator"
        // y lo vamos a llamar iterator, pero lo podiramos llamar como queramos
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;


        iterator begin();
        iterator end();
	
        const_iterator begin() const;
        const_iterator end() const;

        reverse_iterator rbegin();
        reverse_iterator rend();

        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
        
};

#include "MutantStack.tpp"

#endif