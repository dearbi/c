//https://www.acwing.com/problem/content/3/
#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
int v[N],w[N];
int mem[N][N];
int f[N][N];
int dfs(int x,int spV)
{
    if(mem[x][spV]) return mem[x][spV];
    int sum=0;
    if(x>n)
        return 0;
    else if(spV<v[x])
        sum=dfs(x+1,spV);
    else if(spV>=v[x]){
        sum = max(dfs(x+1,spV),dfs(x,spV-v[x])+w[x]);//状态转移方程
    }
    mem[x][spV]=sum;
    return sum;

}
//完全背包问题：每次选择物品的时候，可以选择多次，而01背包问题每次选择只能选择一次
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    int res=dfs(1,m);
    cout<<res<<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j < v[i]) {
                f[i][j] = f[i-1][j];  // 不能选当前物品
            } else {
                f[i][j] = max(f[i-1][j], f[i][j-v[i]] + w[i]);  // 可以选多次
            }
        }
    }

    cout<<f[n][m]<<endl;
    return 0;
}