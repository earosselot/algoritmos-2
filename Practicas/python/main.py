
def contarParejas(lista):
    parejas = 0
    return contarParejasAux(lista, parejas)

def contarParejasAux(lista, parejas):
    if len(lista) == 1:
        return lista, parejas
    mitad = len(lista) // 2
    lista1 = lista[:mitad]
    lista2 = lista[mitad:]
    return merge(contarParejasAux(lista1, parejas), contarParejasAux(lista2, parejas), parejas)

def merge(lista1, lista2, parejas):

if __name__ == '__main__':
    lista = [1, 3]
    print(contarParejas(lista) == 0)

    lista = [4, 3, 2, 1]
    print(contarParejas(lista) == 6)

    lista = [4, 2, 3, 1, 6]
    print(contarParejas(lista) == 5)


# See PyCharm help at https://www.jetbrains.com/help/pycharm/
