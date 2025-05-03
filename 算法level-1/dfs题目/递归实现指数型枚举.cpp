//https://www.acwing.com/problem/content/94/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int st[N];//记录每个数的状态，0表示还没考虑，1表示选这个数，2表示不选这个数
int n;
void dfs(int x)//x表示当前枚举到了哪个位置
{

    if(x>n)
    {
        for(int i=1;i<=n;i++)
        {
            if(st[i]==1)
            {
                cout<<i<<" ";
            }

        }
        cout<<"\n";
        return ;
    }

    //选
    st[x]=1;
    dfs(x+1);
    st[x]=0;//恢复现场

    //不选
    st[x]=2;
    dfs(x+1);
    st[x]=0;//恢复现场


}
int main()
{
    cin>>n;
    dfs(1);
    return 0;
}