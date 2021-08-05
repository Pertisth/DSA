#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int beautifulMatrix(vector<vector<int>> mat)
{
    pair<int,int> idx;
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            if(mat[i][j]==1)
            {
                idx=make_pair(i,j);
                break;
            }
        }
    }
    int count=0;
    count+=abs(idx.first - 2);
    count+=abs(idx.second - 2);
    return count;
}

int main()
{
    vector<vector<int>> mat;
    for(int i=0;i<5;i++)
    {
        vector<int>ve;
        for(int j=0;j<5;j++)
        {
            int in;
            cin >> in;
            ve.push_back(in);
        }
        mat.push_back(ve);
    }
    cout << beautifulMatrix(mat);
    return 0;
}
