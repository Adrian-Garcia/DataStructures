#include <iostream>
#include <vector>

using namespace std;

class Priority {

	private:
		
		//Atributos
		vector<int> data;
		bool priority;			
		int length;

		//Balancea la lista
		void balance();

	public:

		//Constructores
		Priority();
		Priority(bool defPrioriry);

		//Metodos
		void push(int num); 	//Agrega un numero a la lista
		void pop(); 			//Elimina el primer numero
		int top(); 				//Muestra el dato del frente
		int size(); 			//Regresa tamanio de la lista
		bool empty(); 			//Indica si la lista esta vacia

		void print();
};

//Constructor default
Priority::Priority() {
	priority = true;
	data.push_back(0);
	length = 1;
}

//Constructor con prioridad definida
Priority::Priority(bool defPrioriry) {
	priority = defPrioriry;
	data.push_back(0);	
	length = 1;
}

//Mete un numero a la lista
void Priority::push(int num) {
	
	//Colocamos el numero en la parte trasera
	data.push_back(num);
		
	//Aumentamos tamanio
	length++;

	//Si es el primer nodo
	if (length > 2) {

		//Balanceamos
		balance();	
	}
}

//Elimina el ultimo nodo del vector
void Priority::pop() {

	//Si hay varios elementos en el vector 
	if (data.size() > 4) {
		
		//Guardamos elemento de la ultima posicion en primera
		data[1] = data[data.size()-1];

		//Borramos el ultimo elemento
		data.pop_back();

		//Balanceamos
		balance();
	}

	//Si es el ultimo elemento del vector
	else if (data.size() <= 4) {	
		
		//Borramos el ultimo elemento
		data.pop_back();
	}

	//No hay elementos
	else {

		//Terminamos la funcion
		return;
	}

	length --;
}

//Regresa el primer numero de la fila
int Priority::top() {

	//Si hay datos regresamos valor
	if (data.size() != 1) {
		return data[1];
	}

	//Si no hay datos no regresamos nada
	else {
		return 0;
	}
}

//Regresa el tamanio de la lista
int Priority::size() {
	return length-1;
}

//Verifica si la lista esta vacia
bool Priority::empty() {
	return (length == 1)?
		true : false;
}

//Balancea el arbol 
void Priority::balance() {

	//Pivote 
	int pivot = (length-1)/2;

	//Hijos del pivote
	int hijoIzq, hijoDer;

	//Variable mas grande o chica
	int priorityVar;

	//Variable auxiliar
	int aux;

	//Prioridad mayor menor
	if (priority) {

		//Iteramos hasta llegar al padre 
		while (pivot >= 1) {
			
			//Igualamos hijos de pivote
			hijoIzq = 2*pivot;

			//Creamos hijo derecho si se requiere
			if (2*pivot+1 <= length-1) {
				hijoDer = 2*pivot+1;
			} else {
				hijoDer = hijoIzq;
			}
			
			//Encontramos el valor mas grande
			priorityVar = (data[hijoIzq] > data[hijoDer]) ?
				hijoIzq : hijoDer;

			//Comparamos el pivote con sus hijos
			if (data[pivot] < data[priorityVar]) {

				//Intercambiamos si es necesario
				aux = data[pivot];
				data[pivot] = data[priorityVar];
				data[priorityVar] = aux;
			}

			//Reducimos tamanio de pivote
			pivot--;
		}
	}

	//Prioridad menor mayor
	else {

		//Iteramos hasta llegar al padre 
		while (pivot >= 1) {
			
			//Igualamos hijos de pivote
			hijoIzq = 2*pivot;

			//Creamos hijo derecho si se requiere
			if (2*pivot+1 <= length-1) { //Si se requiere
				hijoDer = 2*pivot+1;
			} else { 					//No se requiere
				hijoDer = hijoIzq;
			}
			
			//Encontramos el valor mas chico
			priorityVar = (data[hijoIzq] < data[hijoDer]) ?
				hijoIzq : hijoDer;

			//Comparamos el pivote con sus hijos
			if (data[pivot] > data[priorityVar]) {

				//Intercambiamos si es necesario
				aux = data[pivot];
				data[pivot] = data[priorityVar];
				data[priorityVar] = aux;
			}

			//Reducimos tamanio de pivote
			pivot--;
		}
	}
}

void Priority::print() {

	for (int i=1; i<data.size(); i++) {
		cout << data[i] << " ";
	}
}
