#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int mem[N][N];
int a[N][N];
int f[N][N];
int n;
int dfs(int x1,int y1)
{
    if(mem[x1][y1]) return mem[x1][y1];
    int sum=0;
    if(x1>n||y1>n)
        return 0;
    else
        sum=max(dfs(x1+1,y1),dfs(x1+1,y1+1))+a[x1][y1];
    mem[x1][y1]=sum;
    return sum;
}
//dfs怎么改到递推的形式
//所有的返回值都需要体现
//原来dfs的sum和dfs本身都需要成数组的形式

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    }
    int res=dfs(1,1);
    cout<<res<<endl;

    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
        }
    }
    cout<<f[1][1]<<endl;

    return 0;
}