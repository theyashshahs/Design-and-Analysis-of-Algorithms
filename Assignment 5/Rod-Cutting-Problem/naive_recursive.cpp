#include<bits/stdc++.h>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int Cut_Rod(int price[], int n) {
    if (n <= 0)
        return 0;
    
    int max_val = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        max_val = max(max_val, price[i] + Cut_Rod(price, n-i-1));
    }

    return max_val;
}

int main()
{   
    int price[] = {1,4,9,10,17,17,19,20,25};
    int size = sizeof(price)/sizeof(price[0]);

    cout << "Maximum value : " << Cut_Rod(price, size);
    return 0;
}
