def Matrix_Chain(arr):
    n=len(arr)
    m = [[0 for x in range(n)] for x in range(n)]
    for i in range(1,n):
        for j in range(i,n):
            m[i][j]=999999999
    return look_up(m,arr,1,n-1)

def look_up(m,arr,i,j):
    if m[i][j]<999999999:
        return m[i][j]

    if i==j:
        m[i][j]=0
    else:
        for k in range(i,j):
            q = look_up(m, arr, i, k) + look_up(m, arr, k+1, j) + arr[i-1] * arr[k] * arr[j]
            if q < m[i][j]:
                m[i][j] = q

    return m[i][j]

    
arr = [5, 2, 6, 4, 3]

print("Minimum number of multiplications are : " + str(Matrix_Chain(arr)))