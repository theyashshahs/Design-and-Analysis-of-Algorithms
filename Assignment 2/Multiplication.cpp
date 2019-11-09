#include<bits/stdc++.h>

using namespace std;

vector<int> multiply(vector<int> a,vector<int> b, int base) {
    int carry;
    vector<int> product;
    for (int i = 0; i < b.size(); i++) {
        carry = 0;
        for (int j = 0; j < a.size(); j++){
            product[i+j-1] += carry + a[j]*b[i];
            carry = product[i+j-1]/base;
            product[i+j-1] = product[i+j-1]%base;
            product[i+a.size()] += carry;  
        }
    }
    return product;
}

int main()
{
    int a,b,c;
    vector<int> v1,v2;
    cout<<"Enter the number of digits of first number : ";
    cin>>a;
    cout<<"Enter the number digit by digit : ";
    for(int i=0;i<a;i++){
        cin>>c;
        v1.push_back(c);
    }

    cout<<"Enter the number of digits of second number : ";
    cin>>b;
    cout<<"Enter the number digit by digit : ";
    for(int i=0;i<b;i++){
        cin>>c;
        v2.push_back(c);
    }

    int base;
    cout<<"Enter the base : ";
    cin>>base;

    cout<<"Product is : ";
    vector<int> s = multiply(v1,v2,base);

    for (int i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<" ";
    }
    
    return 0;
}
