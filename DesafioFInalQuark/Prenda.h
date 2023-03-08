#pragma once
#include <string>
using namespace std;

class Prenda {
protected:
	string nombre;
	string calidad;
	float precioUnitario;
	int cantidadStock;
public:
	string getNombre();
	string getCalidad();
	float getPrecioUnitario();
	int getCantidadStock();
	void setCalidad(string calidad);
	void setCantidad(int cantidad);
	void setPrecioUnitario(float precio);
};

class Pantalon : public Prenda {
	string tipo;
public:
	Pantalon();
	string getTipo();
	void setTipo(string tipoSeted);
};

class Camisa : public Prenda {
	string manga;
	string cuello;
public:
	Camisa();
	string getManga();
	string  getCuello();
	void setManga(string mangaSeted);
	void setCuello(string cuelloSeted);
	
};