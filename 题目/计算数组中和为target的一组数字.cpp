/*输入一个数组和一个数字 s
，在数组中查找两个数，使得它们的和正好是 s
。

如果有多对数字的和等于 s
，输出任意一对即可。

你可以认为每组输入中都至少含有一组满足条件的输出。

数据范围
        数组长度 [1,1002]
。

样例
        输入：[1,2,3,4] , sum=7

输出：[3,4]*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	int temp;
	int target;
	cin>>target;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	unordered_set<int> s;
	for(auto x:a)
	{
		if(s.count(target-x))
        {
            cout << x << "," << target - x << endl;
        }
		s.insert(x);
	}
	
	return 0;
}