def existePosicion(a):
    return existePosAux(a, 0, len(a))


def existePosAux(a, d, h):
    if d + 1 == h:
        return a[d] == d + 1

    m = (d + h) // 2
    if m + 1 == a[m]:
        return True
    elif m < a[m]:
        return existePosAux(a, d, m)
    else:
        return existePosAux(a, m, h)


if __name__ == '__main__':
    lista = [0, 5, 6, 7, 4]
    print(existePosicion(lista))

    lista = [-4, -1, 2, 4, 7]
    print(existePosicion(lista))

    lista = [-4, -1, 2, 4, 7]
    print(existePosicion(lista))
