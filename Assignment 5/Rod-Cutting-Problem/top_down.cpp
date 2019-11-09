#include<bits/stdc++.h>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int Memoized_cut_rod_Array(vector<int> price, int n, int r[]) {
    
    int max_value;

    if(r[n+1] >= 0) {
        return r[n+1];
    }

    if(n==0) {
        max_value = 0;
    }

    else
    {
        max_value == INT_MIN;

        for (int i = 1; i <= n; i++) {
            max_value = max(max_value, (price[i] + Memoized_cut_rod_Array(price, n-i, r)));
        }
    }

    r[n+1] = max_value;

    return max_value;
}

int Memoized_cut_rod(vector<int> price, int n) {
    int r[n+1];

    for (int i = 0; i <= n; i++)
    {
        r[i] = INT_MIN;
    }
    
    return Memoized_cut_rod_Array(price, n, r);
}

int main()
{
    vector<int> price{1, 5, 8, 9, 10, 17, 17, 20};

    cout << "Maximum value : " << Memoized_cut_rod(price, price.size()) << "\n";
    return 0;
}
