//题目链接：https://www.starrycoding.com/problem/64
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+9;
vector<int> g[N];
bitset<N> vis;
void dfs(int x)
{
    vis[x]= true;
    for(auto &y:g[x])
    {
        if (vis[y]) continue;
        dfs(y);
    }
}
int main()
{
    int n,m;cin>>n>>m;
    while(m--)
    {
        int u,v;cin>>u>>v;
        if(u!=v) g[u].push_back(v);
    }
    dfs(1);

    for(int i=1;i<=n;i++)
    {
        if(vis[i]) cout<<i<<" ";
    }
    return 0;
}