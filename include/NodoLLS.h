#ifndef NODOLLS_H
#define NODOLLS_H
#include <iostream>

template<class T>
class NodoLLS
{
public:
    T dato;  //DAto a almacenar en un nodo
    NodoLLS<T> *pSig = NULL;


    public:
        //Constructores
        NodoLLS();
        NodoLLS(T dato);
        NodoLLS(T dato, NodoLLS<T> *pSig);

        virtual ~NodoLLS();

    protected:

    private:
};


template<class T>
NodoLLS<T>::NodoLLS()
{
    pSig = NULL;
}

template<class T>
NodoLLS<T>::NodoLLS(T dato)
{
    this->dato = dato;
    pSig = NULL;
}

template<class T>
NodoLLS<T>::NodoLLS(T dato, NodoLLS<T> *pSig)
{
    this->dato = dato;
    this->pSig = pSig;
}



template<class T>
NodoLLS<T>::~NodoLLS(){
}


#endif // NODOLLS_H
