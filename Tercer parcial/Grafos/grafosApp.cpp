#include <iostream>
#include <queue>

using namespace std;
#define N 10				//Constante

//Inicializa matriz
void iniMatAdj(bool matAdj[N][N]) {
	
	//Recorremos matriz
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			
			//Todos los datos son falsos
			matAdj[i][j] = false;
		}
	}
}

//Lee la matriz adyacente
void leeMatAdj(bool matAdj[N][N], int e) {
	
	//Variables de origen y destino (Se piden al usuario)
	int orig, dest;

	for (int i=1; i<=e; i++) {
		cin >> orig >> dest;
		matAdj[orig-1][dest-1] = matAdj[dest-1][orig-1] = true;
	}
}

//Recorrido en Anchura primero 
void BFS(bool matAdj[N][N], int v) {
	
	queue<int> fila; 			//Datos
	int dato;					//Dato auxiliar
	vector<bool> status(v); 	//Status
	fila.push(0); 				//Metemos el primer dato

	status[0] = true; 

	//Vaciamos fila
	while (!fila.empty()) {
		dato = fila.front();
		fila.pop();
		cout << (dato+1) << " ";
		
		for (int j=0; j<v; j++) {
			if (!status[j] && matAdj[dato][j]) {
				status[j] = true;
				fila.push(j);
			}
		}
	}

	cout << endl;
}

//Recorrido en Profundidad primero
void DFS(bool matAdj[N][N], int v) {
	
}

//Imprime la matriz
void printMatAdj(bool matAdj[N][N], int v) {

	//Recorremos la matriz 
	for (int i=0; i<v; i++) {
		for (int j=0; j<v; j++) {
			cout << (matAdj[i][j] ? "T" : "F") << "\t";
		}
		cout << endl;
	}
}

int main() {

	bool matAdj[N][N]; 			//Matriz con los datos (10x10)
	int v, e; 					//Numero de Arcos y de Vertices

	cin >> v >> e;				//Pedimos Arcos y vertices al usuario

	iniMatAdj(matAdj); 			//Matriz con todos sus datos en falso
	leeMatAdj(matAdj, e); 		//Obtiene datos de usuario
	printMatAdj(matAdj, v); 	//Despliega la matriz

	BFS(matAdj, v); 			//Recorremos el grafo en Anchura primero
	DFS(matAdj, v); 			//Recorremos el grafo en Profundidad primero

	return 0; 					//Terminamos programa
}