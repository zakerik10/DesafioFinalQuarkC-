#pragma once
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

// Cada objeto Stock, es un nodo dentro del arbol del Stock
// A medida que se baja de nivel, es una caracteristica que se le agrega a la prenda
// Cada nodo tiene asignado una posicion, que me sirve para despues poder identificar una prenda en especifica
// El Arbol tiene la siguiente forma:
// 
//								          P									P(Prenda)
//										  15
//							         /         \
//							      /               \
//							   /                     \
//					        /                           \
//					      C		                          P					Caracteristica: Prenda, Tipo: C(Camisa) P(Pantalon)
//						  7                               19
//				       /    \						   /      \
//				     /        \						  /        \
//				   /            \					 /          \
//			     /                \				    /            \
//	           M.C.               M.L.			  T.Ch          T.Cm		Caracteristica: Manga, Tipo: M.C (Manga Corta) M.L.(Manga Larga) T.Ch(Tipo Chupin) T.Cm(Tipo Comun)
//			    3                  11              17            21
//			  /   \		         /   \		       /\		     /\
//			 /     \		    /     \		      /  \		    /  \
//          /       \          /       \         /    \        /    \
//	      C.M.     C.C.		 C.M.	   C.C.     S      P      S      P		Caracteristica: Cuello, Tipo: C.M.(Cuello Mao) C.C.(Cuello Comun)
//		   1        5         9         13      16    18      20     22  
//		  /\	    /\	      /\	    /\      
//       /  \	   /  \      /  \      /  \
//		S    P    S    P    S    P    S    P								Caracteristica: Calidad, Tipo: S(Standard) P(Premium)
//		0	 2	  4    6    8    10   12   14

// Cada camino del arbol, representa un tipo de prenda en especifico
// Cada numero por debajo de las iniciales, indica la posicion de cada nodo

class Stock
{
	string caracteristica;
	string tipo;
	int cantidad;
	int posicion;

public:
	Stock(string caracteristica, string tipo, int cantidad, int posicion);
	Stock* izq;
	Stock* der;
	string getCaracteristica();
	string getTipo();
	int getCantidad();
	int getPosicion();
	void setCantidad(int cant);
};

