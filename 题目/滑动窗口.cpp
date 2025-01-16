#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N];


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;cin >> n >> k;
    for(int i = 1;i <= n; ++ i)cin >> a[i];
    deque<int> dq;
    for(int i = 1;i <= n; ++ i){
        //维护队列下标合法性
        while(dq.size() && dq.front() < i - k + 1)dq.pop_front();
        //维护最大值，队列右侧维护区间不增或递减
        //注意一定要判断队列非空，否则会RE
        while(dq.size() && a[dq.back()] < a[i])dq.pop_back();
        dq.push_back(i);
        if(i >= k)cout << a[dq.front()] << ' ';
    }
    cout << '\n';
    dq.clear();
    for(int i = 1;i <= n; ++ i){
        //维护队列下标合法性
        while(dq.size() && dq.front() < i - k + 1)dq.pop_front();
        //维护最大值，队列右侧维护区间不减或递增
        while(dq.size() && a[dq.back()] > a[i])dq.pop_back();
        dq.push_back(i);
        if(i >= k)cout << a[dq.front()] << ' ';
    }
    cout << '\n';
    return 0;
}