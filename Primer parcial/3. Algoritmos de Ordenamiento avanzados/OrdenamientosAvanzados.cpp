/*
Algortimos de Ordenamiento Avanzados

	Recursividad
		Cuando una función se manda a llamar a si misma.
		Sí no hay tope, se vuelve infinita, por lo que es importante ponerla.
		
		Ejemplo
			Factorial
				Matematicamente, es la multiplicación de la suceción de los numeros

	Merge Sort
		Unir dos listas que ya estan previamente ordenadas 
		
		Divide el arreglo en 2 subarreglos.

		Ejemplo 
			|27|30|14|32|08|24|47|17|
			
			   1       1       1       1
			|27|30| |14|32| |08|24| |47|17|
			
				  3             3
			|14|27|30|32| |08|17|24|47|

						7
			|08|14|17|24|27|30|32|47|

				Numero de Comparaciones: 17

	Quick Sort
		-Divide el arreglo en 2 particiones, los que son menores al pivote y los que 
		 son ayores al pivote
		-Se ordenan todas las particiones, y automaticamente se tiene todo el arreglo 
		 ordenado

		Pivote
			Primer elemento del arreglo, se usará para comparar los elementos del 
			arreglo 

		Ejemplo 
			|27|30|14|32|08|24|47|17|

			|27|14|08|24|17| |32|47|30|			7
					
			|17| |14|08| |24| |27|32|47|30|		3/2

			|08|14|17|24| |27| |32|30|47|		
			|08|14| 		   |30|32|47|		1

				Numero de Comparaciones: 13

*/

#include <iostream>

using namespace std;

void mergeSort() {
	int n; 

	cout << "Inserta el tamanio del Arreglo: "
	cin >> n;

	int a[n], i, j;
	
}

void quickSort() {

}

int main() {

	char opcion;	//Opcion del usuario

	do {	//Pedimos al usuario el ordenamiento que desea realizar
		cout << "Que tipo de Ordenamiento quieres hacer?" << endl;
		cout << "1. Merge Sort" << endl;
		cout << "2. Quick Sort" << endl;

		cout << "Opcion: " << endl;
		cin >> opcion;

		if (opcion > '2' || opcion <= '0') {
			cout << "Inserta una opcion valida" << endl;
		}
	} while(opcion > '2' || opcion <= '0');

	switch (opcion) {
		
		case: '1':
			mergeSort();
		break;

		case: '2':
			quickSort();
		break;
	}

	//Terminamos programa
	return 0;
}