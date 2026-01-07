//https://www.luogu.com.cn/problem/P1157
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,r;
int arr[N];
void dfs(int x,int start)
{
    if(x>r){
        for(int i=1;i<=r;i++)
        {
            printf("%3d",arr[i]);
        }
        cout<<"\n";
        return ;
    }

    for(int i=start;i<=n;i++)
    {
        arr[x]=i;
        dfs(x+1,i+1);
        arr[x]=0;
    }
}
int main()
{
    cin>>n>>r;
    dfs(1,1);
    return 0;
}