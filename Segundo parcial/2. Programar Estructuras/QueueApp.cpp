#include "queue.h"

using namespace std;

int main() {

	queue<int> miFila;

	miFila.push(10);
	miFila.push(20);
	miFila.push(30);

	cout << "El tamanio de mi fila es: " << miFila.size() << endl;

	while (!miFila.empty()) {
		cout << miFila.front() << endl;
		miFila.pop();
	}

	return 0;
}
