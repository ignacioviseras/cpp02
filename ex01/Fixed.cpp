#include "Fixed.hpp"

/*
	inicializa el objeto fixed con value igual a 0
	se llama haciendo Fixed a;
*/
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

/*
	crea un objeto como copia de uno ya existente
	asigna el valo de other en this
	se llama haciendo Fixed b(a);
*/
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/*
	permite asignar el valor de un objeto en este caso fixed a uno ya existente
    if (this != &other) esto verifica que no asignes el objeto a si mismo
	copia el valor interno de value que nos proporciona other.getRawBits()
    return *this; lo q se devuelve aqui es una referencia a si mismo y asi se pueden hacer asignaciones encadenadas
	se llama cuando haces una asignacion  " a = b "
*/
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

/*
	se ejecuta cuando el objeto se destruye (al salir del bloque o finalizar el programa)
*/
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

/*
	retorna el valor interno del objeto
*/
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

/*
	asigna el valor q recibe la funcion al objeto
*/
void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

int Fixed::toInt(void) const {
	return this->_value >> _fractional;
}

float Fixed::toFloat(void) const {
	return (float)this->_value / (1 << _fractional);
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = num << _fractional;
}


Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(num * (1 << _fractional));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
