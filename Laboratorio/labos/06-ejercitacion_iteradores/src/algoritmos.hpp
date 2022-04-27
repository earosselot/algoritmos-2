#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// -------------- Ejercicio 1 -----------------------

template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c) {
    auto min = *c.begin();
    for (auto& y: c) {
        if (y < min) {
            min = y;
        }
    }
    return min;
}

// -------------- Ejercicio 2 -----------------------

template<class T>
typename T::value_type promedio(const T& c) {
    typename T::value_type suma = 0;
    typename T::value_type cantidad = 0;
    for (auto& x: c) {
        suma += x;
        cantidad++;
    }
    return suma / cantidad;
}

// -------------- Ejercicio 3 -----------------------

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta) {
    auto it = desde;
    auto min = desde;
    while (it != hasta) {
        if (*it < *min) {
            min = it;
        }
        ++it;
    }
    return *min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta) {
    auto it = desde;
    typename Iterator::value_type suma = 0;
    typename Iterator::value_type cantidad = 0;
    while (it != hasta) {
        suma += *it;
        cantidad++;
        ++it;
    }
    return suma / cantidad;
}

// -------------- Ejercicio 4 -----------------------

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem) {

    typename Contenedor::iterator it = c.begin();

    while (it != c.end()) {
        if (*it == elem) {
            it = c.erase(it);
        } else {
            ++it;
        }
    }
}

// -------------- Ejercicio 5 -----------------------

template<class Contenedor>
bool ordenado(Contenedor& c) {
    auto sig = ++c.begin();
    auto it = c.begin();
    while (sig != c.end()) {
        if (*sig < *it) {
            return false;
        }
        ++sig;
        ++it;
    }
    return true;
}

// -------------- Ejercicio 6 -----------------------



// -------------- Ejercicio 7 -----------------------
// -------------- Ejercicio 8 -----------------------




#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
