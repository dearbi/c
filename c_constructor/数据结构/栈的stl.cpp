#include <bits/stdc++.h>

using namespace std;

int main() {
	// 2. 直接创建一个存储 int 的栈对象，不需要自己定义 struct
	stack<int> s; 
	
	// 3. 直接使用 "." 调用内置功能
	s.push(1); // 入栈
	s.push(2);
	s.push(3);
	
	cout << "栈的大小: " << s.size() << endl;
	
	// 4. 循环出栈
	while (!s.empty()) { // 使用 .empty() 判断
		// 注意：C++ STL 分两步：top() 获取值，pop() 弹出
		cout << "当前栈顶: " << s.top() << endl; 
		s.pop(); 
	}
	
	return 0;
}
