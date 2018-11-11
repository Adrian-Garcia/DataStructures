#include <iostream>
#include <queue>
#include "BST.h"

using namespace std;

int main () {

	BST miArbol;
	
	miArbol.add(10);
	miArbol.add(3);
	miArbol.add(20);
	miArbol.add(1);
	miArbol.add(7);
	miArbol.add(11);
	miArbol.add(27);
	miArbol.add(2);
	miArbol.add(5);
	miArbol.add(8);
	miArbol.add(15);
	miArbol.add(26);
	miArbol.add(28);
	miArbol.add(6);
	miArbol.add(13);
	miArbol.add(25);
	
	cout << "Pre Orden: ";
	miArbol.print(1);
	cout << endl;
	
	cout << "In Orden: ";
	miArbol.print(2);
	cout << endl;
	
	cout << "Post Orden: ";
	miArbol.print(3);
	cout << endl;
	
	/*Descomentar para desplegar
	cout << "preorden: ";
	miArbol.print(1);
	cout << "inOrden: ";
	miArbol.print(2);
	cout << "postOrden: ";
	miArbol.print(3);
	cout << "hojas: ";
	miArbol.print(4);
	cout << "levels: ";
	miArbol.print(5);
	*/
	
	return 0;
}
