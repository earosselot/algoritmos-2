def montana(a):
    medio = len(a) // 2 #division entera
    if a[medio] > a[medio - 1] and a[medio] > a[medio + 1]:
        return a[medio]
    elif a[medio] > a[medio - 1]:
        return montana(a[medio:])
    elif a[medio] > a[medio + 1]:
        return montana(a[:medio])

def montana2(a, d, h):
    # caso base
    medio = (h + d) // 2
    if a[medio] > a[medio-1] and a[medio] > a[medio+1]:
        return a[medio]               # O(1)
    elif a[medio-1] < a[medio]:
        return montana2(a, medio, h)  # T(n/2)
    elif a[medio-1] > a[medio]:
        return montana2(a, d, medio)  # T(n/2)


if __name__ == '__main__':
    lista = [1, 5, 6, 7, 4]
    print(montana2(lista, 0, len(lista)-1) == 7)

    lista = [-13, -12, 14, 16, 456, 43, 32, -123]
    print(montana(lista) == 456)

    lista = [-13, -12, 14, 16, 456, 43, 32, -123]
    print(montana2(lista, 0, len(lista)-1) == 456)

    lista = [-13, -12, 14, 16, 456, 43]
    print(montana(lista) == 456)

    lista = [-13, -12, 14, 16, 456, 43]
    print(montana2(lista, 0, len(lista)-1) == 456)

    lista = [16, 456, 43, 32, -123, -5143]
    print(montana(lista) == 456)

    lista = [16, 456, 43, 32, -123, -5143]
    print(montana2(lista, 0, len(lista)-1) == 456)
