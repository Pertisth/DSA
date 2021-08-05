#include <iostream>

using namespace std;

void Swap(int &a,int &b)
{
    int temp;
    temp = a;
    a=b;
    b=temp;
}
void selectionSort(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(a[j]<a[k])
            {
                k=j;
            }
        }
        Swap(a[i],a[k]);
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
    int a[]={8,1,3,4,17,0,2};
    int n =sizeof(a)/sizeof(a[0]);
    selectionSort(a,n);
    printArr(a,n);
    return 0;
}
