#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n;
    cin>>n;
    double l=0,r=n;
    for(int i=0;i<100;i++)
    {
        double mid=(l+r)/2;
        if(mid*mid>=n)
            r=mid;
        else
            l=mid;
    }
    printf("%lf",l);

    return 0;
}