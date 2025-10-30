/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:34:49 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/30 20:47:42 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int apply_operation(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
    {
        if (b == 0)
        {
            std::cerr << "Error of number in /" << std::endl;
            exit(1);
        }
        return a / b;
    }
    std::cerr << "Error in operation for operator" << std::endl;
    exit(1);
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
                std::cerr << "Error: nuber with more than one digit" << std::endl;
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
        std::cerr << "Error: the resut can not have more than one number" << std::endl;
        return 1;
    }

    std::cout << result.top() << std::endl;
    return 0;
}