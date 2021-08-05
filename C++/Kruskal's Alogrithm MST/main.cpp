#include <bits/stdc++.h>
#define I INT_MAX

using namespace std;

int edge[3][9]={{1,1,2,2,3,4,4,5,5},
                {2,6,3,7,4,5,7,6,7},
                {25,5,12,10,8,16,14,20,18}};

int Set[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int included[9]={0};
int t[2][6];

void Union(int u,int v)
{
    if(Set[u]<Set[v])
    {
        Set[u]=Set[u]+Set[v];
        Set[v]=u;
    }
    else
    {
        Set[v]=Set[u]+Set[v];
        Set[u]=v;
    }

}
int Find(int u)
{
    int x=u,v=0;
    while(Set[x]>0)
    {
        x=Set[x];
    }
    while(u!=x)
    {
        v=Set[u];
        Set[u]=x;
        u=v;
    }
    return x;
}



int main()
{
    int i=0,j,u,v,Min=I,k,n=7,e=9;
    while(i<n-1)
    {
        Min=I;
        u=0;
        v=0;
        k=0;
        for(int j=0;j<e;j++)
        {
            if(included[j]==0&&edge[2][j]<Min)
            {
                Min = edge[2][j];
                u=edge[0][j];
                v=edge[1][j];
                k=j;
            }

        }
        if(Find(u)!=Find(v))
        {
            t[0][i]=u;
            t[1][i]=v;
            Union(Find(u),Find(v));
            i++;
        }
        included[k]=1;
    }
    for(int i=0;i<n-1;i++)
    {
        cout << "(" << t[0][i]<<"," << t[1][i] << ")" << endl;
    }
}
