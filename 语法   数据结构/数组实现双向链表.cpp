#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (m--) {
        int x;
        cin >> x;
        auto it = find(a.begin(), a.end(), x);
        if (it == a.end()) {
            continue; // 未找到元素，跳过处理
        }
        int index = it - a.begin(); // 直接计算索引
        bool has_prev = index > 0;
        bool has_next = index < n - 1;
        if (has_prev && has_next) {
            cout << a[index - 1] << " " << a[index + 1] << endl;
            cout<<index<<endl;
        } else if (has_prev) {
            cout << a[index - 1] << endl;
            cout<<index<<endl;
        } else if (has_next) {
            cout << a[index + 1] << endl;
            cout<<index<<endl;
        }
        // 前后均无元素时（如n=1）不输出
    }
    return 0;
}