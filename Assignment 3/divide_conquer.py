import numpy as np


def split(s, en):
    t = [[0 for x in range(0, en//2)]for y in range(0, en//2)]
    u = [[0 for x in range(0, en//2)]for y in range(0, en//2)]
    v = [[0 for x in range(0, en//2)]for y in range(0, en//2)]
    w = [[0 for x in range(0, en//2)]for y in range(0, en//2)]

    for i in range(0, en//2):
        for j in range(0, en//2):
            t[i][j] = s[i][j]
        for j in range(en//2, en):
            u[i][j-(en//2)] = s[i][j]

    for i in range(en//2, en):
        for j in range(0, en//2):
            v[i-(en//2)][j] = s[i][j]
        for j in range(en//2, en):
            w[i-(en//2)][j-(en//2)] = s[i][j]

    return t, u, v, w


def sum(p, q, m):
    r = [[0 for x in range(0, m)]for y in range(0, m)]
    for i in range(0, m):
        for j in range(0, m):
            r[i][j] = p[i][j] + q[i][j]
    return r


def product(x, y, k):

    if k == 1:
        return [[x[0][0] * y[0][0]]]
    else:
        A, B, C, D = split(x, k)
        E, F, G, H = split(y, k)

        C00 = sum(product(A, E, k // 2), product(B, G, k // 2), k // 2)
        C01 = sum(product(A, F, k // 2), product(B, H, k // 2), k // 2)
        C10 = sum(product(C, E, k // 2), product(D, G, k // 2), k // 2)
        C11 = sum(product(C, F, k // 2), product(D, H, k // 2), k // 2)

        y = np.concatenate(
            (np.concatenate((C00, C01), axis=1), 
            (np.concatenate((C10, C11), axis=1)))
            )

        return y


A = [
        [11,2,3,4,-15,6,17,8],
        [3,-7,16,5,14,3,22,1],
        [22,3,6,25,24,23,12,3],
        [7,6,35,4,23,2,-11,22],
        [25,6,7,28,11,-12,3,4],
        [6,-15,8,7,24,3,23,-4],
        [-11,2,2,-11,5,6,27,18],
        [12,7,24,15,6,17,8,19]
    ]

B = [
        [5,12,8,-11,4,18,6,2],
        [-23,15,9,7,22,11,14,16],
        [-5,-18,23,28,-34,24,6,9],
        [7,14,11,6,9,-4,-7,6],
        [4,5,-6,-7,8,9,10,-11],
        [12,-13,14,15,16,-17,18,19],
        [-20,21,22,-23,24,-25,26,27],
        [4,3,2,1,9,8,7,6]
    ]
    
print(product(A, B, 8))