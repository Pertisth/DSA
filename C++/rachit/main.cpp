#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str[8];
    int count=0;
    int a[8];
    for(int i=0;i<8;i++)
    {
        cin >> str[i];
        cin >> a[i];
    }
    string s = "mohan";
    for(int i=0;i<8;i++)
    {
        if(s==str[i])
        {
            cout << "mohan appears once in the list";
            break;
        }
        count++;
    }
    if(count == 8)
    {
        cout << "mohan not appears in the list";
    }
    return 0;

}
