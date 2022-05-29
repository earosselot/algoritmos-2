#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();

        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T& clave);

        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T& clave) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T& clave);

        // Siguiente elemento al recibido por párametro, en orden.
        const T& siguiente(const T& clave);

        // Devuelve el mínimo elemento del conjunto según <.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar(std::ostream&) const;

    private:

        /**
         * Completar con lo que sea necesario...
         **/

        struct Nodo
        {
            // El constructor, toma el elemento al que representa el nodo.
            Nodo(const T& v);
            // El elemento al que representa el nodo.
            T valor;
            // Puntero a la raíz del subárbol izquierdo.
            Nodo* izq;
            // Puntero a la raíz del subárbol derecho.
            Nodo* der; 
        };

        // Puntero a la raíz de nuestro árbol.
        Nodo* _raiz;

    void insertarEnSubarbol(const T &clave, Nodo *subArbol);

    void removerSubarbol(const T& clave, Nodo* padre, Nodo* nodo, const string& direccion);

    int cardinalSubarbol(Nodo* subArbol) const;

    bool buscarEnSubarbol(Nodo* subArbol, const T& clave) const;

    bool arbolVacio() const;

    bool subArbolVacio(Nodo* subArbol) const;

    bool esHoja(Nodo* subArbol) const;

    void removerEnHijo(const T &clave, Nodo *nodo);

    void removerHoja(Nodo *padre, const Nodo *nodo, const string &direccion) const;

    const T& minimoSubarbol(Nodo* subArbol) const;

    const T& maximoSubarbol(Nodo* subArbol) const;

    void limpiarSubarbol(Nodo *nodo, Nodo *padre, const string &direccion);
};



template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
	 c.mostrar(os);
	 return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_
