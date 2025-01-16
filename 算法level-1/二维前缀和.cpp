#include <bits/stdc++.h>
using namespace std;
const int MAX_M = 1000;
const int MAX_N = 1000;
int a[MAX_M + 1][MAX_N + 1];
int sum[MAX_M + 1][MAX_N + 1];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
            }
        }

        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        int res = 0;
        for (int i = 1; i + x - 1 <= m; i++) {
            for (int j = 1; j + y - 1 <= n; j++) {
                int l = i + x - 1;
                int r = j + y - 1;
                int temp = sum[l][r] - sum[i - 1][r] - sum[l][j - 1] + sum[i - 1][j - 1];
                res = max(res, temp);
            }
        }
        cout << res << endl;
    }

    return 0;
}
