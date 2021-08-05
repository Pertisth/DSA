#include <iostream>

using namespace std;

int findmissing(int arr[],int n)
{
    int num = 0;
    for(int i=1;i<=n+1;i++)
    {
        num = num ^ i;
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        res = res ^ arr[i];
    }
    return num^res;
}

int main()
{
    int a[]={1,4,2,5};
    int n = sizeof(a)/sizeof(a[0]);
    cout << findmissing(a,n);
    return 0;
}
