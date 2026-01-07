//https://www.acwing.com/problem/content/823/
#include <bits/stdc++.h>
using namespace std;
const int N=20;
int n;
int mem[N];
int f[N];
//递归/dfs->记忆化搜索->递推（改循环）
int dfs(int x)
{
    if(mem[x]) return mem[x];
    int sum=0;
    if(x==1) return sum=1;
    else if(x==2) return sum=2;
    else sum=dfs(x-1)+dfs(x-2);//这个就是状态转移方程
    mem[x]=sum;
    return sum;
}
//改递推：dfs改递推需要保留/什么地方？
//1、所有有返回值的地方要写
//2、sum和dfs都换成数组

//循环从头还是末尾开始遍历？
//  看画的递归搜索树是从哪开始的，在树的头结点为输出值，
//  从头开始遍历就是从头结点开始，从末尾开始遍历就是从末尾开始。
int main()
{
    cin>>n;
//    cout<<dfs(n)<<endl;//递归dfs
    f[1]=1;
    f[2]=2;
    if(n==1||n==2)
    {
        cout<<f[n]<<endl;
        return 0;
    }
    for(int i=3;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];//这个递推的公式也就是dfs的向下递归的公式
    }
    cout<<f[n]<<endl;

    return 0;
}