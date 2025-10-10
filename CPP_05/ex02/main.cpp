/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:28:02 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/10 20:59:53 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat boss("Boss", 1);
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Trillian");
    ShrubberyCreationForm tardon("Meg");

    try
    {
        boss.signAForm(robot);
        boss.executeForm(robot);

        boss.signAForm(pardon);
        boss.executeForm(pardon);

        boss.signAForm(tardon);
        boss.executeForm(tardon);
    } catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
