#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto(): _raiz(nullptr) {}

template<class T>
Conjunto<T>::Nodo::Nodo(const T &v): valor(v), izq(nullptr), der(nullptr) {}

template <class T>
Conjunto<T>::~Conjunto() { 
    // todo
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    // todo
    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    // si el arbol esta vacio creo la raiz
    // si valor es mas chico -> insertar en arbol izq
    // si valor es mas grande -> insertar en arbol der
    // si valor es == clave -> no hace nada
    if (this->_raiz == nullptr) {
        Nodo* nodo = new Nodo(clave);
        this->_raiz = nodo;
    } else {
        insertarEnSubarbol(clave, this->_raiz);
    }
}

template<class T>
void Conjunto<T>::insertarEnSubarbol(const T &clave, Nodo* subArbol) {
    if (subArbol->valor > clave) {
        if (subArbol->izq == nullptr) {
            Nodo* nodo = new Nodo(clave);
            subArbol->izq = nodo;
        } else {
            insertarEnSubarbol(clave, subArbol->izq);
        }
    } else if (subArbol->valor < clave) {
        if (subArbol->der == nullptr) {
            Nodo* nodo = new Nodo(clave);
            subArbol->der = nodo;
        } else {
            insertarEnSubarbol(clave, subArbol->der);
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T&) {
    // todo
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    // todo

    return this->_raiz->valor;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    // todo

    return this->_raiz->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    // todo

    return this->_raiz->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    int cardinal = 0;
    if (this->_raiz != nullptr) {
        cardinal += 1;      // la raiz
        if (this->_raiz->izq != nullptr) {
            // todo: pasandole this->_raiz->izq directamente no compila, porque ??
            Nodo* nodoIzq = this->_raiz->izq;
            cardinal += cardinalSubarbol(nodoIzq);
        }
        if (this->_raiz->der != nullptr) {
            Nodo* nodoDer = this->_raiz->der;
            cardinal += cardinalSubarbol(nodoDer);
        }
    }
    return cardinal;
}

template <class T>
int Conjunto<T>::cardinalSubarbol(Nodo* subArbol) const {
    int cardinal = 1;
    if (subArbol->izq != nullptr) {
        cardinal += cardinalSubarbol(subArbol->izq);
    }
    if (subArbol->der != nullptr) {
        cardinal += cardinalSubarbol(subArbol->der);
    }
    return cardinal;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    // todo

}

