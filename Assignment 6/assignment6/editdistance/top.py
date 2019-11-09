def min(x, y, z):
    if (x < y) and (x < z):
        small = x
    elif (y < x) and (y < z):
        small = y
    else:
        small = z
    return small

def Edit_Distance(str1,str2,m,n,dp):
    if m==0:
        return n

    if n==0:
        return m

    if dp[m-1][n-1] != -1 :
        return dp[m-1][n-1]

    if str1[m-1] == str2[n-1]:
        dp[m-1][n-1]=Edit_Distance(str1,str2,m-1,n-1,dp)
        return dp[m-1][n-1]

    dp[m-1][n-1] = 1 + min(Edit_Distance(str1,str2,m-1,n-1,dp),Edit_Distance(str1,str2,m,n-1,dp),Edit_Distance(str1,str2,m-1,n,dp)) 
    return dp[m-1][n-1]

str1="123456789"
str2="987654321"

maximum=10000
m=len(str1)
n=len(str2)

dp = [[-1 for x in range(maximum)] for x in range(m)]

print("The distance is " + str(Edit_Distance(str1, str2, m, n, dp)))