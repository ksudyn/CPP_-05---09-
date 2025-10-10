/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:42:21 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/08 20:42:43 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b0("b0", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b1("b1", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b2("b2", 1);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << "Decrement: " << b2 << std::endl;
		b2.incrementGrade();
		std::cout << "Increment: " << b2 << std::endl;
		b2.incrementGrade();
		std::cout << "Increment: " << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b2("b2", 150);
		std::cout << b2 << std::endl;
		b2.incrementGrade();
		std::cout << "Increment: " << b2 << std::endl;
		b2.decrementGrade();
		std::cout << "Decrement: " << b2 << std::endl;
		b2.decrementGrade();
		std::cout << "Decrement: " << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}