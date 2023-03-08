#include "Historial.h"
#include "Cotizacion.h"

HistorialCotizaciones::HistorialCotizaciones() {
    this->ultimaCotizacionHistorial = new NodoPilaHistorialCotizacion;
    this->ultimaCotizacionHistorial->cotizacion = nullptr;
    this->ultimaCotizacionHistorial->sig = nullptr;
}
NodoPilaHistorialCotizacion* HistorialCotizaciones::getPila()
{
    return this->ultimaCotizacionHistorial;
}
void HistorialCotizaciones::setPila(NodoPilaHistorialCotizacion* newNodo)
{
    this->ultimaCotizacionHistorial = newNodo;
}
;

void HistorialCotizaciones::agregarCotizacion(Cotizacion* c) {
    
};
