#include<iostream>
#include<vector>
using namespace std;

void swapArr(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}


void reArrange(vector<int>&arr, int n)
{
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            mid++;
        }
        else if (arr[mid] >= 1)
        {
            swap(arr[mid], arr[high]);
            cout << "Positive " << arr[mid] << " " << arr[high] << endl;
            high--;
        }
        else if (arr[mid] <= -1)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;

        }
    }


    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";

    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    reArrange(arr, n);
    return 0;
}