/*
Apuntadores y memoria dinamica
	
	Apuntadores 
		Una referencia indirecta a un elemento

			n	| 5 | VAR1
			n+1 | m | VAR2
				|	|
				|	|
				|	|
			m 	| 3 |

		Declaracion en c++
			tipo *nombreApuntador;

			int *apuntador;
			char caracter, *caracterApuntador	
	
		Operador de indireccion
			*varApuntador 			Hace referencia al espacio apuntado por la variable apuntador

		Operador de direccion	
			&varReferencia 			Genera la direccion de la variable. La variable puede ser de cualquier tipo

		Tipos de Memoria
			
			Tipos de almacenamiento de datos
				Estático 			Siemrpre está en uso
				Dinámico 			Se crea y se destruye

			Operadores
				new 			Genera espacio para meter informacion
				delete 			Elimina el espacio junto con la información
	
	Memoria dinamica 

		Decalogo
			1. 	Por cada vez que haya ejecutado un NEW, deberá ejecutarse un DELETE antes de terminar la ejecución de un programa
			2. 	Un DELETE actúa liberando el espacio de memoria apuntado, independientemente de que existan mas apuntadores al mismo espacio
			3. 	Un apuntador local a un modulo, se destruye al terminar la ejecución del mismo, sin importar a que espacio de memoria referencia
					Es importante hacer DELETE antes de terminar la ejecución de un modulo... Revisar...
			4. 	Basura es diferente de nada. Nada = NULL. Basura, son numeros que ocupan memoria
			5. 	Hacer un DELETE, con un apuntador que no hace referencia a un espacio de memoria dinamica, provocará fallas en la ejecución
			6. 	Una referencia a través de un apuntador cuyo valor sea NULL, provocará fallas en la ejecución
			7. 	Al asignar un valor a un apuntador con la operación NEW, el apuntador perderá su valr anterior, independientemente de a qué esté apuntando
			8. 	Para utilizar un apuntador, no siempre se tiene que realiza un NEW
			9. 	Los valores de los apuntadores se pueden comparar para verificar si apuntan a donde mismo
			10.	A un dato referenciado por un apuntador se le pueden aplicar todas las operaciones validas para el tipo de dato	

		Arreglos y apuntadores
			El nombre de un arreglo, es por sí mismo un apuntador al 1er elemento del arreglo
			Los arreglos pueden ser manejados con apuntadores con la siguiente equivalencia
				arreglo[j] es equivalente a *(arreglo+j)
				&arreglo[j] es equivalente a (arreglo+j)
*/