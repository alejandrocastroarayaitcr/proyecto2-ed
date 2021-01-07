#ifndef CLASES_H_
#define CLASES_H_

#include <iostream>
#include <fstream>
#include <string>

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
	string type;
	string link;
	string reaction;
	bool visitado;
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
	string getType();
	string getLink();
	string getReaction();
	bool getVisitado();
	pArista getPrimeraArista();
	short int getGraphX();
	short int getGraphY();
	short int getGraphW();
	short int getGraphH();
	void setSiguiente(Nodo* nodo);
	void setID(short int ID);
	void setName(string pName);
	void setType(string pType);
	void setLink(string pLink);
	void setVisitado(bool pVisitado);
	void setReaction(string pReaction);
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
	string name;
	string org;
	string number;
	string title;
	string image;
private:
	void cargarGrafo();
	void guardarGrafo();
	void putAllNotVisitados();
public:
	ListaAdyacencia();
	~ListaAdyacencia();
	pNodo getPrimero();
	string getName();
	string getOrg();
	string getNumber();
	string getTitle();
	string getImage();
	void setPrimero(pNodo nodo);
	void setName(string name);
	void setOrg(string org);
	void setNumber(string number);
	void setTitle(string title);
	void setImage(string image);
	void cargarKGML();
	void verRutas();
	deque<pNodo> makeLineal();
	void inspeccionar();
	void generarGrafico();
};
typedef ListaAdyacencia* pListaAdyacencia;

class FileManager {
public:
	FileManager();
	void leerArchivo(string filename);
};
	
#endif
