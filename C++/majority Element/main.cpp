#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int>&nums)
{
    int n = nums.size();
    unordered_map<int ,int> hashmap;
    for(int i=0;i<n;i++)
    {
        if(++hashmap[nums[i]>floor(n/2)])
            return nums[i];

    }
    return -1;

}

int mapping(vector<int>&nums)
{
    int n=nums.size();
    unordered_map<int,int>map;
    for(int i=0;i<n;i++)
    {
        map[nums[i]]++;
    }
    unordered_map<int,int>::iterator itr;
    for(auto i:map)
        cout << i.first << "->" <<  i.second << "  "<<endl;
}

int main()
{

    vector<int> arr={2,2,1,1,1,2,2};
    cout << mapping(arr);
    return 0;
}
