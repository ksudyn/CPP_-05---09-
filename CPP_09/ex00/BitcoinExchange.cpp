/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:48:56 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/31 15:47:35 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/*                                                                            */
/*   load_args                                                                */
/*                                                                            */
/*   Descripción:                                                             */
/*   ------------------------------------------------------------------------ */
/*   Esta función recibe una fecha como string en formato "YYYY-MM-DD"        */
/*   y comprueba si es válida.                                                */
/*                                                                            */
/*   - Comprueba que cada parte (año, mes y día) sea numérica.                */
/*   - Valida que la fecha tenga el formato correcto (4-2-2 dígitos y guiones)*/
/*   - Detecta si el año es bisiesto para validar febrero correctamente.      */
/*   - Rechaza fechas imposibles como "2021-13-40" o "2011-02-29" no bisiesto.*/
/*                                                                            */
/*   Devuelve:                                                                */
/*     → Un número entero con la fecha compactada (YYYYMMDD) si es válida.    */
/*     → -1 si la fecha es incorrecta o tiene un formato inválido.            */
/*                                                                            */
/* ************************************************************************** */
int	load_args(const std::string &date)
{
	int	fullDate = 0;
	int	index = 0;
	int	isLeapYear = 0;
	int	month = 0;
	int	day = 0;

	while (date[index] && index < 4)
	{
		if (date[index] < '0' || date[index] > '9')
			return (-1);
		fullDate = fullDate * 10 + (date[index] - '0');
		index++;
	}

	if (index != 4 || fullDate <= 0 || date[index] != '-')
		return (-1);

	// Aplica las reglas del calendario gregoriano
	if ((fullDate % 4 == 0 && fullDate % 100 != 0) || (fullDate % 400 == 0))
		isLeapYear = 1;

	index++;
	while (date[index] && index < 7)
	{
		if (date[index] < '0' || date[index] > '9')
			return (-1);
		fullDate = fullDate * 10 + (date[index] - '0');
		month = month * 10 + (date[index] - '0');
		index++;
	}

	if (index != 7 || date[index] != '-' || month <= 0 || month > 12)
		return (-1);

	index++;
	while (date[index] && index < 10)
	{
		if (date[index] < '0' || date[index] > '9')
			return (-1);
		fullDate = fullDate * 10 + (date[index] - '0');
		day = day * 10 + (date[index] - '0');
		index++;
	}

	if (date[index])
		return (-1);
	if (index != 10)
		return (-1);
	if (day <= 0 || day > 31)
		return (-1);
	if (month % 2 == 0 && day == 31)
		return (-1);
	if (month == 2)
	{
		if (day >= 30)
			return (-1);
		if (isLeapYear == 0 && day == 29)
			return (-1);
	}
	return (fullDate);
}


/* ************************************************************************** */
/*                                                                            */
/*   getClosestPrice                                                          */
/*                                                                            */
/*   Descripción:                                                             */
/*   ------------------------------------------------------------------------ */
/*   Busca en una base de datos (std::map) el valor del bitcoin    			  */
/*   correspondiente a una fecha dada.                                        */
/*                                                                            */
/*   - Primero valida la fecha con load_args().                               */
/*   - Si existe una entrada exacta para esa fecha, devuelve su valor.        */
/*   - Si no existe, busca la fecha anterior más cercana usando               */
/*     std::map::lower_bound().                                               */
/*   - Si no hay ninguna fecha anterior válida, muestra un error.             */
/*                                                                            */
/*   Devuelve:                                                                */
/*     → El valor (float) del bitcoin correspondiente.                        */
/*     → -1.0f si hay un error o no hay fecha anterior válida.                */
/*                                                                            */
/* ************************************************************************** */
float getClosestPrice(const std::map<std::string, float> &database_csv, const std::string &date)
{
	if (load_args(date) == -1)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return -1.0f;
	}

	std::map<std::string, float>::const_iterator it;
	it = database_csv.find(date);
	if (it != database_csv.end())
		return it->second;

	it = database_csv.lower_bound(date);
	if (it == database_csv.begin())
	{
		std::cerr << "Error: no previous date available for " << date << std::endl;
		return -1.0f;
	}

	--it;
	return it->second;
}



/* ************************************************************************** */
/*                                                                            */
/*   BitcoinExchange                                                          */
/*                                                                            */
/*   Descripción:                                                             */
/*   ------------------------------------------------------------------------ */
/*   Es la función principal del programa.                                    */
/*                                                                            */
/*   - Abre el archivo pasado como argumento (input.txt).                     */
/*   - Abre también la base de datos (data.csv) con los precios históricos.   */
/*   - Carga data.csv en un std::map<string, float> ordenado por fecha.       */
/*   - Lee línea por línea el archivo de entrada.                             */
/*   - Valida el formato "fecha | valor".                                     */
/*   - Si el valor es válido (0 < valor ≤ 1000), busca el precio más cercano  */
/*     usando getClosestPrice().                                              */
/*   - Calcula el resultado (valor * precio) y lo muestra por pantalla.       */
/*   - En caso de errores, imprime mensajes claros y continúa con la siguiente*/
/*     línea sin interrumpir el programa.                                     */
/*                                                                            */
/*   Devuelve:                                                                */
/*     → 0 si todo fue correcto.                                              */
/*     → 1 si hubo errores de apertura de archivos.                           */
/*                                                                            */
/* ************************************************************************** */
int	BitcoinExchange(char **argv)
{
	std::ifstream file_txt(argv[1]);
	if (!file_txt.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	std::ifstream data_csv("data.csv");
	if (!data_csv.is_open())
	{
		std::cerr << "Error: could not open data.csv file." << std::endl;
		return (1);
	}

	std::map<std::string, float> database_csv;
	std::string line;

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
		database_csv[date] = static_cast<float>(atof(valueStr.c_str()));
	}
	data_csv.close();

	std::getline(file_txt, line);
	while (std::getline(file_txt, line))
	{
		if (line.empty())
			continue;

		std::stringstream ss(line);
		std::string date;
		std::string valueStr;

		if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		while (!date.empty() && (date[0] == ' ' || date[0] == '\t'))
			date.erase(0, 1);
		while (!date.empty() && (date[date.size() - 1] == ' ' || date[date.size() - 1] == '\t'))
			date.erase(date.size() - 1, 1);
		while (!valueStr.empty() && (valueStr[0] == ' ' || valueStr[0] == '\t'))
			valueStr.erase(0, 1);

		float value_txt = static_cast<float>(atof(valueStr.c_str()));

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

		float rate = getClosestPrice(database_csv, date);
		if (rate < 0)
			continue;

		std::cout << date << " => " << value_txt << " = " << value_txt * rate << std::endl;
	}

	file_txt.close();
	return (0);
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