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
		Fixed();                   
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		Fixed(const int num);             
		Fixed(const float num);           

		float toFloat(void) const;        
		int toInt(void) const;            

		int getRawBits(void) const;
		void setRawBits(int const raw);
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
