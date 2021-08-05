#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int increasing = 0;
    int decreasing = 0;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int i=0;
    while(arr[i]>arr[i-1]&&i<n)
        i++;
    while(arr[i]==arr[i-1]&&i<n)
        i++;
    while(arr[i]<arr[i-1]&&i<n)
        i++;
    if(i==n){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    return 0;
}
