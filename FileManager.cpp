#include "Clases.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

FileManager::FileManager(){

}

void FileManager::leerArchivo(string filename, deque <pListaAdyacencia> lista){
	ifstream input;
	
	input.open(filename.c_str());
	while (input.fail()){
		input.clear();
		cout << "No se pudo abrir el archivo. Por favor escriba un nombre valido: ";
		cin >> filename;
		input.open(filename.c_str());
	}
		
		string line;
		string lineOriginal;
		string temp;
		pListaAdyacencia raizGrafo = new ListaAdyacencia;
		pArista arista = new Arista;
		pNodo nodo = new Nodo;
		raizGrafo->setPrimero(nodo);
		raizGrafo->getPrimero()->setPrimeraArista(arista);
		pNodo nodoTemp = raizGrafo->getPrimero();
		pArista aristaTemp = raizGrafo->getPrimero()->getPrimeraArista();
		fstream myfile;
		
		myfile.open(filename);
		
		while(std::getline(myfile, line)){
			
			if (line.find("pathway name") != string::npos){
				
					// se pone el nombre de la ruta al grafo de la ruta
					lineOriginal = line;
					int startPos = line.find("name");	// necesito hacer esto para todos los elementos necesarios del grafo usando algun tipo de loop
					temp = line.substr(startPos+6);
					int endPos = temp.find('"');
					string finalString = temp.substr(0,endPos);
					raizGrafo->setName(finalString);
					line = lineOriginal;
					
					startPos = line.find("org");
					temp = line.substr(startPos+5);
					endPos = temp.find('"');
					finalString = temp.substr(0,endPos);
					raizGrafo->setOrg(finalString);
					line = lineOriginal;
					
					startPos = line.find("number");
					temp = line.substr(startPos+8);
					endPos = temp.find('"');
					finalString = temp.substr(0,endPos);
					raizGrafo->setNumber(finalString);
			}
			
			if (line.find("title") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("title");
				temp = line.substr(startPos+7);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				raizGrafo->setTitle(finalString);
			}
			
			if (line.find("image") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("image");
				temp = line.substr(startPos+7);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				raizGrafo->setImage(finalString);
			}
			
			if (line.find("show_pathway") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("link");
				temp = line.substr(startPos+6);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				raizGrafo->setLink(finalString);
			}
			
			if (line.find("entry id") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("entry id");
				temp = line.substr(startPos + 10);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				nodoTemp->setID(finalString);
				string strNodo = nodoTemp->getID();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("name");
				temp = line.substr(startPos + 6);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				nodoTemp->setName(finalString);
				strNodo = nodoTemp->getName();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("type");
				temp = line.substr(startPos + 6);
				endPos = temp.find('"');
				finalString = temp.substr(0,endPos);
				nodoTemp->setType(finalString);
				strNodo = nodoTemp->getType();
				cout << strNodo << std::endl;
				
				if (line.find("reaction") == string::npos){
					nodoTemp->setReaction("No tiene reaccion");
				}
				else if (line.find("reaction") != string::npos){
					line = lineOriginal;
					startPos = line.find("reaction");
					temp = line.substr(startPos + 10);
					endPos = temp.find('"');
					finalString = temp.substr(0,endPos);
					nodoTemp->setReaction(finalString);
					strNodo = nodoTemp->getReaction();
					cout << strNodo << std::endl;
				}
				
				
			}
			
			if (line.find("show_pathway") == string::npos && line.find("link") != string::npos){
				
				int startPos = line.find("link");
				temp = line.substr(startPos + 6);
				int endPos =  temp.find('"');
				string finalString = temp.substr(0,endPos);
				nodoTemp->setLink(finalString);
				string strNodo = nodoTemp->getLink();
				cout << strNodo << std::endl;
				line = lineOriginal;
			}
			
			if (line.find("graphics name") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("graphics name");
				temp = line.substr(startPos + 15);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				nodoTemp->setGraphicsName(finalString);
				string strNodo = nodoTemp->getGraphicsName();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("fgcolor");
				temp = line.substr(startPos + 9);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				nodoTemp->setFgColor(finalString);
			    strNodo = nodoTemp->getFgColor();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("bgcolor");
				temp = line.substr(startPos + 9);
				endPos = temp.find('"');
				finalString = temp.substr(0,endPos);
				nodoTemp->setBgColor(finalString);
				strNodo = nodoTemp->getBgColor();
				cout << strNodo << std::endl;
				
			}
			
			if (line.find("width") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("type=");
				temp = line.substr(startPos + 6);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				nodoTemp->setGraphicsType(finalString);
				string strNodo = nodoTemp->getGraphicsType();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("x=");
				temp = line.substr(startPos + 3);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				nodoTemp->setGraphX(stoi(finalString));
			    int intNodo = nodoTemp->getGraphX();
				cout << intNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("y=");
				temp = line.substr(startPos+3);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				nodoTemp->setGraphY(stoi(finalString));
				intNodo = nodoTemp->getGraphY();
				cout << intNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("width=");
				temp = line.substr(startPos+7);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				nodoTemp->setGraphW(stoi(finalString));
				intNodo = nodoTemp->getGraphW();
				cout << intNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("height=");
				temp = line.substr(startPos+8);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				nodoTemp->setGraphH(stoi(finalString));
				intNodo = nodoTemp->getGraphH();
				cout << intNodo << std::endl;
				
				cout << "\nNodo agregado. Datos del nodo:\n" << std::endl;
				
				cout << "Numero de identificacion: ";
				strNodo = nodoTemp->getID();
				cout << strNodo << std::endl;
				
				cout << "Nombre: ";
				strNodo = nodoTemp->getName();
				cout << strNodo << std::endl;
				
				cout << "Tipo: ";
				cout << nodoTemp->getType() << std::endl;
				
				cout << "Reaccion: ";
				cout << nodoTemp->getReaction() << std::endl;
				
				cout << "Link: ";
				cout << nodoTemp->getLink() << std::endl;
				
				cout << "Nombre de graficos: ";
				cout << nodoTemp->getGraphicsName() << std::endl;
				
				cout << "Color de primer plano: ";
				cout << nodoTemp->getFgColor() << std::endl;
				
				cout << "Color de fondo: ";
				cout << nodoTemp->getBgColor() << std::endl;
				
				cout << "Tipo grafico: ";
				cout << nodoTemp->getGraphicsType() << std::endl;
				
				cout << "X: ";
				cout << nodoTemp->getGraphX() << std::endl;
				
				cout << "Y: ";
				cout << nodoTemp->getGraphY() << std::endl;
				
				cout << "Ancho: ";
				cout << nodoTemp->getGraphW() << std::endl;
				
				cout << "Altura: ";
				cout << nodoTemp->getGraphH() << std::endl;
				
				pNodo nodoNuevo = new Nodo;
				nodoTemp->setSiguiente(nodoNuevo);
				nodoTemp = nodoTemp->getSiguiente();
			}

			if (line.find("relation entry") != string::npos){
				nodoTemp = raizGrafo->getPrimero();	// se resetea la posicion del nodo auxiliar para poder revisar todos los nodos para ponerle el arista apropiado a su nodo respectivo
				cout << nodoTemp->getName() << std::endl;
				
				lineOriginal = line;
				int startPos = line.find("entry1=");
				temp = line.substr(startPos + 8);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				aristaTemp->setID1(finalString);
				string strNodo = aristaTemp->getID1();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("entry2=");
				temp = line.substr(startPos + 8);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				aristaTemp->setID2(finalString);
				strNodo = aristaTemp->getID2();
				cout << strNodo << std::endl;
				
				while (nodoTemp->getName() != ""){
					//cout  << "prueba" <<  std::endl;
					
					if (nodoTemp->getID() == aristaTemp->getID2()){
						aristaTemp->setDestino(nodoTemp);
						cout << "Destino puesto." << std::endl;
					}
					
					nodoTemp = nodoTemp->getSiguiente();
				}
				break;

			}
			
			if (line.find("subtype name") != string::npos){
				nodoTemp = raizGrafo->getPrimero();	// se resetea la posicion del nodo auxiliar para poder revisar todos los nodos para ponerle el arista apropiado a su nodo respectivo
				
				lineOriginal = line;
				int startPos = line.find("name=");
				temp = line.substr(startPos + 6);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				aristaTemp->setSubType(finalString);
				string strNodo = aristaTemp->getSubType();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("value=");
				temp = line.substr(startPos + 7);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				aristaTemp->setValue(finalString);
				strNodo = aristaTemp->getValue();
				cout << strNodo << std::endl;

				break;
			}
			
		}
		lista.emplace_back(raizGrafo);
			
		std::cout << "\nRuta agregada. Datos de la ruta:\n" << std::endl;
		std::cout << "Nombre: ";
		std::cout << raizGrafo->getName() << std::endl;
		std::cout << "Org: ";
		std::cout << raizGrafo->getOrg() << std::endl;
		std::cout << "Numero: ";
		std::cout << raizGrafo->getNumber() << std::endl;
		std::cout << "Titulo: ";
		std::cout << raizGrafo->getTitle() << std::endl;
		std::cout << "Imagen: ";
		std::cout << raizGrafo->getImage() << std::endl;
		std::cout << "Link: ";
		std::cout << raizGrafo->getLink() << std::endl;
		
		myfile.close();
	    input.close();
	
return;
}
