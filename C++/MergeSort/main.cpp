#include <bits/stdc++.h>
using namespace std;

void Merge(int a[],int l,int mid ,int h)
{
    int i=l;
    int j=mid+1;
    int k=l;
    int b[h+1];
    while(i<=mid&&j<=h)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];

        }

    }
    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    while(j<=h)
    {
        b[k++]=a[j++];
    }
    for(int i=l;i<h;i++)
    {
        a[i]=b[i];
    }

}

void MergeSort(int a[],int l,int h)
{

    if(l<h)
    {
        int mid = l+(h-l)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,h);
        Merge(a,l,mid,h);

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
    int a[]={1,10,5,1,6,15,15};
    int n =sizeof(a)/sizeof(a[0]);
    MergeSort(a,0,n-1);
    printArr(a,n);
    return 0;

}
