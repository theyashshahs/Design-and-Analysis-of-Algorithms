#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, vector<int>& arr1, int n) 
{
    int i, j, k;
    vector<int> c;
    i = 0;
    j = 0;
    k = 0;

    while(i< arr.size() && j< arr1.size())
    {
        if(arr[i] <= arr1[j]) 
        {
            c[k] = arr[i];
            i++;
        }

        else
        {
            c[k] = arr1[j];
            j++;
        }
        k++;
    }
    vector<int> x;
    int d;
    cout<<"Enter the next number :";
    for (int i = 0; i < n; i++)
    {
        cin>>d;
        x.push_back(d);
    }
    
    merge(c,x,n);

    for (int i = 0; i < c.size(); i++)
    {
        cout<< c[i] << "\n";
    }
    
}


int main() 
{
    int k;
    cin>>k;
    vector<int> a,b;
    int e;
    int n;
    cin>>n;

    cout<<"Enter the numbers 1 : ";
    for (int i = 0; i < n; i++)
    {   cin>>e;
        a.push_back(e);
    }

    cout<<"Enter the numbers 2 : ";
    for (int i = 0; i < n; i++)
    {   cin>>e;
        b.push_back(e);
    
    }

    for(int i = 2; i<k; i++) {
        merge(a,b,n);
    }
    
    return 0;

}