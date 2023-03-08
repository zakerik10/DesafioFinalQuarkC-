#include <iostream>
#include <limits>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Vista.h"
#include "Presentador.h"
#include "Prenda.h" 
#include "Tienda.h" 

View::View(Presenter* presentador) {
    this->presentador = presentador;
}

int View::pantallaPrincipal(string nombreTienda, string direccionTienda, string nombreVendedor, string apellidoVendedor, int idVendedor) {
    cout << "COTIZADOR EXPRESS - MENU PRINCIPAL" << endl;
    this->separador();
    cout << nombreTienda << " | " << direccionTienda << endl;
    this->separador();
    cout << nombreVendedor << " " << apellidoVendedor << " | " << idVendedor << endl;
    this->separador();
    cout << endl;
    cout << "SELECCIONE UNA OPCION DEL MENU:" << endl;
    cout << endl;
    cout << "1) Historial de Cotizaciones" << endl;
    cout << "2) Realizar Cotizacion" << endl;
    cout << "3) Salir" << endl;
    int opcion = this->verificadorOpcionSeleccionada(1, 3);
    return opcion;
};

void View::historial(json historial) { // Imprime el historial en pantalla
    this->principioVentana("HISTORIAL DE COTIZACIONES");
    cout << endl;
    int len = historial["len"];
    if (len > 0) {
        for (int i = 0; i < historial["len"]; i++) {
            json arr = historial["array"][i];
            this->elementoHistorial(arr);
        }
    }
    else {
        cout << "El historial esta vacio" << endl;
    }
    cout << endl;
    this->separador();
    cout << "Presione cualquier tecla para volver al menu principal" << endl;
    this->separador();
    cin.get();
    cin.get();
    system("cls");
};

void View::elementoHistorial(json cot) {
    cout << "Numero de Identificacion: " << cot["idHistorial"] << endl;
    cout << "Fecha y hora de la cotizacion: " << cot["fechaYHora"] << endl;
    cout << "Prenda Cotizada: " << this->caracteristicasPrenda(cot) << endl;
    cout << "Precio Unitario: $" << cot["precioUnitario"] << endl;
    cout << "Cantidad de unidades cotizadas: " << cot["cantidad"] << endl;
    cout << "Precio Final: $" << cot["resultado"] << endl;
    cout << endl;
};

