#include <iostream>
#include "Hash.h"

Hash::Hash(){}

//Funciones Hash
int Hash::HashModulo(int clave, int N){
    clave = (clave%N);
    return clave;
}

int Hash::HashAux(int clave, int N){
    clave = (clave+1)%N+1;
    return clave;
}
//IMPLEMENTACIÓN de la inserción de la Reasignación Prueba Lineal
void Hash::PruebaLinealInsertar(int Arreglo[], int N, int k){
    int D, Dx, contador;
    D = HashModulo(k, N);
    if( (Arreglo[D]!='\0') && (Arreglo[D]==k) ){
        cout << "Clave encontrada en posicion: " << D << endl;;
    }
    else{
        Dx = D+1;
        contador = 1;
        while( (Dx!=D) && (Dx<=N) && (Arreglo[Dx]!='\0') && (Arreglo[Dx]!=k) ){
            Dx = Dx+1;
            if(Dx==(N+1)){
                Dx=1;
            }
            contador++;
        }
        if(Arreglo[Dx]=='\0'){
            Arreglo[Dx]=k;
            cout << "La clave se movio a la posicion: " << Dx << endl;;
        }
        if(contador==N){
            cout << "El arreglo esta lleno*" << endl;
        }
    }
}
//IMPLEMENTACIÓN de la Reasignación Prueba Lineal.
void Hash::PruebaLineal(int Arreglo[], int N, int k){
    int D, Dx;
    D = HashModulo(k, N);
    if( (Arreglo[D]!='\0') && (Arreglo[D]==k) ){
        cout << "Clave encontrada en posicion: " << D << endl;;
    }
    else{
        Dx = D+1;
        while( (Dx!=D) && (Dx<=N) && (Arreglo[Dx]!='\0') && (Arreglo[Dx]!=k) ){
            Dx = Dx+1;
            if(Dx==(N+1)){
                Dx=1;
            }
        }
        if( (Arreglo[Dx]=='\0') || (Dx==D)){
            cout << "La clave no se encuentra en el arreglo"<< endl;;
        }
        else{
            cout << "La clave esta en posicion: " << Dx << endl;
        }
    }
}
//IMPLEMENTACIÓN de la inserción de la Reasignación Prueba Cuadratica.
void Hash::PruebaCuadraticaInsertar(int Arreglo[], int N, int k){
    int D,Dx,i;
    D = HashModulo(k, N);
    if( (Arreglo[D]!='\0') && (Arreglo[D]==k) ){
        cout << "Clave encontrada en posicion: "<< D << endl;
    }
    else{
        i=0;
        Dx = D+(i*i);
        while( (Arreglo[Dx]!='\0') && (Arreglo[Dx]!=k) ){
            i++;
            Dx = D+(i*i);
            if(Dx>N){
                i=0;
                Dx=1;
                D=1;
            }
        }
        if( Arreglo[Dx] == '\0'){
            Arreglo[Dx] = k;
            cout << "Clave desplazada a la posicion: " << Dx << endl;
        }
        else{
            cout << "Clave encontrada en posicion: " << Dx <<endl;
        }
    }
}
//IMPLEMENTACIÓN de la Reasignación Prueba Cuadratica.
void Hash::PruebaCuadratica(int Arreglo[], int N, int k){
    int D,Dx,i;
    D = HashModulo(k, N);
    if( (Arreglo[D]!='\0') && (Arreglo[D]==k) ){
        cout << "Clave encontrada en posicion: "<< D << endl;
    }
    else{
        i=1;
        Dx = D+(i*i);
        while( (Arreglo[Dx]!='\0') && (Arreglo[Dx]!=k) ){
            i++;
            Dx = D+(i*i);
            if(Dx>N){
                i=0;
                Dx=1;
                D=1;
            }
        }
        if( Arreglo[Dx] == '\0'){
            cout << "*Clave no encontrada*" << endl;
        }
        else{
            cout << "Clave encontrada en la posicion: "<< Dx << endl;
        }
    }
}
//IMPLEMENTACIÓN de la inserción de la Reasignación Prueba Doble Dirección.
void Hash::DobleDireccionInsertar(int Arreglo[], int N, int k){
    int D, Dx;
    D = HashModulo(k, N);
    if( (Arreglo[D]!= '\0') && (Arreglo[D]==k) ){
        cout << "Clave encontrada en posicion: " << D << endl;
    }
    else{
        Dx = HashAux(D, N);
        while( (Dx<=N) && (Dx!=D) && (Arreglo[Dx]!=k) && (Arreglo[Dx]!='\0') ){
            Dx = HashAux(Dx, N);
        }
        if( (Arreglo[Dx]=='\0') || (Arreglo[Dx]!=k) ){
            Arreglo[Dx]=k;
            if(Dx==21){
                cout << "*Arreglo lleno*" << endl;
            }
            else{ 
                cout << "Clave desplazada a posicion: " << Dx << endl;
            }
        }
        else{
            cout << "Clave encontrada en posicion: " << Dx << endl;
        }
    }
}
//IMPLEMENTACIÓN de la Reasignación Doble Dirección.
void Hash::DobleDireccion(int Arreglo[], int N, int k){
    int D, Dx;
    D = HashModulo(k, N);
    if( (Arreglo[D]!='\0') && (Arreglo[D]==k) ){
        cout << "La clave esta en la posicion: " << D << endl;
    }
    else{
        Dx = HashAux(D, N);
        while( (Dx<=N) && (Arreglo[Dx]!='\0') && (Arreglo[Dx]!=k) && (Dx!=D) ){
            Dx = HashAux(Dx, N);
        }
        if( (Arreglo[Dx]=='\0') || (Dx==D) ){
            cout << "La clave no se encuentra en el arreglo" << endl;
        }
        else{
            cout << "La clave esta en la posicion: " << Dx << endl;
        }
    }
}
void Hash::ImprimirLista(Nodo *Arreglo[], int D){
    Nodo *aux = NULL;
    aux = Arreglo[D];
    while(aux!=NULL){
        if(aux->numero != 0){
            cout << "(" << aux->numero << ")- " << endl;
        }
        aux = aux->sig;
    }
}
