#include <bits/stdc++.h> 
using namespace std; 
  
void Activity_Selector(vector<int> s, vector<int> f)
{ 
    vector<pair<int,int>> a;  
  
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p; 
  
    for(int i = 0; i < s.size(); i++)
    { 
        p.push(make_pair(f[i],s[i])); 
    } 
    
    auto it = p.top(); 
    int start = it.second; 
    int end = it.first; 

    p.pop(); 
    a.push_back(make_pair(start,end)); 
  
    while(!p.empty()){ 
        auto itr = p.top(); 
        p.pop(); 

        if(itr.second >= end){ 
            start = itr.second; 
            end = itr.first; 
            a.push_back(make_pair(start,end)); 
        } 
    } 
    cout << "Following Activities are be selected :- \n\n"; 
  
    for(auto itr=a.begin(); itr!=a.end(); itr++)
    { 
        cout << "{" << (*itr).first << ", " << (*itr).second << "}" << endl; 
    } 
} 

int main() 
{ 
    vector<int>s = {1, 3, 0, 5, 8, 5}; 
    vector<int>f = {2, 4, 6, 7, 9, 9}; 
    Activity_Selector(s,f); 
  
    return 0; 
} 