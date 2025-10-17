/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:07:19 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/17 18:55:27 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> nums = {10, 20, 30, 40, 50};

    try
    {
        auto it = easyfind(nums, 30);
        std::cout << "Encontrado: " << *it << std::endl;
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        easyfind(nums, 100);
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
