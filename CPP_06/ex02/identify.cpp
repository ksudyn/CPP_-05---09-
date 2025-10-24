/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:34:24 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/24 20:35:53 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    //ponemos una flag para que no se reinicie la semilla
	static bool seeded = false;

	if (!seeded)
	{
		std::srand((std::time(NULL)));
		seeded = true;
	}
    // Usar static bool seeded = false;
    // para asegurarse de que srand(time(NULL)) solo se ejecute una vez 
    // (evita repetir el mismo número aleatorio si llamas varias veces a generate()
    // en el mismo segundo)


    int r = rand() % 3;
    //rand() % 3 devuelve un número entre 0 y 2.

    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}
// Crea dinámicamente un objeto A, B o C de forma aleatoria.
// Devuelve un puntero a Base


void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}
// Recibe un puntero a Base.
// Usa dynamic_cast para saber qué tipo tiene realmente.
// Imprime "A", "B" o "C"


void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch (std::bad_cast&)
    {
    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch (std::bad_cast&)
    {
    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch (std::bad_cast&)
    {
    }

    std::cout << "Unknown type\n";
}
// Recibe una referencia a Base (no puntero).
// Debe identificar el tipo real.
// No puedes usar punteros dentro (así que debes usar dynamic_cast con referencias)


// RTTI (Run-Time Type Information)
// Es el sistema que C++ usa para saber el tipo real de un objeto en ejecución.
// Las herramientas principales de RTTI son:
// typeid → (prohibido en este ejercicio)
// dynamic_cast ✅ (la que SÍ puedes usar)