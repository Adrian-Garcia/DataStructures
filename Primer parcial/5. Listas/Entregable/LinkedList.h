#include "Node.h"

using namespace std;

template <class T>
class LinkedList {

	public:

		//Contructor, destructor y Copy
		LinkedList();				
		~LinkedList();								
		LinkedList(const LinkedList<T> &oldList);	

		//Aniaden datos a la lista
		bool add(T data, int pos);
		void addFirst(T data);
		void addLast(T data);

		//Quitan nodos de la lista
		void del(int pos);
		void deleteFirst();
		void deleteLast();
		void deleteAll();

		//Revisa si la lista esta vacia
		bool isEmpty();

		//Getters
		int getSize();
		T get(int pos);

		//Setters
		T set(T data, int pos);

		//Intercambia los datos de 2 posiciones
		bool change(int pos1, int pos2);
		
		//Despliega datos
		void print();

		//Cambia el orden de la lista
		void reverse();						

		//Operadores
		void operator+=(T newData);					
		void operator+=(LinkedList<T> linkedList);	
		bool operator==(LinkedList<T> linkedList);	
		void operator=(LinkedList<T> linkedList);	//Terminar

	private:
		Node<T> *head;			//Primer elemento de lista
		int size; 				//Tamanio de la lista
		void deleteHelper(); 	//Destructor
};

//Constructor de la lista
template <class T>
LinkedList<T>::LinkedList() {
	head = NULL;
	size = 0;
}

//El destructor libera la memoria que queda despues de deleteAll
template <class T>
LinkedList<T>::~LinkedList() {

	//Invocamos a la funcion destructora
	deleteHelper();
}

//Crea una LinkedList a partir de otra
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &oldList) {

	//Modificamos tamanio y agregamos cabeza
	this->size = oldList.size;
	this->head = new Node<T> (oldList.head->getData(), NULL);
	
	//Nodos auxiliares para recorrer ambas listas
	Node<T>* curr1 = this->head; 
	Node<T>* curr2 = oldList.head->getNext();

	//Recorremos toda la lista y aniadimos valores
	while (curr2 != NULL) {
		curr1->setNext(new Node<T>(curr2->getData(), NULL));
		curr1 = curr1->getNext();
		curr2 = curr2->getNext();
	}
}

//Aniade un nodo a la lista
template <class T>
bool LinkedList<T>::add(T data, int pos) {
	
	//Si la posicion deseada es mas grande que el tamanio
	if (pos > size) {

		//No se puede
		return false;
	}

	//Si esta en la primer posicion
	if (pos == 0) {
		addFirst(data);
	} 

	//Si esta en la ultima posicion
	else if (pos == size) {
		addLast(data);
	}

	//Si esta en medio 
	else {

		//Creamos nodo para encontrar la siguiente posicion
		Node<T> *curr = head;

		//Recorremos todos los nodos hasta la posicion deseada
		for (int i=1; i<pos; i++) {	//Empezamos desde 1 y no 0
			curr = curr->getNext();	
		}

		//Ponemos el siguiente nodo
		curr->setNext(new Node<T>(data, curr->getNext()));
		
		//Agrandamos tamanio
		size++;
	}

	//Indicamos que fue posible ponerlo
	return true;
}

//Aniade un elemento a la primera posicion de la lista
template <class T>
void LinkedList<T>::addFirst(T data) {

	//Crea una nueva cabeza 
	head = new Node<T>(data, head);
	
	//Aumenta el tamanio
	size++;
}

template <class T>
void LinkedList<T>::addLast(T data) {
	
	//Si la lista esta vacia
	if (this->isEmpty()) {

		//Aniadimos a la cabeza
		addFirst(data);
	}

	//Si la lista tiene datos
	else {

		//Creamos un nodo para desplazarnos
		Node<T> *curr = head;

		//Recorremos toda la lista
		while (curr->getNext() != NULL) {
			curr = curr->getNext();
		}

		//Creamos un nuevo Nodo y aumentamos tamanio de lista
		curr->setNext(new Node<T>(data));
		
		//Aumentamos el tamanio
		size++;
	}
}

