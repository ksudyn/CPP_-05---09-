/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:37:16 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/06 17:49:07 by ksudyn           ###   ########.fr       */
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

bool Is_Positive_Numbers(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); ++i)
        if (!isdigit(str[i]))
            return false;
    return true;
}


void M_I_S_Vector(std::vector<int> &arg)
{
    if(arg.size() <= 1)
    {
        return ;
    }

    std::vector<int> small;
    std::vector<int> big;
    bool has_single = false;
    int single = 0;

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

    M_I_S_Vector(big);

    for (std::vector<int>::iterator it = small.begin(); it != small.end(); ++it)
    {
        std::vector<int>::iterator pos;
        
        pos = std::lower_bound(big.begin(), big.end(), *it);
        big.insert(pos, *it);
    }

    if(has_single)
    {
        std::vector<int>::iterator pos;
        
        pos = std::lower_bound(big.begin(), big.end(), single);
        big.insert(pos, single);
    }

    arg = big;
}

void M_I_S_Deque(std::deque<int> &arg)
{
    if(arg.size() <= 1)
    {
        return ;
    }
    
    std::deque<int> small;
    std::deque<int> big;
    bool has_single = false;
    int single = 0;

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
    
    M_I_S_Deque(big);

    for(std::deque<int>::iterator it = small.begin(); it != small.end(); ++it)
    {
        std::deque<int>::iterator pos;

        pos = std::lower_bound(big.begin(), big.end(), *it);
        big.insert(pos, *it);
    }
    
    if(has_single)
    {
        std::deque<int>::iterator pos;

        pos = std::lower_bound(big.begin(), big.end(), single);
        big.insert(pos, single);
    }
    
    arg = big;
}

long getTimeInMicroseconds(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000L + time.tv_usec);
}

long getTimeInMilliseconds(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000L + time.tv_usec / 1000L);
}

double TimeVector(std::vector<int> &vector)
{
    long start = getTimeInMicroseconds();
    M_I_S_Vector(vector);
    long end = getTimeInMicroseconds();
    return static_cast<double>(end - start) / 1000.0;
}

double TimeDeque(std::deque<int> &deque)
{
    long start = getTimeInMicroseconds();
    M_I_S_Deque(deque);
    long end = getTimeInMicroseconds();
    return static_cast<double>(end - start) / 1000.0;
}

int Pmerge_me(char **argv)
{
    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; argv[i]; ++i)
    {
        std::string arg(argv[i]);
        if (!Is_Positive_Numbers(arg))
        {
            std::cerr << "Error: In teh number of teh argument" << std::endl;
            return 1;
        }

        long num = std::strtol(arg.c_str(), NULL, 10);
        if (num > INT_MAX)
        {
            std::cerr << "Error: Number greater than INT_MAX" << std::endl;
            return 1;
        }

        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    double timeVec = TimeVector(vec);
    double timeDeq = TimeDeque(deq);

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << timeVec << " ms" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << timeDeq << " ms" << std::endl;

    return 0;
}
