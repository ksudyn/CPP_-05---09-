/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:28:02 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/10 16:48:05 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 140);

        Form passport("Passport Application", 100, 50);
        Form topSecret("Top Secret Clearance", 10, 5);

        std::cout << passport << std::endl;
        std::cout << topSecret << std::endl;

        std::cout << "\n--- Bob intenta firmar Passport ---" << std::endl;
        bob.signForm(passport); // Bob tiene 140, pero se requiere 100 → fallo

        std::cout << "\n--- Alice intenta firmar Passport ---" << std::endl;
        alice.signForm(passport); // Alice tiene 50, puede firmar

        std::cout << "\n--- Alice intenta firmar Top Secret ---" << std::endl;
        alice.signForm(topSecret); // Alice (50) no puede firmar nivel 10

        std::cout << "\nEstado final de los formularios:" << std::endl;
        std::cout << passport << std::endl;
        std::cout << topSecret << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}
