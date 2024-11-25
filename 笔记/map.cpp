#include <bits/stdc++.h>

using namespace std;

int main()
{
	// multimap基本不会用到
	// multimap<string, int> temp;
	
	// map是常用的
	map<string, int> a;

	a["yxc"] = 2;
	a["cgw"] = 99;

	cout << a["cgw"] << endl;

	map<string, vector<int> > b;

	b.insert({ "hhh", {1} });// 插入一个map元素
	b["yxc"] = vector<int>({ 1, 2, 3, 4 });
	b["jjj"] = { 1, 2, 3 };
	b["kkk"] = { 4, 5, 6 };	

	cout << b["kkk"].size() << endl;
	cout << b["hhh"][0] << endl;//1
	cout << b["kkk"][0] << endl;// 4
	cout << b["kkk"][1] << endl;// 5
	cout << b["kkk"][2] << endl;// 6

	cout << (b.find("cgw") == b.end()) << endl;

	return 0;
}
