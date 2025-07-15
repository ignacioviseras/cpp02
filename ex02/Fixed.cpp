#include "Fixed.hpp"
#include "Fixed.hpp"

/*
	inicializa el objeto fixed con value igual a 0
	se llama haciendo Fixed a;
*/
Fixed::Fixed() : _value(0) {
}

/*
	crea un objeto como copia de uno ya existente
	asigna el valo de other en this
	se llama haciendo Fixed b(a);
*/
Fixed::Fixed(const Fixed &other) {
    *this = other;
}

/*
	permite asignar el valor de un objeto en este caso fixed a uno ya existente
    if (this != &other) esto verifica que no asignes el objeto a si mismo
	copia el valor interno de value que nos proporciona other.getRawBits()
    return *this; lo q se devuelve aqui es una referencia a si mismo y asi se pueden hacer asignaciones encadenadas
	se llama cuando haces una asignacion  " a = b "
*/
Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

/*
	se ejecuta cuando el objeto se destruye (al salir del bloque o finalizar el programa)
*/
Fixed::~Fixed() {
}

/*
	retorna el valor interno del objeto
*/
int Fixed::getRawBits(void) const {
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
    this->_value = num << _fractional;
}

Fixed::Fixed(const float num) {
    this->_value = roundf(num * (1 << _fractional));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_value < other._value;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->_value > other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_value != other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_value <= other._value;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->_value++;
    return tmp;
}

Fixed& Fixed::operator--() {
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->_value--;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
