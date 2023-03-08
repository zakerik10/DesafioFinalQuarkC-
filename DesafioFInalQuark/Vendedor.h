#pragma once
#include <string>
using namespace std;

class HistorialCotizaciones;


class Vendedor {
	int id;
	string nombre;
	string apellido;
	HistorialCotizaciones* historial;
public:
	Vendedor();
	int getId();
	string getNombre();
	string getApellido();
	HistorialCotizaciones* getHistorial();
};

