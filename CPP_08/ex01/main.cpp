/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:03:09 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/22 18:27:56 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Span sp(5);  // capacidad máxima = 5

        // Creamos un vector con algunos números
        std::vector<int> valores;
        valores.push_back(6);
        valores.push_back(3);
        valores.push_back(17);
        valores.push_back(9);
        valores.push_back(11);

        // En lugar de añadir uno por uno:
        // sp.addNumber(6); sp.addNumber(3); ...
        // Podemos añadir todos de una vez:
        sp.addRange(valores.begin(), valores.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
