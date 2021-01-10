#ifndef CLASES_H_
#define CLASES_H_

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>

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
	string graphicsName;
	string fgColor;
	string bgColor;
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
	string getGraphicsName();
	string getFgColor();
	string getBgColor();
	short int getGraphX();
	short int getGraphY();
	short int getGraphW();
	short int getGraphH();
	void setSiguiente(Nodo* nodo);
	void setID(short int ID);
	void setName(string pName);
	void setLink(string pLink);
	void setVisitado(bool pVisitado);
	void setReaction(string pReaction);
	void setPrimeraArista(pArista arista);
	void setGraphicsName(string graphicsName);
	void setFgColor(string fgColor);
	void setBgColor(string bgColor);
	void setType(string type);
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
	string link;
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
	string getLink();
	void setPrimero(pNodo nodo);
	void setName(string name);
	void setOrg(string org);
	void setNumber(string number);
	void setTitle(string title);
	void setImage(string image);
	void setLink(string link);
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
	void leerArchivo(string filename, deque<ListaAdyacencia> lista);
};
	
#endif
