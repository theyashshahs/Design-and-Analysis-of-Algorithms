#include<bits/stdc++.h>

using namespace std;

long long int fibonacci(long int n) 
{ 
  long long int a = 0, b = 1, c, i; 
  if( n == 0) 
    return a; 
  for (i = 2; i <= n; i++) 
  { 
     c = a + b; 
     a = b; 
     b = c; 
  } 
  return b; 
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