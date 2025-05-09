//https://leetcode.cn/problems/min-cost-climbing-stairs/
#include <bits/stdc++.h>
using namespace std;
const int N=1010;
vector<int> a;
int mem[N];
int dfs(int x)
{
    if(x>a.size()) return 0;
    int sum=0;
    if(mem[x]!=-1) return mem[x];
    else
        sum=min(dfs(x+1),dfs(x+2))+a[x];
    mem[x]=sum;
    return sum;
}
int main()
{
    memset(mem,-1,sizeof(mem));
    int x;
    while(cin>>x)
    {
        a.push_back(x);
    }
    int res=min(dfs(0),dfs(1));
    cout<<res<<endl;
    return 0;
}