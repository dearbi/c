#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int mem[N];
//1.dfs 2.记忆化搜索 3.递推循环
int dfs(int n)
{
    //记忆化搜索
    if(mem[n]) return mem[n];
    int sum=0;
    if(n==1) return 1;
    if(n==2) return 2;
    else
        sum=dfs(n-1)+dfs(n-2);
    mem[n]=sum;
    return sum;
}
int main()
{
    int n;cin>>n;
    int res=dfs(n);
    cout<<res<<endl;
    //改递推：dfs改递推需要保留/什么地方？
    //1、所有有返回值的地方要写
    //2、sum和dfs都换成数组
    //循环从头还是末尾开始遍历？
    //  看画的递归搜索树是从哪开始的

    for(int i=1;i<=n;i++)
    {
        if(i==1) mem[i]=1;
        else if(i==2) mem[i]=2;
        else mem[i]=mem[i-1]+mem[i-2];
    }
    return 0;
}