//Elimina un nodo de la lista
template <class T>
void LinkedList<T>::del(int pos) {

	//Si esta en la primer posicion
	if (pos == 0) {
		deleteFirst();
	}

	//Si esta en la ultima posicion
	else if (pos == size-1) {
		deleteLast();
	}

	//Si esta en medio 
	else {

		//Creamos nodo para desplazarnos
		Node<T> *curr = head;
		
		//Recorremos todos los nodos hasta la posicion deseada
		for (int i=1; i<pos; i++) {
			curr = curr->getNext();
		}

		//Creamos nodo auxiliar (siguiente al que estamos)
		Node<T> *temp = curr->getNext();
		
		//El siguiente nodo sera el que va despues de el Nodo auxiliar	
		curr->setNext(temp->getNext());
		
		//Borramos auxiliar
		delete temp;
		
		//Disminuimos tamanio
		size--;
	}
}

//Elimina el primer nodo de la lista
template <class T>
void LinkedList<T>::deleteFirst() {
	if (!this->isEmpty()) { 	//El this->no es necesario
		
		//Creamos un Nodo para desplazarnos
		Node<T> *curr = head;

		//Ahora la cabeza es el siguiente nodo
		head = head->getNext();

		//Borramos el nodo en el que estamos
		delete curr;

		//Disminuimos el tamanio de la lista
		size--;
	}
}

//Elimina el ultimo nodo de la lista
template <class T>
void LinkedList<T>::deleteLast() {
	
	//Si el tamanio menor o igual 1 elimina el primero
	if (size <= 1) { 	//Tambien se puede revisar como isEmpty()
		deleteFirst();
	}

	//Si no, avanzamos por la lista
	else {

		//Creamos un Nodo para desplazarnos
		Node<T> *curr = head;
		
		//Recorremos toda la lista
		while (curr->getNext()->getNext() != NULL) {
			curr = curr->getNext();
		}

		//Borramos el ultimo elemento 
		delete curr->getNext();

		//Indicamos que el siguiente elemento apunta a NULL
		curr->setNext(NULL);
		
		//Disminuimos el tamanio
		size--;
	}
}

//Elimina la lista completa
template <class T>
void LinkedList<T>::deleteAll() {

	//Guardamos la cantidad
	int cant = size;
	
	//Llamamos al metodo que borra todo
	deleteHelper();

	//El tamanio desaparece
	size = 0;
}

//Borra los elementos de la lista
template <class T>
void LinkedList<T>::deleteHelper() {
	
	//Creamos Nodo para desplazarnos
	Node<T> *curr = head;

	//Recorremos todos los nodos y borramos
	while (!this->isEmpty()) {

		//Cambiamos cabeza al siguiente nodo
		head = head->getNext();

		//Borramos nodo
		delete curr;
		curr = head;
	}
}

//Indica si la lista se encuentra vacia o no
template <class T>
bool LinkedList<T>::isEmpty() {
	return (head == NULL);
}

//Regresa el tamanio de la lista
template <class T>
int LinkedList<T>::getSize() {
	return size;
}

//Obtiene el elemento de una posicion
template <class T>
T LinkedList<T>::get(int pos) {
	
	//Creamos Nodo para desplazarnos
	Node<T> *curr = head;

	//Nos movemos por toda la lista hasta llegar a la posicion
	for (int i=1; i<=pos; i++) {
		curr = curr->getNext();
	}

	//Obtenemos el dato y lo regresamos
	return curr->getData();
}

//Cambia el dato
template <class T>
T LinkedList<T>::set(T data, int pos) {
	
	//Creamos Nodo para desplazarnos
	Node<T> *curr = head;

	//Nos movemos por toda la lista hasta llegar a la posicion
	for (int i=0; i<pos; i++) {
		curr = curr->getNext();
	}
	
	T dataAux = curr->getData();

	//Le damos un nuevo valor a el Nodo actual
	curr->setData(data);

	return dataAux;
}

//Intercambia dos valores en la lista
template <class T>
bool LinkedList<T>::change(int pos1, int pos2) {

	//Si el dato es igual, entonces no hacemos nada
	if (pos1 == pos2) {
		return true;
	}

	else if (pos1 > size || pos2 > size) {
		return false;
	}

	//Revisar...
	int posMen = (pos1 < pos2 ? pos1 : pos2);
	int posMay = (pos1 > pos2 ? pos1 : pos2);

	/* Las 2 lineas anteriores se pueden escribir así
	if (pos1 > pos2) {
		posMay = pos1;
	} else {
		posMay = pos2;
	}
	*/

	//Creamos Nodo para desplazarnos 
	Node<T> *curr1 = head;

	//Nos movemos por toda la lista hasta llegar a la posicion
	for (int i=0; i<posMen; i++) {
		curr1 = curr1->getNext();
	}

	//Creamos nodo para encontrar la siguiente posicion
	Node<T> *curr2 = curr1;

	//Nos movemos por el resto de la lista hasta llegar a la posicion
	for (int i=posMen; i<posMay; i++) {
		curr2 = curr2->getNext();
	}

	//Guardamos los datos del Nodo 1 en una variable
	T dataAux = curr1->getData();

	//Intercambiamos los datos de ambos Nodos
	curr1->setData(curr2->getData()); 
	curr2->setData(dataAux);

	//Indicamos que fue posible realizar el intercambio
	return true;
}

