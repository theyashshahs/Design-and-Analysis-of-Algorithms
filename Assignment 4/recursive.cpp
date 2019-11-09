#include<bits/stdc++.h> 
using namespace std; 
  
long int fibonacci(long int n) 
{   
    if (n <= 1) 
        return n; 
    return fibonacci(n-1) + fibonacci(n-2); 
} 
  
int main () 
{   
    cin.tie(NULL);
    cout.tie(NULL);
    // ios_base::sync_with_stdio(false);

    long int n;
    cout<<"Enter the number : ";
    cin>> n;
    clock_t start = clock();
    long int a = fibonacci(n);
    clock_t end = clock();

    cout << a << " "; 
    cout<< std::fixed << "\n\nTime taken to compute " << n << "th " << "fibonacci number : " << (double)(end - start)/CLOCKS_PER_SEC << " seconds " << endl;
    return 0; 
} 