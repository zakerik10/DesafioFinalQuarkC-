#include "Stock.h"

Stock::Stock(string caracteristica, string tipo, int cantidad, int posicion)
{
	this->caracteristica = caracteristica;
    this->tipo = tipo;
    this->cantidad = cantidad;
    this->posicion = posicion;
    this->izq = nullptr;
    this->der = nullptr;
}

string Stock::getCaracteristica()
{
    return this->caracteristica;
}

string Stock::getTipo()
{
    return this->tipo;
}

int Stock::getCantidad()
{
    return this->cantidad;
}

int Stock::getPosicion()
{
    return this->posicion;
}

void Stock::setCantidad(int cant)
{
    this->cantidad = cant;
}
