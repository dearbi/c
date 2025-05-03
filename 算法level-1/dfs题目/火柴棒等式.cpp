//https://www.luogu.com.cn/problem/P1149
#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int n;
int arr[N];
int res=0;
void dfs(int x)
{
    if(x>3)
    {
        if(arr[1]+arr[2]==arr[3])
    }
    for(int i=0;i<=10000;i++)
    {
        arr[x]=i;
        dfs(x+1);
        arr[x]=0;

    }
}

int main()
{
    cin>>n;
    dfs(1);
    return 0;
}


