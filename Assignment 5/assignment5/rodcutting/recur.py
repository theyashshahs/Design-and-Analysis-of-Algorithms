def max(a,b):
    if a>b:
        return a
    else:
        return b

def cutrec(price,n):
    if(n<=0):
        return 0
    mval=-10
    for i in range(0,n):
        mval=max(mval,price[i]+cutrec(price,n-i-1))
    return mval
arr = [1, 5, 18, 9, 15, 13, 15, 11] 
size = len(arr) 
print("Maximum Obtainable Value is", cutrec(arr, size)) 