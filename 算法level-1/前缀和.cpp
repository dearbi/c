#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[100],s[100]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }

    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1];
    }

    return 0;
}