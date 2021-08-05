#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
    int temp;
    temp = a;
    a=b;
    b=temp;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(arr[i],arr[j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << arr[i];
    }

}
