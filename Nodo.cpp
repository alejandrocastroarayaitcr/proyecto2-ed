#include "Clases.h"

Nodo::Nodo(){
	setSiguiente(NULL);
	setID(0);
	setName("");
	setType("");
	setLink("");
	setReaction("");
	setPrimeraArista(NULL);
	setGraphX(0);
	setGraphY(0);
	setGraphW(0);
	setGraphH(0);
}

Nodo::~Nodo(){
	pArista aux;
	while(this->primeraArista){
		aux = getPrimeraArista();
		this->primeraArista = this->primeraArista->getSiguiente();
		delete aux;
	}
}

pNodo Nodo::getSiguiente(){return this->siguiente;}

short int Nodo::getID(){return this->ID;}

string Nodo::getName(){return this->name;}

string Nodo::getType(){return this->type;}

string Nodo::getLink(){return this->link;}

string Nodo::getReaction(){return this->reaction;}

pArista Nodo::getPrimeraArista(){return this->primeraArista;}

short int Nodo::getGraphX(){return this->graphX;}

short int Nodo::getGraphY(){return this->graphY;}

short int Nodo::getGraphW(){return this->graphW;}

short int Nodo::getGraphH(){return this->graphH;}

void Nodo::setSiguiente(pNodo nodo){this->siguiente = nodo;}

void Nodo::setID(short int ID){this->ID = ID;}

void Nodo::setName(string pName){this->name = pName;}

void Nodo::setType(string pType){this->type = pType;}

void Nodo::setLink(string pLink){this->link = pLink;}

void Nodo::setReaction(string pReaction){this->reaction = pReaction;}

void Nodo::setPrimeraArista(pArista arista){this->primeraArista = arista;}

void Nodo::setGraphX(short int x){this->graphX = x;}

void Nodo::setGraphY(short int y){this->graphY = y;}

void Nodo::setGraphW(short int width){this->graphW = width;}

void Nodo::setGraphH(short int height){this->graphH = height;}
