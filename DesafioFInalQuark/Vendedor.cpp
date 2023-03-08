#include "Vendedor.h"
#include "Historial.h"

Vendedor::Vendedor() {
    this->nombre = "Erik";
    this->apellido = "Zakaryan";
    this->id = 1;
    this->historial = new HistorialCotizaciones;
}

int Vendedor::getId() {
    return this->id;
}

string Vendedor::getNombre() {
    return this->nombre;
}

string Vendedor::getApellido() {
    return this->apellido;
}

HistorialCotizaciones* Vendedor::getHistorial() {
    return this->historial;
}
