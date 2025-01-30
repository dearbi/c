#include <bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+9;
int a[N];
bool flag[N];
void dfs(int u)
{
    if(u==n){
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(!flag[u])
        {
            a[u]=i;
            flag[u]=true;
            dfs(u+1);
            flag[u]= false;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dfs(0);
    return 0;
}