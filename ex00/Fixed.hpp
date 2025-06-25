#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class Fixed {
    private:
		int _value;
		static const int _fractional = 8;
		
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

// Crees que sabes números enteros y de punto flotante. Que lindo.
// Lea este artículo de 3 páginas (1, 2, 3) para descubrir que no es así. Anda, léelo.
// Hasta hoy, cada número que usabas en tu código era básicamente un número entero o un
// número de punto flotante, o cualquiera de sus variantes (corto, char, largo, doble, etc.).
// Después de leer el artículo anterior, es seguro asumir que los números enteros y de punto flotante tienen características opuestas.
// Pero hoy las cosas cambiarán. Vas a descubrir un número nuevo e impresionante.
// tipo: números de punto fijo! Siempre ausente de los tipos escalares de la mayoría de los lenguajes,
// Los números de punto fijo ofrecen un valioso equilibrio entre rendimiento, precisión, alcance y
// precisión. Esto explica por qué los números de punto fijo son particularmente aplicables a las computadoras.
// gráficos, procesamiento de sonido o programación científica, sólo por nombrar algunos.
// Como C++ carece de números de punto fijo, los sumarás. Este artículo de
// Berkeley es un buen comienzo. Si no tienes idea de qué es la Universidad de Berkeley, lee esto
// sección de su página de Wikipedia.

// Cree una clase en forma canónica ortodoxa que represente un número de punto fijo:
// • Miembros privados:
// ◦ Un número entero para almacenar el valor del número de punto fijo.
// ◦ Un entero constante estático para almacenar el número de bits fraccionarios. Su valor
// siempre será el literal entero 8.
// • Miembros públicos:
// ◦ Un constructor predeterminado que inicializa el valor numérico de punto fijo en 0.
// ◦ Un constructor de copias.
// ◦ Una sobrecarga del operador de asignación de copia.
// ◦ Un destructor.
// ◦ Una función miembro int getRawBits( void ) const;
// que devuelve el valor bruto del valor de punto fijo.
// ◦ Una función miembro void setRawBits( int const raw );
// que establece el valor bruto del número de punto fijo.
// Ejecutando este código: