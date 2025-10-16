/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:40:04 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/16 16:57:22 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _arr(NULL), _size(0)//Constructor sin parámetros
{}

template <typename T>
Array<T>::Array(unsigned int i): _size(i)
{
    //Constructor con parámetro unsigned int n
    //Crea un array de n elementos, inicializados por defecto.
    _arr = new T[i]();// reserva memoria para n elementos de tipo T
}

template <typename T>
Array<T>::~Array()
{
    delete[] _arr;
}

template <typename T>
Array<T>::Array(const Array& other): _arr(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
		delete[] this->_arr;
        this->_size = other._size;
        this->_arr = new T[this->_size]();
        for (unsigned int i = 0; i < this->_size; i++)
        {
			this->_arr[i] = other._arr[i];
		}
    }
    return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}


template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw Array::NonAllocatedMemory();
	return (_arr[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= this->_size)
        throw Array<T>::NonAllocatedMemory();
    return _arr[index];
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
    os << "[";
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        os << arr[i];
        if (i < arr.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}