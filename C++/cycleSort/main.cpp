#include <iostream>

using namespace std;

void cycleSortDistinct(int arr[],int n)
{

    for(int cs=0;cs<n-1;cs++)
    {
        int item = arr[cs];
        int pos = cs;
        for(int i=cs+1;i<n;i++)
        {
            if(arr[i]<item)
            {
                pos++;

            }
        }

        swap(item,arr[pos]);

        while(pos!=cs)
        {
            pos = cs;
            for(int i=cs+1;i<n;i++)
            {
                if(arr[i]<item)
                {
                    pos++;
                }
            }
            swap(item,arr[pos]);

        }
    }

}


void cycleSort(int arr[],int n)
{
    int sorts=0;
    for(int cs=0;cs<n-1;cs++)
    {
        int item = arr[cs];
        int pos = cs;
        for(int i=cs+1;i<n;i++)
        {
            if(arr[i]<item)
            {
                pos++;
            }
        }
        if(pos==cs)
        {
            continue;
        }
        while(item == arr[pos])
        {
            pos++;
        }
        if(pos!=cs)
        {
            swap(item,arr[pos]);
            sorts++;
        }
        while(pos!=cs)
        {
            pos = cs;
            for(int i=cs+1;i<n;i++)
            {
                if(arr[i]<item)
                {
                    pos++;
                }
            }
            while(item==arr[pos])
            {
                pos++;
            }
            if(item!=arr[pos])
            {
                swap(item,arr[pos]);
                sorts++;
            }
        }
    }
    cout << "Number of min. Sorts : " << sorts << endl;
}

int main()
{
    int arr[]={1, 8,10, 3, 9, 10, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cycleSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
