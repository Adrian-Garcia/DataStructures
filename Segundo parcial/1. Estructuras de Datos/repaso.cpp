#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main() {

	stack<string> pila;
	queue<string> fila;

	fila.push("Fer ");
	fila.push("es ");
	fila.push("La mas hermosa ");

	pila.push("Fer ");
	pila.push("es ");
	pila.push("La mas hermosa ");

	cout << "Fila: ";
	while (!fila.empty()) {
		cout << fila.front();
		fila.pop();
	}
	cout << endl;

	cout << "Pila: ";
	while (!pila.empty()) {
		cout << pila.top();
		pila.pop();
	}
	cout << endl;

	priority_queue<int> pQueueMaxMin;
	priority_queue<int, vector<int>, greater<int> > pQueueMinMax;

	pQueueMaxMin.push(9);
	pQueueMaxMin.push(2);

	pQueueMinMax.push(9);
	pQueueMinMax.push(2);

	cout << "Fila prioritaria descendente: ";
	while (!pQueueMaxMin.empty()) {
		cout << pQueueMaxMin.top() << " ";
		pQueueMaxMin.pop();
	}
	cout << endl;

	cout << "Fila prioritaria ascendente: ";
	while (!pQueueMinMax.empty()) {
		cout << pQueueMinMax.top() << " ";
		pQueueMinMax.pop();
	}

	cout << endl << endl;

	return 0;
}