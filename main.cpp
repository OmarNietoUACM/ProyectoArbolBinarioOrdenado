#include <iostream>
//#include "NodoLLS.h"
#include "Fila.h"
#include "ArbolBinarioOrdenado.h"

using namespace std;

int main()
{

    ArbolBinarioOrdenado<int> arbol;

    arbol.Agregar(30);
    arbol.Agregar(65);
    arbol.Agregar(35);
    arbol.Agregar(29);
    arbol.Agregar(5);
    arbol.Agregar(20);
    arbol.Agregar(50);
    arbol.Agregar(3);
    arbol.Agregar(11);

   // arbol.RecorridoAmplitudArribaAbajoDerIzq();

    cout <<"REcorrido en PreOrden:" <<endl;
    arbol.Preorden();
    cout <<endl <<"REcorrido en orden:" <<endl;
    arbol.EnOrden();
    cout <<endl <<"REcorrido en PostOrden:" <<endl;
    arbol.PostOrden();

    arbol.BorrarPorFusion(30);

    cout <<"\nBorrar 50 por fusion:" <<endl;
    cout <<"REcorrido en PreOrden:" <<endl;
    arbol.Preorden();
    cout <<endl <<"REcorrido en orden:" <<endl;
    arbol.EnOrden();
    cout <<endl <<"REcorrido en PostOrden:" <<endl;
    arbol.PostOrden();


   arbol.Vaciar();
   arbol.Agregar(6);
   arbol.Agregar(9);
   arbol.Agregar(3);
   arbol.Agregar(7);

    cout <<endl <<"REcorrido en orden:" <<endl;
   arbol.EnOrden();







     //NodoLLS<float> nodo;

    /*
    Fila<string> cola;

    cola.AgregarFinal("hola");
    cola.AgregarFinal("UACM");
    cola.AgregarFinal("Word");

    cout << cola.ExtraerInicio() << endl;
    cout << " " << cola.ExtraerInicio() << endl;
    cout << " " << cola.ExtraerInicio() << endl;
    */



    return 0;
}
