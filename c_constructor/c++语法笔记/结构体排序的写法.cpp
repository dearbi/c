#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    return a.size()<b.size();
}
int main()
{
    vector<string> a;
    int i=0;
    string temp;
    while(cin>>temp)
    {
        a.push_back(string(temp));
        if(a[i]=="#")
        {
            a.pop_back();
            break;
        }
        i++;
    }
    sort(a.begin(),a.end(),cmp);

    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}