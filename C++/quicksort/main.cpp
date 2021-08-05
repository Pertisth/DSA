#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void Swap(int &a,int &b)
{
    int temp;
    temp = a;
    a=b;
    b=temp;
}
int Partition(int a[],int l,int h)
{
    int i,j;
    i=l;
    j=h;
    int pivot = a[l];
    do
    {
        do
        {
            i++;
        }while(a[i]<=pivot);
        do
        {
            j--;
        }while(a[j]>pivot);
        if(i<j)
            Swap(a[i],a[j]);
    }while(i<j);
    Swap(a[j],a[l]);
    return j;

}

void quicksort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=Partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
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
    int a[]={11,13,7,12,16,9,24,5,10,3};
    int n =sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n);
    printArr(a,n);
    return 0;
}
