def Matrix_Chain(p, i, j, r):
    if r[i][j] >= 0:
        return r[i][j]
    if i == j:
        r[i][j] = 0
        return r[i][j]
    else:
        q = 99999999
        for k in range(i, j):
            q = min(q, Matrix_Chain(p, i, k, r) + Matrix_Chain(p, k+1, j, r) + (p[i-1]*p[k]*p[j]))
        r[i][j] = q
        return r[i][j]


p = [5, 2, 3, 4, 5]
r = [[0]*len(p)]*len(p)
for i in range(0, len(p)):
    for j in range(0, len(p)):
        r[i][j] = -99999999
print(Matrix_Chain(p, 1, len(p)-1, r))