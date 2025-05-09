//https://leetcode.cn/problems/house-robber/description/?envId=2cktkvj&envId=2cktkvj
#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int n,T;
int home[N];
int mem[N];
int f[N];
int dfs(int x)
{
    if(mem[x]) return mem[x];
    int sum=0;
    if(x>n) return sum=0;
    else
        sum=max(dfs(x+1),dfs(x+2)+home[x]);
    mem[x]=sum;
    return sum;
}
//mem[i]存的是：从第i个店铺开始（i~n）能获取的最大价值
int main()
{
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>home[i];
        }
//        memset(mem,0, sizeof(mem));
//        int res=dfs(1);
//        cout<<res<<endl;
        memset(f,0,sizeof(f));
        for(int i=n;i>=1;i--)
        {
            f[i]=max(f[i+1],f[i+2]+home[i]);//递推的公式就是递归向下的公式
        }
        cout<<f[1]<<endl;
    return 0;
}


