#include <iostream>
#include <stack>
#include <queue>
#include "NodeT.h"

using namespace std;

class BST {
	public:
		BST(); 	//Constructor 
		~BST();	//Destructor

		//Operaciones basicas 
		void add(int data); 	//Aniade un Nodo
		bool search(int data);	//Busca un dato
		void remove(int data);	//Elimina un nodo
		void print(int c); 		//Desplega el arbol

		//Operaciones complejas
		int height();				//Regresa la altura del arbol
		void ancestors(int data);	//Desplega los ancestros del arbol
		int whatLevelamI(int data);	//Indica el nivel de un nodo

	private:
		NodeT *root;
		int howManyChildren(NodeT *r);
		int pred(NodeT *r);
		int succ(NodeT *r);
		void preOrden(NodeT *r);
		void inOrden(NodeT *r);
		void postOrden(NodeT *r);
		void levels(NodeT *r);
		void liberar(NodeT *r);
		int counter(NodeT *r);

};

//Constructor
BST::BST() {
	root = NULL;
}

//Destructor
BST::~BST() {
	liberar(root);
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

//Desplega los datos nivel por nivel
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
}

//Regresa la altura del arbol
int BST::height() {

	//Si no hay nodos, su altura es 0	
	if (root == NULL){
		return 0;
	}

	//Si hay nodos, llamamos otra funcion
	else {
		return counter(root);
	}
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
