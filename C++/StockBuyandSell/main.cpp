#include <iostream>

using namespace std;

int stockBuyAndSellNaive(int arr[],int start,int last)
{
    if(last<=start)
        return 0;
    int profit = 0;
    for(int i=start;i<last;i++)
    {
        for(int j=i+1;j<=last;j++)
        {
            if(arr[j]>arr[i])
            {
                int curr_profit = arr[j]-arr[i] + stockBuyAndSellNaive(arr,start,i-1) + stockBuyAndSellNaive(arr,j+1,last);
                profit = max(profit,curr_profit);
            }
        }
    }
    return profit;

}

int main()
{
    int arr[]={100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << stockBuyAndSellNaive(arr,0,n-1);
    return 0;
}
