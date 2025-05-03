//https://www.acwing.com/problem/content/8/
#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,V,M;
int v[N],w[N],m[N];
int mem[N][110][110];
int f[N][110][110];
//x表示第几个物品，spV表示当前背包剩余容量，spM表示当前背包剩余重量
int dfs(int x,int spV,int spM)
{
    if (x>n)
        return 0;

    int sum=0;
    if(mem[x][spV][spM])
        return mem[x][spV][spM];

    if(spV<v[x]||spM<m[x])
        sum=dfs(x+1,spV,spM);

    else if(spV>=v[x]&&spM>=m[x])
        sum=max(dfs(x+1,spV,spM),dfs(x+1,spV-v[x],spM-m[x])+w[x]);//状态转移方程
    mem[x][spV][spM]=sum;
    return sum;
}
int main()
{
    cin>>n>>V>>M;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>m[i]>>w[i];
    }
//    int res=dfs(1,V,M);
//    cout<<res<<endl;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=V;j++)
        {
            for(int k=1;k<=M;k++)
            {
                if(j<v[i]||k<m[i])
                    f[i][j][k]=f[i+1][j][k];
                else if(j>=v[i]&&k>=m[i])
                    f[i][j][k]=max(f[i+1][j][k],f[i+1][j-v[i]][k-m[i]]+w[i]);
            }
        }
    }
    cout<<f[1][V][M]<<endl;
    return 0;
}