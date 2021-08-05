#include<bits/stdc++.h>

using namespace std;

int findMax(int a[],int n)
{
    int Max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]>Max)
        {
            Max=a[i];
        }
    }
    return Max;
}

void countSort(int a[],int n)
{
    int Max=findMax(a,n);
    int *b;
    b=new int [Max+1];
    for(int i=0;i<Max+1;i++)
    {
        b[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    int i=0;
    int j=0;
    while(j<Max+1)
    {
        if(b[j]>0)
        {
            a[i++]=j;
            b[j]--;
        }
        else
        {
            j++;
        }
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
    int a[]={9,8,1,0,3,5,5,12};
    int n= sizeof(a)/sizeof(a[0]);
    countSort(a,n);
    printArr(a,n);

    return 0;
}
