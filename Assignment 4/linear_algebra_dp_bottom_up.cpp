#include <bits/stdc++.h>

using namespace std;

long int getFibNum(long int n)
{
    if (n == 0)
    {
        return 0;
    }
    long int mat1[2][2] = {{0, 1}, {1, 1}};
    // long int f1 = 1;
    // long int f2 = 1;
    if (n > 2)
    {
        for (long int i = 4; i < n; i++)
        {
            long int mat2[2][2] = {{0, 1}, {1, 1}};
            long int a = (mat1[0][0] * mat2[0][0]) + (mat1[0][1] * mat2[1][0]);
            long int b = (mat1[0][0] * mat2[0][1]) + (mat1[0][1] * mat2[1][1]);
            long int c = (mat1[1][0] * mat2[0][0]) + (mat1[1][1] * mat2[1][0]);
            long int d = (mat1[1][0] * mat2[0][1]) + (mat1[1][1] * mat2[1][1]);
            mat1[0][0] = a;
            mat1[0][1] = b;
            mat1[1][0] = c;
            mat1[1][1] = d;
        }

        return (mat1[1][0] + mat1[1][1]);
    }
    else
    {
        return 1;
    }
}

int main()
{
    // ios_base::sync_with_stdio(false), 
    cin.tie(0), cout.tie(0);
    long int n;
    cout<<"Enter the number : ";
    cin >> n;
    
    clock_t start = clock();
    long int ans = getFibNum(n);
    clock_t end = clock();

    cout << ans << " "; 
    cout<< std::fixed << "\n\nTime taken to compute " << n << "th " << "fibonacci number : " << (double)(end - start)/CLOCKS_PER_SEC << " seconds " << endl; 
    return 0;
}