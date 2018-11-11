/*
Algoritmos de Ordenamiento 
	Existen muchas ideas de como ordenar. Algunas son mejores que otras
	y el algoritmo se escoge dependeindo de cual es mas eficiente

	Para fijarme cual es mas efeicientes basta con ver cuantas comparaciones
	es necesario hacer para ordenar.

	Tipos de ordenamientos que se veran en clase
		Intercambio
		Bubble Sort
		Selection Sort
		Insertion Sort

		Merge Sort
		Quick Sort

		Heap Sort

	Medida de eficiencia 
		Contar el # de comparaciones
		Contar el # de movimientos	

	Sort de Intercambio
		Compara el de la casilla inicial con el resto. Si en el medio de la 
		comparacion se encuentra un dato menor o mayos se intercambia

		[0][1][2][3] 		[0][1][2][3] 		[0][1][2][3] 			
		 8  4  6  2			 4  8  6  2 		 2  8  6  4

		 Aun falta...

	Sort Burbuja
		Compara celdas continuas 1 con 2, 2 con 3, 3 con 4... Y así 
		Sucesivamente dependiendo si es mayor o menos.

	Seleccion Directa
		Se va seleccionando el mayor o el menor segun sea el caso
		Encuentra el menor y lo intercambia en la primera posicion
		luego el segundo menor y con la segunda posicion y así 
		sucesivamente

	Sort por Insercion
		Se van poniendo los datos datos de manera que se toma un dato
		y posteriormente se toma el otro y se acomodo antes o despues
		del valor del dato anteriormente colocado	
			Mejor caso O(n)
			Peor caso O(n^2)

Busquedas 
	Tipos de Busquedas que se veran en clase
		Binaria

	Tipos de busqueda
		Secuencial 				Casilla por casilla
		Binaria					Se va a la mitad del arreglo y busca a partir de eso
*/

#include <iostream>
	
using namespace std;

void ordIntercambio () {

	int n;

	cout << "Inserta el tamanio del arreglo: ";
	cin >> n;
	
	int a[n], comparaciones=0, intercambios=0;
	int i, j, aux;  /* se realizan n-1 pasadas,	a[o] ... a[n-2]	*/

	cout << "Llena el arreglo" << endl; 

	for (i=0; i<n; i++) {
		cin >> a[i];
	}

	for (i=0; i<=n-2; i++) { /* coloca mínimo de a[i+1]...a[n-1] en a[i] */
		for (j=i+1; j<=n-1; j++) {
			comparaciones++;
			if (a[i] > a[j]) {	
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
				intercambios++;
			}
		}
	}

	cout << "Arreglo ordenado: ";
	for (i=0; i<n; i++) {
		cout << a[i] << " ";
	}

	cout << "\nComparaciones: " << comparaciones;
	cout << "\nIntercambios: " << intercambios << endl;
}

void ordBurbuja() {

	int n;

	cout << "Inserta el tamanio del arreglo: ";
	cin >> n;
	
	int a[n], comparaciones=0, intercambios=0;
	int pasada, i, j, aux, tmp;  /* se realizan n-1 pasadas,	a[o] ... a[n-2]	*/

	cout << "Llena el arreglo" << endl; 

	for (i=0; i<n; i++) {
		cin >> a[i];
	}

	bool interruptor = true;
	
	for (pasada=0; pasada<n-1 && interruptor; pasada++) { 
      	interruptor = false;   // no se han hecho intercambios
      	for (j=0; j<n-1-pasada; j++) {
          	comparaciones++;
          	if (a[j+1] < a[j]) {  
            	tmp = a[j]; 
            	a[j] = a[j+1]; 
            	a[j+1] = tmp;
            	intercambios++; 
				interruptor = true;
         	} 
     	} 
    }

    cout << "Arreglo ordenado: ";
	for (i=0; i<n; i++) {
		cout << a[i] << " ";
	}

	cout << "\nComparaciones: " << comparaciones;
	cout << "\nIntercambios: " << intercambios << endl;

}

