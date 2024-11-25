#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m; // 输入总人数和步长
	int num[100];
	queue<int>q; // 使用队列来模拟游戏

	for (int i = 1; i <= n; i++)
	{
		q.push(i); // 将每个人入队
	}
	int cnt = 0;
	while (!q.empty())
	{
		cnt++;
		if (cnt == m)
		{
			cnt = 0;
			cout << q.front() << " "; // 输出当前被淘汰的人
			q.pop(); // 淘汰该人
		}
		else
		{
			q.push(q.front());
			q.pop(); // 将未被淘汰的人移到队列末尾
		}
	}

	return 0;
}
