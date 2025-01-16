#include <bits/stdc++.h>
using namespace std;

void merge_sort(int num[],int l,int r)
{
    if(l>=r)
        return;
    int temp[100];
    int mid=(l+r)>>1;
    merge_sort(num,l,mid);
    merge_sort(num,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(num[i]<num[j])
            temp[k++]=num[i++];
        else
            temp[k++]=num[j++];
    }
    while(i<=mid)
        temp[k++]=num[i++];
    while(j<=r)
        temp[k++]=num[j++];

    for(int i=l,j=0;i<=r;i++,j++)
    {
        num[i]=temp[j];
    }
}
int main()
{
    int n;
    cin>>n;
    int num[100];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    merge_sort(num,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }

    return 0;
}