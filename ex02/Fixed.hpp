#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class Fixed {
	private:
		int _value;                         // Valor entero que representa el número de punto fijo
		static const int _fractional = 8;  // Número de bits fraccionales

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);

		// Operadores de comparación
		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Operadores aritméticos
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Operadores de incremento y decremento
		Fixed& operator++();       // Pre-incremento
		Fixed operator++(int);     // Post-incremento
		Fixed& operator--();       // Pre-decremento
		Fixed operator--(int);     // Post-decremento

		// Métodos estáticos min y max
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		~Fixed();

		Fixed(const int num);
		Fixed(const float num);

		float toFloat(void) const;
		int toInt(void) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

// Sobrecarga del operador de inserción para imprimir objetos Fixed
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

/*
Allowed functions : roundf (from <cmath>)
Add public member functions to your class to overload the following operators:
• The 6 comparison operators: >, <, >=, <=, ==, and !=.
• The 4 arithmetic operators: +, -, *, and /.
• The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, which will increase or decrease the fixed-point value by
the smallest representable ϵ, such that 1 + ϵ > 1.
Add these four public overloaded member functions to your class:
• A static member function min that takes two references to fixed-point numbers as
parameters, and returns a reference to the smallest one.
• A static member function min that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the smallest one.
• A static member function max that takes two references to fixed-point numbers as
parameters, and returns a reference to the greatest one.
• A static member function max that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the greatest one.



*/