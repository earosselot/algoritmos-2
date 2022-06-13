#include "string_map.h"

#include <string>

template <class T>
string_map<T>::string_map(): _raiz(nullptr), _size(0) {
}

template <class T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <class T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    return new string_map<T>; // todo
}

template <class T>
string_map<T>::~string_map(){
    return new string_map<T>; // todo
}

template <class T>
T& string_map<T>::operator[](const string& clave){
    return new string_map<T>; // todo
}

template<class T>
void string_map<T>::insert(const pair<string, T>& par) {
    // si el mapa todavia no tiene ningun valor
    if (this->_raiz == nullptr) {
        Nodo* raiz = new Nodo();
        this->_raiz = raiz;
    }
    // si la clave es un string vacio ""
    if (par.first.length() == 0) {
        this->_raiz->definicion = par.second;
        this->_size += 1;
        return;
    }
    insertAux(par, 0, _raiz);
}

template<class T>
void string_map<T>::insertAux(pair<string, T> const &par, int index, Nodo *padre) {
    Nodo* nuevoNodo;
    if (index + 1 == par.first.length()) {
        nuevoNodo = new Nodo(par.second);
        int asciiNumber = int(par.first.at(index));
        padre->siguientes[asciiNumber] = nuevoNodo;
        this->_size += 1;
    } else {
        nuevoNodo = new Nodo();
        int asciiNumber = int(par.first.at(index));
        padre->siguientes[asciiNumber] = nuevoNodo;
        insertAux(par, index+1, nuevoNodo);
    }
}

// "a"
// charAt(0) -> 67
// len("a") 1

// hola
// 0123
// len(hola) 4

template <class T>
int string_map<T>::count(const string& clave) const{
    return 1;
}

template <class T>
const T& string_map<T>::at(const string& clave) const {
    return new T();
}

template <class T>
T& string_map<T>::at(const string& clave) {
    return new T();
}

template <class T>
void string_map<T>::erase(const string& clave) {
    return;
}

template <class T>
int string_map<T>::size() const{
    return 1;
}

template <class T>
bool string_map<T>::empty() const{
    return true;
}
