#pragma once
#include <string>
using namespace std;

class Prenda;

class Cotizacion {
	int id;
	string fechaYHora;
	int idVendedor;
	int cantidad;
	float resultado;
	Prenda* prenda;
public:
	int getId();
	string getFechaYHora();
	int getIdVendedor();
	int getCantidad();
	float getResultado();
	Prenda* getPrenda();
	void setCotizacion(int id, string fechaYHora, int idVendedor, int cantidad, float resultado, Prenda* prenda);
};