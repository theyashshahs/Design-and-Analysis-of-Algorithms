#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i=0; i < n1; i++)
        L[i] = arr[l+i];
    
    for(j=0; j < n2; j++)
        R[j] = arr[m+1+j];

    i = 0;
    j = 0;
    k = l;

    while(i< n1 && j< n2)
    {
        if(L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }

        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

vector<int> mergesort(vector<int>& arr, int l, int r) {
    if(l < r)
    {
        int m = (l + (r-1))/2;

        mergesort(arr, l, m);
        mergesort(arr, m+1, r);

        merge(arr, l, m, r);
    }

    return arr;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    ifstream fin;
    ofstream fout;
    int ch;
    vector<int> v,v1;
    // clock_t start[5], end[5], startsum = 0, endsum = 0;
    clock_t end1, start1;

    //Average Case file execution
    fin.open("File 4.txt", ios::in);    //change the filename

    while (!fin.eof())
    {
        fin >> ch;
        v.push_back(ch);
    }
    fin.close();
    // for (int i = 0; i < 5; i++)
    // {
    //     start[i] = clock();
    //     v = mergesort(v, 0, v.size() - 1);
    //     end[i] = clock();
    // }

    start1 = clock();
    v = mergesort(v, 0, v.size() - 1);
    end1 = clock();

    fout.open("File 4sort.txt", ios::out);  //change the filename
    for(int i = 0; i < v.size(); i++ )
    fout << v[i] << "\n";
    fout.close();


    //Sorted file execution file
    // fin.open("File 4sort.txt", ios::in);    //change the filename

    // while (!fin.eof())
    // {
    //     fin >> ch;
    //     v1.push_back(ch);
    // }
    v1 = v;
    sort(v1.begin(), v1.end());

    clock_t start2 = clock();
    v1 = mergesort(v1, 0, v1.size() - 1);
    clock_t end2 = clock();

    // fin.close();

    // for (int i = 0; i < 5; i++)
    // {
    //     endsum += end[i];
    //     startsum += start[i];
    // }

    //Reverse sorted file
    reverse(v1.begin(), v1.end());

    fout.open("File 4sortrev.txt", ios::out);   //change the filename
    for(int i = 0; i < v1.size(); i++ )
    fout << v1[i] << "\n";

    fout.close();

    clock_t start3 = clock();
    v1 = mergesort(v1, 0, v1.size() - 1);
    clock_t end3 = clock();

    
    cout<<"Data for 6th File :- \n";
    cout<<std::fixed << "\nExecutable time for best case file : "<< (double)(end2 - start2)/CLOCKS_PER_SEC << " seconds " << endl;
    cout<<std::fixed << "\nExecutable time for average case file : "<< (double)(end1 - start1)/CLOCKS_PER_SEC << " seconds " << endl;
    cout<<std::fixed << "\nExecutable time for worst case file : "<< (double)(end3 - start3)/CLOCKS_PER_SEC << " seconds " << endl;
    return 0;
}