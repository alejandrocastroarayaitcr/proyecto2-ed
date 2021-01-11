#include "Clases.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

deque<pListaAdyacencia> listaRutas; //Lista principal de las rutas


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

pListaAdyacencia buscarRuta(string pNombre){
	for(unsigned int i=0; i<listaRutas.size(); i++){
		if(listaRutas.at(i)->getName() == pNombre)return listaRutas.at(i);
	}
	return NULL;
}

void registrarKGML(deque<pListaAdyacencia> lista){
	
	string filename;
	cout << "\nEscriba el nombre del archivo: " << std::flush;
	cin >> filename;
	
	FileManager manager;
	pListaAdyacencia nuevoGrafo = manager.leerArchivo(filename,lista);
	listaRutas.push_back(nuevoGrafo);
	
}
/*
void comparar_rutas(){
	string nombreRuta1, nombreRuta2;
	cout << "\nEscriba el nombre de la primera ruta: " << std::flush;
	cin >> ruta1;
	cout << "\nEscriba el nombre de la segunda ruta: " << std::flush;
	cin >> ruta2;
	pListaAdyacencia ruta1, ruta2;
	ruta1 = buscarRuta(nombreRuta1);
	ruta2 = buscarRuta(nombreRuta2);
	if(ruta1 == NULL || ruta2 == NULL){
		cout << "No se encontró ruta con el nombre ingresado" << endl;
	}else{
		deque<pNodo> rutaLineal1, rutaLineal2;
		rutaLineal1 = ruta1->makeLineal();
		rutaLineal2 = ruta2->makeLineal();
		if(rutaLineal1.size() < rutaLineal2.size()){
			deque<pNodo> temp;
			temp = rutaLineal1;
			rutaLineal1 = rutaLineal2;
			rutaLineal2 = temp;
		}
		short int matriz[rutaLineal2.size()+1][rutaLineal1.size()+1];
		matriz[0][0] = 0;
		for(int i=1;i<rutaLineal1.size()){
			matriz[0][i] = 0;
		}
		for(int i=1;i<rutaLineal2.size()){
			matriz[i][0] = 0;
		}
		
		Algoritmo 1
		  alineamiento
		
	}
	Algoritmo 2
	  
	
}
*/

void ver_rutas(deque<pListaAdyacencia> listaRutas){
	
	cout << "\nLa cantidad de  rutas disponibles actualmente es: ";
	cout << listaRutas.size() <<  endl; // prueba
	cout << "Las rutas guardadas disponibles actualmente son:" << endl;
	
	for (int i = 0; i < listaRutas.size(); i++){
		int contador = i + 1;
		
		cout << "\n\t\t\tRuta " << std::flush;
		cout << contador << std::flush;
		cout << ":" << endl;
		
		cout << "-------------------------------------------------------------------" << endl;
		cout << "Nombre: " << std::flush;
		cout << listaRutas.at(i)->getName() << endl;
		cout << "Org: " << std::flush;
		cout << listaRutas.at(i)->getOrg() << endl;
		cout << "Numero: " << std::flush;
		cout << listaRutas.at(i)->getNumber() << endl;
		cout << "Titulo: " << std::flush;
		cout << listaRutas.at(i)->getTitle() << endl;
		cout << "URL Imagen: " << std::flush;
		cout << listaRutas.at(i)->getImage() << endl;
		cout << "URL Ruta:" << std::flush;
		cout << listaRutas.at(i)->getLink() << endl;
		cout << "-------------------------------------------------------------------\n" << endl;
		
	}
}

int main(){
	char opcion;

	do {
		mostrar_menu();
		cin >> opcion;
			switch ( opcion ) { // Usa un switch para elegir que sucede dependiendo de la opcion escogida
				case '1': registrarKGML(listaRutas); break;
				case '2': ver_rutas(listaRutas); break;
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
