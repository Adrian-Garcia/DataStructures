#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	map<string, int> miMap; 	//Map
	int n, edad; 				//Numero de datos y edad
	string nom;					//Nombre 

	//Pedimos tamanio de datos a buscar
	cout << "n: ";
	cin >> n;

	cout << "Nombre, edad" << endl;
	
	//Pedimos los datos
	for (int i=1; i<=n; i++) {
		cout << i << ": ";
		cin >> nom >> edad;
		pair<string, int> miPar(nom, edad);
		miMap.insert(miPar);
	}

	//Pedimos un nombre a buscar
	cout << "\nDar el nombre a buscar: ";
	cin >> nom;

	//Buscamos el nombre en el map
	map<string, int>::iterator it = miMap.find(nom);

	//Busca el nombre
	if (it != miMap.end()) {
		cout << (*it).second << endl;
	}
	else {
		cout << "No esta";
	}

	cout << endl;
	
	//Despliega los datos
	for (it=miMap.begin(); it!=miMap.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	//Termina programa
	return 0;
}
