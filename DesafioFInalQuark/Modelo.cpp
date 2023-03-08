#include "Modelo.h"

#include "Cotizacion.h"
#include "Prenda.h"
#include "Tienda.h"
#include "Vendedor.h"
#include "Historial.h"
#include "Stock.h"


Model::Model() {
    this->tienda = new Tienda;

    // Aca se comienza a armar el arbol de stock, Nodo por Nodo
    tienda->raizPrincipal = new Stock("Prenda", "Prenda", 3000, 15);
    Stock* raiz = tienda->raizPrincipal;

    // Tipo de Prenda
    raiz->izq = new Stock("tipoPrenda", "Camisa", 1000, 7);
    raiz->der = new Stock("tipoPrenda", "Pantalon", 2000, 19);

    // Camisa->Manga
    raiz->izq->izq = new Stock("manga", "Corta", 500, 3);
    raiz->izq->der = new Stock("manga", "Larga", 500, 11);

    // Camisa->Manga Corta->Cuello
    raiz->izq->izq->izq = new Stock("cuello", "Mao", 200, 1);
    raiz->izq->izq->der = new Stock("cuello", "comun", 300, 5);
    // Camisa->Manga Larga->Cuello
    raiz->izq->der->izq = new Stock("cuello", "Mao", 150, 9);
    raiz->izq->der->der = new Stock("cuello", "comun", 350, 13);

    // Camisa->Manga Corta->Cuello Mao
    raiz->izq->izq->izq->izq = new Stock("calidad", "Standard", 100, 0);
    raiz->izq->izq->izq->der = new Stock("calidad", "Premium", 100, 2);
    // Camisa->Manga Corta->Cuello Comun
    raiz->izq->izq->der->izq = new Stock("calidad", "Standard", 150, 4);
    raiz->izq->izq->der->der = new Stock("calidad", "Premium", 150, 6);
    // Camisa->Manga Larga->Cuello Mao
    raiz->izq->der->izq->izq = new Stock("calidad", "Standard", 75, 8);
    raiz->izq->der->izq->der = new Stock("calidad", "Premium", 75, 10);
    // Camisa->Manga Larga->Cuello Comun
    raiz->izq->der->der->izq = new Stock("calidad", "Standard", 175, 12);
    raiz->izq->der->der->der = new Stock("calidad", "Premium", 175, 14);

    // Pantalon->Tipo
    raiz->der->izq = new Stock("tipoPantalon", "Chupin", 1500, 17);
    raiz->der->der = new Stock("tipoPantalon", "Comun", 500, 21);

    // Pantalon->Tipo Chupin
    raiz->der->izq->izq = new Stock("calidad", "Standard", 750, 16);
    raiz->der->izq->der = new Stock("calidad", "Premium", 750, 18);
    // Pantalon->Tipo Comun
    raiz->der->der->izq = new Stock("calidad", "Standard", 250, 20);
    raiz->der->der->der = new Stock("calidad", "Premium", 250, 22);

    // A las raices del arbol, la bajada se le asigna nullo, por seguridad
    raiz->izq->izq->izq->izq->izq = nullptr;
    raiz->izq->izq->izq->izq->der = nullptr;
    raiz->izq->izq->izq->der->izq = nullptr;
    raiz->izq->izq->izq->der->der = nullptr;
    raiz->izq->izq->der->izq->izq = nullptr;
    raiz->izq->izq->der->izq->der = nullptr;
    raiz->izq->izq->der->der->izq = nullptr;
    raiz->izq->izq->der->der->der = nullptr;
    raiz->izq->der->izq->izq->izq = nullptr;
    raiz->izq->der->izq->izq->der = nullptr;
    raiz->izq->der->izq->der->izq = nullptr;
    raiz->izq->der->izq->der->der = nullptr;
    raiz->izq->der->der->izq->izq = nullptr;
    raiz->izq->der->der->izq->der = nullptr;
    raiz->izq->der->der->der->izq = nullptr;
    raiz->izq->der->der->der->der = nullptr;

    raiz->der->izq->izq->izq = nullptr;
    raiz->der->izq->izq->der = nullptr;
    raiz->der->izq->der->izq = nullptr;
    raiz->der->izq->der->der = nullptr;
    raiz->der->der->izq->izq = nullptr;
    raiz->der->der->izq->der = nullptr;
    raiz->der->der->der->izq = nullptr;
    raiz->der->der->der->der = nullptr;
}

json Model::getTienda() {
    json tienda;
    tienda = 
    {
        {"nombre", this->tienda->getNombre()},
        {"direccion", this->tienda->getDireccion()},
        {"vendedor", 
            {
                {"id", this->tienda->getVendedor()->getId()},
                {"nombre", this->tienda->getVendedor()->getNombre()},
                {"apellido", this->tienda->getVendedor()->getApellido()}
            }
        }
    };
    return tienda;
}

