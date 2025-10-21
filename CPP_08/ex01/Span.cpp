/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:02:55 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/21 20:54:19 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _N(0)
{}

Span::Span(unsigned int N): _N(N)
{
	_numbers.reserve(N);
}

Span::Span(const Span& other): _numbers(other._numbers), _N(other._N)
{}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->_N = other._N;
		this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{}



void Span::addNumber(int nb)
{
	if (_numbers.size() >= _N)
		throw MaxCapacityReached();
	_numbers.push_back(nb);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanFound();

    //Se hace una copia (sortedVec = _numbers) para no modificar el original.
    std::vector<int> sortedVec = _numbers;
    //Se usa std::sort() para ordenarlo de menor a mayor
    std::sort(sortedVec.begin(), sortedVec.end());

    int minSpan = INT_MAX;
    for (size_t i = 1; i < sortedVec.size(); ++i)
    {
        int span = sortedVec[i] - sortedVec[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanFound();

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}