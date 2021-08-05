#include <iostream>

using namespace std;

void arr(int a[],int n)
{
    int temp;
    temp = a[0];
    a[0] = a[n];
    a[n] = temp;
}

void printArray(int a[],int n)
{
    int i=0;
    while(i<n)
        cout << a[i];
        i++;


}

int main()
{
    int a[]={10,20,30,40,50};

    int n = sizeof(a)/sizeof(a[0]);
    cout << n <<endl;
    printArray(a,n);
    arr(a,n);
    cout << a[0];

    return 0;
}
