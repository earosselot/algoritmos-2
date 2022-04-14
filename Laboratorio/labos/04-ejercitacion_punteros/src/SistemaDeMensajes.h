#ifndef SISTEMADEMENSAJES_H
#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
#include <string>
#include <vector>

using namespace std;

#if EJ == 1 || EJ == 2 || EJ == 3

//  ----------- Ejercicio 1 a 3 -----------------------

class SistemaDeMensajes {
public:
    SistemaDeMensajes();
    // Pre: 0 <= id < 4
    void registrarJugador(int id, string ip);
    // Pre: 0 <= id < 4
    bool registrado(int id) const;

    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);

    // Pre: registrado(id)
    string ipJugador(int id) const;

    void desregistrarJugador(int id);

    ~SistemaDeMensajes();

private:
    ConexionJugador* _conns[4];
};

#elif EJ == 4 || EJ == 5
#include "Proxy.h"

//  ----------- Ejercicio 4 -5 -----------------------

class SistemaDeMensajes {
  public:
    SistemaDeMensajes();
    // Pre: 0 <= id < 4
    void registrarJugador(int id, string ip);
    // Pre: 0 <= id < 4
    bool registrado(int id) const;

    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);

    // Pre: registrado(id)
    string ipJugador(int id) const;

    void desregistrarJugador(int id);

    ~SistemaDeMensajes();

    Proxy* obtenerProxy(int id);

private:
    ConexionJugador* _conns[4];
    vector<Proxy*> _proxys;
};

#elif EJ == 6
#include "Proxy2.h"

//  ----------- Ejercicio 6 -----------------------

class SistemaDeMensajes {
  public:
    SistemaDeMensajes();
    // Pre: 0 <= id < 4
    void registrarJugador(int id, string ip);
    // Pre: 0 <= id < 4
    bool registrado(int id) const;

    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);

    // Pre: registrado(id)
    string ipJugador(int id) const;

    void desregistrarJugador(int id);

    ~SistemaDeMensajes();

    Proxy* obtenerProxy(int id);

private:
    ConexionJugador* _conns[4];
    vector<Proxy*> _proxys;
};

#elif EJ == 7

//  ----------- Ejercicio 7 -----------------------

class SistemaDeMensajes {
public:
    class Proxy;

    SistemaDeMensajes();
    // Pre: 0 <= id < 4
    void registrarJugador(int id, string ip);
    // Pre: 0 <= id < 4
    bool registrado(int id) const;

    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);

    // Pre: registrado(id)
    string ipJugador(int id) const;

    void desregistrarJugador(int id);

    ~SistemaDeMensajes();

    Proxy* obtenerProxy(int id);

    class Proxy {
    public:
        Proxy(ConexionJugador** conn);
        void enviarMensaje(string msg);

    private:
        ConexionJugador** _conn;

        // No puedo copiarlo
        Proxy(const Proxy&);
    };

private:
    ConexionJugador* _conns[4];
    vector<Proxy*> _proxys;
};

#endif

#endif
