#include <bits/stdc++.h>

using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	vector<int> num;
	
	int temp;
	while(cin >> temp)
	{
		num.push_back(temp);			
	}

	cout<<num.size()<<endl;
	num.erase(unique(num.begin(), num.end()),num.end());
	for (auto x:num)
	{
		cout << x << " ";
	}
	printf("\n");
	sort(num.begin(), num.end(),cmp);

	for (auto x : num)
	{
		cout << x << " ";
	}

	return 0;
}