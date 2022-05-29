#include "Conjunto.h"

#include <stack>

template <class T>
Conjunto<T>::Conjunto(): _raiz(nullptr) {}

template<class T>
Conjunto<T>::Nodo::Nodo(const T &v): valor(v), izq(nullptr), der(nullptr) {}

template <class T>
Conjunto<T>::~Conjunto() {
    if (this->_raiz != nullptr) {
        limpiarSubarbol(this->_raiz, nullptr, "");
    }
}

template <class T>
void Conjunto<T>::limpiarSubarbol(Nodo* nodo, Nodo* padre, const string& direccion) {
    if (!esHoja(nodo)) {
        if (nodo->izq != nullptr) {
            limpiarSubarbol(nodo->izq, nodo, "IZQ");
        }
        if (nodo->der != nullptr) {
            limpiarSubarbol(nodo->der, nodo, "DER");
        }
    }
    if (direccion == "IZQ") {
        padre->izq == nullptr;
    }
    if (direccion == "DER") {
        padre->der == nullptr;
    }
    delete nodo;
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    if (arbolVacio()) {
        return false;
    }
    return buscarEnSubarbol(this->_raiz, clave);
}

template<class T>
bool Conjunto<T>::buscarEnSubarbol(Conjunto::Nodo *subArbol, const T& clave) const {
    if (subArbol->valor == clave) {
        return true;
    } else if (subArbol->valor > clave) {
        if (subArbolVacio(subArbol->izq)) {
            return false;
        }
        return buscarEnSubarbol(subArbol->izq, clave);
    }
    if (subArbolVacio(subArbol->der)) {
        return false;
    }
    return buscarEnSubarbol(subArbol->der, clave);
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    // si el arbol esta vacio creo la raiz
    // si valor es mas chico -> insertar en arbol izq
    // si valor es mas grande -> insertar en arbol der
    // si valor es == clave -> no hace nada
    if (arbolVacio()) {
        Nodo* nodo = new Nodo(clave);
        _raiz = nodo;
    } else {
        insertarEnSubarbol(clave, this->_raiz);
    }
}

template<class T>
void Conjunto<T>::insertarEnSubarbol(const T &clave, Nodo* subArbol) {
    // si valor == clave no entra en ningun if y no hace nada.
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
void Conjunto<T>::remover(const T& clave) {
    if (cardinal() == 1 && this->_raiz->valor == clave) {
        delete this->_raiz;
        _raiz = nullptr;
    } else {
        removerSubarbol(clave, nullptr, this->_raiz, "");
    }
}

template <class T>
void Conjunto<T>::removerSubarbol(const T& clave, Nodo* padre, Nodo* nodo, const string& direccion) {
    if (nodo->valor == clave) {
        if (esHoja(nodo)) {
            removerHoja(padre, nodo, direccion);
        } else {
            if (!subArbolVacio(nodo->der)) {
                nodo->valor = minimoSubarbol(nodo->der);
                removerSubarbol(nodo->valor, nodo, nodo->der, "DER");
            } else {
                nodo->valor = maximoSubarbol(nodo->izq);
                removerSubarbol(nodo->valor, nodo, nodo->izq, "IZQ");
            }
        }
    } else {
        removerEnHijo(clave, nodo);
    }
}

template<class T>
void Conjunto<T>::removerHoja(Conjunto<T>::Nodo *padre, const Conjunto<T>::Nodo *nodo, const string &direccion) const {
    if (direccion == "IZQ") {
        padre->izq = nullptr;
    } else if (direccion == "DER") {
        padre->der = nullptr;
    }
    delete nodo;
}

template<class T>
void Conjunto<T>::removerEnHijo(const T &clave, Conjunto<T>::Nodo *nodo) {
    if (nodo->valor < clave) {
        removerSubarbol(clave, nodo, nodo->der, "DER");
    } else {
        removerSubarbol(clave, nodo, nodo->izq, "IZQ");
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    // Pre: { c.pertenece(clave) && clave != c.maximo() }
    stack<Nodo*> stack;
    Nodo* actual = this->_raiz;
    bool encontrado = false;

    while (actual != nullptr || stack.empty() == false) {
        // buscamos el nodo mas a la izquierda
        while (actual != nullptr) {
            stack.push(actual);
            actual = actual->izq;
        }
        // termino con actual null y la pila la rama de nodos que va para la izquierda

        actual = stack.top();
        stack.pop();
        if (encontrado) {
            return actual->valor;
        }
        if (actual->valor == clave) {
            encontrado = true;
        }

        // ahora recorremos el subarbol derecho
        actual = actual->der;
    }
}

template <class T>
const T& Conjunto<T>::minimo() const {
    if (!subArbolVacio(this->_raiz->izq)) {
        return minimoSubarbol(this->_raiz->izq);
    }
    else return this->_raiz->valor;
}

template <class T>
const T& Conjunto<T>::minimoSubarbol(Nodo* subArbol) const {
    if (!subArbolVacio(subArbol->izq)) {
        return minimoSubarbol(subArbol->izq);
    }
    return subArbol->valor;
}

//template <class T>
//const T& Conjunto<T>::maximo() const {
//    Nodo* nodo = this->_raiz;
//    while (!subArbolVacio(nodo->der)) {
//        nodo = nodo->der;
//    }
//    return nodo->valor;
//}

template <class T>
const T& Conjunto<T>::maximo() const {
    if (!subArbolVacio(this->_raiz->der)) {
        return maximoSubarbol(this->_raiz->der);
    }
    else return this->_raiz->valor;
}

template <class T>
const T& Conjunto<T>::maximoSubarbol(Nodo* subArbol) const {
    if (!subArbolVacio(subArbol->der)) {
        return maximoSubarbol(subArbol->der);
    }
    return subArbol->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    int cardinal = 0;
    if (!arbolVacio()) {
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

template<class T>
bool Conjunto<T>::arbolVacio() const {
    if (this->_raiz == nullptr) {
        return true;
    }
    return false;
}

template<class T>
bool Conjunto<T>::subArbolVacio(Nodo* subArbol) const {
    if (subArbol == nullptr) {
        return true;
    }
    return false;
}

template<class T>
bool Conjunto<T>::esHoja(Nodo* subArbol) const {
    if (subArbol->izq == nullptr && subArbol->der == nullptr) {
        return true;
    }
    return false;
}


