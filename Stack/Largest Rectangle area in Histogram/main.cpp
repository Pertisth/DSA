#include <bits/stdc++.h>
using namespace std;


int largestAreaofRectangleInHistogram(vector<int>num) // better solution  this solution uses extra space
{
    stack<int>st;
    vector<int>ps(num.size(),0);
    vector<int>ns(num.size(),0);
    // nearest previous smallest
    st.push(0);
    for(int i=0;i<num.size();i++)
    {
        while(!st.empty() && num[st.top()]>=num[i])
        {
            st.pop();
        }
        ps[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop();
    }

    // nearest next smallest
    st.push(num.size()-1);
    for(int i=num.size()-1;i>=0;i--)
    {
        while(!st.empty() && num[st.top()]>=num[i])
        {
            st.pop();
        }
        ns[i] = st.empty()?num.size():st.top();
        st.push(i);
    }

    //calculate area rectangle
    int res = 0;
    for(int i=0;i<num.size();i++)
    {
        int curr = num[i];
        curr = curr + (i-ps[i]-1)*num[i];
        curr = curr + (ns[i]-i-1)*num[i];
        res = max(res,curr);
    }
    return res;

}

int largestAreaofRectangleInHistogramBetter(vector<int>nums)
{
    stack<int>st;
    int res = 0;
    for(int i=0;i<nums.size();i++)
    {
        while(!st.empty() && st.top()>=nums[i])
        {
            int ht = nums[st.top()];
            st.pop();
            int len = st.empty()?i:i-st.top()-1;
            res = max(res,ht*len);
        }
        st.push(i);
    }
    while(!st.empty())  // remaining elements in stack (increasing order elements at end)
    {
        int ht = nums[st.top()];
        st.pop();
        int len = st.empty()?nums.size():nums.size()-st.top()-1;
        res = max(res,ht*len);
    }
    return res;
}


int main()
{
    vector<int>num;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }
    cout << largestAreaofRectangleInHistogram(num);
    return 0;
}
