#include <bits/stdc++.h>
using namespace std;

struct num {
    int a;
    int b;
    bool operator < (const num& u) const {
        return a < u.a;
    }
}s[1000];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i].a;
        s[i].b = i;
    }

    sort(s+1, s + n+1);
    double sum=0.0;
    int t[1000]={0};
    for(int i=2;i<=n;i++)
    {
        t[i]=t[i-1]+s[i-1].a;
        sum+=t[i];
    }
    double avr=sum/(double)n;
    for (int i = 1; i <= n; i++) {
        cout << s[i].b;
        if (i != n)
            cout << " ";
    }
    cout<<"\n";
    printf("%.2lf",avr);
    return 0;
}