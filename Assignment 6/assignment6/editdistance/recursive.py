def min(x, y, z):
    if (x < y) and (x < z):
        small = x
    elif (y < x) and (y < z):
        small = y
    else:
        small = z
    return small

def Edit_Distance(str1, str2, m , n): 
  
    if m==0: 
         return n 
  
   
    if n==0: 
        return m 
  
    
    if str1[m-1]==str2[n-1]: 
        return Edit_Distance(str1,str2,m-1,n-1) 
  
    
    return (1 + min(Edit_Distance(str1, str2, m, n-1), Edit_Distance(str1, str2, m-1, n), Edit_Distance(str1, str2, m-1, n-1))) 
  
str1 = "123456789"
str2 = "987654321"

print("The distance is : " + str(Edit_Distance(str1, str2, len(str1), len(str2))))