/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:22:33 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/15 16:26:15 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
}

Serializer::Serializer(Serializer const &other)
{
	(void)other;
}

Serializer::~Serializer(void)
{

}

Serializer &Serializer::operator=(Serializer const &other)
{
	(void)other;
	return *this;
}


uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
//serialize() convierte una dirección de memoria (un puntero)
//a un entero sin signo (uintptr_t)

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
//deserialize() hace lo inverso:
//convierte ese entero de nuevo en el puntero original

// reinterpret_cast

// Es un cast de tipo reinterpretativo, no convierte datos, solo reinterpreta bits.

// Sirve para:

// - convertir un puntero a entero,
// - o un entero a puntero,
// - o entre tipos de punteros sin relación.

// En este ejercicio es la manera segura
// y correcta de hacer esa conversión en C++ moderno.

//No transforma el valor numérico en sentido aritmético:
//solo cambia la forma en que se interpretan los bits