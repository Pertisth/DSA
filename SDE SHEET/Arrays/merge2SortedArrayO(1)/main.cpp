#include <iostream>

using namespace std;


void mergeSortedArrays(int arr1[],int arr2[],int m,int n)  //O(m x n)  O(1)
{
    int p,q;
    p=0;
    q=0;
    int k;
    for(int i=0;i<m;i++)
    {
        if(arr1[p]>arr2[q])
        {
            k=q;
            swap(arr1[p],arr2[q]);
            for(int j=0;j<n;j++)
            {
                if(arr2[k]>arr2[j])
                {
                    swap(arr2[k],arr2[j]);
                    k++;
                }
            }
            p++;
        }
        else
        {
            p++;
        }
    }

}


int nxtGap(int gap)
{
    if(gap<=1)
        return 0;
    return (gap/2)+(gap%2);
}

void mergeSortedArraysEfficient(int arr1[],int arr2[],int m,int n)  //Gap Method
{
    int gap = m+n;
    int i,j;
    gap = nxtGap(gap);
    while(gap>0)
    {
        // breaks loop when the window reaches out of bound of first arr. Thus (i+gap < m)
        for(i=0;i+gap<m;i++)
        {
            if(arr1[i]>arr1[i+gap])
            {
                swap(arr1[i],arr1[i+gap]);
            }
        }


        // check if gap is greater than size of first arr.
        //If it is then assign j as gap-n(next window), other wise set j as 0
        for(j= gap>m ? gap-m : 0 ; j<n && i<m; j++, i++)
        {
            if(arr1[i] > arr2[j])
            {
                swap(arr1[i],arr2[j]);
            }
        }


        // check if loop for i breaks and there are still in j loop and perform the operation
        if(j<n)
        {
            for(int j=0;j+gap<n;j++)
            {
                if(arr2[j] > arr2[j+gap])
                {
                    swap(arr2[j],arr2[j+gap]);
                }
            }
        }

        // Calculate next Gap and assign it to gap
        gap = nxtGap(gap);
   }
}

int main()
{
    int arr1[] = { 10, 27, 38, 43, 82 };
    int arr2[] = { 3, 9 };
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    mergeSortedArrays(arr1,arr2,m,n);

    cout<<endl;
    cout << "First Array : ";
    for(int i=0;i<m;i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "Second Array : ";
    for(int i=0;i<n;i++)
    {
        cout << arr2[i] << " ";
    }
    cout <<endl;
    return 0;
}
