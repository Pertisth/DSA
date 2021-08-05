#include <iostream>

using namespace std;


int mergeArrays(int arr[],int low,int mid,int high)
{

    int n = mid-low+1;
    int m = high - mid;
    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++)
    {
        arr1[i] = arr[low+i];
    }
    for(int i=0;i<m;i++)
    {
        arr2[i]=arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=low;
    int inversions = 0;
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k++]=arr1[i++];
        }
        else
        {
            arr[k++]=arr2[j++];
            inversions += n-i;
        }
    }
    while(i<n)
    {
        arr[k++]=arr1[i++];
    }
    while(j<m)
    {
        arr[k++]=arr2[j++];
    }
    return inversions;
}

int mergeSort(int arr[],int low,int high)
{
    int res = 0;
    if(low<high)
    {
        int mid = low + (high-low)/2;
        res += mergeSort(arr,low,mid);
        res += mergeSort(arr,mid+1,high);

        res += mergeArrays(arr,low,mid,high);
    }
    return res;
}

int main()
{
    int arr[]={468, 335 ,1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154 ,293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36 ,395 ,204 ,312, 323};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << mergeSort(arr,0,n-1)<< endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
