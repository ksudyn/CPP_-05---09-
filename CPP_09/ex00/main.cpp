/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:48:29 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/28 18:50:47 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	if (BitcoinExchange(argv) == 1)
		return (1);
	return (0);
}

//Gafas raiban, cascos, llaves de casa, monedero con(dni, carnet de conducir, dos trajetas de credito actualmente bloqueadas, abono transporte, tarjeta de farmacia y 40 euros)