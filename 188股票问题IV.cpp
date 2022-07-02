#include <iostream>
using namespace std;
#include <vector>

int maxProfit(int k, vector<int>& prices) {
    if (prices.size() == 0) return 0;//考虑边界情况
    vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0)); //行数代表天数，是由股票价格数组的长度决定的
    for (int j = 1; j < 2 * k + 1; j += 2)
    {
        dp[0][j] = -prices[0];//第0天所有的买入获得现金都为-prices[0]
    }

    for (int i = 1; i < prices.size(); i++)//因为之前初始化了第0天，因此从第1天开始
    {
        for (int j = 0; j < 2 * k - 1; j += 2)//通过j来区分偶数和奇数，从而控制股票买卖的状态
        {
            dp[i][j + 1] = max(dp[i - 1][j] - prices[i], dp[i - 1][j + 1]);
            dp[i][j + 2] = max(dp[i - 1][j + 1] + prices[i], dp[i - 1][j + 2]);
        }
    }
    return dp[prices.size() - 1][2 * k];
}