#include <bits/stdc++.h>
using namespace std;
const int N=55;
struct node{
    int data;
    shared_ptr<node> lch,rch;
};
using bitree=shared_ptr<node>;
bitree creat(int post[],int in[],int len)
{
    if(len==0) return nullptr;
    bitree t=make_shared<node>();
    t->data=post[len-1];
    int i;
    for(i=0;i<len;i++)
    {
        if(in[i]==post[len-1]) break;
    }

    t->lch=creat(post,in,i);
    t->rch=creat(post+i,in+1+i,len-i-1);
    return t;
}
void pre(bitree t)
{
    if(t==nullptr) return ;
    cout<<" "<<t->data;
    pre(t->lch);
    pre(t->rch);
}
int main()
{
    int n;cin>>n;
    int post[N],in[N];
    for(int i=0;i<n;i++)
    {
        cin>>post[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    bitree t=creat(post,in,n);
    cout<<"Preorder:";
    pre(t);

    return 0;
}