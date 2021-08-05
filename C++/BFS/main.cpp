#include <bits/stdc++.h>

using namespace std;

void BFS(int G[][7],int start,int n)
{
    bool visited[7]={false};
    int i=start;
    queue<int> q;
    cout << i << " ";
    visited[i]=true;
    q.push(i);
    while(!q.empty())
    {
        i=q.front();
        q.pop();
        for(int j=1;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==false)
            {
                cout << j << " ";
                visited[j]=true;
                q.push(j);
            }
        }
    }
}

void DFS(int G[][7],int start,int n)
{
    int i=start;
    static bool visited[7]={false};
    if(visited[i]==false)
    {
        cout << i << " ";
        visited[i]=true;
        for(int j=1;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==false)
            {
               DFS(G,j,n);
            }

        }
    }

}

int main()
{
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};
    DFS(G,4,7);
    return 0;
}
