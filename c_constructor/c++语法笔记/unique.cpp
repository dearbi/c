#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	// unique是去重函数，用这个函数时，一定要保证相同的数是紧挨在一起的
	
	// int a[] = { 1, 1, 2, 2, 3, 3, 4 };
	/*
		unique(x, y)
		第一个参数为开始位置，第二个参数为最后一个数的位置的下一个位置
		函数的返回值是去重后的最后一个数的位置的下一个位置
	*/
	// int m = unique(a, a + 7) - a;
	// cout << m << endl;// m的值为去重后的数组a中不重复的数的个数
	
	// vector<int> a({ 1, 1, 2, 2, 3, 3, 4 });
	// int m = unique(a.begin(), a.end()) - a.begin();
	// cout << m << endl;

	/*
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';// 1 2 3 4
	*/

	vector<int> a({ 1, 1, 2, 2, 3, 3, 4 });
	// 把 去重后的数组a的最后一个元素的下一个位置 到 去重前的数组a的最后一个元素的下一个位置 的 指针所指向的位置的元素全部删除。
	// erase函数的参数也是符合左闭右开的特性
	a.erase(unique(a.begin(), a.end()), a.end());
	for (int x : a)
		cout << x << ' ';// 1 2 3 4

	return 0;
}
