/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:48:56 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/27 16:57:30 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <string>
#include <iostream>

// -----------------------------------------------------------
// Función: load_args
// Propósito: validar una fecha en formato "YYYY-MM-DD"
//            y devolverla como número entero (YYYYMMDD)
// Retorna: int (fecha como entero) o -1 si hay error
// -----------------------------------------------------------
int	load_args(const std::string &date)
{
	int	fullDate = 0;      // Fecha completa como entero (YYYYMMDD)
	int	index = 0;         // Índice para recorrer la cadena
	int	isLeapYear = 0;    // 1 si el año es bisiesto
	int	month = 0;         // Almacena el mes
	int	day = 0;           // Almacena el día

	// -------------- 1. Leer y validar el año (YYYY) --------------
	while (date[index] && index < 4)
	{
		if (date[index] < '0' || date[index] > '9')
			return (-1); // error: no es un número
		fullDate = fullDate * 10 + (date[index] - '0');
		index++;
	}

	// Debe haber exactamente 4 dígitos y luego un guion
	if (index != 4 || fullDate <= 0 || date[index] != '-')
		return (-1);

	// -------------- 2. Comprobar si el año es bisiesto --------------
	if ((fullDate % 4 == 0 && fullDate % 100 != 0) || (fullDate % 400 == 0))
		isLeapYear = 1;

	index++; // saltar el guion '-'

	// -------------- 3. Leer y validar el mes (MM) --------------
	while (date[index] && index < 7)
	{
		if (date[index] < '0' || date[index] > '9')
			return (-1); // error: no es número
		fullDate = fullDate * 10 + (date[index] - '0');
		month = month * 10 + (date[index] - '0');
		index++;
	}

	// Debe haber leído dos dígitos para el mes y luego otro guion
	if (index != 7 || date[index] != '-' || month <= 0 || month > 12)
		return (-1);

	index++; // saltar guion '-'

	// -------------- 4. Leer y validar el día (DD) --------------
	while (date[index] && index < 10)
	{
		if (date[index] < '0' || date[index] > '9')
			return (-1); // error: no es número
		fullDate = fullDate * 10 + (date[index] - '0');
		day = day * 10 + (date[index] - '0');
		index++;
	}

	// -------------- 5. Validaciones finales --------------
	if (date[index]) // no debe haber más caracteres
		return (-1);

	// Debe tener exactamente 10 caracteres (YYYY-MM-DD)
	if (index != 10)
		return (-1);

	// Validar día según mes
	if (day <= 0 || day > 31)
		return (-1);

	// Meses pares no pueden tener 31 días (simplificación)
	if (month % 2 == 0 && day == 31)
		return (-1);

	// Febrero (mes 2) no puede tener más de 29 días
	if (month == 2)
	{
		if (day >= 30)
			return (-1);
		if (isLeapYear == 0 && day == 29)
			return (-1);
	}

	// -------------- 6. Todo correcto: devolver la fecha como número --------------
	return (fullDate);
}
