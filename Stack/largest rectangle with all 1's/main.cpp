#include <bits/stdc++.h>
using namespace std;


int largestArea(vector<int>nums)
{
    stack<int>st;
    int res = 0;
    for(int i=0;i<nums.size();i++)
    {
        while(!st.empty()&&st.top()>=nums[i])
        {
            int ht = nums[st.top()];
            st.pop();
            int len = st.empty()?i:i-st.top()-1;
            res = max(res,ht*len);
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int ht = nums[st.top()];
        st.pop();
        int len = st.empty()?nums.size():st.top()-1;
        res = max(res,ht*len);
    }
    return res;
}

int maxRectangle(vector<vector<int>>&matrix)
{
    int res = largestArea(matrix[0]);
    for(int i=1;i<matrix[0].size();i++)
    {
        for(int j=0;j<matrix.size();j++)
        {
            if(matrix[i][j] == 1)
            {
                matrix[i][j] = matrix[i][j] +matrix[i-1][j];
            }
        }
        res = max(res,largestArea(matrix[i]));
    }
    return res;
}

int main()
{
    vector<vector<int>>matrix={
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
    cout << maxRectangle(matrix);

    return 0;
}
