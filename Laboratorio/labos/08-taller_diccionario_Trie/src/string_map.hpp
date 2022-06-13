template <typename T>
string_map<T>::string_map() : _raiz(nullptr), _size(0) {}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {

    if (_raiz != nullptr)
        _raiz->vaciar();
    else
        _raiz = new Nodo();

    if (d._raiz != nullptr)
        d._raiz->traverseAndCopy(*this, "");

    return *this;
}

template <typename T>
void string_map<T>::Nodo::vaciar() {

    for (int i = 0; i < 256; ++i) {
        if (definicion != nullptr)
            delete definicion;

        if (siguientes[i] != nullptr) {
            siguientes[i]->vaciar();
            delete siguientes[i];
        }
    }
}

template <typename T>
void string_map<T>::Nodo::traverseAndCopy(string_map<T>& copia, const string& clave) {
    if (definicion != nullptr)
        copia.insert(make_pair(clave, *definicion));

    for (int i = 0; i < 256; ++i) {
        char c = i;
        if (siguientes[i] != nullptr) {
            siguientes[i]->traverseAndCopy(copia, clave+c);
        }
    }
}

template <typename T>
void string_map<T>::mostrar(ostream& os) {
    _raiz->mostrar(os, "");
    os <<endl << "------" <<endl;
}

template <class T>
void string_map<T>::Nodo::mostrar(std::ostream& os, string clave) {
    
    if (definicion != nullptr) {
        os << clave << ": def=" << definicion << " | *def =" << *definicion << " | &def=" << &definicion << endl;
    } else {
        os << clave << " nullptr" << endl;
    }

    for (int i = 0; i < siguientes.size(); i++)
    {
        if (siguientes[i] != nullptr) {
            char c = i;
            siguientes[i]->mostrar(os, clave+c);
        }
    }
}

template <typename T>
string_map<T>::~string_map(){
    if (_raiz != nullptr) {
        _raiz->vaciar();
        delete _raiz;
    }
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& par) {
    if (_raiz == nullptr)
        _raiz = new Nodo();

    bool nuevo = _raiz->insert(par, 0);
    if (nuevo)
        _size++;
}

template <typename T>
bool string_map<T>::Nodo::insert(const pair<string, T>& par, int offset) {
    char nextChar = par.first[offset];

    if (siguientes[nextChar] == nullptr)
        siguientes[nextChar] = new Nodo();

    if (offset == par.first.size()-1) {
        bool nuevo = (siguientes[nextChar]->definicion == nullptr);
        siguientes[nextChar]->definicion = new T(par.second);
        return nuevo;
    } else {
        return siguientes[nextChar]->insert(par, offset+1);
    }

}

template <typename T>
int string_map<T>::count(const string& clave) const{
    if (_raiz == nullptr)
        return 0;
    
    return _raiz->count(clave, 0);
}

template <class T>
int string_map<T>::Nodo::count(const string& clave, int offset) const {
    char nextChar = clave[offset];

    if (siguientes[nextChar] == nullptr) {
        return 0;
    } else if (offset == clave.size()-1) {
        return (siguientes[nextChar]->definicion != nullptr) ? 1 : 0;
    }

    return siguientes[nextChar]->count(clave, offset+1);
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    return _raiz->at(clave, 0);
}

template <typename T>
const T& string_map<T>::Nodo::at(const string& clave, int offset) const {
    char nextChar = clave[offset];

    if (offset == clave.size()-1) {
        return *siguientes[nextChar]->definicion;
    }

    return siguientes[nextChar]->at(clave, offset+1);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    return _raiz->at(clave, 0);
}

template <typename T>
T& string_map<T>::Nodo::at(const string& clave, int offset) {
    char nextChar = clave[offset];

    if (offset == clave.size()-1) {
        return *siguientes[nextChar]->definicion;
    }

    return siguientes[nextChar]->at(clave, offset+1);
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    bool was_present = false;
    if (_raiz != nullptr)
        was_present = _raiz->erase(clave, 0);

    if (was_present)
        _size--;
}

template <typename T>
bool string_map<T>::Nodo::erase(const string& clave, int offset) {
    char nextChar = clave[offset];

    if (offset == clave.size()-1) {
        if (siguientes[nextChar]->definicion != nullptr) {
            siguientes[nextChar]->definicion = nullptr;
            bool empty = true;
            for (int i = 0; i < 256; ++i) {
                if (siguientes[nextChar]->siguientes[i] != nullptr)
                    empty = false;
            }
            if (empty)
                delete siguientes[nextChar];

            return true;
        }
        return false;
    }

    return siguientes[nextChar]->erase(clave, offset+1);
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return (_size == 0);
}