#include <iostream>
#include <stack>
#include <queue>
#include "NodeT.h"

using namespace std;

class BST {
	public:

		//Constructores
		BST(); 						//Constructor 
		BST(const BST& tree);		//Copy Constructor									
		~BST();						//Destructor

		//Operaciones basicas 
		void add(int data); 		//Aniade un Nodo
		bool search(int data);		//Busca un dato
		void remove(int data);		//Elimina un nodo
		void print(int c); 			//Desplega el arbol

		//Operaciones complejas
		int height();				//Regresa la altura del arbol
		void ancestors(int data);	//Desplega los ancestros del arbol
		int whatLevelamI(int data);	//Indica el nivel de un nodo
		int count();				//Cuenta los nodos

		//Operaciones mas complejas
		int maxWidth();								//Anchura maxima
		int nearstRelative(int data1, int data2);	//Pariente mas cercano
		void mirror();								//Invierte nodos

		//Operadores
		bool operator==(BST otherTree);

	private:

		//Raiz del arbol
		NodeT *root;

		//Remove
		int howManyChildren(NodeT *r);
		int pred(NodeT *r);
		int succ(NodeT *r);

		//Destructor
		void liberar(NodeT *r);

		//Copy contructor
		void keepAdding(NodeT *rA, NodeT *rB);
		
		//Count
		int cuantos(NodeT *r);

		//Height
		int altura(NodeT *r);
		int counter(NodeT *r);

		//nearstRelative
		bool isChild(int data1, int data2);
		
		//Print
		void preOrden(NodeT *r);
		void inOrden(NodeT *r);
		void postOrden(NodeT *r);
		void printLeaves(NodeT *r);
		void levels(NodeT *r);

		//Operador ==
		void equal(NodeT *rA, NodeT *rB, bool &answer);

		//Mirror
		void change(NodeT *r);
};

//Constructor
BST::BST() {
	root = NULL;
}

//Destructor
BST::~BST() {
	liberar(root);
}

//Copy contructor
BST::BST(const BST& tree) {
	
	//Cuando el arbol esta vacio
	if (tree.root == NULL) {
		root = NULL;
	}

	//Si tiene datos
	else {
	
		//Nuestra raiz es la raiz del otro arbol
		root = tree.root;
		
		NodeT *curr = root;

		//Llamamos funciones recursivas
		keepAdding(curr, tree.root);
	}
}

//Agrega nodos recursivamente
void BST::keepAdding(NodeT *rA, NodeT *rB) {

	//Si no hay datos en rB terminamos funcion
	if (rB == NULL) 
		return;

	//Si hay datos en ambas
	if (rB->getRight()!=NULL && rB->getLeft()!=NULL) {
		rA->setLeft(new NodeT(rB->getLeft()->getData()));
		rA->setRight(new NodeT(rB->getRight()->getData()));
		keepAdding(rA->getLeft(), rB->getLeft());
		keepAdding(rA->getRight(), rB->getRight());
	}

	//Si hay datos por la izquierda
	else if (rB->getRight()==NULL && rB->getLeft()!=NULL) {
		rA->setLeft(new NodeT(rB->getLeft()->getData()));
		keepAdding(rA->getLeft(), rB->getLeft());
	}

	//Si hay datos por la derecha
	else if (rB->getRight()!=NULL && rB->getLeft()==NULL) {
		rA->setRight(new NodeT(rB->getRight()->getData()));
		keepAdding(rA->getRight(), rB->getRight());		
	}

	else {
		return;
	}
}

//Regresa numero de hijos de un Nodo
int BST::howManyChildren(NodeT *r) {
	
	//Contador de hijos
	int c = 0;

	//Si hay hijo a la izquierda
	if (r->getLeft() != NULL) {
		c++;
	}

	//Si hay hijo a la derecha
	if (r->getRight() != NULL) {
		c++;
	}

	//Regresamos numero de hijos
	return c;
}

