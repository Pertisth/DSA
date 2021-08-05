#include <bits/stdc++.h>

using namespace std;

void N_Bonacii(int n,int m)  //window sliding technique
{
    int arr[m]={0};
    arr[n-1]=1;
    arr[n]=1;
    for(int i=n+1;i<m;i++)
    {
        arr[i]=(2*arr[i-1] - arr[i-n-1]);
    }
    for(int i=0;i<m;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n=5,m=15;
    N_Bonacii(n,m);
    return 0;
}
