/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:34:48 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/15 16:41:14 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
	public:
		virtual ~Base(void) {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif
// La clase Base tiene un destructor virtual,
// lo que permite usar polimorfismo correctamente.

// Si no fuese virtual,
// borrar un objeto A a través de un puntero Base* provocaría
// comportamiento indefinido.