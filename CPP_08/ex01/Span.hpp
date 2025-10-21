/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:03:02 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/21 20:49:39 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <climits>

class Span
{
    private:
        std::vector<int> _numbers;//donde se guardan los números
        unsigned int _N;//capacidad máxima.
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int nb);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            size_t count = std::distance(begin, end);
            //std::distance(begin, end) devuelve cuántos pasos hay entre ambos iteradores
            if (_numbers.size() + count > _N)
                throw MaxCapacityReached();
            //Suma los elementos actuales + los nuevos que quieres añadir.
            //Si eso supera _N, lanza una excepción
            _numbers.insert(_numbers.end(), begin, end);
            //std::vector::insert() copia todos los valores del rango [begin, end)
            //al final de _numbers
        }
        
        class MaxCapacityReached : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Error: Cannot add more numbers.";
                }
        };
        class NoSpanFound : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Error: At least two numbers are required.";
                }
        };

};

#endif
