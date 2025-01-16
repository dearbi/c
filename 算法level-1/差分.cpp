#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int d[1000];
    for(int i=1;i<=n;i++)
    {
        d[i]=a[i]-a[i-1];
    }
    while(m--)
    {
        int l,r,c;
        cin>>l>>r>>c;
            d[l]+=c;
            d[r+1]-=c;
    }

    for(int i=1;i<=n;i++)
    {
        a[i]=d[i]+a[i-1];
    }

    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
        if(i!=n)
            cout<<" ";
    }

    return 0;
}