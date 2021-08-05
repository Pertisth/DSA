#include <iostream>

using namespace std;

void insertionSort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j = i-1;
        int x = a[i];
        while(j>-1 && a[j] > x)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=x;
    }
}

void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[]={5,1,10,4,15,1,2,3};
    int n = sizeof(a)/sizeof(a[0]);
    insertionSort(a,n);
    printArray(a,n);
    return 0;
}
