#include "Clases.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

FileManager::FileManager(){

}

void FileManager::leerArchivo(string filename, deque <ListaAdyacencia> lista){
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
		ListaAdyacencia raizGrafo;
		pNodo nodo = new Nodo;
		raizGrafo.setPrimero(nodo);
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
					raizGrafo.setName(finalString);
					line = lineOriginal;
					
					startPos = line.find("org");
					temp = line.substr(startPos+5);
					endPos = temp.find('"');
					finalString = temp.substr(0,endPos);
					raizGrafo.setOrg(finalString);
					line = lineOriginal;
					
					startPos = line.find("number");
					temp = line.substr(startPos+8);
					endPos = temp.find('"');
					finalString = temp.substr(0,endPos);
					raizGrafo.setNumber(finalString);
			}
			
			if (line.find("title") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("title");
				temp = line.substr(startPos+7);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				raizGrafo.setTitle(finalString);
			}
			
			if (line.find("image") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("image");
				temp = line.substr(startPos+7);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				raizGrafo.setImage(finalString);
			}
			
			if (line.find("show_pathway") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("link");
				temp = line.substr(startPos+6);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				raizGrafo.setLink(finalString);
			}
			
			if (line.find("entry id") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("entry id");
				temp = line.substr(startPos + 10);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setID(stoi(finalString));
				int intNodo = raizGrafo.getPrimero()->getID();
				cout << intNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("name");
				temp = line.substr(startPos + 6);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setName(finalString);
				string strNodo = raizGrafo.getPrimero()->getName();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("type");
				temp = line.substr(startPos + 6);
				endPos = temp.find('"');
				finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setType(finalString);
				strNodo = raizGrafo.getPrimero()->getType();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("reaction");
				temp = line.substr(startPos + 10);
				endPos = temp.find('"');
				finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setReaction(finalString);
				strNodo = raizGrafo.getPrimero()->getReaction();
				cout << strNodo << std::endl;
			}
			
			if (line.find("show_pathway") == string::npos && line.find("link") != string::npos){
				
				int startPos = line.find("link");
				temp = line.substr(startPos + 6);
				int endPos =  temp.find('"');
				string finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setLink(finalString);
				string strNodo = raizGrafo.getPrimero()->getLink();
				cout << strNodo << std::endl;
				line = lineOriginal;
			}
			
			if (line.find("graphics name") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("graphics name");
				temp = line.substr(startPos + 15);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setGraphicsName(finalString);
				string strNodo = raizGrafo.getPrimero()->getGraphicsName();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("fgcolor");
				temp = line.substr(startPos + 9);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setFgColor(finalString);
			    strNodo = raizGrafo.getPrimero()->getFgColor();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("bgcolor");
				temp = line.substr(startPos + 9);
				endPos = temp.find('"');
				finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setBgColor(finalString);
				strNodo = raizGrafo.getPrimero()->getBgColor();
				cout << strNodo << std::endl;
				
			}
			
			if (line.find("width") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("type=");
				temp = line.substr(startPos + 6);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setType(finalString);
				string strNodo = raizGrafo.getPrimero()->getType();
				cout << strNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("x=");
				temp = line.substr(startPos + 3);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setGraphX(stoi(finalString));
			    int intNodo = raizGrafo.getPrimero()->getGraphX();
				cout << intNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("y=");
				temp = line.substr(startPos+3);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setGraphY(stoi(finalString));
				intNodo = raizGrafo.getPrimero()->getGraphY();
				cout << intNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("width=");
				temp = line.substr(startPos+7);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setGraphW(stoi(finalString));
				intNodo = raizGrafo.getPrimero()->getGraphW();
				cout << intNodo << std::endl;
				
				line = lineOriginal;
				startPos = line.find("height=");
				temp = line.substr(startPos+8);
				endPos =  temp.find('"');
				finalString = temp.substr(0,endPos);
				raizGrafo.getPrimero()->setGraphH(stoi(finalString));
				intNodo = raizGrafo.getPrimero()->getGraphH();
				cout << intNodo << std::endl;
				
				cout << "\nNodo agregado. Datos del nodo:\n" << std::endl;
				
				cout << "Numero de identificacion: ";
				intNodo = raizGrafo.getPrimero()->getID();
				cout << intNodo << std::endl;
				
				cout << "Nombre: ";
				strNodo = raizGrafo.getPrimero()->getName();
				cout << strNodo << std::endl;
				
				cout << "Tipo: ";
				cout << raizGrafo.getPrimero()->getType() << std::endl;
				
				cout << "Reaccion: ";
				cout << raizGrafo.getPrimero()->getReaction() << std::endl;
				
				cout << "Link: ";
				cout << raizGrafo.getPrimero()->getLink() << std::endl;
				
				cout << "Nombre de graficos: ";
				cout << raizGrafo.getPrimero()->getGraphicsName() << std::endl;
				
				cout << "Color de primer plano: ";
				cout << raizGrafo.getPrimero()->getFgColor() << std::endl;
				
				cout << "Color de fondo: ";
				cout << raizGrafo.getPrimero()->getBgColor() << std::endl;
				
				cout << "Tipo grafico: ";
				cout << raizGrafo.getPrimero()->getType() << std::endl;
				
				cout << "X: ";
				cout << raizGrafo.getPrimero()->getGraphX() << std::endl;
				
				cout << "Y: ";
				cout << raizGrafo.getPrimero()->getGraphY() << std::endl;
				
				cout << "Ancho: ";
				cout << raizGrafo.getPrimero()->getGraphW() << std::endl;
				
				cout << "Altura: ";
				cout << raizGrafo.getPrimero()->getGraphH() << std::endl;
				
			}
			
			if (line.find("relation entry") != string::npos){
				
				break;
				
			}
			
		}
		lista.push_back(raizGrafo);
			
		std::cout << "\nRuta agregada. Datos de la ruta:\n" << std::endl;
		std::cout << "Nombre: ";
		std::cout << raizGrafo.getName() << std::endl;
		std::cout << "Org: ";
		std::cout << raizGrafo.getOrg() << std::endl;
		std::cout << "Numero: ";
		std::cout << raizGrafo.getNumber() << std::endl;
		std::cout << "Titulo: ";
		std::cout << raizGrafo.getTitle() << std::endl;
		std::cout << "Imagen: ";
		std::cout << raizGrafo.getImage() << std::endl;
		std::cout << "Link: ";
		std::cout << raizGrafo.getLink() << std::endl;
		
		myfile.close();
	    input.close();
	
return;
}
