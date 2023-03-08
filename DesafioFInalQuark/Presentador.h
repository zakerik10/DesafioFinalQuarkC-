#pragma once
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

class Model;
class View;
class HistorialCotizaciones;

class Presenter {
	View* view;
	Model* model;
public:
	Presenter();
	void iniciar();
	int pedirStock(int pos);
	int getIdUltimoElementoHistorial();
	int getIdVendedor();
	float calcularResultadoCotizacion(json json);
	void mostrarCotizaciones();
	void cargarCotizacion(json cot);
	void actualizarCantidadStock(int pos, int cantidadAñadida);
};