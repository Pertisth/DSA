#include <bits/stdc++.h>

using namespace std;

void RotateArray(vector<vector<int>>&m)
{
    int n = m.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(m[i][j],m[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        reverse(m[i].begin(),m[i].end());
    }

}

void printArray(vector<vector<int>>m)
{
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m[i].size();j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> m{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    RotateArray(m);
    printArray(m);





    return 0;
}
