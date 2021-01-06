#include "Clases.h"
#include <fstream>
#include <iostream>
#include <string>

FileManager::FileManager(){

}

void FileManager::leerArchivo(string filename){
	ifstream input;
	
	input.open(filename.c_str());
	while (input.fail()){
		input.clear();
		cout << "No se pudo abrir el archivo. Por favor escriba un nombre valido: ";
		cin >> filename;
		input.open(filename.c_str());
	}
		
		string line;
		string temp;
		ListaAdyacencia raizGrafo;
		pNodo nodo = new Nodo;
		fstream myfile;
		
		myfile.open(filename);
		
		while(std::getline(myfile, line)){
			
			if (line.find("pathway") != string::npos){
				
				if (line.find("name") != string::npos){	// se pone el nombre de la ruta al grafo de la ruta
					int startPos = line.find("name");	// necesito hacer esto para todos los elementos necesarios del grafo usando algun tipo de loop
					temp = line.substr(startPos+11);
					int endPos = temp.find('"');
					string finalString = temp.substr(0,endPos);
					raizGrafo.setName(finalString);
					std::cout << raizGrafo.getName() << std::endl;
					break;
					}
				
			}
			
		}
			
			
		
		
		
		myfile.close();
	input.close();
	
return;
}
