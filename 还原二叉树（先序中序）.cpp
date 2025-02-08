//题目链接：https://pintia.cn/problem-sets/1879338689378000896/exam/problems/type/7?problemSetProblemId=1888022163837038592&page=0
#include <bits/stdc++.h>
using namespace std;
const int N=55;
struct node{
    char data;
    shared_ptr<node> lch,rch;
};
using bitree=shared_ptr<node>;
bitree creat(char pre[],char in[],int len)
{
    if(len==0) return nullptr;
    bitree t=make_shared<node>();
    t->data=pre[0];
    int i;
    for(i=0;i<len;i++)
    {
        if(in[i]==pre[0]) break;
    }

    t->lch=creat(pre+1,in,i);//先序
    t->rch=creat(pre+1+i,in+1+i,len-i-1);//中序
    return t;
}
int depth(bitree t)
{
    if(t==nullptr) return 0;

    int dl=depth(t->lch);
    int dr=depth(t->rch);

    return max(dl,dr)+1;
}
int main()
{
    int n;cin>>n;
    char pre[N],in[N];
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    bitree t=creat(pre,in,n);

    cout<<depth(t)<<endl;

    return 0;
}