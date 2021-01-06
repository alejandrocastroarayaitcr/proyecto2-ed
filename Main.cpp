#include "Clases.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void mostrar_menu(){ // Esta funcion muestra el menu del programa
	
	cout << "\n\t\tMenú:\n================================" << endl;
	cout << "1.- Registrar KGML" << endl;
	cout << "2.- Ver rutas disponibles" << endl;
	cout << "3.- Comparar rutas" << endl;
	cout << "4.- Generar grafo" << endl;
	cout << "5.- Modo Inspeccionar" << endl;
	cout << "6.- Salir\n" << endl;
	
	cout << "Escoja una opción: " << std::flush;
	
}

void registrarKGML(){
	
	string filename;
	cout << "\nEscriba el nombre del archivo: " << std::flush;
	cin >> filename;
	
	FileManager manager;
	manager.leerArchivo(filename);
	
}

int main(){
	char opcion;
	do {
		mostrar_menu();
		cin >> opcion;
			switch ( opcion ) { // Usa un switch para elegir que sucede dependiendo de la opcion escogida
				case '1': registrarKGML(); break;
				//case '2': ver_rutas(); break;
				//case '3': comparar_rutas(); break;
				//case '4': generar_grafico(); break;
				//case '5': modo_inspeccionar(); break;
				case '6': exit(1);
				default:
					printf( "\nOpción no válida. Por favor intente de nuevo.\n" );
						break;
		}
	} while (opcion!='8');

}
