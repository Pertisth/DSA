#include <bits/stdc++.h>

using namespace std;

/// Navie's Approach ///

int sumFun(int arr[],int a,int b)
{
    int sum = 0;
    for(int i=a;i<=b;i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int minPages(int arr[],int n,int k)
{
    int res = INT_MAX;
    if(n==1)
        return arr[0];
    if(k==1)
    {
        return sumFun(arr,0,n-1);
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            res = min(res,max(minPages(arr,i,k-1),sumFun(arr,i,n-1)));
        }
    }
    return res;
}

/// Navie's Approach ///




/// Efficient Approach using Binary Search ///

bool isFeasible(int arr[],int n,int k,int ans);
int minPagesBinary(int arr[],int n,int k)
{
    int sum = 0;
    int mx = 0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        mx = max(mx,arr[i]);
    }
    int low = mx;
    int high = sum;
    int res = 0;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(isFeasible(arr,n,k,mid))
        {
            res = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }

    }
    return res;
}

bool isFeasible(int arr[],int n,int k,int ans)
{
    int req = 1;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]>ans)
        {
            req++;
            sum = arr[i];
        }
        else
        {
            sum = sum+arr[i];
        }
    }
    return (req<=k);
}


/// Efficient Approach using Binary Search ///




int main()
{
    int arr[]= {12, 34, 67, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout << minPagesBinary(arr,n,k);
    return 0;
}
