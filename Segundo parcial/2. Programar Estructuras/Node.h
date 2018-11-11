/*
Listas

	Constructor 			Metodo inicializador que se ebe llamar igual que la clase 				Lista uno;
	Copy Constructor 		Contruye un elemento copiando lo que otro objeto tiene 					Lista dos(uno);

	Lista (const Lista<t> &otra)
*/
/*
Tipo de Dato
	Un rango
	El conjunto de operaciones validas que se pueden apicar a esos valores

Estructura de datos
	Puede despcomponerse en un conjunto de elementos, cada uno es simple o es otra estructura
	Incluye conjunto de asociaciones o relaciones entre los elementos

Abstraccion
	Proceos mental que extrae rasgos esenciales de "algo" para representarlos por medio de un lenguaje grafico o escritos

	Durante el dise;o de la estructura, se ignroan los detalles de la implementacion

Tipo de datos abstracto
	Siglas en ingles ADT (Abstract Data Type)

Especificacion logica
	Se menciona lo siguiente
		Elemento
		Organizacion
		Dominio
		Terminar...	

Operaciones
	Todo lo que se puede hacer en la estructura de datos
		Nombre
		Descripcion
		Datos de entrada
		Datos de salidas
		Precondiciones 			Condicion que debe de cumplirse para ejecutarse la operacion
		Postcondiciones 		

Listas encadenadas
	-Es una estructura de datos con organizacion linea, y se caracterista por que cada elemento indica donde está el siguiente nodo en la lista
	-Memoria dinamica, se pueden seguir creando datos a medida que se desea
	-Cada nodo d ela lista encadenada tiene un campo llamado next. El ultimo campo apunt a NULL	

*/
#include <iostream>

template <class T>
class Node {
	public:
		Node(T data);
		Node(T data, Node<T> *next);
		T getData();
		Node<T>* getNext();
		void setData(T data);
		void setNext(Node<T> *next);

	private:
		T data;
		Node<T> *next;
};

template <class T>
Node<T>::Node(T data) {
	this->data = data;
	this->next = NULL;
}

template <class T>
Node<T>::Node (T data, Node<T> *next) {
	this->data = data;
	this->next = next;
}

template <class T>
T Node<T>::getData() {
	return data;
}

template <class T>
Node<T>* Node<T>::getNext() {
	return next;
}

template <class T> 
void Node<T>::setData(T data) {
	this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T> *next) {
	this->next = next; 
}
