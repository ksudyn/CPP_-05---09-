/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:37:16 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/04 20:44:04 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Hay que dividir el stack por parejas de 2
// Si hay una cantidad impar en el stack el úlltimos se queda solo
// En las parejas coloco el valor mas bajo a la izquierda y el mas alto a la derecha
// Luego los de la derecha los meto en un nuevo stack orednados de menor a mayor
// Y voy introduciendolos los valores mas bajos en su respectivo lugar

//Para ordenar los largos se llama de forma recursiva a la misma funcion
// Así, aunque al principio no estén ordenados, la recursión los dejará ordenados por completo.
// Esa es la parte “merge” del merge-insertion sort

// Para ordenar los cortos en sus posicion correspondiente se hace mnuelamente o
// usando std::lower_bound que devuelve el iterador al primer elemento mayor al valor dado.

void M_I_S_Vector(std::vector<int> &arg)
{
    if(arg.size() <= 1)
    {
        std::cerr << "Error: insufficient numbers" << std::endl;
    }

    std::vector<int> small;
    std::vector<int> big;
    bool has_single = false;
    int single;

    for (size_t i = 0; i < arg.size(); i += 2)
    {
        if (i + 1 < arg.size())
        {
            int a = arg[i];
            int b = arg[i + 1];
            if (a < b)
            {
                small.push_back(a);
                big.push_back(b);
            }
            else
            {
                small.push_back(b);
                big.push_back(a);
            }
        }
        else
        {
            has_single = true;
            single = arg[i];
        }
    }
}

void M_I_S_Deque(std::deque<int> &arg)
{
    if(arg.size() <= 1)
    {
        std::cerr << "Error: insufficient numbers" << std::endl;
    }
    
    std::deque<int> small;
    std::deque<int> big;
    bool has_single;
    int single;

    for (size_t i = 0; i < arg.size(); i += 2)
    {
        if (i + 1 < arg.size())
        {
            int a = arg[i];
            int b = arg[i + 1];
            if (a < b)
            {
                small.push_back(a);
                big.push_back(b);
            }
            else
            {
                small.push_back(b);
                big.push_back(a);
            }
        }
        else
        {
            has_single = true;
            single = arg[i];
        }
    }
}