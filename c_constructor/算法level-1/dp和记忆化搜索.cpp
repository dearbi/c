#include <bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int dp[N];
int f(int x)
{
    if(x==1||x==2) return x;
    if(dp[x]!=-1) return f(x);
    return dp[x]=f(x-1)+f(x-2);
}
int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++) dp[i]=-1;
    cout<<f(n)<<endl;
    return 0;
}