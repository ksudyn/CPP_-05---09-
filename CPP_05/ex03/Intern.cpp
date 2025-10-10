/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:52:08 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/10 18:56:09 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

AForm *createPresi(const std::string &target)
{
	AForm *a = new PresidentialPardonForm(target);
	return (a);
}

AForm *createRobot(const std::string &target)
{
	AForm *a = new RobotomyRequestForm(target);
	return (a);
}

AForm *createShrub(const std::string &target)
{
	AForm *a = new ShrubberyCreationForm(target);
	return (a);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string names[3] = {"PresidentialPardon", "RobotomyRequest",
						"ShrubberyCreation"};
	int i = 0;
	while (i <= 3)
	{
		if (names[i] == name)
			break;
		i++;
	}

	switch (i)
	{
	case 0:
		return (createPresi(target));
		break;
	case 1:
		return (createRobot(target));
	case 2:
		return (createShrub(target));
	default:
		throw FormNotFound();
	}
}