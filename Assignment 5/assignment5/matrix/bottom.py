def Matrix_Chain(a,n):
    m = [[0 for x in range(n)] for x in range(n)]
    s = [[0 for x in range(n)] for x in range(n)]

    for i in range(1,n):
        m[i][i]=0
    for l in range(2,n):
        for i in range(1,n-l+1):
            j=i+l-1
            m[i][j]=99999999999

            for k in range(i,j):
                q=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j]
                if q<m[i][j]:
                    m[i][j]=q
                    s[i][j]=k
    return m,s

arr = [5, 2, 6, 4, 3] 
n = len(arr) 
m,s=Matrix_Chain(arr, n)

print("Minimum number of multiplications are " + str(m[1][n-1]))
print("Paranthesis => " + str(s)) 

