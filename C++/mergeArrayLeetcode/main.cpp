#include <bits/stdc++.h>

using namespace std;

vector<int> mergeArray(vector<int>&num1,vector<int>&num2)
{
    vector<int>vect;
    int m = num1.size();
    int n = num2.size();
    int i = 0;
    int j = 0;


    while(i<m && j<n)
    {
        if(num1[i]<num2[j])
        {
            vect.push_back(num1[i++]);
        }
        else
        {
            vect.push_back(num2[j++]);
        }

    }
    while(i<m)
    {
        vect.push_back(num1[i++]);
    }
    while(j<n)
    {
        vect.push_back(num2[j++]);
    }
    return vect;

}

int main()
{
    vector<int>num1{2,4,6,8};
    vector<int>num2{2,4,6,8};
    vector<int> merged = mergeArray(num1,num2);
    for(int i=0;i<merged.size();i++)
    {
        cout << merged[i] << " ";
    }

    return 0;
}
