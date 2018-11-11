#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct punto{
	int x, y;

	//Es necesario sobrecargar el operador para ponerlo en priority queue
	bool operator< (const punto &otro) const {
		if (x == otro.x) {
			return y < otro.y;	
		}
		return x > otro.x;
	}
};

int main() {
	
	priority_queue<int> pq1; 								//Lista de mayor a menor
	priority_queue<int, vector<int>, greater<int> > pq2; 	//Lista de menor a mayor
	priority_queue<punto> pq3; 								//Lista usando estructura
	int n, dato;

	cout << "Inserta el tamanio de la lista prioritaria: ";
	cin >> n;


	for (int i=1; i<=n; i++) {
		cin >> dato;
		pq1.push(dato);
		pq2.push(dato);
	}

	cout << "\nLa fila1 ordenada de mayor a menor es: ";
	while (!pq1.empty()) {
		cout << pq1.top() << " ";
		pq1.pop();
	}
	cout << endl;


	cout << "La fila2 ordenada de menor a mayor es: ";
	while (!pq2.empty()) {
		cout << pq2.top() << " ";
		pq2.pop();
	}

	cout << endl << endl;
	cout << "Inserta la fila3 con dos elementos por estructura"<< endl;

	punto aux;
	for (int i=1; i<=n; i++) {
		cin >> aux.x >> aux.y;
		pq3.push(aux);
	}

	cout << "La fila3 ordenada de mayor a menor es " << endl;
	while (!pq3.empty()) {
		aux = pq3.top();
		cout << aux.x << "-" << aux.y << endl;
		pq3.pop();
	}
	cout << endl;

	return 0;
}
