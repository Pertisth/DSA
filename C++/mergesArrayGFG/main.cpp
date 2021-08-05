#include <iostream>

using namespace std;

void mergeSort(int arr[],int arr2[],int m,int n)
{

    int i=0;
    int j=0;
    while(i<m && j<n)
    {
        if(arr[i]<arr2[j])
        {
            cout << arr[i++] << " ";
        }
        else
        {
            cout << arr2[j++] << " ";
        }
    }
    while(i<m)
    {
        cout << arr[i++] << " " ;
    }
    while(j<n)
    {
        cout << arr2[j++] << " ";
    }
}

int main()
{
    int arr[]={1,2,5,4,3};
    int arr2[]={4,6,1,0,9};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    mergeSort(arr,arr2,m,n);

    return 0;
}
