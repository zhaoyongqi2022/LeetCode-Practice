#include <iostream>
using namespace std;
#include <vector>

// n:楼梯总阶数
// m:每次爬1....m
int climb(int& n, vector<int>& obj)
{
	if (n <= 2)
	{
		return n;
	}
	vector<int> dp(n + 1, 0);
	dp[0] = 1;

	//i从1开始
	for (int i = 1; i <= n; i++)//外层遍历背包容量
	{
		for (int j = 0; j < obj.size(); j++)//内层遍历物品
		{
			if (i >= obj[j])
			{
				dp[i] += dp[i - obj[j]];
			}
		}
	}
	return dp.back();
}