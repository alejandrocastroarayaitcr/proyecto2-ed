#include "Clases.h"

Nodo::Nodo(){
	setSiguiente(NULL);
	setID(0);
	setName("");
	setType("");
	setLink("");
	setReaction("");
	setVisitado(false);
	setPrimeraArista(NULL);
	setGraphicsName("");
	setFgColor("");
	setBgColor("");
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

bool Nodo::getVisitado(){return this->visitado;}

pArista Nodo::getPrimeraArista(){return this->primeraArista;}

string Nodo::getGraphicsName(){return this->graphicsName;}

string Nodo::getFgColor(){return this->fgColor;}

string Nodo::getBgColor(){return this->bgColor;}

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

void Nodo::setVisitado(bool pVisitado){this->visitado = pVisitado;}

void Nodo::setPrimeraArista(pArista arista){this->primeraArista = arista;}

void Nodo::setGraphicsName(string graphicsName){this->graphicsName = graphicsName;}

void Nodo::setFgColor(string fgColor){this->fgColor = fgColor;}

void Nodo::setBgColor(string bgColor){this->bgColor = bgColor;}

void Nodo::setGraphX(short int x){this->graphX = x;}

void Nodo::setGraphY(short int y){this->graphY = y;}

void Nodo::setGraphW(short int width){this->graphW = width;}

void Nodo::setGraphH(short int height){this->graphH = height;}
