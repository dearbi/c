#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;cin>>m;
    int max=0;
    vector<int> a;
    while(m--)
    {
        int p,n;
        cin>>p>>n;
        if(p>max+1) p=max+1;
        a.insert(a.begin()+p,n);
        max=p;
    }
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i];
        if(i!=a.size()-1) cout<<" ";
    }


    return 0;
}