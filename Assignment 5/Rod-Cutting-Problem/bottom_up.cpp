#include<bits/stdc++.h>

using namespace std;
  
int max(int a, int b) { 
    return (a > b)? a : b;
} 
  
int Cut_Rod(vector<int> price, int n) 
{ 
   int value[n+1]; 
   value[0] = 0; 
   int i, j; 
  
   for (i = 1; i<n+1; i++) 
   { 
       int max_value = INT_MIN; 
       
       for (j = 0; j < i; j++) { 
        max_value = max(max_value, price[j] + value[i-j-1]);
       }

       value[i] = max_value; 
   } 
  
   return value[n]; 
} 
  
int main() 
{ 
    vector <int> price{1,4,9,10,17,17,19,20,25}; 

    cout << "Maximum value : " << Cut_Rod(price, price.size());
     
    return 0; 
} 