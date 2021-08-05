#include <bits/stdc++.h>
#define I INT_MAX

using namespace std;

int cost[8][8]={
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
};
int t[2][6];
int near[8];



int main()
{
    int n=7;
    int Min = I;
    int u,v;

    for(int i=1;i<=n;i++)
    {
        near[i]=I;
        for(int j=i;j<=n;j++)
        {
            if(cost[i][j]<Min)
            {
                Min = cost[i][j];
                u=i;
                v=j;
            }
        }
    }
    t[0][0]=u;
    t[1][0]=v;
    near[u]=0;
    near[v]=0;

    for(int i=1;i<=n;i++)
    {
        if(near[i]!=0 ){                   // here seperate if ,,you used && condition
                if(cost[i][u]<cost[i][v]){
                near[i]=u;
        }
            else{
                near[i]=v;
            }
        }
}


    for(int i=1;i<n-1;i++)
    {
          int k;
        Min=I;
        for(int j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][near[j]] < Min)
            {
                k=j;
                Min=cost[j][near[j]];

            }
        }
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
        for(int j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]])
            {
                near[j]=k;
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        cout << "(" << t[0][i] <<"," << t[1][i] << ")" << endl;
    }




    return 0;
}
