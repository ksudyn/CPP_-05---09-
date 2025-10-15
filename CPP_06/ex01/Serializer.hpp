/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:22:40 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/15 16:14:41 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &other);
		~Serializer(void);

		Serializer &operator=(Serializer const &other);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
//Es un ejercicio para entender cómo funcionan las direcciones de memoria
//y cómo puedes "guardar" o "transformar" punteros sin perder su valor real.


// uintptr_t
// Es un tipo entero especial definido en <cstdint>.
// Está diseñado para almacenar una dirección de memoria sin perder información.
// Es un entero sin signo (unsigned integer).
// Su tamaño depende de la arquitectura (por ejemplo, 8 bytes en sistemas de 64 bits).
// Permite convertir un puntero a entero y viceversa sin modificar su valor.