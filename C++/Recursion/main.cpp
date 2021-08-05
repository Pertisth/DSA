#include <iostream>

using namespace std;

int sumof(int A[],int N)
{
    if(N <=0)
    {
        return 0;
    }
    return sumof(A,N-1)+A[N-1];
}
void reverse(int a[],int i ,int j)
{
   if(i<j)
   {
       int temp;
        temp = a[i];
        a[i]= a[j];
        a[j]=temp;
        reverse(a,i+1,j-1);
   }

}

int pow(int n ,int x)
{
    if(x==0)
    {
        return 1;
    }
    if(x%2==0)
    {
        return pow(n*n,x/2);
    }
    else
    {
        return n*pow(n*n,(x-1)/2);
    }
}
int main()
{

    cout << pow(2,2);

    return 0;
}
