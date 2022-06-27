#include <iostream>
using namespace std;
#include <vector>

int maxProfit(vector<int>& prices)
{
	vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
	dp[0][0] = -prices[0];

	for (int i = 1; i < prices.size(); i++)
	{
		dp[i][0] = max(dp[i - 1][0], -prices[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
	}

	return dp[prices.size() - 1][1];
}

//int main()
//{
//	int a[6] = { 7, 1, 5, 3, 6, 4 };
//	vector<int> prices(a, a + 6);
//	int res = maxProfit(prices);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}