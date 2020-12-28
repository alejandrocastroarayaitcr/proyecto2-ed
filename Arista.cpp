#include "Clases.h"

Arista::Arista(){
	setSiguiente(NULL);
	setID(0);
	setDestino(NULL);
}

pArista Arista::getSiguiente(){return this->siguiente;}

short int Arista::getID(){return this->ID;}

Nodo* Arista::getDestino(){return this->destino;}

void Arista::setSiguiente(Arista* arista){this->siguiente = arista;}

void Arista::setID(short int ID){this->ID = ID;}

void Arista::setDestino(Nodo* nodo){this->destino = nodo;}
