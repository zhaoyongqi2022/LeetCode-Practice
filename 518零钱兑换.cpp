#include <iostream>
using namespace std;
#include <vector>

int change(vector<int>& coins, int amount)
{
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < coins.size(); i++)// traversal object
	{
		for (int j = coins[i]; j <= amount; j++)// traversal volume
		{
			dp[j] += dp[j - coins[i]];
		}
	}
	return dp.back();
}

//int main()
//{
//	//amount = 5, coins = [1, 2, 5]
//	int co[3] = { 1, 2, 5 };
//	vector<int> coins (co, co + 3);
//	int amount = 5;
//
//	int res = change(coins,amount);
//
//	cout << res << endl;
//	system("pause");
//	return 0;
//}