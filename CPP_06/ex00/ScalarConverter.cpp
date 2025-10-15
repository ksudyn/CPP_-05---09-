/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:51:01 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/15 15:21:32 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return *this;
}


// ------------------------------------------------------------
//  Funciones auxiliares para detectar el tipo de literal
// ------------------------------------------------------------

// Detecta pseudoliterales como nan, +inf, -inff, etc.
static bool isPseudoLiteral(const std::string &s)
{
    return (
        s == "nan"  || s == "nanf"  ||
        s == "+inf" || s == "+inff" ||
        s == "-inf" || s == "-inff"
    );
}
// Los pseudoliterales son literales especiales de punto flotante
// que no representan un número real normal,
// sino un valor especial reconocido por el estándar IEEE-754
// (el formato de números flotantes usado por C++).

// Son:

// nan	    Not A Number -> resultado de una operación inválida (por ejemplo 0.0 / 0.0)	double
// nanf	    igual, pero versión float
// +inf	    infinito positivo (1.0 / 0.0)	double
// +inff	infinito positivo en float
// -inf	    infinito negativo (-1.0 / 0.0)	double
// -inff	infinito negativo en float




// Detecta si el literal es un solo carácter imprimible (ej: 'a', '#', etc.)
// No se considera dígito ni signo ni punto ni 'f'.
static bool isSingleCharCandidate(const std::string &s)
{
    if (s.size() != 1)//Size es equivalente a s.length() (ambas hacen lo mismo)
        return false;

    unsigned char ch = static_cast<unsigned char>(s[0]);
    //static_cast es una palabra clave de C++ que sirve para convertir (hacer cast) un valor de un tipo a otro de forma segura y explícita.
    //Es decir, le dices al compilador: “quiero convertir este valor al tipo X”
    // Aqui estás diciendo:
    // “Convierte el carácter s[i] (que puede ser con signo) a unsigned char.”
    // “Ahora pásalo a std::isdigit() sin riesgo de comportamiento indefinido.”

    if (!std::isprint(ch))      // no imprimible
        return false;
    if (std::isdigit(ch))       // es número -> no es char literal
        return false;
    if (ch == '+' || ch == '-' || ch == '.' || ch == 'f')
        return false;

    return true;
}

// Detecta si el literal es un número entero válido (ej: -42, +7, 0)
static bool isIntLiteral(const std::string &s)
{
    if (s.empty())//Empty devuelve true si el string no contiene ningún carácter (está vacío).
        return false;

    std::size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
    {
        if (s.size() == 1) // solo signo -> no válido
            return false;
        ++i;
    }

    // Todos los demás deben ser dígitos
    for (; i < s.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }

    return true;
}

// Detecta si el literal es un float (termina en 'f', contiene punto decimal)
static bool isFloatLiteral(const std::string &s)
{
    if (s.size() < 2)
        return false;
    if (s.back() != 'f')//Back devuelve el último carácter del string,
        return false;  // debe terminar con 'f'
        

    // Quitamos la 'f' final
    std::string core = s.substr(0, s.size() - 1);

    bool hasDigit = false;
    bool hasDot   = false;
    std::size_t i = 0;

    // Signo opcional
    if (core[i] == '+' || core[i] == '-')
    {
        if (core.size() == 1)
            return false;
        ++i;
    }

    // Debe tener al menos un dígito y, opcionalmente, un solo '.'
    for (; i < core.size(); ++i)
    {
        char c = core[i];

        if (c == '.')
        {
            if (hasDot) // más de un punto
                return false;
            hasDot = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(c)))
        {
            hasDigit = true;
        }
        else
        {
            return false; // cualquier otro símbolo no permitido
        }
    }

    return hasDigit;
}

// Detecta si el literal es un double (con punto decimal, sin 'f')
static bool isDoubleLiteral(const std::string &s)
{
    if (s.empty())
        return false;

    bool hasDigit = false;
    bool hasDot   = false;
    std::size_t i = 0;

    // Signo opcional
    if (s[i] == '+' || s[i] == '-')
    {
        if (s.size() == 1)
            return false;
        ++i;
    }

    // Debe tener al menos un dígito y, opcionalmente, un solo '.'
    for (; i < s.size(); ++i)
    {
        char c = s[i];

        if (c == '.')
        {
            if (hasDot) // más de un punto -> no válido
                return false;
            hasDot = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(c)))
        {
            hasDigit = true;
        }
        else
        {
            return false;
        }
    }

    return hasDigit;
}


enum LiteralType { CHAR, INT, FLOAT, DOUBLE, PSEUDO, UNKNOWN };

static LiteralType detectType(const std::string &s)
{
    if (isPseudoLiteral(s))       return PSEUDO;
    if (isSingleCharCandidate(s)) return CHAR;
    if (isIntLiteral(s))          return INT;
    if (isFloatLiteral(s))        return FLOAT;
    if (isDoubleLiteral(s))       return DOUBLE;
    return UNKNOWN;
}

// ================================================================
//  3️⃣ MÉTODO PRINCIPAL: convertir y mostrar resultados
// ================================================================

void ScalarConverter::convert(const std::string &literal)
{
    LiteralType type = detectType(literal);

    // Variables temporales para almacenar las conversiones
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    // ------------------------------------------------------------
    // CONVERSIÓN SEGÚN EL TIPO DETECTADO
    // ------------------------------------------------------------
    try
    {
        switch (type)
        {
            case CHAR:
                c = literal[0];
                i = static_cast<int>(c);
                f = static_cast<float>(c);
                d = static_cast<double>(c);
                break;

            case INT:
                i = std::stoi(literal);
                c = static_cast<char>(i);
                f = static_cast<float>(i);
                d = static_cast<double>(i);
                break;

            case FLOAT:
                f = std::stof(literal);
                i = static_cast<int>(f);
                c = static_cast<char>(i);
                d = static_cast<double>(f);
                break;

            case DOUBLE:
                d = std::stod(literal);
                f = static_cast<float>(d);
                i = static_cast<int>(d);
                c = static_cast<char>(i);
                break;

            case PSEUDO:
                // Pseudoliterales: mostrar directamente
                std::cout << "char: impossible\n";
                std::cout << "int: impossible\n";
                if (literal.back() == 'f')
                {
                    std::cout << "float: " << literal << '\n';
                    std::cout << "double: " << literal.substr(0, literal.size() - 1) << '\n';
                }
                else
                {
                    std::cout << "float: " << literal << "f\n";
                    std::cout << "double: " << literal << '\n';
                }
                return; // Ya mostramos todo, salimos

            default:
                std::cout << "Error: tipo desconocido\n";
                return;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: conversión fallida (" << e.what() << ")\n";
        return;
    }

    // ------------------------------------------------------------
    // MOSTRAR LOS RESULTADOS DE LAS CONVERSIONES
    // ------------------------------------------------------------

    // Mostrar char
    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";

    // Mostrar int
    std::cout << "int: " << i << '\n';

    // Mostrar float
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f\n";

    // Mostrar double
    std::cout << "double: " << d << '\n';
}