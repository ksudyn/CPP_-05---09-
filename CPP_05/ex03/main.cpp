/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:28:02 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/13 17:28:36 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;

    try
    {
        AForm *form = intern.makeForm("RobotomyRequest", "Bender");
        std::cout << "Form created: " << form->getName() << std::endl;
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n";
    try
    {
        AForm *form = intern.makeForm("UnknownForm", "Nowhere");
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