//Busca en todo el arbol un dato
bool BST::search(int data) {
	
	//Nodo para recorrer el arbol
	NodeT *curr = root;
	
	//Recorremos el arbol
	while (curr != NULL) {

		//Regresamos verdadero al encontrarlo
		if (curr->getData() == data) {
			return true;
		}

		//Vamos a la derecha o a la izqueirda dependiendo del caso
		curr = (curr->getData() > data) ? 
			curr->getLeft() : curr->getRight();
	}

	//Regresamos falso si no lo encuentra
	return false;
}

//Regresa el dato del nodo predecesor a un nodo
int BST::pred(NodeT *r) {
	
	//Creamos un nodo auxiliar por la izquierda
	NodeT *aux = r->getLeft();

	//Recorremos por la derecha
	while(aux->getRight() != NULL) {
		aux = aux->getRight();
	}

	//Regresamos el nodo predecesor
	return aux->getData();
}

//Regresa el dato sucesor a un nodo
int BST::succ (NodeT *r) {

	//Creamos un nodo auxiliar por la derecha
	NodeT *aux = r->getRight();

	//Recorremos por la izquierda
	while (aux->getLeft() != NULL) {
		aux = aux->getLeft();
	}

	//Regresamos el sucesor
	return aux->getData();
}

void BST::liberar(NodeT *r){
	if (r != NULL) {
		liberar(r->getLeft());
		liberar(r->getRight());
		cout << r->getData() << " ";
	}
}

//Aniade un dato al arbol
void BST::add(int data) {
	
	//Nodos auxiliares
	NodeT *curr = root;
	NodeT *father = NULL;

	//Recorremos el arbol
	while (curr != NULL){
		
		//Si la informacion es la misma, terminamos la funcion
		if (curr->getData() == data) {
			return;
		}
		
		father = curr;

		//Vamos a la derecha o a la izqueirda dependiendo del caso
		curr = (curr->getData() > data) ? 
			curr->getLeft() : curr->getRight();
	}

	//Si el arbole esta vacio, el dato sera la raiz
	if (father == NULL) {
		root = new NodeT(data);
	}

	//Si tiene datos, agregamos 
	else {

		//Agregamos a la izquierda si el dato es menor
		if (father->getData() > data) {
			father->setLeft(new NodeT(data));
		}

		//Agregamos a la derecha si el dato es mayor
		else {
			father->setRight(new NodeT(data));
		}
	}
}

//Elimina un nodo del arbol
void BST::remove(int data) {
		
	//Creamos Nodos auxiliares	
	NodeT *curr = root;
	NodeT *father = NULL;

	//Recorremos todo el nodo hasta encontrar el dato
	while (curr != NULL && curr->getData() != data) {
		
		//Colocamos momentaneamente al padre como curr
		father = curr; 

		//Vamos a la derecha o a la izquierda
		curr = (curr->getData() > data) ? 
				curr->getLeft() : curr->getRight();
	}

	if (curr == NULL) {
		return;
	}

	//Obtenemos el numero de hijos
	int c = howManyChildren(curr);

	switch (c) {

		//Sin hijos
		case 0: 

			//Hay un solo nodo
			if (father == NULL) {
				root = NULL;
			}

			//Hay Varios nodos
			else {

				//Movemos a la izquierda si padre es mayor que el dato
				if (father->getData() > data) {
					father->setLeft(NULL);
				}
				
				//Movemos a la derecha si padre es menor que el dato
				else {
					father->setRight(NULL);
				}
			}

			//Borramos el dato
			delete curr;
		break;

		//Un solo hijo
		case 1:  

			if (father == NULL) {

				if (curr->getLeft() != NULL) {
					root = curr->getLeft();
				}

				else {
					root = curr->getRight();
				}
			}

			else {

				if (father->getData() > data) {
					if (curr->getLeft() != NULL) {
						father->setLeft(curr->getLeft());
					}

					else {
						father->setLeft(curr->getRight());
					}
				}

				else {
					if (curr->getLeft() != NULL) {
						father->setRight(curr->getLeft());
					}
					else {
						father->setRight(curr->getRight());
					}
				}
			}

			//Borramos el dato
			delete curr;
		break;

		case 2:
			int x = succ(curr); 	
			remove(x); 				//Removemos x
			curr->setData(x);
		break;	
	}
}

