//输入一组数字（可能包含重复数字），输出其所有的排列方式。
//数据范围
//输入数组长度 [0,6]
//数组元素取值范围 [1,10]
//样例
//输入：[1,2,3]
//输出：
//      [
//        [1,2,3],
//        [1,3,2],
//        [2,1,3],
//        [2,3,1],
//        [3,1,2],
//        [3,2,1]
//      ]

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> nums;
    int n;
    cin>>n;
    int temp;
//    vector<vector<int>> res;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        nums.push_back(temp);
    }
    while(next_permutation(nums.begin(),nums.end()))
    {
        for(int j=0;j<n;j++)
        {
            cout<<nums[j];
            if(j!=n-1)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}