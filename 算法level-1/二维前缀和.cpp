#include <bits/stdc++.h>
using namespace std;
const int MAX_M = 1000;
const int MAX_N = 1000;
int sum[MAX_M + 1][MAX_N + 1];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin>>sum[i][j];
                sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }

        int res = 0;
        for (int i = 1; i <= m-x+1; i++) {
            for (int j = 1; j <= n-y+1; j++) {
                int x2 = i + x - 1;
                int y2 = j + y - 1; 
                int temp = sum[x2][y2] - sum[i - 1][y2] - sum[x2][j - 1] + sum[i - 1][j - 1];
                res = max(res, temp);
            }
        }
        cout << res << endl;
    }
    return 0;
}

