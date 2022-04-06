#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto() const;
        uint ancho() const;
        float area() const;

    private:
        int alto_;
        int ancho_;
};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho) {};

uint Rectangulo::alto() const {
    return alto_;
}

uint Rectangulo::ancho() const {
    return ancho_;
}

float Rectangulo::area() const {
    return (float) ancho_ * (float) alto_;
}

// Ejercicio 2

class Elipse {
    public:
        Elipse(uint r_a, uint r_b);
        uint r_a() const;
        uint r_b() const;
        float area() const;

    private:
        uint r_a_;
        uint r_b_;
        float PI;
};

Elipse::Elipse(uint r_a, uint r_b): r_a_(r_a), r_b_(r_b), PI(3.14) {}

uint Elipse::r_a() const {
    return r_a_;
}

uint Elipse::r_b() const {
    return r_b_;
}

float Elipse::area() const {
    return PI * (float) r_a_ * (float) r_b_;
}

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    // Completar
}

float Cuadrado::area() {
    // Completar
}

// Ejercicio 4

class Circulo {
public:
    Circulo(uint radio);
    uint radio();
    float area();

private:
    uint radio_;
};

Circulo::Circulo(uint radio): radio_(radio) {}

uint Circulo::radio() {
    return radio_;
}

float area() {
    return Elipse::area();
}


// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.ancho() << ", " << r.alto() << ")";
    return os;
}

// ostream Elipse

// Ejercicio 6

