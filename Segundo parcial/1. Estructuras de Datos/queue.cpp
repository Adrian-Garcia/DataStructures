#include <iostream>
#include <queue>

using namespace std;

int main() {

	queue<int> q;
	int n, dato;

	cout << "Inserta el tamanio de la lista: ";
	cin >> n;

	for (int i=1; i<=n; i++) {
		cin >> dato;
		q.push(dato);
	}

	cout << "La fila es: ";

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << endl;

	return 0;
}

g++ EjVarios.cpp -o EjVarios
./EjVarios

//EjVarios es el nombre del archivo 
