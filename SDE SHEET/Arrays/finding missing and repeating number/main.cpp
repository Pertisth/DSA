#include <bits/stdc++.h>

using namespace std;


pair<int,int> missingAndRepeating(int arr[],int n)
{
    int xor1 = arr[0];
    for(int i=1;i<n;i++)
    {
        xor1 = xor1 ^ arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        xor1 = xor1 ^ i;
    }

    int setBitNo = xor1 & ~(xor1-1);

    int x=0;
    int y=0;

    for(int i=0;i<n;i++)
    {
        if(setBitNo & arr[i])
            x = x^arr[i];
        else
            y = y^arr[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(setBitNo & i)
            x=x^i;
        else
            y=y^i;
    }

    pair<int,int> result = make_pair(x,y);
    return result;



}

int main()
{
    int arr[]={ 4,3,6,2,1,1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    pair<int,int> result = missingAndRepeating(arr,n);
    cout << "Missing Number : " << result.first << " " <<"Repeating Number : "<< result.second;
    return 0;
}
