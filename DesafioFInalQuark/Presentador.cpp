#include "Presentador.h"

#include <iostream>
using namespace std;

#include "Vista.h"
#include "Modelo.h"
#include "Historial.h"

Presenter::Presenter() {
	this->view = new View(this);
	this->model = new Model;	
	iniciar();
}

void Presenter::iniciar()
{
	bool quit = false;
	while (!quit) {
		json tienda = model->getTienda();
		int option = this->view->pantallaPrincipal(tienda["nombre"], tienda["direccion"], tienda["vendedor"]["nombre"], tienda["vendedor"]["apellido"], tienda["vendedor"]["id"]);
		switch (option)
		{
		case 1:
			this->mostrarCotizaciones();
			break;
		case 2:
			this->view->cotizador();
			break;
		case 3:
			quit = true;
			break;
		default:
			break;
		}
	}
}

int Presenter::pedirStock(int pos)
{
	return this->model->buscarPrendaEnStock(pos)["cantidad"];
}

int Presenter::getIdUltimoElementoHistorial()
{
	return this->model->getIdUltimoElementoHistorial();
}

int Presenter::getIdVendedor()
{
	json tienda = model->getTienda();
	return tienda["vendedor"]["id"];
}

float Presenter::calcularResultadoCotizacion(json json)
{
	return this->model->calcularResultadoCotizacion(json);
}


void Presenter::mostrarCotizaciones()
{
	this->view->historial(this->model->verHistorial());
}

void Presenter::cargarCotizacion(json cot)
{
	this->model->cargarCotizacion(cot);
}

void Presenter::actualizarCantidadStock(int pos, int cantidadAñadida)
{
	this->model->actualizarCantidadStock(pos, cantidadAñadida);
}

