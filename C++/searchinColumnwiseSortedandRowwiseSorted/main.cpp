#include <bits/stdc++.h>

using namespace std;


pair<int,int>search2DMat(vector<vector<int>>arr,int x)
{
    int right=(arr[0].size())-1;
    int left =0;
    while(left<arr.size() && right>=0)
    {
        if(arr[left][right] == x)
        {
            return make_pair(left,right);
        }
        else if(arr[left][right] > x)
        {
            right--;
        }
        else{
            left++;
        }
    }
    return make_pair(-1,-1);

}

void printArr(vector<vector<int>>arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();i++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>>arr={
        {10,20,30,40,},
        {15,25,35,45},
        {27,29,27,48},
        {32,33,39,50},
    };
    pair<int,int> index;
    index = search2DMat(arr,39);
    cout <<"arr" << "["  << index.first  << "]"<< "["<< index.second <<"]";
    return 0;
}
