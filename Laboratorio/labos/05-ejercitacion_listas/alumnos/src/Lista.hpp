#include "Lista.h"

Lista::Lista(): _primerNodo(nullptr), _ultimoNodo(nullptr), _longitud(0) {}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::Nodo::Nodo(int v): valor(v), siguiente(nullptr), anterior(nullptr) {}

Lista::~Lista() {
    // todo: falta hacer que este metodo ande :_)
//    if(this->_primerNodo != nullptr) delete this->_primerNodo;
//    if(this->_ultimoNodo != nullptr)  delete this->_ultimoNodo;
    for (Nodo* nodo = this->_primerNodo; nodo != nullptr; nodo = nodo->siguiente) {
        delete nodo->siguiente;
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    this->_primerNodo = nullptr;
    this->_ultimoNodo = nullptr;
    this->_longitud = 0;
    for (Nodo* nodoAC = aCopiar._primerNodo; nodoAC != nullptr; nodoAC = nodoAC->siguiente) {
        this->agregarAtras(nodoAC->valor);
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nodo = new Nodo(elem);

    if (this->_primerNodo == nullptr) {
        this->_ultimoNodo = nodo;
    } else {
        this->_primerNodo->anterior = nodo;  // apunto el anterior del primer Nodo(antiguo) al nuevo primer Nodo
        nodo->siguiente = this->_primerNodo; // apunto el siguiente del nuevo nodo al primer anterior

    }

    this->_primerNodo = nodo;            // ahora seteo el nuevo primer nodo de la lista

    this->_longitud++;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nodo = new Nodo(elem);

    if (this->_ultimoNodo == nullptr) {
        this->_primerNodo = nodo;
    } else {
        this->_ultimoNodo->siguiente = nodo;
        nodo->anterior = this->_ultimoNodo;
    }

    this->_ultimoNodo = nodo;

    this->_longitud++;
}

void Lista::eliminar(Nat i) {

    if (i >= this->longitud()) return;

    if (this->longitud() == 1) {        // lista con 1 solo nodo
        this->_primerNodo = nullptr;
        this->_ultimoNodo = nullptr;
    } else if (i == 0) {                // eliminar el primero
        this->_primerNodo = this->_primerNodo->siguiente;
        this->_primerNodo->anterior = nullptr;
    } else if (i == this->longitud() - 1) {     // eliminar el ultimo
        this->_ultimoNodo = this->_ultimoNodo->anterior;
        this->_ultimoNodo->siguiente = nullptr;
    } else {                            // eliminar uno intermedio
        Nodo* nodoEliminar = this->_primerNodo;
        while (i > 0) {
            nodoEliminar = nodoEliminar->siguiente;
            i--;
        }
        nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;
        nodoEliminar->siguiente->anterior = nodoEliminar-> anterior;
    }
    this->_longitud--;
}

int Lista::longitud() const {
    return  this->_longitud;
}

const int& Lista::iesimo(Nat i) const {

    Nodo* iesimoNodo = this->_primerNodo;
    while (i > 0) {
        iesimoNodo = iesimoNodo->siguiente;
        i--;
    }
    return iesimoNodo->valor;
}

int& Lista::iesimo(Nat i) {

    Nodo* iesimoNodo = this->_primerNodo;
    while (i > 0) {
        iesimoNodo = iesimoNodo->siguiente;
        i--;
    }
    return iesimoNodo->valor;
}

void Lista::mostrar(ostream& o) {
    // Completar
}
