#include<bits/stdc++.h>
using namespace std;


void findSubsequence(string str, int idx, int n, string &res, string temp)
{
    if (idx == str.length())
    {
        if (temp.size() == n)
        {
            cout << temp << " ";
        }

        return;
    }

    findSubsequence(str, idx + 1, n, res, temp + str[idx]);
    findSubsequence(str, idx + 1, n, res, temp);
}

void permu(string user, string mother, int n)
{
    map<char, int>arr1;
    map<char, int>arr2;
    for (int i = 0; i < user.length(); i++)
    {
        arr1[user[i]]++;
    }
    for (int i = 0; i < mother.length(); i++)
    {
        arr2[mother[i]]++;
    }
    string common = "";
    for (auto  x : arr1)
    {
        if (arr2.find(x.first) != arr2.end())
        {
            common = common + x.first;
        }
    }
    // cout << common;
    string res = "";
    string temp = "";
    findSubsequence(common, 0, n, res, temp);
    cout << res << endl;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string user;
    string mother;
    int n;
    cin >> user >> mother >> n;
    transform(user.begin(), user.end(), user.begin(), ::tolower);
    transform(mother.begin(), mother.end(), mother.begin(), ::tolower);
    permu(user, mother, n);


    return 0;
}