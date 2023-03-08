#pragma once

class Cotizacion;

struct NodoPilaHistorialCotizacion {
	Cotizacion* cotizacion;
	NodoPilaHistorialCotizacion* sig;
};


class HistorialCotizaciones {
	NodoPilaHistorialCotizacion* ultimaCotizacionHistorial;
public:
	HistorialCotizaciones();
	NodoPilaHistorialCotizacion* getPila();
	void setPila(NodoPilaHistorialCotizacion* newNodo);
	void agregarCotizacion(Cotizacion* c);
};
