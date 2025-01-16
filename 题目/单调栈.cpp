
//数组写法
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,top=0;
    cin>>n;
    int a[n];
    int l[n];
    int stk[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        while(top&&a[stk[top]]>=a[i]) top--;
        if(top) l[i]=a[stk[top]];
        else l[i]=-1;
        stk[top++]=i;

    }

    for(int i=1;i<=n;i++)
    {
        cout<<l[i]<<" ";
    }

    return 0;
}
//栈写法
//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int n;
//    cin>>n;
//    int a[n];
//    int l[n];
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a[i];
//    }
//    stack<int> stk;
//
//    for(int i=1;i<=n;i++)
//    {
//
//
//        while(stk.size()&&stk.top()>=a[i])
//            stk.pop();
//        if(stk.empty())
//            l[i]=-1;
//        else
//            l[i]=stk.top();
//
//        stk.push(a[i]);
//
//    }
//
//    for(int i=1;i<=n;i++)
//    {
//        cout<<l[i]<<" ";
//    }
//
//    return 0;
//}