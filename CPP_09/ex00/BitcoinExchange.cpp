/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:48:56 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/30 17:54:17 by ksudyn           ###   ########.fr       */
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
	// Aplica las reglas del calendario gregoriano
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


float getClosestPrice(const std::map<std::string, float> &database_csv, const std::string &date)
{
    // Validar formato de fecha con tu función load_args()
    if (load_args(date) == -1)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return -1.0f;
    }

    // Buscar la fecha exacta
    std::map<std::string, float>::const_iterator it;
	it = database_csv.find(date);
    if (it != database_csv.end())
        return it->second; // Fecha exacta encontrada

    // Buscar la fecha anterior más cercana
    it = database_csv.lower_bound(date);

    // Si lower_bound devuelve begin(), no hay fecha anterior
    if (it == database_csv.begin())
    {
        std::cerr << "Error: no previous date available for " << date << std::endl;
        return -1.0f;
    }

    // Retrocedemos un elemento para obtener la fecha inmediatamente anterior
    --it;

    return it->second; // Devolver el valor del día anterior más cercano
}

// Un std::map es un contenedor que:
// Guarda pares (clave, valor) → aquí (fecha, precio).
// Está ordenado automáticamente por la clave (std::string).
// No puede tener claves duplicadas


// std::map<tipoClave, tipoValor>
// Por ejemplo:

// Ejemplo	Qué hace
// std::map<int, std::string>		Mapa que asocia un número con una palabra (ej. 1 → "Lunes")
// std::map<std::string, float>		Mapa que asocia un texto (como una fecha) con un número (precio)
// std::map<char, int>				Mapa que asocia letras con valores numéricos

// Asi find busca dentro de database el date mientras avanza
// Si no llega a end que es el final devuelve esa fecha
// Si llega hasta end entonces usa lower_bound
// para retrocede hasta encontrar la primera fecha anterior mas cercana
// Si llega a begin que es el principio significa que no hay fecha anterior cercana valida
// Si no devolvemos esa fecha


int	BitcoinExchange(char **argv)
{
	//Se abre argv[1] en modo lectura y se asocia a file_txt usando ifstream
	std::ifstream file_txt(argv[1]);
	if (!file_txt.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	//Se abre data.csv en modo lectura y se asocia a data_csv usando ifstream
	std::ifstream data_csv("data.csv");
	if (!data_csv.is_open())
	{
		std::cerr << "Error: could not open data.csv file." << std::endl;
		return (1);
	}

	// Un std::map es un contenedor que:
	// Guarda pares (clave, valor) → aquí (fecha, precio).
	// Está ordenado automáticamente por la clave (std::string).
	// No puede tener claves duplicadas
	std::map<std::string, float> database_csv;
	std::string line;


	//std::getline() lee una línea completa del archivo, hasta que encuentra un salto de línea (\n)
	
	std::getline(data_csv, line);
	while (std::getline(data_csv, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string valueStr;
		if (!std::getline(ss, date, ','))
			continue;
		if (!std::getline(ss, valueStr))
			continue;
		// std::stringstream ss(line);
		// Crea un "flujo de texto" interno para poder leer partes separadas de line fácilmente.
		// Si line = "2011-01-03,0.3", entonces con std::stringstream ss(line) puedes leer:
		// std::getline(ss, date, ','); // lee hasta la coma -> "2011-01-03"
		// std::getline(ss, valueStr);  // lee el resto -> "0.3"
		
		database_csv[date] = static_cast<float>(atof(valueStr.c_str()));
	}
	data_csv.close();

	// Procesar archivo de entrada del usuario (input.txt)
	std::getline(file_txt, line);
	while (std::getline(file_txt, line))
	{
		if (line.empty())///sila línea esta vacía se la salta
			continue;

		std::stringstream ss(line);
		//Crea un objeto de flujo de texto (stringstream)
		//que permite leer partes de la cadena igual que si fuera un archivo
		std::string date;
		std::string valueStr;

		if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
		{
			// std::getline(ss, date, '|')
			// Lee desde el inicio de ss hasta encontrar el carácter '|',
			// y guarda esa parte en date

			// std::getline(ss, valueStr)
			// Vuelve a leer del mismo ss, pero esta vez sin delimitador (por defecto usa el fin de línea).
			// Así que toma el resto de la cadena después del '|'
			
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		// empty comprueba si la cadena esta vacía
		// erase elimina caracteres y funciona asi
		// rase(0, 1) significa:
		// “Borra desde la posición 0 (el primer carácter), 1 carácter
		// size saca el tamaño total
		while (!date.empty() && (date[0] == ' ' || date[0] == '\t'))
			date.erase(0, 1);
		while (!date.empty() && (date[date.size() - 1] == ' ' || date[date.size() - 1] == '\t'))
			date.erase(date.size() - 1, 1);
		while (!valueStr.empty() && (valueStr[0] == ' ' || valueStr[0] == '\t'))
			valueStr.erase(0, 1);
		//Basicamente si en la cadena hay algo y al principio o al final hay espacios o tabulaciones se eliminan

		float value_txt = static_cast<float>(atof(valueStr.c_str()));
		// valueStr.c_str() convierte el std::string a un const char *,
		// para poder usar funciones C como atof.
		// atof() convierte esa cadena de caracteres ("3.5") en número real (3.5).
		// static_cast<float>() asegura que el resultado sea tipo float.
		

		if (value_txt < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value_txt > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		// Obtener el precio
		float rate = getClosestPrice(database_csv, date);
		if (rate < 0)
			continue;

		std::cout << date << " => " << value_txt << " = " << value_txt * rate << std::endl;
	}

	file_txt.close();
	return (0);
}