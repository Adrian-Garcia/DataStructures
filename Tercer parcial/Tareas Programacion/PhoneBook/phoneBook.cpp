#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

int main() {

	int n, num; 			//Numero de telefono y datos
	string query, name; 	//Solicitud y nombre

	map<int, string> data;	//Para almacenar datos
	queue<string> output;	//Fila con datos

	//Iterador para buscar
	map<int, string>::iterator it;

	//Pedimos numero de datos
	cin >> n;

	//Pedimos información
	for (int i=0; i<n; i++) {
		
		cin >> query;

		//Aniade numeros
		if (query == "add") {

			//Pedimos nombres
			cin >> num >> name;

			//Buscamos numero telefonico
			it = data.find(num);

			//Si encontramos el numero
			if (it != data.end()) {
				
				//Borramos el que estaba anteriormente
				data.erase(it);

				//Insertamos
				data.insert(pair <int, string> (num, name));
			}

			//Si no lo encontramos
			else {
				
				//Insertamos
				data.insert(pair <int, string> (num, name));
			}			
		}

		//Busca numero
		else if (query == "find") {

			cin >> num;

			//Buscamos numero telefonico
			it = data.find(num);			

			//Si encontramos el dato
			if (it != data.end()) {
				output.push(it->second);
			}

			//Si no lo encontramos
			else {
				output.push("not found");
			}
		}

		//Elimina numero
		else if (query == "del") {

			cin >> num;

			//Buscamos numero telefonico
			it = data.find(num);

			//Si encontramos el dato
			if (it != data.end()) {
				data.erase(it);
			}
		}

		else if (query == "all") {

			for (it=data.begin(); it!=data.end(); ++it) {
    			cout << it->first << " => " << it->second << '\n';
			}
		}
	}

	//Desplegamos datos de output
	while (!output.empty()) {
		cout << output.front() << endl;
		output.pop();
	}

	//Programa termina
	return 0;
}
