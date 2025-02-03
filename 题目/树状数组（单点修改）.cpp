#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 9;
int n, q;
int a[N], bit[N];  // bit 是树状数组

// 计算二进制索引树的最低有效位
int lowbit(int x) {
    return x & -x;
}

// 更新函数：给第 w 个元素加上 k
void update(int w, int k) {
    for (int i = w; i <= n; i += lowbit(i)) {
        bit[i] += k;  // 更新树状数组
    }
}

// 获取前缀和：查询从 1 到 x 的前缀和
int getsum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += bit[i];  // 累加区间和
    }
    return sum;
}

signed main() {
    cin >> n >> q;

    // 输入数组 a 和初始化 BIT
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);  // 初始化时更新 BIT
    }

    // 处理查询
    while (q--) {
        int m;
        cin >> m;
        if (m == 1) {  // 更新操作
            int k, v;
            cin >> k >> v;
            update(k, v);  // 给第 k 个元素加上 v
        } else if (m == 2) {  // 查询操作
            int l, r;
            cin >> l >> r;
            // 查询区间 [l, r] 的和
            cout << getsum(r) - getsum(l - 1) << endl;
        }
    }

    return 0;
}