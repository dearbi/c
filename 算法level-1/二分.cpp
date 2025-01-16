#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n,k;cin>>n>>k;
    int a[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int x;
    while(k--)
    {
        int l=0,r=n;
        cin>>x;
        while(l+1!=r)
        {
            int mid=(l+r)>>1;
            if(a[mid]<x)
                l=mid;
            else r=mid;
        }
        if(a[r]==x)
            cout<<r<<" ";
        else cout<<"-1 ";

    }

    return 0;
}