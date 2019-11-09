#include<bits/stdc++.h>

using namespace std;

int main()
{   cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    ifstream fin;
    ofstream fout;
    int ch, flag = 0;
    vector<int> v,v1;

    //Unsorted file execution file

    fin.open("File 1.txt", ios::in);    //change the filename

    while (!fin.eof())
    {
        fin >> ch;
        v.push_back(ch);
    }

    fin.close();

    int key;
    int i,j;
    
    clock_t start1 = clock();
    for( i = 1; i < v.size(); i++ ) {
        cout<<" Completed %  \r" << ((double)i/v.size()*100); 
        key = v[i];
        j = i - 1;
        
        while(j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = key;
    }
    fin.close();
    clock_t end1 = clock();

    fout.open("File 1sort.txt", ios::out);  //change the filename
    for(int i = 0; i < v.size(); i++ )
    fout << v[i] << "\n";

    fout.close();

    //Sorted file execution file
    fin.open("File 1sort.txt", ios::in);    //change the filename

    while (!fin.eof())
    {
        fin >> ch;
        v1.push_back(ch);
    }

    clock_t start2 = clock();

    for( i = 0; i < v1.size(); i++ ){
        cout<<" Completed %  \r" << ((double)i/v1.size()*100); 
        key = v1[i];
        j = i - 1;
        
        while(j >= 0 && v1[j] > key){
            v1[j+1] = v1[j];
            j = j - 1;
        }
        v1[j+1] = key;
    }

    fin.close();
    
    clock_t end2 = clock();
    
    //Reverse sorted filecd 
    reverse(v1.begin(), v1.end());
    clock_t start3 = clock();
    
    for( i = 0; i < v1.size(); i++ ){
        cout<<" Completed %  \r" << ((double)i/v1.size()*100); 
        key = v1[i];
        j = i - 1;
        
        while(j >= 0 && v1[j] > key){
            v1[j+1] = v1[j];
            j = j - 1;
        }
        v1[j+1] = key;
    }

    clock_t end3 = clock();

    
    cout<<std::fixed << "\nExecutable time for average case file : "<< (double)(end1 - start1)/CLOCKS_PER_SEC << " seconds " << endl;
    cout<<std::fixed << "\nExecutable time for best case file : "<< (double)(end2 - start2)/CLOCKS_PER_SEC << " seconds " << endl; 
    cout<<std::fixed << "\nExecutable time for worst case file : "<< (double)(end3 - start3)/CLOCKS_PER_SEC << " seconds " << endl;
    
    return 0;
}
