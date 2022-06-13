template <typename T>
string_map<T>::string_map() : _raiz(nullptr), _size(0) {}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {

    return *this;
}

template <typename T>
void string_map<T>::mostrar(ostream& os) {
    return;
}

template <typename T>
string_map<T>::~string_map(){
    return;
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    //
}

template <typename T>
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

template <typename T>
int string_map<T>::count(const string& clave) const{
    return 1;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    return new T();
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    //
}


template <typename T>
void string_map<T>::erase(const string& clave) {
    return;
}

template <typename T>
int string_map<T>::size() const{
    return 1;
}

template <typename T>
bool string_map<T>::empty() const{
    return true;
}