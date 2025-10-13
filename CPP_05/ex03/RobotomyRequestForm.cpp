/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:06:52 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/10 20:21:46 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy_form", 72, 45) 
{
	_target = "nadie";
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy_form", 72, 45) 
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) 
{
    if (this != &other) 
	{
		this->_target = other.getTarget();
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    // Primero, comprueba si el burócrata tiene permiso y si el form está firmado
    getGradeToExecute(); // método heredado de AForm (si lo implementas allí)

    std::cout << "* DRRRRRRRRRR... drilling noises *" << std::endl;

    // Inicializamos el random una vez (puedes hacerlo en main también)
    std::srand(std::time(0));

    // 50% de probabilidad de éxito
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
}