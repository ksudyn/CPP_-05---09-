/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:39:56 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/16 16:49:39 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

//Hasta ahora usaste template<typename T> en funciones.
//Ahora será en una clase
template <typename T>
class Array
{
    private: 
        T *_arr;
        unsigned int _size;

    public:
        Array();                      // constructor vacío
        Array(unsigned int n);        // constructor con tamaño
        ~Array();                     // destructor
        Array(const Array& other);    // constructor por copia
        Array& operator=(const Array& other); // operador de asignación


        T& operator[](unsigned int index);             // acceso
        const T& operator[](unsigned int index) const; // acceso const

        unsigned int size() const;    // devuelve cantidad de elementos


        class NonAllocatedMemory : public std::exception {
            public:
                const char *what() const throw()
                {
                    return ("Index is out of bounds:\nIf i was not here to catch you, you would have Undefined Behavior, scaryyyy");
                }
        };
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);


#include "Array.tpp"

#endif
