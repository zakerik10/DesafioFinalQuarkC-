#include <iostream>
#include "Prenda.h"

using namespace std;
string Prenda::getNombre() {
    return nombre;
}

string Prenda::getCalidad()
{
    return this->calidad;
}

float Prenda::getPrecioUnitario()
{
    return this->precioUnitario;
}

int Prenda::getCantidadStock()
{
    return this->cantidadStock;
}

void Prenda::setCalidad(string calidad) {
    this->calidad = calidad;
}

void Prenda::setCantidad(int cantidad) {
    this->cantidadStock = cantidad;
}

void Prenda::setPrecioUnitario(float precio)
{
    this->precioUnitario = precio;
}

Pantalon::Pantalon() {
    this->nombre = "Pantalon";
}

string Pantalon::getTipo() {
    return this->tipo;
}

void Pantalon::setTipo(string tipoSeted) {
    this->tipo = tipoSeted;
}


Camisa::Camisa() {
    this->nombre = "Camisa";
}

string Camisa::getManga() {
    return this->manga;
}


string Camisa::getCuello() {
    return this->cuello;
}

void Camisa::setManga(string mangaSeted) {
    this->manga = mangaSeted;
}

void Camisa::setCuello(string cuelloSeted) {
    this->cuello = cuelloSeted;
}

