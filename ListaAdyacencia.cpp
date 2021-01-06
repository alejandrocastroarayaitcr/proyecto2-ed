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
string ListaAdyacencia::getName(){return this->name;}
string ListaAdyacencia::getOrg(){return this->org;}
string ListaAdyacencia::getNumber(){return this->number;}
string ListaAdyacencia::getTitle(){return this->title;}
string ListaAdyacencia::getImage(){return this->image;}
void ListaAdyacencia::setPrimero(pNodo nodo){this->primero = nodo;}
void ListaAdyacencia::setName(string name){this->name = name;}
void ListaAdyacencia::setOrg(string org){this->org = org;}
void ListaAdyacencia::setNumber(string number){this->number = number;}
void ListaAdyacencia::setTitle(string title){this->title = title;}
void ListaAdyacencia::setImage(string image){this->image = image;}
void ListaAdyacencia::cargarKGML(){}
void ListaAdyacencia::verRutas(){}
void ListaAdyacencia::compararRutas(){}
void ListaAdyacencia::inspeccionar(){}
void ListaAdyacencia::generarGrafico(){}
