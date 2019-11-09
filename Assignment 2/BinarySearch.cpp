#include<bits/stdc++.h>

using namespace std;

long int BinarySearch(vector<int> v, long int c){
    long int start = 0;
    long int end = v.size();
    long int mid;

    while(start <= end){
        mid = (start + end)/2;

        if(v[mid] == c)
            return mid;
        else if(v[mid] > c)
            end = mid -1;
        
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    ifstream fin;
    ofstream fout;
    vector<int> v;
    long int ch;

    fin.open("File 9.txt", ios::in); //change the filename

    while (!fin.eof())
    {
        fin>>ch;
        v.push_back(ch);
    }

    fin.close();

    cout<<"Size of file : " << v.size() - 1;

    sort(v.begin(), v.end());

    long int a,b,t1,t2;
    clock_t start1,start2,end1,end2;
    b = (v.size())/2 ;
    a = v[b];
  
        start2 = clock();
        t2 = BinarySearch(v, -1);
        end2 = clock();

        start1 = clock();
        t1 = BinarySearch(v, a);
        end1 = clock();

    if(t1>0)
        cout<<"\n\nBest case \nElement found at "<< t1 << "th position";

    if(t2<0)
        cout<<"\n\nWorst case \nElement not found ";

    cout<<std::fixed << "\n\nBest case executable time : "<< (double)(end1 - start1)/CLOCKS_PER_SEC << " seconds ";
    cout<<std::fixed << "\nWorst case executable time : "<< (double)(end2 - start2)/CLOCKS_PER_SEC << " seconds ";
    return 0;
}
