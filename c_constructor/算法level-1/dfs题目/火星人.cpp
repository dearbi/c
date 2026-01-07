//https://www.luogu.com.cn/problem/P1088
//#include <bits/stdc++.h>
//using namespace std;
//const int N=10010;
//int n,m;
//int arr[N];//记录方案
//int mars[N];//记录火星人的初始排列
//bool st[N];//每个数选没选过
//int res=0;
//bool return0;
//void dfs(int x)
//{
//    if(return0) return ;
//    if(x>n){
//        res++;
//        if(res==m+1)
//        {
//            return0=true;
//            for(int i=1;i<=m;i++)
//            {
//                cout<<arr[i]<<" ";
//            }
//        }
//        return ;
//    }
//    for(int i=1;i<=n;i++)
//    {
//        if(!res)
//        {
//            i=mars[x];
//        }
//        if(!st[i]){
//            st[i]=true;
//            arr[x]=i;
//            dfs(x+1);
//            arr[x]=0;
//            st[i]=false;
//        }
//    }
//}
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>mars[i];
//    }
//    dfs(1);
//    return 0;
//}


#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int n, m;
int mars[N];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> mars[i];

    // 直接使用STL的排列函数
    while(m--) next_permutation(mars, mars + n);

    for(int i = 0; i < n; i++) cout << mars[i] << " ";
    return 0;
}
