//https://www.luogu.com.cn/problem/P1216
#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N][N];
int n;
int mem[N][N];
int f[N][N];
int dfs(int x1,int y1)
{
    if(mem[x1][y1])
        return mem[x1][y1];
    int sum=0;
    if(x1>n||y1>n)
        return 0;
    else
        //求子问题：dfs(x)=dfs(x+1)+dfs(x+2)
        //求最优子问题：dfs(x)=max(dfs(x+1),dfs(x+2))+a[x][y]
        sum= max(dfs(x1+1,y1),dfs(x1+1,y1+1))+a[x1][y1];
    mem[x1][y1]=sum;
    return sum;
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for (int j = 1; j <=i ; j++) {
            cin>>a[i][j];
        }
    }

//    for (int i = n; i >=1 ; i--) {
//        for (int j = 1; j <=i ; j++) {
//            f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
//        }
//    }


    return 0;
}