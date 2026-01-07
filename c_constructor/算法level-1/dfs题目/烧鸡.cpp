#include <bits/stdc++.h>
using namespace std;

const int N =8005;
int n;
int arr[N]; // 存临时方案
int res = 0; // 存方案数
int mem[N][N];

void dfs(int x, int sum) {
    if (sum > n) return; // 如果当前和超过n，返回
    if (x > 10) { // 如果已经选择了10个数字
        if (sum == n) { // 如果当前和等于n，输出当前组合
            res++;
            for (int i = 1; i <= 10; i++) {
                mem[res][i]=arr[i];
            }
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        arr[x] = i;
        dfs(x + 1, sum + i); // 正确地累加当前选择的数字
    }
}

int main() {
    cin >> n;
    dfs(1, 0); // 初始和为0
    cout << res << endl; // 输出方案总数

    for(int i=1;i<=res;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cout<<mem[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}



