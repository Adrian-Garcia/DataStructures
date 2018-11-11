#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Obtiene la lista del usuario
void leerListAdj(vector<vector<int> > &listAdj, int e) {
	
	//Variables de origen y destino (Se piden al usuario)
	int a, b;

	//Leemos los arcos
	for (int i=0; i<e; i++) {
		cin >> a >> b;
		listAdj[a-1].push_back(b-1);
		listAdj[b-1].push_back(a-1);
	}
}

//Imprime la lista
void printListAdj(vector<vector<int> > &listAdj) {

	//Recorremos la matriz 
	for (int i=0; i<listAdj.size(); i++) {
		cout << i+1 << " ";
		for (int j=0; j<listAdj[i].size(); j++) {
			cout << " - " << listAdj[i][j]+1; 
		}
		cout << endl;
	}
}

//Recorrido
void DFS(vector<vector<int> > &listAdj, int v) {
	

	stack<int> pila;					//Pila para meter datos
	int data; 							//Dato auxiliar
	vector<bool> status(v, false); 		//vector de status
	
	//Metemos un elemento a la pila
	pila.push(0);

	//Recorremos la pila hasta que nos quedemos sin datos
	while (!pila.empty()) {
		
		
		data = pila.top();
		pila.pop();

		//Si no se ha revisado ese dato
		if (!status[data]) {
			cout << data+1 << " ";
			status[data] = true;

			for (int i=listAdj[data].size()-1; i>=0; i--) {
				if ( !status[listAdj[data][i]] ) {
					pila.push(listAdj[data][i]);
				}
			}
		}
	}
	cout << endl;
}

int main() {

	//Arcos y Vertices
	int v, e;

	cin >> v >> e;

	//Usaremos una matriz de vectores (vector de vectores)
	vector<vector<int> > listAdj(v);

	//Metodos
	leerListAdj(listAdj, e);
	printListAdj(listAdj);
	DFS(listAdj, v);
}
