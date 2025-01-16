#include <iostream>
#include <vector>

using namespace std;

struct Rec
{
	int x, y;
};

int main()
{
	vector<int> a({ 1, 2, 3 });
	
	// a.front()等价于a[0]、*a.begin();
	cout << a.front() << ' ' << a[0] << ' ' << *a.begin() << endl;
	// a.back()返回最后一个元素的值
	cout << a.back() << ' ' << a[a.size() - 1] << endl;

	// a.push_back(4)在a的最后一个位置添加一个元素，元素值为4
	a.push_back(4);
	for (int x : a)
		cout << x << ' ';
	cout << endl;

	// a.pop_back()删除a的最后一个元素
	a.pop_back();
	for (int x : a)
		cout << x << ' ';
	cout << endl;

	return 0;
}
