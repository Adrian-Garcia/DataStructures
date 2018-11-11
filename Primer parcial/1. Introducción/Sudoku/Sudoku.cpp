#include <iostream>

using namespace std;

int main () {

	int Sudoku[9][9];	//Matriz donde se encuentra el Sudoku
	int Numeros[9];		//Numero de numeros del sudoku

	//Valida que la linea y la columna tengan 45
	int linea = 1;

	//Variable que valida que el Sudoku este correcto
	bool Validacion = true;

	//Ingresamos los datos del Sudoku y analisamos filas
	for (int i=0; i<9 && Validacion == true; i++) {
		for (int j=0; j<9 && Validacion == true; j++) {
			cin >> Sudoku[i][j];
			linea*=Sudoku[i][j];		//Agregamos el numero de la casilla al contador linea
		}

		//Si la suma de los numeros no da 45 es por que esa linea esta mal hecha
		if (linea != 362880) {
			Validacion = false;
		}		

		linea = 1;	//Regresamos contador a 1
	}

	//Validamos las lineas faltantes
	for (int i=0; i<9 && Validacion == true; i++) {
		for (int j=0; j<9; j++) {
			linea*=Sudoku[j][i]; 
		}

		//Si la suma de los numeros no da 45 es por qe esa linea esta mal hecha
		if (linea != 362880) {
			Validacion = false;
		}

		linea = 1;	//Regresamos contador a 1
	}

	//Recorreremos el arreglo de 3 en 3
	for (int i=0; i<3 && Validacion == true; i++) {
		for (int j=0; j<3 && Validacion == true; j++) {
			for (int k=0; k<3; k++) {
				for (int l=0; l<3; l++) {	
					linea*=Sudoku[i*3+k][j*3+l];
				}
			}

			//Verificamos que el producto de los numeros sea igual a 362880
			if (linea != 362880) {
				Validacion = false;
			}

			linea = 1;	//Regresamos contador a 1
		}
	}

	//Informamos si el sudoku esta correcto o no
	if (Validacion) {
		cout << "YES" << endl;
	}

	else {
		cout << "NO" << endl;
	}

	//Terminamos programa
	return 0;
}