int Model::getIdUltimoElementoHistorial()
{
    NodoPilaHistorialCotizacion* pila = this->tienda->getVendedor()->getHistorial()->getPila();
    if (pila->cotizacion != nullptr) {
        return pila->cotizacion->getId();
    }
    else {
        return 0;
    }   
}

json Model::verHistorial() // Devuelve un JSON que contiene todo el historial y su longitud, la cantidad de elementos del historial
{
    HistorialCotizaciones* historial = this->tienda->getVendedor()->getHistorial();
    json arrayHistorial = json::array({});
    NodoPilaHistorialCotizacion* aux = historial->getPila();
    int len = 0;
    json elementoHistorial = {};
    bool continuar = false;
    if (aux->cotizacion != nullptr) {
        while (aux != nullptr) {
            elementoHistorial = {
                {"pos", 0},
                {"prenda", aux->cotizacion->getPrenda()->getNombre()},
                {"manga", ""},
                {"cuello", ""},
                {"tipoPantalon", ""},
                {"calidad", aux->cotizacion->getPrenda()->getCalidad()},
                {"precioUnitario", aux->cotizacion->getPrenda()->getPrecioUnitario()},
                {"cantidad", aux->cotizacion->getCantidad()},
                {"resultado", 0.0f},
                {"idHistorial", aux->cotizacion->getId()},
                {"idVendedor", aux->cotizacion->getIdVendedor()},
                {"fechaYHora", aux->cotizacion->getFechaYHora()}
            };
            if (aux->cotizacion->getPrenda()->getNombre() == "Camisa") {
                elementoHistorial["manga"] = static_cast<Camisa*>(aux->cotizacion->getPrenda())->getManga();
                elementoHistorial["cuello"] = static_cast<Camisa*>(aux->cotizacion->getPrenda())->getCuello();
            }
            else {
                elementoHistorial["tipoPantalon"] = static_cast<Pantalon*>(aux->cotizacion->getPrenda())->getTipo();
            }
            elementoHistorial["resultado"] = this->calcularResultadoCotizacion(elementoHistorial) * aux->cotizacion->getCantidad();
            arrayHistorial.push_back(elementoHistorial);
            aux = aux->sig;

            len++;
        }
    }
    json j = {
        {"len", len},
        {"array", arrayHistorial}
    };
    return j;
}

json Model::buscarPrendaEnStock(int pos) // Realiza una busqueda en el arbol del stock segun la posicion, y devuelve la prenda
{
    Stock* nodoActual = this->tienda->raizPrincipal;
    json prendaEnStock = {
        {"prenda", ""},
        {"manga", ""},
        {"cuello", ""},
        {"tipoPantalon", ""},
        {"calidad", ""},
        {"cantidad", 0},
    };
    Stock* recorrido[5] = {};
    int i = 0;
    while (nodoActual != nullptr) {
        recorrido[i] = nodoActual;
        if (nodoActual->getPosicion() > pos) {
            if (nodoActual->izq != nullptr) {
                nodoActual = nodoActual->izq;
            }
            else {
                nodoActual = nullptr;
            }
        }
        else {
            if (nodoActual->getPosicion() == 16 || nodoActual->getPosicion() == 18) {
            }
            if (nodoActual->der != nullptr) {
                nodoActual = nodoActual->der;
            }
            else {
                nodoActual = nullptr;
            }
        }
        i++;
    }
    if (recorrido[1]->getTipo() == "Camisa") {
        prendaEnStock["prenda"] = "Camisa";
        prendaEnStock["manga"] = recorrido[1]->getTipo();
        prendaEnStock["cuello"] = recorrido[2]->getTipo();
        prendaEnStock["calidad"] = recorrido[3]->getTipo();
        prendaEnStock["cantidad"] = recorrido[4]->getCantidad();

    }
    else {
        prendaEnStock["prenda"] = "Pantalon";
        prendaEnStock["tipoPantalon"] = recorrido[1]->getTipo();
        prendaEnStock["calidad"] = recorrido[2]->getTipo();
        prendaEnStock["cantidad"] = recorrido[3]->getCantidad();
    }
    return prendaEnStock;
}

string Model::getCaracteristicasPrenda(Prenda* prenda) { // Sirve para devolver las caracteristicas de la prenda en un formato en especifico
    string caracteristicas = prenda->getNombre() + " - ";
    if (prenda->getNombre() == "Pantalon") {
        Pantalon* pant = static_cast<Pantalon*>(prenda);
         caracteristicas = caracteristicas + pant->getTipo() + " - " + prenda->getCalidad();
    }
    else {
        Camisa* cam = static_cast<Camisa*>(prenda);
         caracteristicas = caracteristicas +  cam->getManga() + " - " + cam->getCuello() + " - " + prenda->getCalidad();
    }
    return caracteristicas;
    // Ejemplo return: Camisa - Larga - Mao - Premium
}

