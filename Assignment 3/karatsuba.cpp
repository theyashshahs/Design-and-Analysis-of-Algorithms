#include<bits/stdc++.h>

using namespace std;

int MakeEqualLength(string &a, string &b) {
    int len1 = a.size();
    int len2 = b.size();

    if(len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
            a = '0' + a;
        
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
            b = '0' + b;
    }
    
    return len1;
}

string AddString(string a, string b) {
    int length = MakeEqualLength(a, b);
    int carry = 0;

    for (int i = length-1; i >= 0; i--) {
        
    }
   
    
}