## Ejercicio11

1. Estructura de representacion que permite cantPersonas en O(1)

    IngresosAlBanco SRC estr
        donde estr es tupla(totalDeDias: Nat, personasPorDia: vector(Nat), personasAcumuladas: vector(Nat))

2. Calcular memoria en funcion de los dias que pasaron n.

    O(2n + 1) = O(n)

3. Buscar estr que use O(n) memoria

    Es la del punto 2.

4. Agregar al diseño una operacion _mediana_ que devuelva el ultimo (mayor) dia _d_ tal que _cantPersonas_(i, 1, d) <= _cantPersonas_(i, d+1, totDias(i)), restringiendo la operacion a los casos donde este dia existe.

    TAD IngresosAlBanco
        otras operaciones
            mediana: iab i -> Nat     {totDias(i) > 1 ^ (Existe d: Nat)(cantPersonas(i, 1, d) <= cantPersonas(i, d+1, totDias(i)))}
    
        axiomas
            mediana = 

    // completar este
    

    