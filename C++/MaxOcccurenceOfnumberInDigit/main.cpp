#include <bits/stdc++.h>

using namespace std;

int MaxOccurence(int arr[],int k,int n)
{
    vector<int>nums;
    for(int i=0;i<n;i++)
    {
        int num;
        num = arr[i];
        int rem=0;
        int counter=0;
        while(num>0)
        {
            rem = num % 10;
            if(rem == k)
            {
                counter++;
            }
            num=num/10;
        }
        nums.push_back(counter);
    }
    int max_num = INT_MIN;
    int index_num;
    int m = nums.size();
    for(int i=0;i<m;i++)
    {
        if(nums[i]>max_num)
        {
            max_num = nums[i];
            index_num=i;
        }
    }
    if(max_num==0)
    {
        return 0;
    }
    return arr[index_num];
}

int main()
{
    int n;
    cin >> n;
    if(n==0)
    {
        return -1;
    }
    int k;
    cin >> k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int ans = MaxOccurence(arr,k,n);
    cout << ans;
    return 0;

}
