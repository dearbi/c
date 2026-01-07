//https://www.acwing.com/problem/content/846/
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m;
int g[N][N];
int dist[N][N];
typedef pair<int, int> PII;

PII node = {1, 1};
queue<PII> q;
int dx[] = {-1, 0, 1, 0};//上右下左
int dy[] = {0, 1, 0, -1};

int bfs(int x1, int y1) {
    memset(dist, -1, sizeof(dist)); // 初始化距离数组为-1
    q.push({x1, y1});
    dist[x1][y1] = 0;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int a = t.first + dx[i];
            int b = t.second + dy[i];

            if (a < 1 || a > n || b < 1 || b > m) continue; // 边界检查
            if (g[a][b] != 0) continue; // 障碍物检查
            if (dist[a][b] != -1) continue; // 已访问检查

            q.push({a, b});
            dist[a][b] = dist[t.first][t.second] + 1; // 更新距离
            if (a == n && b == m)
                return dist[n][m]; // 找到终点，返回距离
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    int res = bfs(1, 1);
    cout <<res<< endl;
    return 0;
}