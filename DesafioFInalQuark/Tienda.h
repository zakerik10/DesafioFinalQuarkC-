#pragma once
#include <string>
using namespace std;

class Prenda;
class Pantalon;
class Camisa;
class Vendedor;
class Stock;

class Tienda {
	string nombre;
	string direccion;
	Vendedor* vendedor;
public:
	Tienda();
	Stock* raizPrincipal;
	string getNombre();
	string getDireccion();
	Vendedor* getVendedor();
};

