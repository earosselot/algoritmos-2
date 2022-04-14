#include "SistemaDeMensajes.h"

#if EJ == 1 || EJ == 2 || EJ == 3

SistemaDeMensajes::SistemaDeMensajes(): _conns() {}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    this->_conns[id] = new ConexionJugador(ip);
}

bool SistemaDeMensajes::registrado(int id) const {
    return this->_conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    this->_conns[id]->enviarMensaje(mensaje);
    // otras opciones que hacen lo mismo:
    // ConexionJugador* conexionJugador = this->_conns[id];
    // a:
    // (*conexionJugador).enviarMensaje(mensaje);
    // b:
    // conexionJugador->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return this->_conns[id]->ip();
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (ConexionJugador* conn: this->_conns) {
        delete conn;
    }
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    this->_conns[id] = nullptr;
}

// todo: falta correr ej 2 y 3 con valgrind


#elif EJ == 4 || EJ == 5

SistemaDeMensajes::SistemaDeMensajes(): _conns() {}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    this->_conns[id] = new ConexionJugador(ip);
}

bool SistemaDeMensajes::registrado(int id) const {
    return this->_conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    this->_conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return this->_conns[id]->ip();
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (ConexionJugador* conn: this->_conns) {
        delete conn;
    }
    for (Proxy* proxy: this->_proxys) {
        delete proxy;
    }
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    this->_conns[id] = nullptr;
}

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    _proxys.push_back(new Proxy(this->_conns[id]));
    return _proxys.back();
}
// todo: falta correr ej 4 y 5 con valgrind

#elif EJ == 6

SistemaDeMensajes::SistemaDeMensajes(): _conns() {}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    this->_conns[id] = new ConexionJugador(ip);
}

bool SistemaDeMensajes::registrado(int id) const {
    return this->_conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    this->_conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return this->_conns[id]->ip();
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (ConexionJugador* conn: this->_conns) {
        delete conn;
    }
    for (Proxy* proxy: this->_proxys) {
        delete proxy;
    }
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    this->_conns[id] = nullptr;
}

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    _proxys.push_back(new Proxy(&(this->_conns[id])));
    return _proxys.back();
}

#elif EJ == 7

//  ----------- Ejercicio 7 -----------------------

SistemaDeMensajes::SistemaDeMensajes(): _conns() {}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    this->_conns[id] = new ConexionJugador(ip);
}

bool SistemaDeMensajes::registrado(int id) const {
    return this->_conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    this->_conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return this->_conns[id]->ip();
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (ConexionJugador* conn: this->_conns) {
        delete conn;
    }
    for (Proxy* proxy: this->_proxys) {
        delete proxy;
    }
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    this->_conns[id] = nullptr;
}

SistemaDeMensajes::Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    _proxys.push_back(new Proxy(&(this->_conns[id])));
    return _proxys.back();
}

SistemaDeMensajes::Proxy::Proxy(ConexionJugador** conn): _conn(conn) {}

void SistemaDeMensajes::Proxy::enviarMensaje(string msg) {
    (**_conn).enviarMensaje(msg);
}

#endif





