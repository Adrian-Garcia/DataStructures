#include "Listas.h"

int main() {
	
	cout << "Listas" << endl;
	
	bool uno;
	char opcion;
	Lista <int> nuevaLista;
	Lista <int> Lista;
	int elemento;

	do {
		
		cout << "Inserta una opcion" << endl;
		cout << "1. Agregar a la lista" << endl;
		cout << "2. Tener cantidad de arreglos de la lista" << endl;
		cout << "3. Obtener un dato de la lista segun el indie" << endl;
		cout << "5. Buscar un elemento" << endl;
		cout << "6. Ordenar Lista" << endl;
		cout << "7. Imprimir Lista" << endl;
		
		cout << "Opcion: ";
		cin >> opcion;
	
		switch (opcion) {
			case '1':
				cout << "Elemento: ";
				cin >> elemento;
				Lista.add(elemento);
				cout << endl;
			break;

			case '2':
				cout << "Cantidad: " << Lista.getCant();
				cout << endl;
			break;

			case '3':
				cout << "Inserta el indice: ";
				cin >> elemento;
				cout << endl << "Elemento: " << Lista.getDato(elemento);
			break;

			case '5':
				cout << "Inserta el elemento: ";
				cin >> elemento;
				cout << endl << "Indice: " << Lista.search(elemento);			
			break;

			case '6':
				cout << "Insera 1 o 0: ";
				cin >> uno;
				Lista.sort(uno);
				cout << endl;
			break;

			case '7':
				cout << "Imprimiendo" << endl;
				Lista.print();
				cout << endl;
			break;
		}
		
	} while(opcion != '0');
	
	nuevaLista = Lista;
	nuevaLista.add(1);
	
	if (nuevaLista == Lista) {
		cout << "Si";
	} else {
		cout << "NO";
	}
	
	
	return 0;
}
