def cutRod(price, n): 
    val = [0 for x in range(n+1)] 
    val[0] = 0
    for i in range(1, n+1): 
        mval =-100 
        for j in range(i): 
             mval = max(mval, price[j] + val[i-j-1]) 
        val[i] = mval
  
    return val[n] 
  

arr = [1, 5, 8, 9, 15, 11, 15, 20] 
size = len(arr) 
maxval=str(cutRod(arr, size))
print("Maximum Obtainable Value is " + maxval ) 