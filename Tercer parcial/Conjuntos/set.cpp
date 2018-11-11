#include <iostream>
#include <set>

using namespace std;

int main() {

	set<int> miSet; 	//Set de datos
	int n, dato; 		//Numero de datos y datos

	//Pedimos tamanio de n
	cout << "n: ";
	cin >> n;

	//Insertamos datos en el set 
	for (int i=1; i<=n; i++) {
		cout << i << ": ";
		cin >> dato;
		miSet.insert(dato);
	}

	//Pedimos el dato a buscar
	cout << "\nDato a Buscar: ";
	cin >> dato;

	//Buscamos dato con un iterador
	set<int>::iterator it = miSet.find(dato);

	//Informamos si se encontro el dato
	if (it != miSet.end()) {
		cout << "Si esta" << endl;
	} else {
		cout << "No esta" << endl;
	}

	/* Tambien se puede poner como
	if (miSet.count(dato)) {}
	*/

	return 0;
}