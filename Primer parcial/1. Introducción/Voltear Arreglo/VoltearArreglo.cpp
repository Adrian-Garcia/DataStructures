#include <iostream>

using namespace std;

int main() {

	//Numero de vueltas
	int n;

	//Numero matriz
	int Arreglo[4][4];

	//Pedimos el numero de vueltas a dar a la matriz
	cin >> n;

	//Pedimos los datos de la matriz 
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			cin >> Arreglo[i][j];
		}
	}

	//Validamos que n sea positiva	
	if (n < 0 && n > -5) {
		if (n%4 == 0) {
			n = 4;
		}

		else if (n%2 == 0) {
			n = 2;
		}

		else if (n%3 == 0) {
			n = 1;
		}

		else {
			n = 3;
		}
	} 

	if (n%4 == 0|| n == 0) {	// 0 vueltas

		//Muestra el arreglo final
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (j != 0) {
					cout << " ";
				}
				cout << Arreglo[i][j];
			}
			cout << endl;
		}
	} 

	else if (n%2 == 0) { 		// 2 Vueltas
		
		//Muestra el arreglo final
		for (int i=3; i>-1; i--) {
			for (int j=3; j>-1; j--) {
				if (j != 3) {
					cout << " ";
				}
				cout << Arreglo[i][j];
			}
			cout << endl;
		}
	} 

	else if (n%3 == 0) { 		// 3 vueltas
		
		//Muestra el arreglo final
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (j != 0) {
					cout << " ";
				}
				cout << Arreglo[j][3-i];
			}
			cout << endl;
		}
	}

	else {						// 1 vuelta

		//Muestra el arreglo final
		for (int i=0; i<4; i++) {
			for (int j=3; j>-1; j--) {
				if (j != 3) {
					cout << " ";
				}
				cout << Arreglo[j][i];
			}
			cout << endl;
		}
	}

	return 0;
}
