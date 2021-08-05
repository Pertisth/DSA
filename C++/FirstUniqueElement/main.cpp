#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int uniqueElement(string a)
{
    int H[26]={};
    for(int i=0;a[i]!='\0';i++)
    {
        H[a[i]-97]++;
    }
    for(int i=0;a[i]!='\0';i++)
    {
        if(H[a[i]-97]==1)
        {
            return i;
        }
    }
    return -1;

}





int main()
{
    string a;
    getline(cin , a);
    int b = uniqueElement(a);
    cout << b;

    return 0;
}
