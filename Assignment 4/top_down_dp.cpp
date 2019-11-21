#include<bits/stdc++.h>
#define max_limit 100

using namespace std;

long long int F[max_limit];

void init_fib() {
  for(int i=0; i<max_limit; i++) {
    F[i] = -1;
  }
}

long long int fibonacci(long int n) {
  if (F[n] < 0) {

    if (n==0) {
      F[n] = 0;
    }

    else if (n == 1) {
      F[n] = 1;
    }
    
    else {
      F[n] = fibonacci(n-1) + fibonacci(n-2);
    }
  }
  return F[n];
}

int main() 
{
    init_fib();
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