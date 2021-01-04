#include "Clases.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string filename;
	cout << "Escriba el nombre del archivo: ";
	cin >> filename;
	
	FileManager manager;
	manager.leerArchivo(filename);
	cout << "Prueba de main" << endl;

}
