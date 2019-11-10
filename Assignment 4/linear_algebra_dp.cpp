#include <bits/stdc++.h>

using namespace std;

void multiply(long long int F[2][2], long long int M[2][2]); 
  
void power(long long int F[2][2], int n); 
  
long long int fibonacci(int n) 
{ 
  long long int F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
      return 0; 
  power(F, n-1); 
  
  return F[0][0]; 
} 
  
void multiply(long long int F[2][2], long long int M[2][2]) 
{ 
  long long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
  long long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
  long long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
  long long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 
  
void power(long long int F[2][2], int n) 
{ 
  long long int M[2][2] = {{1,1},{1,0}}; 
  
  for (int i = 2; i <= n; i++) 
      multiply(F, M); 
} 
  
int main() 
{ 
    cin.tie(NULL);
    cout.tie(NULL);

    long int n;
    cout<<"Enter the number : ";
    cin>> n;
    clock_t start = clock();
    long long int a = fibonacci(n);
    clock_t end = clock();

    cout << a << " "; 
    cout<< std::fixed << "\n\nTime taken to compute " << n << "th " << "fibonacci number : " << (double)(end - start)/CLOCKS_PER_SEC << " seconds " << endl; 
  return 0; 
} 