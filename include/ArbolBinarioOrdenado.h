#ifndef ARBOLBINARIOORDENADO_H
#define ARBOLBINARIOORDENADO_H

#include "NodoArbolBin.h"
#include "Fila.h"


template <class T>
class ArbolBinarioOrdenado
{
    protected:
        NodoArbolBin<T> *pRaiz;
    public:
        ArbolBinarioOrdenado();

        void Agregar(T valor);
        /*
        void Eliminar(T info);
        */

        T *Buscar(T valor);
        T *BuscarRecursivo(T valor);
        T *BuscarRecursivo(T valor,  NodoArbolBin<T> *pNodo);

        bool EstaVacio();

        //REcorridos
        // REcorrido Primero en Amplitud, de arriba hacia abaj
        // y de Izquierda a derecha

        void RecorridoAmplitudArribaAbajoIzqDer();
        void RecorridoAmplitudArribaAbajoDerIzq();

        //Recorridos primero en profundidad
        // VLR PReorden
        void Preorden();
        void RecorrerVLR(NodoArbolBin<T> *nodo);
        void EnOrden();
        void RecorrerLVR(NodoArbolBin<T> *nodo);
        void PostOrden();
        void RecorrerLRV(NodoArbolBin<T> *nodo);



        virtual ~ArbolBinarioOrdenado();
private:
        void Visitar(NodoArbolBin<T> *nodo);
};

template <class T>
ArbolBinarioOrdenado<T>::ArbolBinarioOrdenado()
{
    pRaiz = NULL;
}

template <class T>
bool ArbolBinarioOrdenado<T>::EstaVacio()
{
    return pRaiz == NULL;
}



// Recorrido en profundidad
template <class T>
void ArbolBinarioOrdenado<T>::Preorden()
{
    RecorrerVLR(pRaiz);
}

template <class T>
void ArbolBinarioOrdenado<T>::RecorrerVLR(NodoArbolBin<T> *nodo)
{
    if (nodo == NULL) return;
    Visitar(nodo);
    if(nodo->pIzq != NULL)
        RecorrerVLR(nodo->pIzq);
     if(nodo->pDer != NULL)
        RecorrerVLR(nodo->pDer);
}


template <class T>
void ArbolBinarioOrdenado<T>::EnOrden()
{
    RecorrerLVR(pRaiz);
}

template <class T>
void ArbolBinarioOrdenado<T>::RecorrerLVR(NodoArbolBin<T> *nodo)
{
    if (nodo == NULL) return;

    if(nodo->pIzq != NULL)
        RecorrerLVR(nodo->pIzq);
    Visitar(nodo);
    if(nodo->pDer != NULL)
        RecorrerLVR(nodo->pDer);
}


template <class T>
void ArbolBinarioOrdenado<T>::PostOrden()
{
    RecorrerLRV(pRaiz);
}

template <class T>
void ArbolBinarioOrdenado<T>::RecorrerLRV(NodoArbolBin<T> *nodo)
{
    if (nodo == NULL) return;

    if(nodo->pIzq != NULL)
        RecorrerLRV(nodo->pIzq);
    if(nodo->pDer != NULL)
        RecorrerLRV(nodo->pDer);
     Visitar(nodo);
}


template <class T>
void ArbolBinarioOrdenado<T>::RecorridoAmplitudArribaAbajoIzqDer()
{
    if (pRaiz == NULL) return;

    Fila<NodoArbolBin<T> *> cola;
    NodoArbolBin<T> *nodo = NULL;

    cola.AgregarFinal(pRaiz);
    while(!cola.EstaVacia())
    {
        nodo = cola.ExtraerInicio();
        if (nodo->pIzq != NULL)
            cola.AgregarFinal(nodo->pIzq );
        if (nodo->pDer != NULL)
            cola.AgregarFinal(nodo->pDer);

        Visitar(nodo);
    }
}


template <class T>
void ArbolBinarioOrdenado<T>::RecorridoAmplitudArribaAbajoDerIzq()
{
    if (pRaiz == NULL) return;

    Fila<NodoArbolBin<T> *> cola;
    NodoArbolBin<T> *nodo = NULL;

    cola.AgregarFinal(pRaiz);
    while(!cola.EstaVacia())
    {
        nodo = cola.ExtraerInicio();

        if (nodo->pDer != NULL)
            cola.AgregarFinal(nodo->pDer);
        if (nodo->pIzq != NULL)
            cola.AgregarFinal(nodo->pIzq );

        Visitar(nodo);
    }
}



template <class T>
void ArbolBinarioOrdenado<T>::Agregar(T valor)
{
    NodoArbolBin<T> *prev = NULL;
    NodoArbolBin<T> *pNodo = pRaiz;

    //Recorrido del árbol
    while(pNodo  != NULL)
    {
        prev = pNodo;
        if (valor < pNodo->info)
            pNodo = pNodo->pIzq;
        else if (valor > pNodo->info)
            pNodo = pNodo->pDer;
        else{
            cout << "El valor: " <<valor << " ya se encuentra en el arbol" <<endl;
            return;
        }
    }

    //Inserción de la información
    NodoArbolBin<T> *nuevoNodo = new NodoArbolBin<T>(valor);
    if (pRaiz == NULL) pRaiz = nuevoNodo;
    else if (valor < prev->info)
        prev->pIzq = nuevoNodo;
    else
        prev->pDer = nuevoNodo;
}



template <class T>
void ArbolBinarioOrdenado<T>::Visitar(NodoArbolBin<T> *nodo)
{

    cout << nodo->info << ", ";
}




template <class T>
T *ArbolBinarioOrdenado<T>::Buscar(T valor)
{
    NodoArbolBin<T> *nodo = pRaiz;

    while (nodo != NULL)
    {
        if (valor == nodo->info)
            return &nodo->info;
        if (valor <  nodo->info)
            nodo = nodo->pIzq;
        else
            nodo = nodo->pDer;
    }
    return NULL;
}


template <class T>
T *ArbolBinarioOrdenado<T>::BuscarRecursivo(T valor)
{
    return BuscarRecursivo(valor, pRaiz);
}

template <class T>
T *ArbolBinarioOrdenado<T>::BuscarRecursivo(T valor,  NodoArbolBin<T> *pNodo)
{
    if (pNodo == NULL) return NULL;
    if (pNodo->info == valor) return pNodo->info;
    if (valor < pNodo->info) return BuscarRecursivo(valor, pNodo->pIzq);
    else return BuscarRecursivo(valor, pNodo->pDer);
}

template <class T>
ArbolBinarioOrdenado<T>::~ArbolBinarioOrdenado()
{
    //dtor
}


#endif // ARBOLBINARIOORDENADO_H
