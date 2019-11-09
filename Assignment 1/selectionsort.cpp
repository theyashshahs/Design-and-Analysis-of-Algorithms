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

    int min,temp;

    clock_t start1 = clock();
    for(int i = 0; i < v.size() - 1; i++ ) {
        cout<<" Completed %  \r" << ((double)i/v.size()*100); 
        min = i;
        for (int j = i+1 ; j < v.size(); j++){
            if(v[j] < v[min])
                min = j;
        }
            temp = v[min];
            v[min] = v[i];
            v[i] = temp; 
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

    for(int i = 0; i < v1.size() - 1; i++){
        cout<<" Completed %  \r" << ((double)i/v1.size()*100); 
        min = i;
        for (int j = i+1 ; j < v1.size(); j++){
            if(v1[j] < v1[min])
                min = j;
        }
            temp = v1[min];
            v1[min] = v1[i];
            v1[i] = temp; 
    }

    clock_t end2 = clock();

    fin.close();

    //Reverse sorted file
    reverse(v1.begin(), v1.end());
    fout.open("File 1sortrev.txt", ios::out);   //change the filename
    for(int i = 0; i < v1.size(); i++ )
    fout << v1[i] << "\n";

    fout.close();

    clock_t start3 = clock();
    
    for(int i = 0; i < v1.size() - 1; i++ ){
        cout<<" Completed %  \r" << ((double)i/v1.size()*100); 
        min = i;
        for (int j = i+1 ; j < v1.size(); j++){
            if(v1[j] < v1[min])
                min = j;
        }                                                           
            temp = v1[min];
            v1[min] = v1[i];
            v1[i] = temp; 
    }

    clock_t end3 = clock();

    fout.open("File 1sorting.txt", ios::out);   //change the filename
    for(int i = 0; i < v1.size(); i++ )
    fout << v1[i] << "\n";

    fout.close();

    cout<<std::fixed << "\nExecutable time for best case file : "<< (double)(end2 - start2)/CLOCKS_PER_SEC << " seconds " << endl;
    cout<<std::fixed << "\nExecutable time for average case file : "<< (double)(end1 - start1)/CLOCKS_PER_SEC << " seconds " << endl;
    cout<<std::fixed << "\nExecutable time for worst case file : "<< (double)(end3 - start3)/CLOCKS_PER_SEC << " seconds " << endl;
    return 0;
}