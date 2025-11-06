/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:34:49 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/06 19:21:56 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int apply_operation(int a, int b, char op)
{
    long long result = 0;

    if (op == '+')
        result = static_cast<long long>(a) + static_cast<long long>(b);
    else if (op == '-')
        result = static_cast<long long>(a) - static_cast<long long>(b);
    else if (op == '*')
        result = static_cast<long long>(a) * static_cast<long long>(b);
    else if (op == '/')
    {
        if (b == 0)
        {
            std::cerr << "Error: division by zero" << std::endl;
            exit(1);
        }
        result = static_cast<long long>(a) / static_cast<long long>(b);
    }
    else
    {
        std::cerr << "Error: invalid operator" << std::endl;
        exit(1);
    }

    if (result > INT_MAX || result < INT_MIN)
    {
        std::cerr << "Error: result overflow at INT_MAX or INT_MIN" << std::endl;
        exit(1);
    }

    return static_cast<int>(result);
}


int reverse_polish_notation(const char *expr)
{
    std::stack<int> result;
    int i = 0;

    while (expr[i])
    {
        if (std::isspace(expr[i]))
        {
            i++;
            continue;
        }

        if (std::isdigit(expr[i]))
        {
            if (std::isdigit(expr[i + 1]))
            {
                std::cerr << "Error: number with more than one digit" << std::endl;
                return 1;
            }
            result.push(expr[i] - '0');
        }
        else if (is_operator(expr[i]))
        {
            if (result.size() < 2)
            {
                std::cerr << "Error insufficient numbers" << std::endl;
                return 1;
            }
            int b = result.top(); result.pop();
            int a = result.top(); result.pop();
            int operation = apply_operation(a, b, expr[i]);
            result.push(operation);
        }
        else
        {
            std::cerr << "Error invalid character" << std::endl;
            return 1;
        }
        i++;
    }

    if (result.size() != 1)
    {
        std::cerr << "Error: the result can not have more than one number" << std::endl;
        return 1;
    }

    std::cout << result.top() << std::endl;
    return 0;
}