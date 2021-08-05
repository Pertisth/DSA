#include <bits/stdc++.h>

using namespace std;
int NumberOfDistinctElements(int arr[],int n) // unsorted array
{
    unordered_set<int> nums;
    for(int i=0;i<n;i++)
    {
        nums.insert(arr[i]);

    }
    return nums.size();
}

int countDistinct(int arr[],int n) // if array is sorted
{
    sort(arr,arr+n);
    int res=0;
    for(int i=0;i<n;i++)
    {
        while(i<n-1 && arr[i]==arr[i+1])
        {
            i++;
        }
        res++;
    }
    return res;
}

int countDistinctNaive(int arr[],int n) //TC n2 , SC 1
{
    int res = 1;
    int i,j;
    for(i=1;i<n;i++)
    {
        int j;
        for(j=0;j<i;j++)
        {
            if(arr[i]==arr[j])
                break;
        }
        if(i==j)
            res++;
    }
    return res;
}

int main()
{
    int arr[]={6, 10, 5, 4, 9, 120, 4, 6,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countDistinctNaive(arr,n);

    return 0;
}
