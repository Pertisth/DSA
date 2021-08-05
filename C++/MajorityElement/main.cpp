#include <iostream>

using namespace std;

int majorityElementEfficient(int arr[],int n) //Moore's Vooting algorithm
{
    int ele = 0;
    int counter=1;
    for(int i=1;i<n;i++)
    {
        if(arr[ele]==arr[i])
        {
            counter++;
        }
        else
            counter--;
        if(counter==0)
        {
            ele = i;
            counter=1;
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[ele]==arr[i])
            cnt++;

    }
    if(cnt <= n/2)
        return -1;
    return arr[ele];

}

int majorityElementNaive(int arr[],int n)
{

    for(int i=0;i<n;i++)
    {
        int cnt = 1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
                cnt++;
        }
        if(cnt > n/2)
            return arr[i];
    }
    return -1;
}

int main()
{
    int arr[]={1,25,1,2,1,1,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << majorityElementNaive(arr,n);

    return 0;
}
