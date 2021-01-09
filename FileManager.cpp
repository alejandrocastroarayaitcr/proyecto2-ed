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
		string lineOriginal;
		string temp;
		ListaAdyacencia raizGrafo;
		pNodo nodo = new Nodo;
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
			
			if (line.find("link") != string::npos){
				
				lineOriginal = line;
				int startPos = line.find("link");
				temp = line.substr(startPos+6);
				int endPos = temp.find('"');
				string finalString = temp.substr(0,endPos);
				raizGrafo.setLink(finalString);
				break;
			}
			
		}
			
			
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
