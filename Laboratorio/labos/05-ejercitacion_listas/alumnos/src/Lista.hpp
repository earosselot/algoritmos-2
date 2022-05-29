#include "Lista.h"

Lista::Lista(): _primerNodo(nullptr), _ultimoNodo(nullptr), _longitud(0) {}

Lista::Lista(const Lista& l) : Lista() {
    // Inicializa una lista vacía y luego utiliza operator= para no duplicar el 
    // código de la copia de una lista.
    *this = l;
}

Lista::Nodo::Nodo(int v): valor(v), siguiente(nullptr), anterior(nullptr) {}

Lista::~Lista() {
    limpiarLista();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    limpiarLista();
    this->_primerNodo = nullptr;
    this->_ultimoNodo = nullptr;
    this->_longitud = 0;
    Nodo* nodoCopiar = aCopiar._primerNodo;
    while (nodoCopiar != nullptr) {
        this->agregarAtras(nodoCopiar->valor);
        nodoCopiar = nodoCopiar->siguiente;
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
        delete this->_primerNodo;
    } else if (i == 0) {                // eliminar el primero
        Nodo* primerNodoViejo = this->_primerNodo;
        this->_primerNodo = this->_primerNodo->siguiente;
        this->_primerNodo->anterior = nullptr;
        delete primerNodoViejo;
    } else if (i == this->longitud() - 1) {     // eliminar el ultimo
        Nodo* ultimoNodoViejo = this->_ultimoNodo;
        this->_ultimoNodo = this->_ultimoNodo->anterior;
        this->_ultimoNodo->siguiente = nullptr;
        delete ultimoNodoViejo;
    } else {                            // eliminar uno intermedio
        Nodo* nodoEliminar = this->_primerNodo;
        while (i > 0) {
            nodoEliminar = nodoEliminar->siguiente;
            i--;
        }
        nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;
        nodoEliminar->siguiente->anterior = nodoEliminar->anterior;
        delete nodoEliminar;
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
    o << "[";
    for (Nodo* nodo = this->_primerNodo; nodo != nullptr; nodo = nodo->siguiente) {
        o << nodo->valor;
        if (nodo->siguiente != nullptr) {
            o << ", ";
        }
    }
    o << "]" << endl;
}

void Lista::limpiarLista() {
    if (this->_longitud == 1) {
        delete this->_primerNodo;
    } else if (this->_longitud > 1) {
        Nodo* nodoActual = this->_primerNodo;
        while (nodoActual != nullptr ) {
            Nodo* nodoSiguiente = nodoActual->siguiente;
            delete nodoActual;
            nodoActual = nodoSiguiente;
        }
    }
}
