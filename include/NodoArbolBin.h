#ifndef NODOARBOLBIN_H
#define NODOARBOLBIN_H

#include <iostream>

using namespace std;


template <class T>
class NodoArbolBin
{
public:
    T info;
    NodoArbolBin<T> *pIzq;
    NodoArbolBin<T> *pDer;

public:
    NodoArbolBin();
    NodoArbolBin(T info);
    virtual ~NodoArbolBin();
};

template <class T>
NodoArbolBin<T>::NodoArbolBin()
{
    pIzq = NULL;
    pDer = NULL;
}

template <class T>
NodoArbolBin<T>::NodoArbolBin(T info)
{
    this->info = info;
    pIzq = NULL;
    pDer = NULL;
}

template <class T>
NodoArbolBin<T>::~NodoArbolBin()
{
}


#endif // NODOARBOLBIN_H
