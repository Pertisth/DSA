#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int removeKelements(string s,int k)
{
    if(s.size()== k)
    {
        return 0;
    }
    stack <char> a;
    int i=0;
    while(!a.empty() && k>0 && a.top()> s[i])
    {
        a.pop();
        k--;
    }



}

int main()
{
    string a = "12345";
    int k = 4;
    int num=removeKelements(a,k);
    cout << num;




    return 0;
}
