#include <iostream>
#include <vector>

using namespace std;

struct Rec
{
	int x, y;
};

int main()
{
	vector<int> a;// 相当于定义了一个长度动态变化的int数组
	vector<int> b[233];// 相当于定义了一个一维长度为233，二维长度动态变化的int二维数组
	vector<Rec> c;
	
	// 所有的STL容器都有这两个函数：size()、empty()
	a.size();
	a.empty();

	a.clear();// 表示把当前数组的元素全部清空
    // 除了普通队列、优先队列、栈、bitset之外，所有的STL容器都有clear()函数

	// 迭代器
	vector<int>::iterator it = a.begin();// 这里的it相当于访问a[0]，it可以看做是指针
	*it;// 这里的*it相当于取a[0]的值，等价于*a.begin()
	a.begin();// a.begin()返回值是第一个元素的地址
	a.end();// a.end()返回值是最后一个元素的下一个位置的地址

	return 0;
}
