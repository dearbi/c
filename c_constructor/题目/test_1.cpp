#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
        {
            break;
        }
        vector<int> a(n);
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int i;
        for (i = 0; i < n; i++) {
            if (a[i] < m) {
                break;
            }
        }
        a.insert(a.begin() + i, m);
        for (int j = 0; j < a.size(); j++) {
            cout << a[j];
            if (j < a.size())
                cout << " ";
        }
    }
    return 0;
}