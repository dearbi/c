#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n=0;
	cin>>n;
	vector<int> a(n);
	for(int k=0;k<n;k++)
	{
		cin>>a[k];
	}
	int i=0,j=a.size()-1;
	while(i<j)
	{
		while(i<j&&a[i]%2!=0)
			i++;
		while(i<j&&a[j]%2==0)
			j--;
		if(i<j)
		{
			swap(a[i],a[j]);
		}
	}
	for(auto x:a)
	{
		cout<<x<<" ";
	}

	return 0;
}