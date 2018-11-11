#include <iostream>
#include <string>

using namespace std;

//Creamos la estructura de los problemas 
struct Puntos {
	string nombre;	
	int intentos[10];
	int aceptados;
	int tiempo;
}; 

int main() {

	//Varibles
	int numTeam, numProblemas, numIntentos; 	//Inputs de usuario
	int i, j;									//Contadores 
	int tiempo;									//Tiempo de un problema
	string nomTeam;								//Nombre del equipo
	char problema; 								//Nombre del problema 
	char estado; 								//Correcto/Incorrecto
	bool interruptor; 							//Termina for loops

	//Pedimos el numero de equipos y problemas
	cin >> numTeam >> numProblemas;
	
	//Estrcuturas
	Puntos Equipos[numTeam]; 
	Puntos EquipoAux;

	//Insertamos los nombres del equipo
	for (i=0; i<numTeam; i++) {
		cin >> nomTeam;
		
		//Asignamos valores base del equipo
		Equipos[i].nombre = nomTeam;
		Equipos[i].aceptados = 0;
		Equipos[i].tiempo = 0;

		//Inicializamos en 0 todos los intentos de equipo
		for (j=0; j<10; j++) {
			Equipos[i].intentos[j] = -1;
		}
	}

	//Pedimos el numero de intentos
	cin >> numIntentos;

	//Usuario inserta datos de problemas
	for (i=0; i<numIntentos; i++) {
		
		//Pedimos valores
		cin >> nomTeam >> problema >> tiempo >> estado;
		
		//El equipo aun no se encuentra
		interruptor = false;

		//Buscamos el equipo
		for (j=0; j<numTeam && interruptor==false; j++) {
			
			//Si encontramos el equipo
			if (Equipos[j].nombre == nomTeam) {
				
				//Si el problema es aceptado
				if (estado == 'A') { //Si es correcto
					
					//Creamos variables auxiliares 
					int intentos = Equipos[j].intentos[problema-65];
					int tiempoActual = Equipos[j].tiempo;
					int aceptados = Equipos[j].aceptados;
					
					//Cambiamos datos del equipo
					intentos++;
					aceptados++;
					
					//Modificamos la variables auxiliares
					tiempo += intentos*20;
					tiempo += tiempoActual;

					//Modificamos el valor del tiempo del equipo
					Equipos[j].tiempo = tiempo;
					Equipos[j].aceptados = aceptados;
				
					//Indicamos que lo encontramos
					interruptor = true;
				}

				//Si el problema es incorrecto
				else {

					//Igualamos intentos al valor del arreglo
					int intentos =  Equipos[j].intentos[problema-65];
					
					//Sumamos 1 intento
					intentos++;

					//Lo aniadimos al arreglo de equipos
					Equipos[j].intentos[problema-65] = intentos;

					//Indicamos que lo encontramos
					interruptor = true;
				}
			}
		}
	}
	
	//Ahora usamos interruptor para busqueda
	interruptor = true;	//Lo ponemos como verdadero para que entre a loop

	//Ordenamos
	for (i=0; i<numTeam-1 && interruptor; i++) {	//Pasadas
		interruptor = false;

		//Recorremos todo el arreglo
		for (j=0; j<numTeam-1-i; j++) {
			if (Equipos[j+1].aceptados == Equipos[j].aceptados && Equipos[j+1].tiempo > Equipos[j].tiempo) {
			
				//Cambiamos valores
				EquipoAux = Equipos[j];
				Equipos[j] = Equipos[j+1];
				Equipos[j+1] = EquipoAux;
				
				//Indicamos que intercambiamos un numero
				interruptor = true;
			} else if (Equipos[j+1].aceptados < Equipos[j].aceptados) {
				
				//Cambiamos valores
				EquipoAux = Equipos[j];
				Equipos[j] = Equipos[j+1];
				Equipos[j+1] = EquipoAux;
				
				//Indicamos que intercambiamos un numero
				interruptor = true;
			}
		}
	}

	//Contador de lugar
	j=1; 
	
	//Desplegamos todos los datos de
	for (i=numTeam-1; i>=0; i--) {
		cout << j << " - " << Equipos[i].nombre << " " << Equipos[i].aceptados 
		<< " ";

		if (Equipos[i].tiempo != 0) { 	//Desplegamos tiempo si no es 0
			cout << Equipos[i].tiempo << endl;
		} 

		else { //Si es 0, ponemos -	
			cout << "-" << endl;
		}

		//Actualizamos contador 
		j++;	
	} 

	return 0;	//Termianamos programa
}
