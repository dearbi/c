//快速排序
void qucksort(int a[],int l,int r)
{
    if(l>=r) return ;

    int i=l,j=r;
    int m=a[i];
    while(i<j)
    {
        while(i<j&&a[j]>=m) j--;
        a[i]=a[j];
        while(i<j&&a[i]<=m) i++;
        a[j]=a[i];
    }
    a[i]=m;
    qucksort(a,l,i-1);
    qucksort(a,j+1,r);
}
//二分查找
int mid_search(int a[],int l,int r,int x)
{
    l=0;
    while(l+1!=r)
    {
        int mid=(l+r)>>1;
        if(a[mid]<x)
            l=mid;
        else
            r=mid;
    }
    if(a[r]==x) return r;
    else return -1;
}
//归并排序
void merge_sort(int num[],int l,int r)
{
    if(l>=r) return ;
    int temp[100];
    int mid=(l+r)>>1;
    merge_sort(num,l,mid);
    merge_sort(num,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(num[i]<num[j])
            temp[k++]=temp[i++];
        else
            temp[k++]=temp[j++];
    }
    while(i<=mid) temp[k++]=temp[i++];
    while(j<=mid) temp[k++]=temp[j++];

    for(int i=l,j=0;i<=r;i++,j++)
    {
        num[i]=temp[j];
    }
}

