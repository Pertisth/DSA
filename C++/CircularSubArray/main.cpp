#include <iostream>

using namespace std;

int MaxCircularSubArrayNaive(int arr[],int n)
{
   int res = arr[0];
   for(int i=0;i<n;i++)
   {
       int currSum = arr[i];
       int currMax = arr[i];
       for(int j=1;j<n;j++)
       {
           int index = (i+j)%n;
           currSum+=arr[index];
           currMax=max(currMax,currSum);
       }
       res = max(res,currMax);
   }
   return res;
}

int KadaneAlgo(int arr[],int n)
{
    int max_ending = arr[0];
    int res = arr[0];
    for(int i=1;i<n;i++)
    {
        max_ending = max(max_ending+arr[i],arr[i]);
        res = max(res,max_ending);
    }
    return res;
}

int maxCircularSubArrayEfficient(int arr[],int n) //using normal kadane's algo - O(n)
{
    int res;
    int kadane_sum = KadaneAlgo(arr,n);
    if(kadane_sum<0)
        return kadane_sum;
    int arrSum = 0;
    for(int i=0;i<n;i++)
    {
        arrSum+=arr[i];
        arr[i]=-arr[i];
    }
    int circularSum = arrSum + KadaneAlgo(arr,n);
    return (circularSum > kadane_sum) ? circularSum : kadane_sum;
}
int main()
{
    int arr[]={-5 ,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << MaxCircularSubArrayNaive(arr,n);
    return 0;
}
