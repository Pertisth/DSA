#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void MissinginFirstN(int a[],int N)
{
    int sum1=0;
    for(int i=0;i<N;i++)
    {
        sum1=sum1+a[i];
    }
    int sum = a[N-1]*(a[N-1]+1)/2;
    cout << "The Missing Element is : " << sum-sum1;
}

void MissinginNotFirstElements(int a[],int N)
{
    int first=a[0];
    int count=0;

    for(int i=0;i<N;i++)
    {
        //cout << a[i]-i<< endl;
        if(a[i]-i!=first)
        {
            while(first < a[i]-i)
            {
                cout << "Missing Element is: "<<i+first<< endl;
                first++;
            }
        }
    }
}

void MissingEleinUnsortedArr(int a[],int N)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0;i<N;i++)
    {
        if(maxi < a[i])
        {
            maxi=a[i];
        }
        if(mini > a[i])
        {
            mini = a[i];
        }
    }
    int l=mini;
    int h=maxi;
    int b[h]={};
    for(int i=0;i<N;i++)
    {
        b[a[i]]=1;
    }
    for(int i=l;i<=h;i++)
    {

        if(b[i]==0)
        {
            cout << "Missing Element is : " << i <<endl;
        }
    }



}
int main()
{
    int num;
    int a[]={1,2, 3, 4, 5, 6, 7, 8, 10};
    int N=sizeof(a)/sizeof(a[0]);

    MissingEleinUnsortedArr(a,N);





    return 0;
}
