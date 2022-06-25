#include <iostream>
using namespace std;
#include <vector>

int change(vector<int>& coins, int& amount)
{
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 0; i < coins.size(); i++)//遍历物品
	{
		for (int j = coins[i]; j <= amount; j++) //遍历背包容量
		{
			if (dp[j - coins[i]] != INT_MAX)
			{
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
	}
	if (dp.back() == INT_MAX)
	{
		return -1;
	}
	else
	{
		return dp.back();
	}
}

//int main()
//{
//	int coi[1] = { 2 };
//	int amount = 3;
//	vector<int> coins(coi, coi + 1);
//	int res = change(coins, amount);
//	cout << res << endl;
//
//	system("pause");
//	return 0;
//}