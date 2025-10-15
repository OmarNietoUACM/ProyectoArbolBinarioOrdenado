#ifndef LISTALIGADASIMPLE_H
#define LISTALIGADASIMPLE_H
#include<iostream>
#include <new>
#include "NodoLLS.h"

using namespace std;


template <class T>
class Fila
{
private:
    NodoLLS<T> *pIni;
    NodoLLS<T> *pFin;

    public:
        Fila();

        // Agrega el dato al final de lista
        void AgregarFinal(T dato);

        //Imprime la lista
        void Imprimir();

        T ExtraerInicio();


        void Vaciar();
        //Regresa verdadero si la lista está vaciar
        //y falso en caso contrario
        bool EstaVacia();



        virtual ~Fila();

    protected:
        NodoLLS<T> *CrearNodoLLS(T dato);

    private:

};


template <class T>
Fila<T>::Fila()
{
    pIni = NULL;
    pFin = NULL;
}

template <class T>
NodoLLS<T> *Fila<T>::CrearNodoLLS(T dato)
{
    //Creación de un nuevo nodo
    NodoLLS<T> *pNodo = NULL;

    try{
        pNodo = new NodoLLS<T>(dato);
    }
    catch(bad_alloc){
        cout << "ERROR: No se puede crear un nuevo nodo" <<endl;
        cout << " error en la asignación dinámica de memoria" <<endl;
    }

    return pNodo;
}


// Agrega el dato al final de lista
template <class T>
void Fila<T>::AgregarFinal(T dato)
{
    //Creación de un nuevo nodo
    NodoLLS<T> *pNodo = CrearNodoLLS(dato);
    if (pNodo == NULL) return;

    //caso 1: La lista está vacia
    if (EstaVacia())
    {
        pIni = pNodo;
        pFin = pNodo;

    }
    else {
        //No está vacia la lista
        pFin->pSig = pNodo;
        pFin = pNodo;
    }
}


//Imprime la lista
template <class T>
void Fila<T>::Imprimir()
{
    NodoLLS<T> *p = pIni;

    cout << "{ ";
    while (p!=NULL)
    {
        cout << p->dato << ", ";
        p = p->pSig;
    }
    cout << " }" <<endl;

}



//Obtiene el dato de la posición especificada
//por el índice sin extraerlo de la lista
/*
template <class T>
NodoLLS<T> *Fila<T>::ExtraerInicio()
{
    NodoLLS<T> *nodo = pIni;
    if (pIni != NULL){
        pIni = pIni->pSig;
        nodo->pSig = NULL;
    }
    return nodo;
}
*/


template <class T>
T Fila<T>::ExtraerInicio()
{
    T valor;

    NodoLLS<T> *nodo = pIni;
    if (pIni != NULL)
    {
        pIni = pIni->pSig;
        valor = nodo->dato;
        delete nodo;
    }

    return valor;
}



//Vacía todos los elementos en la lista
template <class T>
void Fila<T>::Vaciar()
{
    NodoLLS<T> *p = pIni;
    while (p!=NULL)
    {
        p = p->pSig;
        delete pIni;
        pIni = p;
    }
    pFin = NULL;
}

//Regresa verdadero si la lista está vaciar
//y falso en caso contrario
template <class T>
bool Fila<T>::EstaVacia()
{
    return pIni == NULL;
}





template <class T>
Fila<T>::~Fila()
{
    //dtor
    Vaciar();  //Se libera la memoria
}





#endif // LISTALIGADASIMPLE_H
