#include <bits/stdc++.h>

using namespace std;

void frequency(int arr[],int n)
{
    map<int,int>umap;
    for(int i=0;i<n;i++)
    {
        umap[arr[i]]++;
    }

    for(auto i : umap)
    {
        cout << i.first << " " << i.second << endl;
    }
}

int main()
{
    int arr[]={10,10,10,25,30,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    frequency(arr,n);
    return 0;
}

