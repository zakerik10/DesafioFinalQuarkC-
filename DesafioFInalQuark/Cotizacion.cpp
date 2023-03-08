#include "Cotizacion.h"
#include "Prenda.h" 

int Cotizacion::getId()
{
	return this->id;
}

string Cotizacion::getFechaYHora()
{
	return this->fechaYHora;
}

int Cotizacion::getIdVendedor()
{
	return this->idVendedor;
}

int Cotizacion::getCantidad()
{
	return this->cantidad;
}

float Cotizacion::getResultado()
{
	return this->resultado;
}

Prenda* Cotizacion::getPrenda()
{
	return this->prenda;
}

void Cotizacion::setCotizacion(int id, string fechaYHora, int idVendedor, int cantidad, float resultado, Prenda* prenda)
{
	this->id = id;
	this->fechaYHora = fechaYHora;
	this->idVendedor = idVendedor;
	this->cantidad = cantidad;
	this->resultado = resultado;
	this->prenda = prenda;
}
