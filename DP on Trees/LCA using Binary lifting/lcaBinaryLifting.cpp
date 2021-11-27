#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<long long>list[], int n)
{
    int currEle = 2;
    for (int i = 1; i < n; i++)
    {
        int ele;
        cin >> ele;
        list[currEle].push_back(ele);
        list[ele].push_back(currEle);
        currEle++;
    }
}

long long parent[2 * 100005][20];
long long level[2 * 100005];
void dfs(vector<long long>list[], long long node, long long par = 0, long long lev = 1)
{
    level[node] = lev;
    parent[node][0] = par;

    for (int i = 1; i <= 19; i++)
    {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }

    for (int x : list[node])
    {
        if (x != par)
        {
            dfs(list, x, node, lev + 1);
        }
    }
}

long long kthParent(long long node, long long k)
{
    int count = 0;
    while (k)
    {
        if (k & 1)
        {
            node = parent[node][count];
        }
        k = k >> 1;
        count++;
    }
    return node;
}

long long lca(long long u, long long v)
{
    if (level[v] < level[u])
    {
        swap(u, v);
    }

    long long k = level[v] - level[u];
    v = kthParent(v, k);
    if (u == v)
    {
        return u;
    }
    for (int i = 16; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n, q;
    cin >> n >> q;
    vector<long long>list[n + 1];
    addEdge(list, n);
    dfs(list, 1);
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        cout << lca(l, r) << endl;
    }
    return 0;

}