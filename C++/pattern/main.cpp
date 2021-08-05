#include <iostream>

using namespace std;

int main()
{

    int k=0;
    for(int i=1;i<=5;i++)
    {


        for(int j=1;j<=5;i++)
        {
            if(j<=i)
            {
                cout << i ;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
