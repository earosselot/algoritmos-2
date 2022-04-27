#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// -------------- Ejercicio 1 -----------------------
#if EJ < 8

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
#endif
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

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor& c, const typename Contenedor::value_type& elem) {
    std::pair<Contenedor, Contenedor> res;

    for (auto& item: c) {
        if (item < elem) {
            res.first.insert(res.first.end(), item);
        } else {
            res.second.insert(res.second.end(), item);
        }
    }
    return res;
}

// -------------- Ejercicio 7 -----------------------

template<class Contenedor>
void merge(const Contenedor& c1, const Contenedor& c2, Contenedor& res) {
    auto it1 = c1.begin();
    auto it2 = c2.begin();

    while (it1 != c1.end() && it2 != c2.end()) {
        if (*it1 < *it2) {
            res.insert(res.end(), *it1);
            ++it1;
        } else {
            res.insert(res.end(), *it2);
            ++it2;
        }
    }

    while (it1 != c1.end()) {
        res.insert(res.end(), *it1);
        ++it1;
    }

    while (it2 != c2.end()) {
        res.insert(res.end(), *it2);
        ++it2;
    }
}

// -------------- Ejercicio 8 -----------------------

#if EJ >= 8
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c) {
    auto min = c.begin();
    auto it = c.begin();
    while (it != c.end()) {
        if (*it < *min) {
            min = it;
        }
        ++it;
    }
    return *min;
}
#endif

#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
