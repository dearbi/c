#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		int max=0;
		for(int i=1;i<a.size();i++)
		{
			if(a[i]>a[max])
			{
				max=i;
			}
		}
		cout<<a.substr(0,max+1)+b+a.substr(max+1)<<endl;
	}
	return 0;
}