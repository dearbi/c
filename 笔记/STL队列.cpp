#include <bits/stdc++.h>
using namespace std;
int main()
{
	queue<int> q;//队列
	priority_queue<int> a;//优先队列——大根堆（优先输出最大的）
	priority_queue<int,vector<int>,greater<int>> b;//优先队列——小根堆（优先输出最小的）
	
	struct rec {
	    int a, b;
	    // 使用优先队列需要重载（大根堆小于号，小根堆大于号）
	    bool operator >(const rec& t) const {
	        return a > t.a;
	    }
	};
	
	priority_queue<rec, vector<rec>, greater<>> d;
	
	d.push({1, 2});
	
	queue<int> q;// 队列
	
	q.push(2)//在对尾插入一个元素
	q.pop();//取最大值
	q.front();//返回对头
	cout<<q.back()<<endl;
	
	q.queue//队列清空的方式（所有的队列没有clear函数）
	
	priority_queue<int> a;
	
	a.push(2);//插入一个数（不知道位置）
	a.top();//取最大值
	a.pop();//删除最大值
	
	
	//双端队列
	deque<int> a;
	
	
	set<int> s;
	struct rec{…}; set<rec> s;  // 结构体rec中必须定义小于号
	multiset<double> s;

	return 0;
}