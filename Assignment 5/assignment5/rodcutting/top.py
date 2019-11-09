def max(a,b):
    if a>b:
        return a
    else:
        return b

def cutrec(price,n,val):
    if(val[n]>=0):
        return val[n]
    if n==0:
        mval=0
    else:
        mval=-10
    for i in range(1,n):
        mval=max(mval,price[i]+cutrec(price,n-i-1,val))
    val[n]=mval
    return mval

arr1 = [1, 5, 18, 9, 15, 13, 15, 11]
arr = [1, 5, 8, 9, 15, 11, 15, 20] 

n=len(arr)
val = [-10 for x in range(n+1)]
print("Maximum Obtainable Value is", cutrec(arr, n ,val)) 