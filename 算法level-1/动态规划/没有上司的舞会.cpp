//https://www.luogu.com.cn/problem/P1352
#include <bits/stdc++.h>
using namespace std;

const int N = 6010;
vector<int> adj[N]; // 邻接表存储树结构
int r[N]; // 存储每个职员的快乐指数
int mem[N][2]; // mem[u][0]不选u，mem[u][1]选u
int indegree[N]; // 入度数组找根节点

// 记忆化搜索函数
int dfs(int u, int choose) {
    if (mem[u][choose] != -1) return mem[u][choose]; // 已计算过，直接返回
    if (choose == 1) { // 选u
        mem[u][1] = r[u];
        for (int v : adj[u]) {
            mem[u][1] += dfs(v, 0); // 选u则子节点不能选
        }
    } else { // 不选u
        mem[u][0] = 0;
        for (int v : adj[u]) {
            mem[u][0] += max(dfs(v, 0), dfs(v, 1)); // 不选u则子节点选或不选的最大值
        }
    }
    return mem[u][choose];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for (int i = 1; i < n; i++) {
        int l, k;
        cin >> l >> k;
        adj[k].push_back(l); // k是l的上司，l是k的子节点
        indegree[l]++; // l的入度加1
    }
    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) { // 找根节点
            root = i;
            break;
        }
    }
    memset(mem, -1, sizeof(mem)); // 初始化mem为-1，表示未计算
    // 计算选根节点和不选根节点的情况
    int res1 = dfs(root, 1);
    int res2 = dfs(root, 0);
    cout << max(res1, res2) << endl;
    return 0;
}