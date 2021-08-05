#include <bits/stdc++.h>
using namespace std;
void Execute(int &x,int y=200)
{
    int temp=x+y;
    x+=temp;
    if(y!=200)
        cout << temp << x << y << "--";
}
int main()
{
    char arr[100];
    printf("%d",scanf("%s",arr));


    return 0;
}
