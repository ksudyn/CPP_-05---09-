/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:22:07 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/15 16:09:17 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data data = {42, "OpenAI", 3.14f};

    std::cout << "Original Data pointer: " << &data << std::endl;

    // Convertimos el puntero a entero
    uintptr_t raw = Serializer::serialize(&data);

    std::cout << "Serialized value (raw): " << raw << std::endl;

    // Lo reconvertimos a puntero
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Deserialized pointer:   " << restored << std::endl;

    // Verificamos que apunta al mismo objeto
    std::cout << "ID: " << restored->id << ", Name: " << restored->name
              << ", Value: " << restored->value << std::endl;

    return 0;
}