//Desplega el arbol
void BST::print(int c) {
	switch(c) {
		case 1: 
			preOrden(root);
		break;

		case 2: 
			inOrden(root);
		break;
		
		case 3: 
			postOrden(root);
		break;	

		case 4:
			printLeaves(root);
		break;

		case 5:
			levels(root);
		break;	
	}
	cout << endl;
}

//Despliega los datos en preOrden
void BST::preOrden(NodeT *r) {
	if (r != NULL) {
		cout << r->getData() << " ";
		preOrden(r->getLeft());
		preOrden(r->getRight());
	}
}

//Despliega los datos en inOrden
void BST::inOrden(NodeT *r) {
	if (r != NULL) {
		inOrden(r->getLeft());
		cout << r->getData() << " ";
		inOrden(r->getRight());
	}
}

//Desplega los datos en postOrden
void BST::postOrden(NodeT *r) {
	if (r != NULL) {
		postOrden(r->getLeft());
		postOrden(r->getRight());
		cout << r->getData() << " ";
	}
}

//Desplega las hojas del arbol en recorrido postOrden
void BST::printLeaves(NodeT *r) {
	if (r != NULL) {
		
		if (r->getLeft() == NULL && r->getRight() == NULL) {
			cout << r->getData() << " ";
		}

		else {		
			printLeaves(r->getLeft());
			printLeaves(r->getRight());
		}
	
	}	
}

/*Desplega los datos nivel por nivel
void BST::levels(NodeT *r) {

	//Si no hay arbol, terminamos la funcion 
	if (r == NULL)
		return;

	//Creamos fila para llenar los datos 
	queue <NodeT*> q;

	//Tamanio de la fila
	int size;
	
	//Agregamos la raiz
	q.push(r);

	//Mas adelante se rompe esta funcion
	while (true) {

		//Le damos valor al tamanio de la lista
		size = q.size();

		//Si no hay mas elementos, terminamos loop
		if (size == 0)
			break; 

		//Sacamos valores de la fila
		while (size > 0) {

			//Desplegamos dato y sacamos de fila
			NodeT *curr = q.front();
			cout << curr->getData() << " ";
			q.pop();

			//Si hay datos por la izquierda
			if (curr->getLeft() != NULL) {
				q.push(curr->getLeft());
			}

			//Si hay datos por la derecha
			if (curr->getRight() != NULL) {
				q.push(curr->getRight());
			}

			//Actualizamos tamanio
			size--;
		}
	}
}*/

//Manera de wicho de imprimir nivel por nivel
void BST::levels(NodeT *r) {
	if (root != NULL) {
		queue<NodeT*> fila;
		fila.push(root);
		NodeT *curr;

		while (!fila.empty()) {
			curr = fila.front();
			fila.pop();

			cout << curr->getData() << " ";

			if (curr->getLeft() != NULL) {
				fila.push(curr->getLeft());
			}

			if (curr->getRight() != NULL) {
				fila.push(curr->getRight());
			}
		}
	}
}

/*Regresa la altura del arbol
int BST::height() {

	//Si no hay nodos, su altura es 0	
	if (root == NULL){
		return 0;
	}

	//Si hay nodos, llamamos otra funcion
	else {
		return counter(root);
	}
}*/

//Regresa la altura segun wicho
int BST::height() {
	return altura(root);
}

//Regresa la altura segun wicho
int BST::altura(NodeT *r) {
	if (r == NULL) {
		return 0;
	}

	int izq = altura(r->getLeft());
	int der = altura(r->getRight());

	return 1 + (izq > der ? izq : der);
}

