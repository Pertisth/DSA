#include <iostream>

using namespace std;

int minsumpath(int a[][5])
{
    int dp[5][5];
    int i=0;
    for(int j=0;j<3;j++)
    {
        a[i][j]=d[i][j];
    }
    int j=0;
    for(int i=0;i<n;i++)
    {
       a[i][j]=dp[i][j];
    }
    int sum=0;
    for(int i=1;i<3;i++)
    {
        for(int j=1;j<3;j++)
        {
            if(a[i][])
        }
    }
}

int main()
{
    int a[][5] ={{1,2,3},
                 {4,5,6},
                 {7,8,9}};
    cout << minsumpath(a);
    return 0;
}