//Despliega Datos de la Lista
template <class T>
void LinkedList<T>::print() {
	
	//Creamos Nodo para desplazarnos
	Node<T> *curr = head;

	//Nos movemos por toda la llista hasta llegar a la posicion
	while (curr != NULL) {

		//Desplegamos informacion
		cout << curr->getData() << " ";
		
		//Asignamos siguiente Nodo
		curr = curr->getNext();
	}

	//Terminamos linea
	cout << endl;
}

//Voltea la dirección de la lista encadenada
template <class T>
void LinkedList<T>::reverse() {


	//Tiene que haber mas de 1 nodo en la lista para revertirlo
	if (size > 1){

		//Nodos auxiliares para recorrer la lista
		Node<T>* prev = NULL; 
		Node<T>* curr = head->getNext();

		//Recorremos toda la lista		
		while (curr != NULL){

			head->setNext(prev);
			prev = head;
			head = curr;
			curr = head->getNext();
		}	

		//La nueva cabeza es el nodo en el que nos encontramos
		head->setNext(prev);
		delete curr;
	}
}

//+= Asigna un dato al final de la lista
template <class T>
void LinkedList<T>::operator+=(T newData) {
	addLast(newData);
} 

//+= Asigna una lista al final de la lista que ya tenemos
template <class T>
void LinkedList<T>::operator+=(LinkedList<T> linkedList) {

	//Solo agrega listas mayores a 0
	if (linkedList.size > 0) {
		
		//Creamos un nodo para desplazarnos
		Node<T>* curr1 = head;
		Node<T>* curr2 = linkedList.head;

		//Nos movemos hasta el final de la lista
		while (curr1->getNext() != NULL) {
			curr1 = curr1->getNext();
		}

		//Asignamos el siguiente dato a la siguiente linkedList
		while(curr2 != NULL) {	
			curr1->setNext(new Node<T>(curr2->getData()));
			
			//Recorremos los nodos
			curr1 = curr1->getNext();
			curr2 = curr2->getNext();
			
			//Incrementamos tamanio
			size++;
		}
	}
}

//Operador == verifica si dos listas son iguales
template <class T>
bool LinkedList<T>::operator==(LinkedList linkedList) {

	//Si no tienen el mismo tamanio no son iguales
	if (this->getSize() != linkedList.getSize()) {
		return false;
	}

	//Creamos nodos para desplazarnos
	Node<T>* curr1 = head;
	Node<T>* curr2 = linkedList.head;

	//Recorremos todos los nodos
	while (curr1->getNext() != NULL) {

		//Si un solo dato es diferente, entonces no son iguales
		if (curr1->getData() != curr2->getData()) {
			return false;
		}

		//Vamos al siguiente nodo
		curr1 = curr1->getNext();
		curr2 = curr2->getNext();
	} 

	//Regresamos verdadero si no hay ninguna anomalia
	return true;
}

//Operador = Iguala una lista a otra
template <class T>
void LinkedList<T>::operator=(LinkedList<T> nuevaLista) {

	//Borramos la lista actual
	deleteAll();

	//Varios elementos en la lista
	if (nuevaLista.size > 1) {

		//Aniade una nueva cabeza
		addFirst(nuevaLista.head->getData());		

		//Nodos para recorrer toda la lista
		Node<T>* currNew = nuevaLista.head;
		Node<T>* currOld = head;

		currNew = currNew->getNext();

		//Recorremos la lista
		while (currNew != NULL) {

			// cout << currNew->getData() << " ";

			//Aniadimos otro dato a la lista
			currOld->setNext(new Node<T>(currNew->getData()));

			//Avanzamos ambas listas
			currOld = currOld->getNext();
			currNew = currNew->getNext();
		}
	}

	//Solo un elemento en la lista
	else if (nuevaLista.size == 1) {
		addFirst(nuevaLista.head->getData());
	}
}