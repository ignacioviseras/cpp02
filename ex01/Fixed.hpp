#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class Fixed {
    private:
		int _value;
		static const int _fractional = 8;

	public:
		Fixed();                            // Constructor por defecto
		Fixed(const Fixed &other);         // Constructor por copia
		Fixed &operator=(const Fixed &other); // Operador de asignación
		~Fixed();                           // Destructor

		Fixed(const int num);              // Constructor desde int
		Fixed(const float num);            // Constructor desde float

		float toFloat(void) const;         // Conversión a float
		int toInt(void) const;             // Conversión a int

		int getRawBits(void) const;        // Getter raw
		void setRawBits(int const raw);    // Setter raw
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

// El ejercicio anterior fue un buen comienzo, pero nuestra clase es bastante inútil.
// Sólo puede representan el valor 0,0.
// Agregue los siguientes constructores públicos y funciones miembro públicas a su clase:

// • Un constructor que toma un número entero constante como parámetro.
// Lo convierte al valor de punto fijo correspondiente. El valor de bits fraccionarios.
// debe inicializarse a 8, como en el ejercicio 00.

// • Un constructor que toma un número de punto flotante constante como parámetro.
// Lo convierte al valor de punto fijo correspondiente. El valor de bits fraccionarios.
// debe inicializarse a 8, como en el ejercicio 00.

// • Una función miembro float toFloat( void ) const;
// que convierte el valor de punto fijo en un valor de punto flotante.

// • Una función miembro int toInt( void ) const;
// que convierte el valor de punto fijo en un valor entero.
// Y agregue la siguiente función a los archivos de clase fija:

// • Una sobrecarga del operador de inserción («) que inserta una representación de punto flotante
// del número de punto fijo en el objeto de flujo de salida pasado como parámetro.
