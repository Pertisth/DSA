#include <iostream>

using namespace std;

int func(int n)
{

    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    else
    {
        return func(n-1)+func(n-2);
    }
}

int main()
{
    int sum = func(6);
    cout << sum;
    return 0;
}
