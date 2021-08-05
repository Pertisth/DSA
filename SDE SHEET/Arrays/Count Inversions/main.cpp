#include <iostream>

using namespace std;


int mergeArr(int arr[],int temp[],int left,int mid,int right)
{
    int i=left;
    int j=mid;
    int k=left;
    int inv_count = 0;
    while(i<=mid-1 && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];

            // counting inversion
            inv_count+= (mid-i);

        }
    }

    while(i<=mid-1)
    {
        temp[k++]=arr[i++];
    }
    while(j<=right)
    {
        temp[k++] = arr[j++];
    }
    for(i=left;i<right;i++)
    {
        arr[i] = temp[i];
    }
    return inv_count;
}


int mergeSort(int arr[],int temp[],int left,int right)
{
    int inv_count = 0;
    int mid = left + (right-left)/2;
    if(left<right)
    {
        inv_count+=mergeSort(arr,temp,left,mid);
        inv_count+=mergeSort(arr,temp,mid+1,right);
        inv_count+=mergeArr(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

int main()
{
    int arr[]={1, 20, 6, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    cout << "No. of Inversions : ";
    cout << mergeSort(arr,temp,0,n-1);

    return 0;
}
