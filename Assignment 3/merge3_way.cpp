#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& a, int low, int mid1, int mid2, int high, vector<int>& b) 
{
    int i = low, j = mid1, k = mid2, l = low;

    while ((i < mid1) && (j < mid2) && (k < high)) {

        if(a[i] < a[j]) {
            if(a[i] < a[k]) 
                b[l++] = a[i++];
        
            else
                b[l++] = a[k++];
        }
        else
        {
            if (a[j] < a[k])
                b[l++] = a[j++];

            else
                b[l++] = a[k++];
        }
    }
    while ((i < mid1) && (j < mid2)) {

        if(a[i] < a[j])
            b[l++] = a[i++];

        else
            b[l++] = a[k++];
        
    }
    
    while ((j < mid2) && (k < high))
    {
        if(a[j] < a[k])
            b[l++] = a[j++];
        
        else
            b[l++] = a[k++];
    }
    
    while ((i < mid1) && (k < high)) {

        if(a[i] < a[k])
            b[l++] = a[i++];
    
        else
            b[l++] = a[k++];
    }
    
    while (i <  mid1)
    {
        b[l++] = a[i++];
    }
    
    while (j < mid2)
    {
        b[l++] = a[j++];
    }
    
    while (k < high)
    {
        b[l++] = a[k++];
    }
    
}

void MergeSortRec(vector<int>& a, int low, int high, vector<int>& b) 
{
    if(high - low < 2) {
        return;

    }
    
    int mid1 = low + ((high - low)/3);
    int mid2 = low + 2*((high - low)/3) + 1;

    MergeSortRec(b, low, mid1, a);
    MergeSortRec(b, mid1, mid2, a);
    MergeSortRec(b, mid2, high, a);

    merge(b, low, mid1, mid2, high, a);
}

void MergeSort(vector<int>& a, int n) 
{
    if(n==0)
        return;
    
    vector<int> b;

     for(int i=0; i < a.size(); i++) {
        b[i] = a[i];
    }
    
    MergeSortRec(b, 0, n, a);

    for(int i=0; i < b.size(); i++) {
        a[i] = b[i];
    }

}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    ifstream fin;
    ofstream fout;
    int ch;
    vector<int> v,v1;
    clock_t end1, start1;

    
    fin.open("File 1.txt", ios::in);   

    while (!fin.eof())
    {
        fin >> ch;
        v.push_back(ch);
    }
    fin.close();
   
    //Average Case file execution
    start1 = clock();
    MergeSort(v, v.size() - 1);
    end1 = clock();

    fout.open("File 1sort.txt", ios::out); 
    for(int i = 0; i < v.size(); i++ )
    fout << v[i] << "\n";
    fout.close();

    
    //Best Case file execution
    v1 = v;
    sort(v1.begin(), v1.end());

    clock_t start2 = clock();
    MergeSort(v1, v1.size() - 1);
    clock_t end2 = clock();

    //Reverse sorted file
    reverse(v1.begin(), v1.end());

    fout.open("File 1sortrev.txt", ios::out);  
    for(int i = 0; i < v1.size(); i++ )
    fout << v1[i] << "\n";

    fout.close();

    clock_t start3 = clock();
    MergeSort(v1, v1.size() - 1);
    clock_t end3 = clock();

    
    cout<<"\nData for 1th File :- \n";
    cout<<std::fixed << "\nExecutable time for best case file : "<< (double)(end2 - start2)/CLOCKS_PER_SEC << " seconds " << endl;
    cout<<std::fixed << "\nExecutable time for average case file : "<< (double)(end1 - start1)/CLOCKS_PER_SEC << " seconds " << endl;
    cout<<std::fixed << "\nExecutable time for worst case file : "<< (double)(end3 - start3)/CLOCKS_PER_SEC << " seconds " << endl;
    return 0;
}
