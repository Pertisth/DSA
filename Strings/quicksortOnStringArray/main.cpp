#include <iostream>
#include <time.h>

using namespace std;

int partitioning(string arr[],int low,int high)
{
    srand(time(0));
    int n = sizeof(arr)/sizeof(arr[0]);

    int num = rand()%((high) - low + 1) + low;
    swap(arr[num],arr[high]);
    string pivot = arr[high];
    int i = (low-1);

    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]>=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}


void quickSort(string arr[],int low,int high)
{
    if(low<high)
    {
        int pivot = partitioning(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int main()
{
    string arr[]={"fa","d","pertisth"};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
