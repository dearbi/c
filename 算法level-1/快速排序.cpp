#include<bits/stdc++.h>
using namespace std;
const int N=200020;
int a[N];

void quicksort(int a[],int l,int r)
{
    if(l>=r)
        return ;
    int i=l;
    int j=r;
    int m=a[i];
    while(i<j)
    {
        while(i<j&&a[j]>=m)
            j--;
        a[i]=a[j];
        while(i<j&&a[i]<=m)
            i++;
        a[j]=a[i];
    }
    a[i]=m;
    quicksort(a,l,i-1);
    quicksort(a,j+1,r);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}