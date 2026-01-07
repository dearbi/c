//https://www.acwing.com/problem/content/2/
#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
int v[N],w[N];
int mem[N][N];
int f[N][N];
int dfs(int x,int spV)
{
    int sum=0;
    if(mem[x][spV]) return mem[x][spV];
    if(x>n) sum=0;
    else if(spV<v[x])
        sum=dfs(x+1,spV);
    else if(spV>=v[x]){
        sum = max(dfs(x+1,spV),dfs(x+1,spV-v[x])+w[x]);//状态转移方程
    }
    mem[x][spV]=sum;
    return sum;

}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
//    int res=dfs(1,m);
//    cout<<res<<endl;
    for(int i=n;i>=1;i--)
    {
        for (int j = 1; j <=m; j++)
        {
            if(j<v[i])
                f[i][j]=f[i+1][j];
            else if(j>=v[i])
                f[i][j]=max(f[i+1][j],f[i+1][j-v[i]]+w[i]);
        }
    }
    cout<<f[1][m]<<endl;
    return 0;
}