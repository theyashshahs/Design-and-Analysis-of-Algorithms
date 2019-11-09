#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main()
{   
    ifstream fin;
    ofstream fout;
    int ch, flag = 0;
    vector<int> v;

    fin.open("File 7.txt", ios::in); //change the filename

    while (!fin.eof())
    {
        fin>>ch;
        v.push_back(ch);
    }

    int s;
    cout<<"\nEnter the element you want to search for  : ";
    cin>>s;
    clock_t start = clock();
    for(int i = 0; i < v.size(); i++ ){
        
        if(v[i] == s) {
            flag = 1;
            break;
        }
    }

    clock_t end = clock();

    if(flag == 1)
        cout<<"\nElement found ";

    else
        cout<<"\nElement not found";
    
    cout<<std::fixed << "\nExecutable time : "<< (double)(end - start)/CLOCKS_PER_SEC << " seconds " << endl;
    fin.close();

    return 0;
}
