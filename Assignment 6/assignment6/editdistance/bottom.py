def Edit_Distance(str1, str2, m, n): 
    dp = [[0 for x in range(n+1)] for x in range(m+1)] 
 
    for i in range(m+1): 
        for j in range(n+1): 
            if i == 0: 
                dp[i][j] = j 
 
            elif j == 0: 
                dp[i][j] = i
 
            elif str1[i-1] == str2[j-1]: 
                dp[i][j] = dp[i-1][j-1]
 
            else: 
                dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])
 
    return dp[m][n] 
 
str1 = "123456789"
str2 = "987654321"
 
print("The distance is " + str(Edit_Distance(str1, str2, len(str1), len(str2)))) 
