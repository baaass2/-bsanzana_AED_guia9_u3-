#include <iostream>
using namespace std;

typedef struct _Nodo{
	int numero;
	struct _Nodo *sig;
} Nodo;

class Hash {
    
  public:
        Hash();
        int HashModulo(int clave, int N);
        int HashAux(int clave, int N);  
        void PruebaLinealInsertar(int Arreglo[], int N, int k);
        void PruebaLineal(int Arreglo[], int N, int k);
        void PruebaCuadraticaInsertar(int Arreglo[], int N, int k);
        void PruebaCuadratica(int Arreglo[], int N, int k);
        void DobleDireccionInsertar(int Arreglo[], int N, int k);
        void DobleDireccion(int Arreglo[], int N, int k);
        void ImprimirLista(Nodo *Arreglo[], int D);
};