//Regresa cuenta los niveles del arbol
int BST::counter(NodeT *r) {

	//Para terminar la funcion
	if (r == NULL) {	
		return 0;
	}

	//Si sigue habiendo nodos
	else {

		//Obtenemos tamanio de arboles con recursividad
		int rightHeight = counter(r->getRight());
		int leftHeight = counter(r->getLeft());

		//Regresamos la rama mas larga que encontremos
		return (rightHeight > leftHeight) ?
			rightHeight+1 : leftHeight+1;
	}
}

//Despliega los ancestros de un dato iniciando desde el padre
void BST::ancestors(int data) {

	//Stack para almacenar los ancestros
	stack<int> ancestors;
	
	//Nodo auxiliar para recorrer el BST
	NodeT *curr = root;

	//Para terminar la funcion
	bool end = true;

	//Recorremos el BST
	while (curr != NULL && end) {

		//Si encontramos el dato en el BST
		if (curr->getData() == data) {
			while (!ancestors.empty()) {
				cout << ancestors.top() << " ";
				ancestors.pop();
				end = false;
			}
		}

		//Si no encontramos el dato en el BST
		else {

			//Agregamos el dato al stack
			ancestors.push(curr->getData());

			//Vamos a la derecha o izquierda segun sea el caso
			curr = (curr->getData() > data) ?
				curr->getLeft() : curr->getRight();
		}
	}
}

//Regresa el nivel en el que el dato se encuentra
int BST::whatLevelamI(int data) {

	//Nodo para recorrer el arbol
	NodeT *curr = root;
	
	//Contador de niveles
	int level = 0;

	//Recorremos el arbol
	while (curr != NULL) {

		//Regresamos verdadero al encontrarlo
		if (curr->getData() == data) {
			return level;
		}

		//Vamos a la derecha o a la izqueirda dependiendo del caso
		curr = (curr->getData() > data) ? 
			curr->getLeft() : curr->getRight();

		//Aumentamos tamanio a level
		level++;	
	}

	//Regresamos falso si no lo encuentra
	return -1;
}

//Regresa el numero de nodos del arbol
int BST::count() {
	return cuantos(root);
}

//Cuenta los arboles
int BST::cuantos(NodeT *r) {
	if (r == NULL) {
		return 0;
	}

	return 1+cuantos(r->getLeft()) + cuantos(r->getRight());
}

//Voltea un arbol (mayores izquierdo, menores derecho)
void BST::mirror() {
	
	//Si el arbol esta vacio terminamos la funcion
	if (root == NULL) {
		return;
	}

	//Si tiene datos
	else {

		//Usamos la funcion change para intercambiar los nodos
		change(root);
	}
}

//Intercambia nodos de manera recursiva
void BST::change(NodeT *r) {
	
	//Terminamos funcion si es NULL
	if (r == NULL) {
		return;
	}

	//Nodo auxiliar
	NodeT *aux = r->getRight();

	//Intercambiamos nodos
	r->setRight(r->getLeft());
	r->setLeft(aux);

	//Repetimos recursivamente
	change(r->getLeft());
	change(r->getRight());
}

//Indica si dos arboles son iguales
/*bool BST::operator==(BST tree) {
	
	// Si no hay datos en el arbol, terminamos programa
	if (root == NULL && tree.root == NULL) {
		return true;
	}

	//Si hay datos en el arbol
	else {
		
		//Creamos variable que indica si los arboles son iguales
		bool validator = true;

		//Ejecutamos funcion recursiva que verifica nodos
		equal(root, tree.root, validator);

		//Regresamos de vaidator
		return validator;
	}
}

//Indica si dos nodos son iguales
void BST::equal(NodeT *rA, NodeT *rB, bool &validator) {

	//Terminar funcion recursiva
	if ((rA == NULL && rB == NULL) || validator == false)
		return;

	//Si uno es NULL y el otro no
	if ((rA==NULL && rB!=NULL) || (rA!=NULL && rB==NULL)) {
		validator = false;
		return;
	}

	//Si los datos son distintos
	if (rA->getData() != rB->getData()) {
		validator = false;
		return;
	}

	//Repetimos funciones recursivas en ambos extremos
	equal(rA->getLeft(), rB->getLeft(), validator);
	equal(rA->getRight(), rB->getLeft(), validator);
}*/

