#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> nums;
	int temp;
    int n;
    cin>>n;

	for(int i=0;i<n;i++)
	{
        cin>>temp;
		nums.push_back(temp);
	}
	unordered_set<int> a;
	for(int i=0;i<nums.size();i++)
	{
		a.insert(i);
	}
	for(int x:nums)
	{
		a.erase(x);
	}

	cout<<*a.begin()<<endl;
	return 0;
}