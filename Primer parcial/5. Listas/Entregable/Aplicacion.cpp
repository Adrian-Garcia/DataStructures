#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main () {
	
	cout << "1" << endl;
	
	LinkedList<int> miLista;
	LinkedList<int> tuLista;
	
	cout << "2" << endl;
	
	miLista.addFirst(1);
	miLista.addLast(2);
	miLista.addLast(3);

	tuLista.addFirst(4);
	tuLista.addLast(5);
	tuLista.addLast(6);
	
	cout << "miLista Original: ";
	miLista.print();

	cout << "miLista+=tuLista: ";
	miLista+=tuLista;
	
	miLista.print();

	miLista.reverse();
	cout << "miLista cambiada: ";
	miLista.print();
	
	cout << "tuLista Original: ";
	tuLista.print();
	
	return 0;
}
