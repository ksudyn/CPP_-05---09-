/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:37:16 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/31 20:37:24 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Basicamente tengo que dividir el stack por parejas de 2
// Si hay una cantidad impar en el stack el úlltimos se queda solo
// En las parejas coloco el valor mas bajo a la izquierda y el mas alto a la derecha
// Luego los de la derecha los meto en un nuevo stack orednados de menor a mayor
// Y voy introduciendolos los valores mas bajos en su respectivo lugar

//Para ordenar los largos se llama de forma recursiva a la misma funcion
// Así, aunque al principio no estén ordenados, la recursión los dejará ordenados por completo.
// Esa es la parte “merge” del merge-insertion sort

// Para ordenar los cortos en sus posicion correspondiente se hace mnuelamente o
// usando std::lower_bound que devuelve el iterador al primer elemento mayor al valor dado.
