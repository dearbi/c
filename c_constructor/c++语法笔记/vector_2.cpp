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
	
	cout << a[0] << ' ' << *a.begin() << endl;
	cout << a[1] << ' ' << *(a.begin() + 1) << endl;
	cout << a[2] << ' ' << *(a.begin() + 2) << endl;

	// 遍历方式一：
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << endl;

	// 遍历方式二：
	// for (auto i = a.begin(); i != a.end(); i++)// 简写
	for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
		cout << *i << ' ';
	cout << endl;
	
	// 遍历方式三：
	for (int x : a)
		cout << x << ' ';
	cout << endl;

	return 0;
}
