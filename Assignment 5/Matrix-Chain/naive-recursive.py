def Matrix_Chain(a, i, j): 
    if i == j: 
        return 0
        
    min = 999999999999999 

    for k in range(i,j):
        count = (Matrix_Chain(a, i, k) + Matrix_Chain(a, k+1, j) + a[i-1] * a[k] * a[j])
        
        if count<min:
            min=count
            
    return min
   

arr = [5, 2, 6, 4, 3]

print("Minimum number of multiplications are : " + str(Matrix_Chain(arr, 1, (len(arr)-1)))) 