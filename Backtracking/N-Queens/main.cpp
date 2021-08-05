#include <iostream>

using namespace std;


bool isSafe(int **arr,int x,int col,int n)
{
    for(int row=0;row<x;row++)
    {
        if(arr[row][col] == 1)
            return false;
    }

    // check for left diagonal
    int i=x;
    int j=col;
    while(i>=0 && j>=0)
    {
        if(arr[i][j] == 1)
            return false;
        i--;
        j--;
    }

    // check for right diagonal

    i=x;
    j=col;
    while(i>=0 && j<n)
    {
        if(arr[i][j] == 1)
            return false;

        i--;
        j++;
    }

    // if any of the conditions does not return false then the position is safe
    return true;
}


bool nQueen(int **arr,int row,int n)
{
    if(row>=n)
        return true;  // base case when all queens are set

    for(int col=0;col<n;col++)
    {
        if(isSafe(arr,row,col,n))
        {
            arr[row][col] = 1;

            if(nQueen(arr,row+1,n))
            {
                return true;
            }
            arr[row][col] = 0;  //backtracking
        }
    }
    return false;
}

int main()
{

    int n;
    cin >> n;
    int** arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j] = 0;
        }
    }

    if(nQueen(arr,0,n))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Didn't find solution";
    }
    return 0;
}
