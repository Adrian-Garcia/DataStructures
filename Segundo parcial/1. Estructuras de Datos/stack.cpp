#include <iostream>
#include <stack>

using namespace std;

int main() {

	stack<int> s;
	int n, dato;

	cout << "Inserta el tamanio de la pila: ";
	cin >> n;

	for (int i=1; i<=n; i++) {
		cin >> dato;
		s.push(dato);
	}

	cout << "La pila es: ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;

	return 0;
}
