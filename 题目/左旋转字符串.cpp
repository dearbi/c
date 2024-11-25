#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int n;
	cin>>n;
	cout<<s.substr(n)+s.substr(0,n)<<endl;

	return 0;
}

