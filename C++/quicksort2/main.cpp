#include <iostream>

using namespace std;
void swap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

}

int partition(int a[],int l,int h)
{
    int pivot = a[h];
    int i = l-1;
    for(int j=l;j<h;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);

        }
    }
    swap(a[i+1],a[h]);
    return i;

}
void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int p = partition(a,l,h);
        quicksort(a,l,p);
        quicksort(a,p+1,h);
    }
}
void print_array(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
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
    int l = 0;
    int h = n-1;
    quicksort(a,l,h);
    print_array(a,n);
    return 0;


}
