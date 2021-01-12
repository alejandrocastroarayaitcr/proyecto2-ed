#include "FileManager.cpp"

using namespace std;

deque<pListaAdyacencia> listaRutas; //Lista principal de las rutas


void mostrar_menu(){ // Esta funcion muestra el menu del programa
	
	cout << "\n=================================================\n\t\tMenú:\n=================================================" << endl;
	cout << "1.- Registrar KGML" << endl;
	cout << "2.- Ver rutas disponibles" << endl;
	cout << "3.- Comparar rutas" << endl;
	cout << "4.- Generar grafo" << endl;
	cout << "5.- Modo Inspeccionar" << endl;
	cout << "6.- Salir\n" << endl;
	
	cout << "Escoja una opción: " << std::flush;
	
}

pListaAdyacencia buscarRuta(deque<pListaAdyacencia> lista, string pNombre){
	for(unsigned int i=0; i<lista.size(); i++){
		if(lista.at(i)->getName() == pNombre)return lista.at(i);
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

void comparar_rutas(deque<pListaAdyacencia> lista){
	string nombreRuta1, nombreRuta2;
	cout << "\nEscriba el nombre de la primera ruta: " << std::flush;
	cin >> nombreRuta1;
	cout << "\nEscriba el nombre de la segunda ruta: " << std::flush;
	cin >> nombreRuta2;
	pListaAdyacencia ruta1, ruta2;
	ruta1 = buscarRuta(lista,nombreRuta1);
	ruta2 = buscarRuta(lista,nombreRuta2);
	if(ruta1 == NULL || ruta2 == NULL){
		cout << "No se encontró ruta con el nombre ingresado" << endl;
	}else{
		cout << "Lineal" << endl;
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
		for(int x=0;x<rutaLineal2.size();x++){
			for(int y=0;y<rutaLineal1.size();y++){
				if(x==0 || y==0){
					matriz[x][y] = 0;
				}else{
					if(rutaLineal1.at(y)->getName() == rutaLineal2.at(x)->getName()){
						matriz[x][y] = max(matriz[x-1][y-1]+1,max(matriz[x-1][y]-2,matriz[x][y-1]-2));
					}else{
						matriz[x][y] = max(matriz[x-1][y-1]-1,max(matriz[x-1][y]-2,matriz[x][y-1]-2));
					}
				}
			cout << matriz[x][y];
			}
		cout << endl;
		}
		//Algoritmo 2
	}
}

void ver_rutas(deque<pListaAdyacencia> listaRutas){
	
	cout << "\nLa cantidad de  rutas disponibles actualmente es: ";
	cout << listaRutas.size() <<  endl; // prueba
	cout << "Las rutas guardadas disponibles actualmente son:" << endl;
	
	for (int i = 0; i < listaRutas.size(); i++){
		pNodo nodoTemp = listaRutas.at(i)->getPrimero();
		
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
		cout << "URL Ruta: " << std::flush;
		cout << listaRutas.at(i)->getLink() << endl;
		cout << "-------------------------------------------------------------------\n" << endl;
		
		cout << "Desea ver los nodos de esta ruta? S/N: " << std::flush;
		string respuesta;
		cin >> respuesta;
		if (respuesta == "s" || respuesta == "S"){
			int contNodo = 1;
			while (nodoTemp->getName() != ""){
				
			cout << "\n\t\t\tNodo " << std::flush;
			cout << contNodo << std::flush;
			cout << ":" << endl;
			
			cout << "-------------------------------------------------------------------" << endl;
			cout << "Numero de identificacion: ";
			string strNodo = nodoTemp->getID();
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
			
			if (nodoTemp->getPrimeraArista() != NULL){
				
				pArista aristaTemp = nodoTemp->getPrimeraArista();
				int contArista  = 1;
				while (aristaTemp->getID1() != ""){
					
					cout << "\n\t\tDatos de arista ";
					cout << contArista << std::endl;
					
					cout << "Entry ID 1 de arista: ";
					cout << aristaTemp->getID1() << std::endl;
					
					cout << "Entry ID 2 de arista: ";
					cout << aristaTemp->getID2() << std::endl;
					
					cout << "Tipo del arista: ";
					cout << aristaTemp->getType() << std::endl;
					
					cout << "Subtipo del arista: ";
					cout << aristaTemp->getSubType() << std::endl;
					
					cout << "Valor del arista: ";
					cout << aristaTemp->getValue() << std::endl;
					
					cout << "Nombre del nodo destino del arista: ";
					cout << aristaTemp->getDestino()->getName() << std::endl;
					
					contArista = contArista + 1;
					aristaTemp = aristaTemp->getSiguiente();
				}
			}
			cout << "-------------------------------------------------------------------\n" << endl;
			
			contNodo = contNodo + 1;
			nodoTemp = nodoTemp->getSiguiente();
			}
			
		}
		
	}
	
	cout << "Se ha terminado de desplegar las rutas y sus datos.\n" << std::endl;
}

void modo_inspeccionar(deque<pListaAdyacencia> listaRutas){
	
	pNodo tempNodo;
	pListaAdyacencia tempGrafo;
	
	cout << "\n|--------------------------------Reporte------------------------------------------------|" << endl;
	cout << "|                                                                                       |";
	cout << "\n|-----------------------------listaRutas------------------------------------------------|" << endl;
	cout << "| listaRutas: \t" << std::flush;
	cout <<  sizeof(listaRutas);
	cout << " bytes\t\t\tDireccion hexadecimal -> ";
	cout << &listaRutas;
	cout << " |" << endl;
		for (int i = 0; i < listaRutas.size(); i++){
			
			cout << "| pListaAdyacencia: \t" << std::flush;
			cout <<  sizeof(listaRutas.at(i));
			cout << " bytes\t\t\tDireccion hexadecimal -> ";
			cout << listaRutas.at(i);
			cout << " |" << endl;
			
		}
	cout << "|---------------------------------------------------------------------------------------|" << endl;
	
	for (int i = 0; i < listaRutas.size(); i++){
		
		cout << "|                                                                                       |";
		cout << "\n|-----------------------------pListaAdyacencia------------------------------------------|" << endl;
		cout << "| pListaAdyacencia: \t" << std::flush;
		cout << sizeof(listaRutas.at(i));
		cout << " bytes\t\t\tDireccion hexadecimal -> ";
		cout << listaRutas.at(i);
		cout << " | " <<  endl;
		
		cout << "| name: \t" << std::flush;
		cout << sizeof(listaRutas.at(i)->getName());
		cout << " bytes\t\t\tDireccion hexadecimal -> ";
		string graphString = listaRutas.at(i)->getName();
		cout << &graphString;
		cout << " | " <<  endl;
		
		cout << "| org: \t\t" << std::flush;
		cout << sizeof(listaRutas.at(i)->getOrg());
		cout << " bytes\t\t\tDireccion hexadecimal -> ";
		graphString = listaRutas.at(i)->getOrg();
		cout << &graphString;
		cout << " | " <<  endl;
		
		cout << "| number: \t" << std::flush;
		cout << sizeof(listaRutas.at(i)->getNumber());
		cout << " bytes\t\t\tDireccion hexadecimal -> ";
		graphString = listaRutas.at(i)->getNumber();
		cout << &graphString;
		cout << " | " <<  endl;
		
		cout << "| title: \t" << std::flush;
		cout << sizeof(listaRutas.at(i)->getTitle());
		cout << " bytes\t\t\tDireccion hexadecimal -> ";
		graphString = listaRutas.at(i)->getTitle();
		cout << &graphString;
		cout << " | " <<  endl;
		
		cout << "| image: \t" << std::flush;
		cout << sizeof(listaRutas.at(i)->getImage());
		cout << " bytes\t\t\tDireccion hexadecimal -> ";
		graphString = listaRutas.at(i)->getImage();
		cout << &graphString;
		cout << " | " <<  endl;
		
		cout << "| link: \t" << std::flush;
		cout << sizeof(listaRutas.at(i)->getLink());
		cout << " bytes\t\t\tDireccion hexadecimal -> ";
		graphString = listaRutas.at(i)->getLink();
		cout << &graphString;
		cout << " | " <<  endl;
			
		cout << "| primero: \t" << std::flush;
		cout << sizeof(listaRutas.at(i)->getPrimero());
		cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
		cout << listaRutas.at(i)->getPrimero();
		cout << " | " <<  endl;

	cout << "|---------------------------------------------------------------------------------------|" << endl;
	
	}
	
	for (int i = 0; i < listaRutas.size(); i++){
		
		pNodo nodoTemp = listaRutas.at(i)->getPrimero();
		while (nodoTemp->getName() != ""){
			
			pArista aristaTemp = nodoTemp->getPrimeraArista();
			
			if (aristaTemp != NULL){
				
				while (aristaTemp != NULL){
					if (aristaTemp->getSiguiente() == 0){
						
						aristaTemp = aristaTemp->getSiguiente();
					}
					
					else{
						
						cout << "|                                                                                       |";
					cout << "\n|----------------------------pArista----------------------------------------------------|" << endl;
					
					cout << "| Arista: \t" << std::flush;
					cout << sizeof(aristaTemp);
					cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
					cout << aristaTemp;
					cout << " | " <<  endl;
					
					cout << "| siguiente: \t" << std::flush;
					cout << sizeof(aristaTemp->getSiguiente());
					cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
					cout << aristaTemp->getSiguiente();
					cout << " | " <<  endl;

					cout << "| ID1: \t" << std::flush;
					cout << sizeof(aristaTemp->getID1());
					cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
					cout << aristaTemp->getID1();
					
					cout << " \t\t| " <<  endl;
					
					cout << "| ID2: \t" << std::flush;
					cout << sizeof(aristaTemp->getID2());
					cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
					cout << aristaTemp->getID2();
					cout << " \t\t| " <<  endl;
					
					cout << "| type: \t" << std::flush;
					cout << sizeof(aristaTemp->getType());
					cout << " bytes\t\t\tDireccion hexadecimal -> ";
					cout << aristaTemp->getType();
					cout << " \t\t| " <<  endl;
					
					cout << "| subType: \t" << std::flush;
					cout << sizeof(aristaTemp->getSubType());
					cout << " bytes\t\t\tDireccion hexadecimal -> ";
					cout << aristaTemp->getSubType();
					cout << " \t| " <<  endl;
					
					cout << "| value: \t" << std::flush;
					cout << sizeof(aristaTemp->getValue());
					cout << " bytes\t\t\tDireccion hexadecimal -> ";
					cout << aristaTemp->getValue();
					cout << " \t\t| " <<  endl;
					
					cout << "| destino: \t" << std::flush;
					cout << sizeof(aristaTemp->getDestino());
					cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
					cout << aristaTemp->getDestino();
					cout << " | " <<  endl;
					
					cout << "|---------------------------------------------------------------------------------------|" << endl;
					
					aristaTemp = aristaTemp->getSiguiente();
						
					}
					
					
					
				}
				
			}
			nodoTemp = nodoTemp->getSiguiente();
		}
		
	}
	
	for (int i = 0; i < listaRutas.size(); i++){
		
		pNodo nodoTemp = listaRutas.at(i)->getPrimero();
		while (nodoTemp->getName() != ""){
			
			cout << "|                                                                                       |";
			cout << "\n|-----------------------------pNodo-----------------------------------------------------|" << endl;
					
			cout << "| pNodo: \t" << std::flush;
			cout << sizeof(nodoTemp);
			cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
			cout << nodoTemp;
			cout << " | " <<  endl;
			
			cout << "| siguiente: \t" << std::flush;
			cout << sizeof(nodoTemp->getSiguiente());
			cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
			cout << nodoTemp->getSiguiente();
			cout << " | " <<  endl;
			
			cout << "| ID: \t" << std::flush;
			cout << sizeof(nodoTemp->getID());
			cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
			string nodoString = nodoTemp->getID();
			cout << &nodoString;
			cout << " | " <<  endl;
			
			cout << "| name: \t" << std::flush;
			cout << sizeof(nodoTemp->getName());
			cout << " bytes\t\t\tDireccion hexadecimal -> ";
			nodoString = nodoTemp->getName();
			cout << &nodoString;
			cout << " | " <<  endl;
			
			cout << "| type: \t" << std::flush;
			cout << sizeof(nodoTemp->getType());
			cout << " bytes\t\t\tDireccion hexadecimal -> ";
			nodoString = nodoTemp->getType();
			cout << &nodoString;
			cout << " | " <<  endl;
			
			cout << "| link: \t" << std::flush;
			cout << sizeof(nodoTemp->getLink());
			cout << " bytes\t\t\tDireccion hexadecimal -> ";
			nodoString = nodoTemp->getLink();
			cout << &nodoString;
			cout << " | " <<  endl;
			
			cout << "| reaction: \t" << std::flush;
			cout << sizeof(nodoTemp->getReaction());
			cout << " bytes\t\t\tDireccion hexadecimal -> ";
			nodoString = nodoTemp->getReaction();
			cout << &nodoString;
			cout << " | " <<  endl;
			
			cout << "| visitado: \t" << std::flush;
			cout << sizeof(nodoTemp->getVisitado());
			cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
			bool nodoBool = nodoTemp->getVisitado();
			cout << &nodoBool;
			cout << " | " <<  endl;
			
			if (nodoTemp->getPrimeraArista() != NULL){
				
				cout << "| primeraArista: \t" << std::flush;
				cout << sizeof(nodoTemp->getPrimeraArista());
				cout << " bytes\t\t\tDireccion hexadecimal -> ";
				cout << nodoTemp->getPrimeraArista();
				cout << " | " <<  endl;
				
			}
			else if (nodoTemp->getPrimeraArista() == NULL){
				
				cout << "| primeraArista: " << std::flush;
				cout << "No tiene arista";
				cout << " \t\tDireccion hexadecimal -> ";
				cout << "No tiene arista";
				cout << "| " <<  endl;
				
			}
			
			cout << "| graphicsName: \t" << std::flush;
			cout << sizeof(nodoTemp->getGraphicsName());
			cout << " bytes\t\tDireccion hexadecimal -> ";
			nodoString = nodoTemp->getGraphicsName();
			cout << &nodoString;
			cout << " | " <<  endl;
			
			cout << "| fgColor: \t" << std::flush;
			cout << sizeof(nodoTemp->getFgColor());
			cout << " bytes\t\t\tDireccion hexadecimal -> ";
			nodoString = nodoTemp->getFgColor();
			cout << &nodoString;
			cout << " | " <<  endl;
			
			cout << "| bgColor: \t" << std::flush;
			cout << sizeof(nodoTemp->getBgColor());
			cout << " bytes\t\t\tDireccion hexadecimal -> ";
			nodoString = nodoTemp->getBgColor();
			cout << &nodoString;
			cout << " | " <<  endl;
			
			cout << "| graphicsType: \t" << std::flush;
			cout << sizeof(nodoTemp->getGraphicsType());
			cout << " bytes\t\tDireccion hexadecimal -> ";
			nodoString = nodoTemp->getGraphicsType();
			cout << &nodoString;
			cout << " | " <<  endl;
			
			cout << "| graphX: \t" << std::flush;
			cout << sizeof(nodoTemp->getGraphX());
			cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
			short int nodoInt = nodoTemp->getGraphX();
			cout << &nodoInt;
			cout << " | " <<  endl;
			
			cout << "| graphY: \t" << std::flush;
			cout << sizeof(nodoTemp->getGraphY());
			cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
			nodoInt = nodoTemp->getGraphY();
			cout << &nodoInt;
			cout << " | " <<  endl;
			
			cout << "| graphW: \t" << std::flush;
			cout << sizeof(nodoTemp->getGraphW());
			cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
			nodoInt = nodoTemp->getGraphW();
			cout << &nodoInt;
			cout << " | " <<  endl;
			
			cout << "| graphH: \t" << std::flush;
			cout << sizeof(nodoTemp->getGraphH());
			cout << " bytes\t\t\t\tDireccion hexadecimal -> ";
			nodoInt = nodoTemp->getGraphH();
			cout << &nodoInt;
			cout << " | " <<  endl;

			cout << "|---------------------------------------------------------------------------------------|" << endl;
					
			nodoTemp = nodoTemp->getSiguiente();
		}
		
	}
	
	cout << "\n";
	cout << "Se ha terminado de desplegar el reporte.\n" << std::endl;
}

void generar_grafico(deque<pListaAdyacencia> listaRutas){
	
	if (listaRutas.size() == 0){
		
		cout << "\nLa lista de rutas esta vacia!" << std::endl;
		return;
		
	}
	
	string rutaEscogida;
	
	cout << "\n";
	for (int i = 0; i < listaRutas.size(); i++){
		
		int numRuta = i + 1;
		cout << numRuta;
		cout << ". ";
		cout << listaRutas.at(i)->getName() << endl;
		
	}
	
	cout << "\nPor favor escriba el numero de la ruta que desea generar: ";
	cin >> rutaEscogida;
	cout << "\n";
	cout << "Ha escogida la ruta ";
	cout << rutaEscogida << endl;
	int rutaInt = stoi(rutaEscogida);
	rutaInt = rutaInt - 1;
	
	cout << "\n";
	
	cout << "------------------------------------------------------------Inicio de ruta------------------------------------------------------------------\n" << endl;
	pListaAdyacencia grafo = listaRutas.at(rutaInt);
	pNodo nodoTemp = grafo->getPrimero();
	
	while (nodoTemp->getName() != ""){
		pArista aristaTemp = nodoTemp->getPrimeraArista();
		
		cout << nodoTemp->getName();
		
		
		if (aristaTemp != NULL){
			
			while (aristaTemp != NULL){
				
				if (aristaTemp->getDestino() == 0){
					break;
				}
				
				cout << " ---> ";
				cout << aristaTemp->getDestino()->getName();
				cout << " | ";
				
				aristaTemp = aristaTemp->getSiguiente();
			}
			
			cout << "\n";
				
		}
		else if (aristaTemp == NULL){
			
			cout << "\n";
		}
		cout << "\n";
		nodoTemp = nodoTemp->getSiguiente();
	}
	cout << "------------------------------------------------------------Fin de ruta---------------------------------------------------------------------\n" << endl;
}

int main(){
	char opcion;

	do {
		mostrar_menu();
		cin >> opcion;
			switch ( opcion ) { // Usa un switch para elegir que sucede dependiendo de la opcion escogida
				case '1': registrarKGML(listaRutas); break;
				case '2': ver_rutas(listaRutas); break;
				case '3': comparar_rutas(listaRutas); break;
				case '4': generar_grafico(listaRutas); break;
				case '5': modo_inspeccionar(listaRutas); break;
				case '6': exit(1);
				default:
					printf( "\nOpción no válida. Por favor intente de nuevo.\n" );
						break;
		}
	} while (opcion!='6');

}
