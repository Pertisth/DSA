#include <iostream>

using namespace std;

void mergetwoSortedList(int a[],int b[],int m,int n,int c[])
{
    int i,j,k;
    i=j=k=0;

    while(i<m&&j<n)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }
    for(;i<m;i++)
    {
        c[k++]=a[i];
    }
    for(;j<n;j++)
    {
        c[k++]=b[j];
    }
}

void printArr(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[]={1,3,4,6,7,9};
    int b[]={2,5,8,10,12,13};
    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);
    int c[m+n];
    mergetwoSortedList(a,b,m,n,c);
    printArr(c,m+n);
    return 0;
}
