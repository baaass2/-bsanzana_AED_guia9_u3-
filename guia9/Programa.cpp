#include<bits/stdc++.h> 
using namespace std; 
#include "Hash.h"

int menu(){
	string opc;
	cout << "----------------------------------------" << endl;
	cout << "\t\t[ MENU ]" << endl;
	cout << "----------------------------------------" << endl;
	cout << " [1] Insertar Numeros al Arreglo" << endl;
	cout << " [2] Buscar numero en Arreglo" << endl;
	cout << " [3] Salir" << endl;
	cout << "----------------------------------------" << endl;
	cout << " Opcion: ";

	getline(cin,opc);
    
	while( (stoi(opc) != 3 ) and (stoi(opc) != 1) and (stoi(opc) != 2) ){
		cout << "\n**Opcion no valida**" << endl;
		cout << " Opcion: ";
		getline(cin,opc);
	}
	return stoi(opc);
}
void RellenarArreglo(int Arreglo[], int N){
	for(int i=0; i<N; i++){
		Arreglo[i] = '\0';
	}
}
void ImprimirArreglo(int Arreglo[], int N){
	cout << "----------------------------------------" << endl;
	cout << "**Arreglo**" << endl;
	for(int i=0; i<N; i++){
		if(Arreglo[i] == 0){
			cout << "[*]-";
		}
		else{
			cout << "["<< Arreglo[i] << "]-";
		}
	}
	cout << endl;
	cout << "----------------------------------------" << endl;
}

//Reconocer si el arreglo esta completamente vacio.
bool ArregloVacio(int Arreglo[], int N){
	int contador=0;
	for(int i=0; i<N; i++){
		if(Arreglo[i] == '\0'){
			contador++;
		}
	}
	if(contador == N){
		return true;
	}
	else{
		return false;
	}
}

//Función de inserción dependiendo del metodo señalado por el usuario.
void EjecutarPruebaInsercion(int Arreglo[], int N, int k, string metodoColision){
	Hash *hash = new Hash();
	//Prueba Lineal
	if( (metodoColision.compare("L")==0) || (metodoColision.compare("l")==0)){
		hash->PruebaLinealInsertar(Arreglo, N, k);
	}
	//Prueba Cuadratica
	else if( (metodoColision.compare("C")==0) || (metodoColision.compare("c")==0)){
		hash->PruebaCuadraticaInsertar(Arreglo, N, k);
	}
	//Prueba Doble direccion
	else if( (metodoColision.compare("D")==0) || (metodoColision.compare("d")==0)){
		hash->DobleDireccionInsertar(Arreglo, N, k);
	}
}
//Función ejecuta la resolución de las colisiones a través de la opción señalada por el usuario.
void EjecutarPrueba(int Arreglo[], int N, int k, string metodoColision){
	Hash *hash = new Hash();
	//Prueba Lineal
	if( (metodoColision.compare("L")==0) || (metodoColision.compare("l")==0)){
		hash->PruebaLineal(Arreglo, N, k);
	}
	//Prueba Cuadratica
	else if( (metodoColision.compare("C")==0) || (metodoColision.compare("c")==0)){
		hash->PruebaCuadratica(Arreglo, N, k);
	}
	//Prueba Doble direccion
	else if( (metodoColision.compare("D")==0) || (metodoColision.compare("d")==0)){
		hash->DobleDireccion(Arreglo, N, k);
	}
}

bool revisarOpcion(string metodoColision){
    bool aux= false;
	if( (metodoColision.compare("L")==0) || (metodoColision.compare("l")==0)){
        aux=true;
	}
	else if( (metodoColision.compare("C")==0) || (metodoColision.compare("c")==0)){
		aux=true;
	}
	else if( (metodoColision.compare("D")==0) || (metodoColision.compare("d")==0)){
		aux=true;
	}
    return aux;
}

int main(int argc, char *argv[]){
    
	system("clear");
    		
	int N=20, opcion=0;
    bool aux = NULL;
    
	string metodoColision;

	if( argc == 2){
		metodoColision = argv[1];
	}
	else{
		cout << "Se necesita escribir parametro [L|C|D]" << endl;
		return 0;
	}
    aux=revisarOpcion(metodoColision);
    if(aux == false){
        cout << "Parametro erroneo, escoja estos [L|C|D]" << endl;
        return 0;
    }
	string line;
	int numero;
	int posicion;
	int Arreglo[N];
	RellenarArreglo(Arreglo, N);
	Hash *hash = new Hash();

	while(opcion!=3){
		opcion = menu();
		system("clear");
		switch(opcion){
			//Insertar numero en arreglo
			case 1:
				cout << "Ingrese numero: ";
				getline(cin,line);
				numero = stoi(line);
				//Obtencion de posicion con Hash
				posicion = hash->HashModulo(numero, N);
				//Si no existe nada en esa posicion se asigna 
				if(Arreglo[posicion] == '\0'){
					Arreglo[posicion] = numero;
					ImprimirArreglo(Arreglo, N);
				}
				//De lo contrario existe colision y se debe ejecutar algun metodo
				else{
					cout << "Colision en posicion: " << posicion << endl;
					EjecutarPruebaInsercion(Arreglo, N, numero, metodoColision);
					ImprimirArreglo(Arreglo, N);
				}
				break;
			//Busqueda de elemento en arreglo
			case 2:
				//Si arreglo no esta vacio entonces se puede buscar
				if(ArregloVacio(Arreglo, N) == false){
					cout << "Ingrese numero: ";
					getline(cin,line);
					numero = stoi(line);
					//Obtencion de posicion con Hash
					posicion = hash->HashModulo(numero, N);
					if(Arreglo[posicion] == numero){
						cout << "Clave se encuentra en posicion: " << posicion << endl;
						ImprimirArreglo(Arreglo, N);
					}
					else{
						EjecutarPrueba(Arreglo, N, numero, metodoColision);
						ImprimirArreglo(Arreglo, N);
					}
				}
				else{
					cout << "*Arreglo Vacio*" << endl;
				}
				break;
			
			case 3:
				break;
		}
	}
}
