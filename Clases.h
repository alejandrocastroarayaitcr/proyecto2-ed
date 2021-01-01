#ifndef CLASES_H_
#define CLASES_H_

#include <iostream>

using namespace std;

class Arista {
private:
	Arista* siguiente;
	short int ID;
	class Nodo* destino;
public:
	Arista();
	Arista* getSiguiente();
	short int getID();
	class Nodo* getDestino();
	void setSiguiente(Arista* arista);
	void setID(short int ID);
	void setDestino(class Nodo* nodo);
friend class Nodo;
};
typedef Arista* pArista;

class Nodo {
private:
	Nodo* siguiente;
	short int ID;
	string name;
	pArista primeraArista;
	short int graphX;
	short int graphY;
	short int graphW;
	short int graphH;
public:
	Nodo();
	~Nodo();
	Nodo* getSiguiente();
	short int getID();
	string getName();
	pArista getPrimeraArista();
	short int getGraphX();
	short int getGraphY();
	short int getGraphW();
	short int getGraphH();
	void setSiguiente(Nodo* nodo);
	void setID(short int ID);
	void setName(string pName);
	void setPrimeraArista(pArista arista);
	void setGraphX(short int x);
	void setGraphY(short int y);
	void setGraphW(short int width);
	void setGraphH(short int height);
};
typedef Nodo* pNodo;

class ListaAdyacencia {
private:
	pNodo primero;
private:
	void cargarGrafo();
	void guardarGrafo();
public:
	ListaAdyacencia();
	~ListaAdyacencia();
	pNodo getPrimero();
	void setPrimero(pNodo nodo);
	void cargarKGML();
	void verRutas();
	void compararRutas();
	void inspeccionar();
	void generarGrafico();
};
typedef ListaAdyacencia* pListaAdyacencia;
#endif
