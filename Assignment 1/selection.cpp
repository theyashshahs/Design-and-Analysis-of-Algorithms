#include<bits/stdc++.h>

using namespace std;

int main()
{   cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    vector<long int> v;
    ifstream fin;
    long int ch;
    fin.open("File 2.txt", ios::in);

    while (!fin.eof())
    {
        fin >> ch;
        v.push_back(ch);
    }

    clock_t start1 = clock();
    int min,temp;
    for(int i = 0; i < v.size() - 1; i++ ){
        min = i;
        for (int j = i+1 ; j < v.size(); j++){
            if(v[j] < v[min])
                min = j;

            temp = v[min];
            v[min] = v[i];
            v[i] = temp; 
        }
    }
    fin.close();
    clock_t end1 = clock();
    cout<<std::fixed << "\nExecutable time for unsorted file : "<< (double)(end1 - start1)/CLOCKS_PER_SEC << " seconds " << endl;

    return 0;
}