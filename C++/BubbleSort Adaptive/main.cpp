#include <iostream>

using namespace std;

void Swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void bubbleSort(int a[],int n)
{
    int flag = 0;
    for(int i=0;i<n-1;i++)
    {

        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                Swap(a[j],a[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            return;

    }
}

void printArr(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";

    }
    cout << endl;
}

int main()
{
    int a[]={8,8,3,5,4};
    int n =sizeof(a)/sizeof(a[0]);
    bubbleSort(a,n);
    printArr(a,n);
    return 0;
}
