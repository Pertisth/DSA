#include <iostream>
#include <bits/stdc++.h>

using namespace std;



void snakepattern(int m, int n, int a[][50])
{
    for(int i=0;i<m;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<n;j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for(int j=n-1;j>=0;j--)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int m,n;
    cout << "Enter the Dimensions : ";
    cin >> m >> n;
    int a[50][50];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    snakepattern(m,n,a);

    return 0;
}
