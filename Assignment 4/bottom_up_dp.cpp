#include<bits/stdc++.h> 

using namespace std;
  
long long int fibonacci(long int n) 
{ 
  long long int fib[n+2];  
  long int i; 
  
  
  fib[0] = 0; 
  fib[1] = 1; 
  
  for (i = 2; i <= n; i++) 
  { 
      fib[i] = fib[i-1] + fib[i-2]; 
  } 
  
  return fib[n]; 
} 
  
int main () 
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