void ordInsercion () {

	int n;

	cout << "Inserta el tamanio del arreglo: ";
	cin >> n;

	int a[n], aux;	//Almacenan valores

	int i,j; //Contadores

	//Numero de comparaciones y corrimientos en el algoritmo
	int comparaciones = 0;
	int corrimientos = 0;

	cout << "Llena el arreglo" << endl; 
	for (i=0; i<n; i++) {
		cin >> a[i];
	}

	//Recorremos todo el arreglo
	for (i=1; i<n; i++) {  	
		j = i;
		aux = a[i];  

		comparaciones++;
		
		while (j > 0 && aux < a[j-1]) { 
		 	a[j] = a[j-1];
			j--;
			corrimientos++;
		}
		a[j] = aux;
	}

	cout << "Arreglo ordenado: ";
	for (i=0; i<n; i++) {
		cout << a[i] << " ";
	}

	cout << "\nComparaciones: " << comparaciones;
	cout << "\nCorrimientos: " << corrimientos << endl;
}

void ordSeleccion() {

	int n;

	cout << "Inserta el tamanio del arreglo: ";
	cin >> n;
	
	int a[n], comparaciones=0, intercambios=0;
	int indiceMenor, i, j;

	cout << "Llena el arreglo" << endl; 

	for (i=0; i<n; i++) {
		cin >> a[i];
	}

	int aux;
	for (i = 0; i < n-1; i++) {	  // ordenar a[0]..a[n-2] y a[n-1] en cada pasada 
		indiceMenor = i;	  // comienzo de la exploración en índice i 
		for (j = i+1; j < n; j++) { // j explora la sublista a[i+1]..a[n-1] 
			if (a[j] < a[indiceMenor]) {
				indiceMenor = j;
			}

			if (i != indiceMenor) {	// sitúa el elemento mas pequeño en a[i] 
				aux = a[i];
				a[i] = a[indiceMenor];
				a[indiceMenor] = aux;
				intercambios++;
			}
			comparaciones++;
		}
	}

	cout << "Arreglo ordenado: ";
	for (i=0; i<n; i++) {
		cout << a[i] << " ";
	}

	cout << "\nComparaciones: " << comparaciones;
	cout << "\nIntercambios: " << intercambios << endl;
}

void busquedaBin() {
	int n;

	cout << "Inserta el tamanio del arreglo: ";
	cin >> n;

	int a[n], i, numero, valorCentral;
	int mitad = n/2;
	int bajo, alto, central;

	bool Validacion = false;

	cout << "Llena el arreglo (De forma ordenada)" << endl;
	for (i=0; i<n; i++) {
		cin >> a[i];
	}

	cout << "Numero a buscar: ";
	cin >> numero;

	bajo = 0;
	alto = n-1;

	while (bajo <= alto) {
		central = (bajo+alto)/2;
		valorCentral = a[central];

		if (valorCentral == numero) {
			Validacion = true;
			cout << "El numero " << numero << " se encuentra en la posicion " << central;
		}
	
		else if (valorCentral > numero) {
			alto = central-1;
		}

		else {
			bajo = central+1;
		}
	}
	
	if (Validacion == false) {
		cout << "Valor no encontrado" << endl;
	}
}

void busquedaSec() {
	int n;

	cout << "Inserta el tamanio del arreglo: ";
	cin >> n;

	int a[n], numero, i, posicion; 
	bool Validacion = false;

	cout << "Llena el arreglo" << endl;
	for (i=0; i<n; i++) {
		cin >> a[i];
	}

	cout << "\nNumero a buscar: ";
	cin >> numero;

	//Buscamos el arreglo
	for (i=0; i<n && Validacion==false; i++) {
		if (a[i] == numero) {
			Validacion = false;
			posicion = i;
		}
	}

	cout << "El numero " << numero << " se encuentra en la posicion " << posicion;
}

int main() {

	char opcion;

	do { 
		cout << "Que tipo de ordenamiento o busqueda quieres hacer?" << endl;
		cout << "1. Ordenamiento por Intercambio" << endl;
		cout << "2. Ordenamiento por Burbuja" << endl;
		cout << "3. Ordenamiento por Insercion" << endl;
		cout << "4. Ordenamiento por Seleccion" << endl;
		cout << "5. Busqueda Binaria" << endl;
		cout << "6. Busqueda Secuencial" << endl;

		cout << "Opcion: ";
		cin >> opcion;

		if (opcion > '6' || opcion <= '0') {
			cout << "Inserta una opcion valida" << endl;
		}

		cout << endl;
	}while (opcion > '6' || opcion <= '0');

	switch (opcion) {
		case '1':
			ordIntercambio();
		break;

		case '2':
			ordBurbuja();
		break;

		case '3':
			ordInsercion();
		break;

		case '4':
			ordSeleccion();
		break;

		case '5':
			busquedaBin();
		break;

		case '6':
			busquedaSec();
		break;
	}

	return 0;
}
