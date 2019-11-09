def max(x, y): 
	if(x > y): 
		return x 
	return y

def look_up(arr):
    n=len(arr)
    m = [[0 for x in range(n)] for x in range(n)]

    for i in range(1,n):

        for j in range(i,n):
            m[i][j]=0
    
    return lps(arr,0,n-1,m)  

def lps(arr,i,j,look):
    if i>j:
        return 0
    if i==j:
        return 1
    
    if(look[i][j]==0):
        if arr[i]==arr[j] and i+1==j:
            return 2
        if arr[i]==arr[j] :
            look[i][j]=lps(arr,i+1,j-1,look)+2
        else:
            look[i][j]=max(lps(arr,i,j-1,look),lps(arr,i+1,j,look))

    return look[i][j]

arr = "1234432112214534"
n = len(arr) 
print("The length of the LPS is " + str(look_up(arr))) 