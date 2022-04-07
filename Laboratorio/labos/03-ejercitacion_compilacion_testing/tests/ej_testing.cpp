#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    int resultado = 15 + 7;
    int resultadoEsperado = 22;
    EXPECT_EQ(resultado, resultadoEsperado);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    int resultado = pow(10, 2);
    int resultadoEsperado = 100;
    EXPECT_EQ(resultado, resultadoEsperado);
}

TEST(Aritmetica, potencia_general) {
    for (int num = -5; num <= 6; num++) {
        int resultado = pow(num, 2);
        int resultadoEsperado = num * num;
        EXPECT_EQ(resultado, resultadoEsperado);
    }
}

// Ejercicios 6..9
TEST(Diccionario, obtener) {
    map<int, int> dicEnteros;
    dicEnteros.insert(make_pair(6, 14));
    ASSERT_EQ(dicEnteros[6], 14);
}

TEST(Diccionario, definir) {
    map<int, int> dicEnteros;
    int count6 = dicEnteros.count(6);
    ASSERT_EQ(count6, 0);
    dicEnteros.insert(make_pair(6, 7));
    count6 = dicEnteros.count(6);
    ASSERT_EQ(count6, 1);
}

TEST(Truco, inicio) {
    Truco truco = Truco();
    EXPECT_EQ(truco.puntaje_j1(), 0);
    EXPECT_EQ(truco.puntaje_j2(), 0);
}

TEST(Truco, buenas) {
    Truco truco = Truco();
    EXPECT_FALSE(truco.buenas(1));
    for(int i = 1; i < 16; i++) {
        truco.sumar_punto(1);
    }
    EXPECT_FALSE(truco.buenas(1));
    truco.sumar_punto(1);
    EXPECT_TRUE(truco.buenas(1));
}
s82ns0pwLRjj*8