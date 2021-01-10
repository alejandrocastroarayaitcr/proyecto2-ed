#include "Clases.h"

Arista::Arista(){
	setSiguiente(NULL);
	setID1("");
	setID2("");
	setType("");
	setSubType("");
	setValue("");
	setDestino(NULL);
}

pArista Arista::getSiguiente(){return this->siguiente;}

string Arista::getID1(){return this->ID1;}

string Arista::getID2(){return this->ID2;}

string Arista::getType(){return this->type;}

string Arista::getSubType(){return this->subType;}

string Arista::getValue(){return this->value;}

Nodo* Arista::getDestino(){return this->destino;}

void Arista::setSiguiente(Arista* arista){this->siguiente = arista;}

void Arista::setID1(string ID1){this->ID1 = ID1;}

void Arista::setID2(string ID2){this->ID2 = ID2;}

void Arista::setType(string type){this->type = type;}

void Arista::setSubType(string subType){this->subType = subType;}

void Arista::setValue(string value){this->value = value;}

void Arista::setDestino(Nodo* nodo){this->destino = nodo;}
