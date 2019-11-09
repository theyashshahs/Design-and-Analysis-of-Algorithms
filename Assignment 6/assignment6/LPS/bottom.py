def lps(arr): 
	n = len(arr) 
	l = [[0 for x in range(n)] for x in range(n)]

	for i in range(n): 
		l[i][i] = 1
	
	for k in range(2, n+1): 
		for i in range(n-k+1): 
			j = i+k-1
			if arr[i] == arr[j] and k == 2: 
				l[i][j] = 2
			elif arr[i] == arr[j]: 
				l[i][j] = l[i+1][j-1] + 2
			else: 
				l[i][j] = max(l[i][j-1], l[i+1][j]); 

	return l[0][n-1] 

arr = "1234432112214534"

print("The length of the lPS is : " + str(lps(arr))) 

