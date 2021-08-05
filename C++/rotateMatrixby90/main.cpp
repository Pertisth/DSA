#include <bits/stdc++.h>

using namespace std;

void rotateMatby90(vector<vector<int>>&mat)
{


    //transpose of matrix
    for(int i=0;i<mat.size();i++)
    {
        for(int j=i+1;j<mat[0].size();j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }

    //reversing columns
    for(int i=0;i<mat.size();i++)
    {
        int low = 0;
        int high = mat.size()-1;
        while(low<high)
        {
            swap(mat[low][i],mat[high][i]);
            low++;
            high--;
        }
    }

}

void printMat(vector<vector<int>>mat)
{


    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>>mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    //printMat(mat);
    rotateMatby90(mat);


    printMat(mat);
    return 0;
}
