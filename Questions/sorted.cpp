#include<bits/stdc++.h>

using namespace std;

void EvenOdd(int arr[], int n)
{
    int even = 0,odd = 0;

    for(int i=0; i < n; i++)
    {
        if(arr[i]%2 == 0)
        {
            even++;
        }

        else
        {
            odd++;    
        }
    }

    cout<<"Even number : " << even;
    cout<<"\nOdd number : "<< odd;


    vector<int> arr1, arr2;

    for(int i=0; i < n; i++)
    {
        if(arr[i]%2 == 0)
        {
            arr1.push_back(arr[i]);
        }
        else
        {
            arr2.push_back(arr[i]);
        }
        
    }

    cout<< "\nEven numbers are : ";
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }

    cout<< "\nOdd numbers are : ";
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }

}

int main()
{   int n;

    cout<<"Enter the size of the array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the numbers in sorted order : ";
    for(int i=0; i < n; i++)
        cin>>arr[i];

    EvenOdd(arr,n);
    
    return 0;
}

