#include <iostream>
#include "Tienda.h"
#include "Prenda.h"
#include "Vendedor.h"
#include "Stock.h"
using namespace std;

Tienda::Tienda() {
    this->nombre = "Zeta Indumentaria";
    this->direccion = "Avenida Lope de Vega 2859";

    this->vendedor = new Vendedor;
}

string Tienda::getNombre() {
    return this->nombre;
}

string Tienda::getDireccion() {
    return this->direccion;
}

Vendedor* Tienda::getVendedor() {
    return this->vendedor;
}