void View::cotizador() {
    string titulo = "COTIZAR";
    this->principioVentana(titulo);
    int pos = 15; // Cuando se comienza a cotizar, se arranca con una posicion 15, que es la posicion de la raiz en el arbol del Stock
    // A medida que se vaya cotizando, A esta pos se le va sumando o restando, segun las caracteristicas que se van eligiendo
    // Hasta que al terimar, se consigue un valor, que es la posicion de alguna de las raices del arbol
    // Sabiendo exactamente la posicion de la raiz, sabemos la prenda exacta que se quiere cotizar, y se puede buscar su stock
    json nuevaCotizacion = {
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
    };
    int opcion = -1;
    cout << "PASO 1: Selecciona la prenda a cotizar" << endl;
    cout << "1) Camisa" << endl;
    cout << "2) Pantalon" << endl;
    opcion = this->verificadorOpcionSeleccionada(1, 3);
    if (opcion == 3) {
        system("cls");
        return;
    }
    if (opcion == 1) {
        nuevaCotizacion["prenda"] = "Camisa";
        pos = pos - 8;
    }
    else {
        nuevaCotizacion["prenda"] = "Pantalon";
        pos = pos + 4;
    }

    this->principioVentana(titulo);
    if (nuevaCotizacion["prenda"] == "Camisa") {
        cout << "PASO 2.a: La camisa a cotizar, ¿Es Manga Corta?" << endl;
        cout << "1) Si" << endl;
        cout << "2) No" << endl;
        opcion = this->verificadorOpcionSeleccionada(1, 3);
        if (opcion == 3) {
            system("cls");
            return;
        }
        if (opcion == 1) {
            nuevaCotizacion["manga"] = "Corta";
            pos = pos - 4;
        }
        else {
            nuevaCotizacion["manga"] = "Larga";
            pos = pos + 4;
        }

        this->principioVentana(titulo);
        cout << "PASO 2.B: La camisa a cotizar, ¿Es Cuello Mao?" << endl;
        cout << "1) Si" << endl;
        cout << "2) No" << endl;
        opcion = this->verificadorOpcionSeleccionada(1, 3);
        if (opcion == 3) {
            system("cls");
            return;
        }
        if (opcion == 1) {
            nuevaCotizacion["cuello"] = "Mao";
            pos = pos - 2;
        }
        else {
            nuevaCotizacion["cuello"] = "Comun";
            pos = pos + 2;
        }
    }
    else {
        cout << "PASO 2: El pantalon a cotizar, ¿Es Chupin?" << endl;
        cout << "1) Si" << endl;
        cout << "2) No" << endl;
        opcion = this->verificadorOpcionSeleccionada(1, 3);
        if (opcion == 3) {
            system("cls");
            return;
        }
        if (opcion == 1) {
            cout << "Es chupin" << endl;
            nuevaCotizacion["tipoPantalon"] = "Chupin";
            pos = pos - 2;
        }
        else {
            nuevaCotizacion["tipoPantalon"] = "Comun";
            pos = pos + 2;
        }
    }

    this->principioVentana(titulo);
    cout << "PASO 3: Seleccione la calidad de la prenda" << endl;
    cout << "1) Standard" << endl;
    cout << "2) Premium" << endl;
    opcion = this->verificadorOpcionSeleccionada(1, 3);
    if (opcion == 3) {
        system("cls");
        return;
    }
    if (opcion == 1) {
        nuevaCotizacion["calidad"] = "Standard";
        pos = pos - 1;
    }
    else {
        nuevaCotizacion["calidad"] = "Premium";
        pos = pos + 1;
    }


    this->principioVentana(titulo);
    cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar" << endl;
    nuevaCotizacion["precioUnitario"] = this->verificadorOpcionSeleccionada(0, 999999999);

    this->principioVentana(titulo);
    nuevaCotizacion["pos"] = pos;
    int cantidadStock = this->presentador->pedirStock(pos);
    if (cantidadStock != 0) {
        cout << "EXISTE " << cantidadStock << " CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA" << endl << endl;
        cout << "Paso 5: Ingrese la cantidad de unidades a cotizar, que sea menor o igual al stock disponible" << endl;
        int cantidadSeleccionada = this->verificadorOpcionSeleccionada(1, cantidadStock);
        nuevaCotizacion["cantidad"] = cantidadSeleccionada;
        this->principioVentana(titulo);
        nuevaCotizacion["idHistorial"] = this->presentador->getIdUltimoElementoHistorial() + 1;
        nuevaCotizacion["idVendedor"] = this->presentador->getIdVendedor();
        nuevaCotizacion["fechaYHora"] = this->fechaYHoraActual();
        nuevaCotizacion["resultado"] = this->presentador->calcularResultadoCotizacion(nuevaCotizacion) * cantidadSeleccionada;
        this->elementoHistorial(nuevaCotizacion);
        this->presentador->cargarCotizacion(nuevaCotizacion);
        this->presentador->actualizarCantidadStock(pos, -cantidadSeleccionada);
    }
    else {
        cout << "Lo siento, no quedan en stock este tipo de prendas" << endl;
    }
    this->separador();
    cout << "Presione cualquier tecla para volver al menu principal" << endl;
    this->separador();
    cin.get();
    cin.get();
    system("cls");
    return;
};

void View::separador() {
    cout << "-------------------------------------------------" << endl;
};

void View::principioVentana(string titulo) {
    system("cls");
    cout << "COTIZADOR EXPRESS - " << titulo << endl;
    this->separador();
    cout << "Presiona 3 para volver al menu principal" << endl;
    this->separador();
};

int View::verificadorOpcionSeleccionada(int desde, int hasta) {
    int selec;
    bool inputOk = false;
    do {
        cin >> selec;
        if (cin.fail() || (selec < desde || selec > hasta)) {
            cout << "El valor ingresado no es un número entero válido. Por favor, intente nuevamente." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            inputOk = true;
        }
    } while (!inputOk);
    return selec;
}
string View::fechaYHoraActual()
{
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    tm tm_struct;
    if (localtime_s(&tm_struct, &time) != 0) {
        // Error al llamar a localtime_s()
        // Manejo del error
    }
    stringstream ss;
    ss << put_time(&tm_struct, "%d-%m-%Y %H:%M:%S");
    std::string time_str = ss.str();
    return time_str;
}


string View::caracteristicasPrenda(json cot) {
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
    string caracteristicas = cot["prenda"];
    caracteristicas = caracteristicas + " - ";
    if (cot["prenda"] == "Pantalon") {
        //Pantalon* pant = static_cast<Pantalon*>(prenda);
        string tipoPant = cot["tipoPantalon"];
        string calid = cot["calidad"];
        caracteristicas = caracteristicas + tipoPant + " - " + calid;
    }
    else {
        //Camisa* cam = static_cast<Camisa*>(prenda);
        string manga = cot["manga"];
        string cuello = cot["cuello"];
        string calid = cot["calidad"];
        caracteristicas = caracteristicas + manga + " - " + cuello + " - " + calid;
    }
    return caracteristicas;
};