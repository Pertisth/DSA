#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int c;
        cin >> c;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        int s = a[0];
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            if(s-a[i]<=c)
            {
                ans++;
            }
        }
        if(ans>0)
        {
            cout << ans+1 <<endl;
        }
        else
        {
            cout << ans <<endl;
        }
    }
    return 0;
}
