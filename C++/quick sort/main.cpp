#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

int partition(int a[],int l,int h)
{
    int pivot = a[l];
    int i,j;
    i=l;
    j=h;
    while(i<j)
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
        {
            swap(a[i],a[j]);
        }
    }
    swap(a[l],a[j]);
    return j;
}
void quicksort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,l+1,h);

    }
}
void print_arr(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] <<" ";
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int l=0;
    int h=n-1;
    quicksort(a,l,h);
    print_arr(a,n);
    return 0;
}
