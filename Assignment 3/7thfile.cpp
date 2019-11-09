#include<bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    int ch;
    vector<int> v,v1;
    clock_t end1, start1;

    
    fin.open("File 10.txt", ios::in);   

    while (!fin.eof())
    {
        fin >> ch;
        v.push_back(ch);
    }
    fin.close();
    
    // reverse(v.begin(), v.end());
    sort(v.begin(), v.end());

    start1 = clock();
    sort(v.begin(), v.end());
    end1 = clock();

    cout<<std::fixed << "\nExecutable time for best case file : "<< (double)(end1 - start1)/CLOCKS_PER_SEC << " seconds " << endl;
    return 0;
}
