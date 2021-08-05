#include <iostream>

using namespace std;

int oneOddOccuringNaive(int arr[],int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int count = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count%2!=0)
        {
            return arr[i];
        }
    }
}

int OneoddOccuringEfficient(int a[],int n)
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        res = res^a[i];
    }
    return res;
}

void twoOddOccuring(int arr[],int n)
{
    int res1=0;
    int res2=0;
    int Xor = 0;
    for(int i=0;i<n;i++)
    {
        Xor = Xor ^ arr[i];
    }
    int rightmostsetbit = (Xor) & ~(Xor-1);
    for(int i=0;i<n;i++)
    {
        if((arr[i]&rightmostsetbit)!=0)
        {
            res1 = res1^arr[i];
        }
        else
        {
            res2 = res2 ^ arr[i];
        }
    }
    cout <<  res1 <<" ," << res2;
}

int main()
{
    int a[]={1,1,2,2,4,4,4,5};
    int n =sizeof(a)/sizeof(a[0]);
    cout << OneoddOccuringEfficient(a,n);
    return 0;
}
