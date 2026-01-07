//题目链接：https://www.starrycoding.com/problem/63
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9;
int n;

struct s{
    int x,y;
}a[N],m[N];

int k[N*3];
vector<int> b;

int getindex(int x)
{
    return lower_bound(b.begin(),b.end(),x)-b.begin()+1;
}

void slove()
{

    int q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int w,e;cin>>w>>e;
        a[i]={w,e};
        b.push_back(w);
    }

    for(int i=1;i<=q;i++)
    {
        int l,r;cin>>l>>r;
        m[i]={l,r};
        b.push_back(l);
        b.push_back(r);
    }

    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());

    for(int i=1;i<=n;i++)
    {
        int w=getindex(a[i].x);
        int e=a[i].y;
        k[w]+=e;
    }
    for(int i=1;i<=b.size();i++)
    {
        k[i]+=k[i-1];
    }

    for(int i=1;i<=q;i++)
    {
        int l= getindex(m[i].x);
        int r= getindex(m[i].y);
        cout<<k[r]-k[l-1]<<endl;
    }
}

signed main()
{
    slove();
    return 0;
}