//https://www.luogu.com.cn/problem/P103
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,k;
int q[N];//存数据
int arr[N];//存答案
int res=0;//存种类数
bool is_prime(int sum)
{
    if(sum<2) return false;
    for(int i=2;i*i<=sum;i++)
    {
        if(sum%i==0) return  false;
    }
    return true;
}
void dfs(int x,int start)
{
    if((x-1)+n-start+1<k){
        return;
    }
    if(x>k)
    {
        int sum=0;
        for(int i=1;i<=k;i++)
        {
            sum+=arr[i];
        }
        if(is_prime(sum))//如果是素数，种类+1
        {
            res++;
        }
        return ;
    }
    for(int i=start;i<=n;i++)
    {
        arr[x]=q[i];
        dfs(x+1,i+1);//继续向下
        arr[x]=0;//恢复现场
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>q[i];
    }
    dfs(1,1);
    cout<<res<<endl;
    return 0;
}