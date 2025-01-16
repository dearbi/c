#include <bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+9;
int a[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    stack<int> stc;
    int pos=1,flag=1;
    for(int i=1;i<=n;i++)
    {
        while(pos<=n&&(stc.empty()||stc.top()!=i))
        {
            stc.push(a[pos++]);
        }

        if(stc.top()==i)
        {
            stc.pop();
        }
        else
        {
            flag=0;
            cout<<"NO"<<'\n';
            break;
        }
    }

    if(flag)
    {
        cout<<"Yes"<<'\n';
    }


    return 0;
}