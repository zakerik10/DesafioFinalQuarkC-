#pragma once
#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;

class Prenda;
class Tienda;
class Presenter;

class View {
	Presenter* presentador;
public:
	View(Presenter* presentador);
	int pantallaPrincipal(string nombreTienda, string direccionTienda, string nombreVendedor, string apellidoVendedor, int idVendedor);
	void historial(json historial);
	void elementoHistorial(json cot);
	void cotizador();
	void separador();
	void principioVentana(string titulo);
	int verificadorOpcionSeleccionada(int desde, int hasta);
	string fechaYHoraActual();
	string caracteristicasPrenda(json cot);
};
