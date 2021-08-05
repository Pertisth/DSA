#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    vector<int> nums;

    while(k--)
    {
        for(int i=0;i<n;i++)
        {
            nums.push_back(arr[i]);
        }
    }
    int m;
    m = nums.size();
    for(int i=0;i<m;i++)
    {
        nums[i]=nums[i]--;
    }
    for(int i=0;i<m;i++)
    {
        nums[nums[i]%m]=nums[nums[i]%m]+m;
    }
    for(int i=0;i<m;i++)
    {
        nums[i] =nums[i]/m;
    }
    for(int i=0;i<m;i++)
    {
        cout << nums[i] << " ";
    }


    return 0;
}
