#include <bits/stdc++.h>

using namespace std;



int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int a,b,k,counting = 0;
        cin >> a >> b >> k;
        int minimum = min(a,b);
        cout << "minimum value : " << minimum;
        while(k--)
        {
            int sum=0;
            sum=sum+minimum;
            counting++;
            if(sum>=k)
            {
                counting--;
                cout << counting <<endl;
                return 0;
            }
        }


    }
    return 0;
}
