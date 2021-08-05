#include <iostream>
using namespace std;

void heapify(int a[],int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        int j = i*2+1;
        while(j<n-1)
        {
            if(a[j+1]>a[j])
                j=j+1;
            if(a[i]<a[j])
            {
                int temp;
                temp = a[i];
                a[i]=a[j];
                a[j]=temp;
                i=j;
                j=2*i+1;
            }
            else
                break;
        }
    }
}

int DeleteHeap(int a[],int n)
{
    int x=a[0];
    a[0]=a[n-1];

    int i=0;
    int j=2*i+1;
    while(j<n-1)
    {
        if(a[j]<a[j+1])
            j=j+1;
        if(a[i]<a[j])
        {
            int temp;
            temp = a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*i+1;

        }
        else
        {
            break;
        }
    }
    a[n-1]=x;
    return x;
}


void heapSort(int a[],int n)
{
    int x=a[0];
    a[0]=a[n-1];
    int i,j;
    i=0;
    j=2*i+1;
    while(j<n-1)
    {
        if(a[j]<a[j+1])
        {
            j=j+1;
        }
        if(a[i]<a[j])
        {
            int temp;
            temp = a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*i+1;
        }
        else
            break;
    }
    a[n-1]=x;
}
void printHeap(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[]={5, 10, 30, 20, 35, 40, 15};
    int n = sizeof(a)/sizeof(a[0]);
    heapify(a,n);

    for(int i=n;i>0;i--)
    {
       heapSort(a,i);
    }
    printHeap(a,n);

    return 0 ;

}
