/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:50:59 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/14 20:00:02 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert <literal>\n";
        return 1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}

/*
----------- PRUEBAS -----------

./convert 0 (cero ND)
./convert 42 (entero normal imprime *)
./convert 2147483647 (max int)
./convert 2147483648 (max int + 1 overflow en int)
./convert -2147483648 (min int)
./convert -2147483649 (min int - 1 overflow en int)
./convert " "
./convert 4.2f (float normal)
./convert .5f (float con punto delante)
./convert 5.f (float con punto detrás)
./convert 0.0000001f

./convert +.0
./convert ++1
./convert 1..0
./convert +
*/