#include "Nodo.cpp"
#include "Arista.cpp"

ListaAdyacencia::ListaAdyacencia(){
	setPrimero(NULL);
	cargarGrafo();
}

ListaAdyacencia::~ListaAdyacencia(){
	pNodo aux;
	while(this->primero){
		aux = getPrimero();
		this->primero = this->primero->getSiguiente();
		delete aux;
	}
	guardarGrafo();
}

void ListaAdyacencia::cargarGrafo(){}
void ListaAdyacencia::guardarGrafo(){}
pNodo ListaAdyacencia::getPrimero(){return this->primero;}
void ListaAdyacencia::setPrimero(pNodo nodo){this->primero = nodo;}
void ListaAdyacencia::cargarKGML(){}
void ListaAdyacencia::verRutas(){}
void ListaAdyacencia::compararRutas(){}
void ListaAdyacencia::inspeccionar(){}
void ListaAdyacencia::generarGrafico(){}
