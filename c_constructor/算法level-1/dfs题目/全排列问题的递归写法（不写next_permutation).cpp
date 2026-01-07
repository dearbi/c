//https://www.acwing.com/problem/content/94/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
bool st[N];//true表示选过，false表示还没选，刚开始默认是false
int arr[N];//存的是答案
int n;
void dfs(int x)//x表示当前枚举到了哪个位置
{
    if(x>n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            st[i]=true;
            arr[x]=i;
            dfs(x+1);
            //恢复现场
            st[i]= false;
            arr[x]=0;//其实这里不需要，因为下一次会直接覆盖
        }
    }
}
int main()
{
    cin>>n;
    dfs(1);
    return 0;
}