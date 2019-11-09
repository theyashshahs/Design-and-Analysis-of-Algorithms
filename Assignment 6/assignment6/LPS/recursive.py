def max(x, y): 
	if(x > y): 
		return x 
	return y  
	
def lps(arr, i, j): 
	if (i == j): 
		return 1

	if (arr[i] == arr[j] and i + 1 == j): 
		return 2

	if (arr[i] == arr[j]): 
		return lps(arr, i + 1, j - 1) + 2

	return max(lps(arr, i, j - 1), lps(arr, i + 1, j)) 


arr = "1234432112214534"
n = len(arr) 
print("The length of the LPS is : " + str(lps(arr, 0, n - 1))) 
