#include "Clases.h"
#include <fstream>
#include <iostream>
#include <string>

FileManager::FileManager(){

}

void FileManager::leerArchivo(){
	string filename;
	ifstream input;
	
	cout << "Escriba el nombre del archivo: ";
	cin >> filename;
	input.open(filename.c_str());
	while (input.fail()){
		input.clear();
		cout << "No se pudo abrir el archivo. Por favor escriba un nombre valido: ";
		cin >> filename;
		input.open(filename.c_str());
	}
		
		string output;
		fstream myfile;
		
		myfile.open(filename);
		std::cout << std::ifstream(filename).rdbuf();
		myfile.close();
	input.close();
	
return;
}
