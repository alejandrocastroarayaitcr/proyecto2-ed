#include "Clases.h"

Arista::Arista(){
	setSiguiente(NULL);
	setID1(0);
	setID2(0);
	setType("");
	setDestino(NULL);
}

pArista Arista::getSiguiente(){return this->siguiente;}

short int Arista::getID1(){return this->ID1;}

short int Arista::getID2(){return this->ID2;}

string Arista::getType(){return this->type;}

Nodo* Arista::getDestino(){return this->destino;}

void Arista::setSiguiente(Arista* arista){this->siguiente = arista;}

void Arista::setID1(short int ID1){this->ID1 = ID1;}

void Arista::setID2(short int ID2){this->ID2 = ID2;}

void Arista::setType(string type){this->type = type;}

void Arista::setDestino(Nodo* nodo){this->destino = nodo;}
