#include <bits/stdc++.h>

using namespace std;

bool checkSumZero(int arr[],int n)
{
    unordered_map<int,int>umap;
    int preFix = 0;


    for(int i=0;i<n;i++)
    {
        preFix+=arr[i];
        if(umap.find(preFix)!=umap.end())
        {
            cout << umap[preFix]+1 << " " << i << endl;
            return true;
        }
        umap[preFix]=i;
    }
    return false;
}


int main()
{

    int arr[]={4, 2, -3, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(checkSumZero(arr,n))
    {
        cout << "Found" ;
    }
    else{
        cout << "Not Found";
    }


    return 0;
}
