#include <iostream>

using namespace std;
int mini(int &a,int &b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a,b,k;
        cin >> a >> b >> k;
        while(k--)
        {
            int min=mini(a,b);
        }
        cout << min;
    }
}
