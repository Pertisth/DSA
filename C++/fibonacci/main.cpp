#include <iostream>

using namespace std;
int a[10];

int fib(int n)
{
    if(n<=1)
    {
        a[n]=n;
        return n;
    }
    else
    {
        if(a[n-2]==-1)
        {
            a[n-2]=fib(n-2);
        }
        if(a[n-1]==-1)
        {
            a[n-1]=fib(n-1);
        }
        a[n]=a[n-2]+a[n-1];
        return a[n-2]+a[n-1];
    }

}

int main()
{
    for(int i=0;i<10;i++)
    {

        a[i]=-1;
    }
    cout << fib(5);

    return 0;
}
