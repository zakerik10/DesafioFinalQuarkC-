#pragma once
#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

class Cotizacion;
class Prenda;
class Tienda;
class Vendedor;
class HistorialCotizaciones;
class Stock;

class Model {
	Tienda* tienda;
public:
	Model();
	json getTienda();
	int getIdUltimoElementoHistorial();
	json verHistorial();
	json buscarPrendaEnStock(int pos);
	string getCaracteristicasPrenda(Prenda* prenda);
	void cargarCotizacion(json cot);
	float calcularResultadoCotizacion(json json);
	void actualizarCantidadStock(int pos, int cantidadAñadida);
};

