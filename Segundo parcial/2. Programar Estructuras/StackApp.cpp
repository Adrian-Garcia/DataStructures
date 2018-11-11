#include "stack.h"

using namespace std;

int main() {

	stack<int> miPila;

	miPila.push(10);
	miPila.push(20);
	miPila.push(30);

	cout << "El tamanio de mi pila es: " << miPila.size() << endl;

	while (!miPila.empty()) {
		cout << miPila.top() << endl;
		miPila.pop();
	}

	return 0;
}