void Model::cargarCotizacion(json cot) // Carga la nueva cotizacion dentro de la pila Historial
{
    // Forma en que llega cot
    /*json cot = {
        {"pos", 15},
        {"prenda", ""},
        {"manga", ""},
        {"cuello", ""},
        {"tipoPantalon", ""},
        {"calidad", ""},
        {"precioUnitario", 0.0f},
        {"cantidad", 0},
        {"resultado", 0.0f},
        {"idHistorial", 0},
        {"idVendedor", 0},
        {"fechaYHora", ""}
    };*/
    NodoPilaHistorialCotizacion* pila = this->tienda->getVendedor()->getHistorial()->getPila();
    // Aca comenzamos a procesar el json que nos llega para poder guardar la info en una variable tipo Cotizacion*, asi podemos cargarlo en el historial
    Cotizacion* nuevaCot = new Cotizacion;
    if (cot["prenda"] == "Camisa") {
        Camisa* cam = new Camisa;
        cam->setCalidad(cot["calidad"]);
        cam->setCantidad(cot["cantidad"]);
        cam->setPrecioUnitario(cot["precioUnitario"]);
        cam->setManga(cot["manga"]);
        cam->setCuello(cot["cuello"]);
        nuevaCot->setCotizacion(cot["idHistorial"], cot["fechaYHora"], cot["idVendedor"], cot["cantidad"], cot["resultado"], cam);
    }
    else {
        Pantalon* pant = new Pantalon;
        pant->setCalidad(cot["calidad"]);
        pant->setCantidad(cot["cantidad"]);
        pant->setPrecioUnitario(cot["precioUnitario"]);
        pant->setTipo(cot["tipoPantalon"]);
        nuevaCot->setCotizacion(cot["idHistorial"], cot["fechaYHora"], cot["idVendedor"], cot["cantidad"], cot["resultado"], pant);
    }
    if (pila->cotizacion == nullptr) { // De forma estandar, tengo ya un nodo del historial creado, aunque no tenga cotizacion. Si el dato del nodo es nulo, no hay ninguna cotizacion en el historial
        pila->cotizacion = nuevaCot;
    }
    else { // Si ya existen cotizaciones dentro del historial, se crea un nuevo nodo, se introduce la cotizacion, este nodo apunta al ultimo que ya estaba y hacemos que el puntero principal apunte al nuevo
        NodoPilaHistorialCotizacion* nuevo = new NodoPilaHistorialCotizacion;
        nuevo->cotizacion = nuevaCot;
        nuevo->sig = pila;
        this->tienda->getVendedor()->getHistorial()->setPila(nuevo);
        NodoPilaHistorialCotizacion* temp = pila;
    }
}

float Model::calcularResultadoCotizacion(json json) // Modifica el precio unitario segun las caracteristicas de la prenda
{
    float resultado = json["precioUnitario"];
    if (json["prenda"] == "Camisa") {
        if (json["manga"] == "Corta") {
            resultado = resultado - resultado * 0.10;
        }
        else {
            //Es Manga Larga, no modifica precio
        }
        if (json["cuello"] == "Mao") {
            resultado = resultado + resultado * 0.03;
        }
        else {
            //Es cuello comun, no modifica precio
        }
    }
    else {
        if (json["tipoPantalon"] == "Chupin") {
            resultado = resultado - resultado * 0.12;
        }
        else {
            // Es tipo comun, no modifica precio
        }
    }
    if (json["calidad"] == "Premium") {
        resultado = resultado + resultado * 0.3;
    }
    else {
        //Es estandar, no modifica el precio
    }
    return resultado;
}

void Model::actualizarCantidadStock(int pos, int cantidadAñadida) // Actualiza la cantidad de prendas en el stock. Cada nodo tiene una cantidad guardada, y se actualiza cada nodo del camino que representa la prenda
{
    Stock* nodoActual = this->tienda->raizPrincipal;
    while (nodoActual != nullptr) {
        nodoActual->setCantidad(nodoActual->getCantidad() + cantidadAñadida);
        if (nodoActual->getPosicion() > pos) {
            if (nodoActual->izq != nullptr) {
                nodoActual = nodoActual->izq;
            }
            else {
                nodoActual = nullptr;
            }
        }
        else {
            if (nodoActual->der != nullptr) {
                nodoActual = nodoActual->der;
            }
            else {
                nodoActual = nullptr;
            }
        }
    }
};