bool BST::operator== (BST tree) {
	
	//Si el arbol esta vacio
	if (root == NULL && tree.root == NULL) {
		return true;
	}

	//Si tiene datos
	else {

		//Verifica que los arboles sean iguales
		bool validator = true;

		//Ejecutamos la funcion
		equal(root, tree.root, validator);
  
  		//Regresamos el valor de validador
		return validator;
	}
}

//Modifica la variable validator 
void BST::equal(NodeT *rA, NodeT *rB, bool &validator) {

	if (validator == false) {
		return;
	}
	else if (rA==NULL && rB==NULL) {
		return;
	} 
	else if ((rA==NULL && rB!=NULL) || (rA!=NULL && rB==NULL)) {
		validator =  false;
		return;
	}
	else if (rA->getData() != rB->getData()) {
		validator = false;
	}

	equal(rA->getLeft(), rB->getLeft(), validator);
	equal(rA->getRight(), rB->getRight(), validator);		
}

//Regresa el numero con el pariente comun mas cercano
int BST::nearstRelative(int data1, int data2) {

	//Dato mayor y menor
	int max, min;

	//Para viajar por el arbol
	NodeT *curr = root;

	//Si los datos son iguales
	if (data1 == data2) {
		cout << "Son iguales";
		return data1;
	}

	//Definimos el mayor y el menor
	if (data1 > data2) {
		max = data1;
		min = data2;
	} else {
		max = data2;
		min = data1;
	}

	//Si la raiz es el nodo mas cercano
	if (max>curr->getData() && min<curr->getData()) {
		return curr->getData();
	}

	//Si los datos son mas chicos, vamos por la izquierda
	while (max<curr->getData() && min<curr->getData()) {
		curr = curr->getLeft();
	}

	//Si los datos son mas grandes, vamos por la derecha
	while (max>curr->getData() && min>curr->getData()) {
		curr = curr->getRight();
	}

	//Regresamos el valor que curr nos haya dado
	return curr->getData();
}

//Regresa la maxima anchura del arbol
int BST::maxWidth(){
	
	//Nodo auxiliar para recorrer el arbol
	NodeT *curr = root;

	//Fila para almacenar datoss
	queue<NodeT*> fila;
	fila.push(curr);
	
	//Variables auxiliares
	int count= 1; 		//Contador de nodos de un nivel
	int max = 0;		//Numero maximo de nodos en un arbol
	int currNum = 1; 	//Numero en el que nos encontramos
	
	//Realizamos una accion si hay datos en el arbol
	if (curr != NULL){
		
		//Por ahora, la anchura mas grande es 1
		max = 1;

		//Recorremos la fila
		while (fila.front() != NULL){
			
			//La cuenta de nuestro nodo es 0
			count = 0;

			//Recorremos los nodos
			while (currNum > 0){

				//Si hay elementos por la izqueirda	
				if (fila.front()->getLeft() != NULL){
					
					//Entran a la fila
					fila.push(fila.front()->getLeft());
					count++;
				}

				//Si hay elementos por la derecha
				if (fila.front()->getRight() != NULL){
					
					//Entran a la fila
					fila.push(fila.front()->getRight());
					count++;
				}

				//Sacamos el primer elemento de la fila
				fila.pop();
				currNum--;
			}

			//Actualizamos el numero actual
			currNum = count;
			
			//Modificamos mac si encontramos un numero mas grande
			if (count > max)
				max = count;
		}
	}
	return max;
}
